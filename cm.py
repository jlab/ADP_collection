import numpy as np
import os

def parse_cm(fp):
    """Parses a covariance model file and returns it as a dictionary of states

    Parameters
    ----------
    fp : str
        Filepath to cm file, as provided by Rfam or generated via cmbuild + cmcalibrate

    Returns
    -------
    dict{index, state}
        A dictionary of covariance model states.

    Comments stem from Infernal documentation, section "9 File and output formats"
    """
    def _toBit(inp):
        if inp == '*':
            return np.nan
        return float(inp)


    with open(fp, 'r') as f:
        entry_started = False
        CM_main_model_section_started = False

        states = dict()
        node = dict()
        for line in f.readlines():
            if line.startswith('INFERNAL1/a'):
                entry_started = True
                continue
            if line.strip() == "//":
                entry_started = False
                CM_main_model_section_started = False
                continue
            if entry_started and line.strip() == 'CM':
                CM_main_model_section_started = True
                continue
            if CM_main_model_section_started:
                # Each node line begins with 45 spaces, and includes ten fields.
                if line.startswith((" " * 45) + "["):
                    parts = line.split()
                    node['type'] = parts[1]
                    node['index'] = int(parts[2])
                    continue
                parts = line.strip().split()
                #print(parts)
                state = dict()

                state['node_type'] = node['type']
                state['node_index'] = node['index']

                # The first field is the state type, either “MP”, “ML”, “MR”, “IL”, “IR”, “D”, “B”, “S”, or “E”.
                state['type'] = parts.pop(0)

                # The next field is the state index, these are in increasing order starting with 0 (i.e. lower numbered states always occur earlier in the file than higher numbered ones).
                state['index'] = int(parts.pop(0))

                # The next field is the index of the highest numbered “parent” state for the current state, where state a is a parent of state b if state a can transition to state b.
                state['parent_index'] = int(parts.pop(0))

                # The next field is the number of parent states for the current state. A set of parent states are always contigu- ously numbered. For example, if state a is the highest numbered parent state of b and b has 3 parent states, then a − 2, a − 1, and a are the three parent states of b.
                state['parent_number'] = int(parts.pop(0))

                # The next field is the index of the lowest numbered “child” state for the current state, where state c is a child of state b if b can transition to state c.
                state['child_index'] = int(parts.pop(0))

                # The next field is the number of child states for the current state. A set of child states are always contiguously numbered. For example, if state c is the lowest numbered parent state of b and b has 3 parent states, then c, c + 1, and c + 2 are the three child states of b. As a special case, for “B” (bifurcation) states this field is the state index of the “BEGR S” state to which the “B” state necessarily transitions with probability 1.0.
                state['child_number'] = int(parts.pop(0))

                # The next four fields <n1>, <n2>, <n3>, and <n4> are query dependent band values for the current state.
                # These are integers. <n1> is the minimum expected subsequence length to align at the subtree rooted at this
                # state calculated with the QDB algorithm (Nawrocki and Eddy, 2007) using a β tail loss probability value given
                # in the header in the QDBBETA2 line. <n2> is the same, but calculated with β equal to the value from the
                # QDBBETA1 header line. <n3> is the maximum expected subsequence length to align at the subtree rooted at
                # this state calculated with the QDB algorithm (Nawrocki and Eddy, 2007) using a β tail loss probability value
                # given in the header in the QDBBETA1 line. <n4> is the same, but calculated with β equal to the value from the
                # QDBBETA2 header line. These values should be in increasing order: < n1 >≤< n2 >≤< n3 >≤< n4 >,
                # although Infernal does not enforce this to be true. The QDB values will only be used by cmsearch and
                # cmscan if certain option combinations are used (see the manual page for those programs); by default they
                # are not used.
                if state['type'] not in ['E']:
                    parts = parts[4:]

                # next set of fields are log-odds bit scores for possible transitions out of this
                # state to all child states of the current states. The number of child states is given earlier on the line as the
                # sixth field. It varies depending on the state type and the node type of the next node in the model. For
                # a list of all possible sets of transitions for each possible state type/next node combination see Table 1 of
                # (Nawrocki and Eddy, 2007). As a special case, “B” (bifurcation) states have zero transition score fields, they
                # necessarily transition to their child “BEGL S” and “BEGR S” states with a probability of 1.0 (score of 0 bits).
                if state['type'] != 'B':
                    state['transition_bits'] = list(map(_toBit, parts[:state['child_number']]))
                    parts = parts[state['child_number']:]
                else:
                    # As a special case, “B” (bifurcation) states have zero transition score fields, they
                    # necessarily transition to their child “BEGL S” and “BEGR S” states with a probability of 1.0 (score of 0 bits)
                    state['transition_bits'] = [0.0, 0.0]

                # After the transition scores are the emission scores. “MP” state lines have 16 emission log-odds bit scores.
                # All other types of emitting states (“ML”, “MR”, “IL”, “IR”) will have four emission scores. All other types of
                # states will have no emission scores. For “MP” states, the sixteen scores are for the sixteen possible non-
                # degenerate RNA basepairs: “AA”, “AC”, “AG”, “AU”, “CA”, “CC”, “CG”, “CU”, “GA”, “GC”, “GG”, “GU”, “UA”,
                # “UC”, “UG”, “UU”, in that order. For the other emitting states the four scores are for “A”, “C”, “G”, and “U”, in
                # that order.
                state['emission_bits'] = list(map(_toBit, parts))

                states[state['index']] = state
    return states


def model2grammar(model):
    """Generates an gapc grammar from a given CM-model

    Parameters
    ----------
    model : dict{position, state}
        Result of parse_cm

    Returns
    -------
    str : gapL code for a grammar constituting the input covariance model.
    """
    grammar = "grammar gra_cm uses sig_cm(axiom = state_S_0) {\n"

    curr_node_index = None
    for index in range(len(model)):
        nt_name = "state_%s_%i" % (model[index]["type"], index)

        transitions = []
        for inc in range(model[index]['child_number']):
            to_index = model[index]['child_index'] + inc
            if np.isnan(model[index]['transition_bits'][inc]):
                # The special case of a score of infinity, corresponding to an impossible emission
                # or transition, is stored as ’*’
                continue
            if (model[index]['type'] in ['S', 'D']):
                #print(model[index], to_index)
                transitions.append("silent_transition(CONST_FLOAT(%f), state_%s_%i)" % (
                    model[index]['transition_bits'][inc],
                    model[model[to_index]['index']]['type'],
                    model[model[to_index]['index']]['index']))
            elif model[index]['type'] == 'B':
                transitions.append("bifurcation_transition(CONST_FLOAT(%f), CONST_FLOAT(%f), state_%s_%i, state_%s_%i; %i)" % (
                    model[index]['transition_bits'][0],
                    model[index]['transition_bits'][1],
                    model[model[index]['child_index']]['type'],
                    model[model[index]['child_index']]['index'],
                    model[model[index]['child_number']]['type'],
                    model[model[index]['child_number']]['index'],
                    index))
                break
            elif model[index]['type'] == 'MP':
                transitions.append("pair_transition(CONST_FLOAT(%f), CHAR, state_%s_%i, CHAR; %i)" % (
                    model[index]['transition_bits'][inc],
                    model[model[to_index]['index']]['type'],
                    model[model[to_index]['index']]['index'],
                    index))
            elif model[index]['type'] in ['IL', 'ML']:
                transitions.append("left_transition(CONST_FLOAT(%f), CHAR, state_%s_%i; %i)" % (
                    model[index]['transition_bits'][inc],
                    model[model[to_index]['index']]['type'],
                    model[model[to_index]['index']]['index'],
                    index))
            elif model[index]['type'] in ['IR', 'MR']:
                transitions.append("right_transition(CONST_FLOAT(%f), state_%s_%i, CHAR; %i)" % (
                    model[index]['transition_bits'][inc],
                    model[model[to_index]['index']]['type'],
                    model[model[to_index]['index']]['index'],
                    index))
            else:
                raise ValueError(model[index])
        if model[index]['type'] == 'E':
            transitions.append("nil(CONST_FLOAT(%f), EMPTY; %i)" % (
                0.0, # probability 1.0 in bits
                index))
        #break
        if model[index]['node_index'] != curr_node_index:
            grammar += "  // node [ %s %s ]\n" % (model[index]['node_type'], model[index]['node_index'])
            curr_node_index = model[index]['node_index']
        space = (" " * (len(nt_name) + 3))
        grammar += "  %s = %s\n%s# h;\n\n" % (nt_name, ("\n" + space + "| ").join(transitions), space)
    grammar += "}\n"

    return grammar


def model2probs(model):
    """Generates a helper header file holding emission bit scores for CM.

    Parameters
    ----------
    model : dict{position, state}
        Result of parse_cm

    Returns
    -------
    str : C++ header file code for an external header file. Will be read by the
    generated gapL code of a model.
    """

    header = """
#ifndef CMPROBS_HH
#define CMPROBS_HH

inline int charToIndex(char a) {
  if ((a == 'A') || (a == 'a')) return 0;
  if ((a == 'C') || (a == 'c')) return 1;
  if ((a == 'G') || (a == 'g')) return 2;
  if ((a == 'U') || (a == 'u')) return 3;
  return 99;
}
inline int charToIndex(char a, char b) {
  if (((a == 'A') || (a == 'a')) && ((b == 'A') || (b == 'a'))) return 0;
  if (((a == 'A') || (a == 'a')) && ((b == 'C') || (b == 'c'))) return 1;
  if (((a == 'A') || (a == 'a')) && ((b == 'G') || (b == 'g'))) return 2;
  if (((a == 'A') || (a == 'a')) && ((b == 'U') || (b == 'u'))) return 3;
  if (((a == 'C') || (a == 'c')) && ((b == 'A') || (b == 'a'))) return 4;
  if (((a == 'C') || (a == 'c')) && ((b == 'C') || (b == 'c'))) return 5;
  if (((a == 'C') || (a == 'c')) && ((b == 'G') || (b == 'g'))) return 6;
  if (((a == 'C') || (a == 'c')) && ((b == 'U') || (b == 'u'))) return 7;
  if (((a == 'G') || (a == 'g')) && ((b == 'A') || (b == 'a'))) return 8;
  if (((a == 'G') || (a == 'g')) && ((b == 'C') || (b == 'c'))) return 9;
  if (((a == 'G') || (a == 'g')) && ((b == 'G') || (b == 'g'))) return 10;
  if (((a == 'G') || (a == 'g')) && ((b == 'U') || (b == 'u'))) return 11;
  if (((a == 'U') || (a == 'u')) && ((b == 'A') || (b == 'a'))) return 12;
  if (((a == 'U') || (a == 'u')) && ((b == 'C') || (b == 'c'))) return 13;
  if (((a == 'U') || (a == 'u')) && ((b == 'G') || (b == 'g'))) return 14;
  if (((a == 'U') || (a == 'u')) && ((b == 'U') || (b == 'u'))) return 15;
  return 99;
}
"""
    probs = ""
    pairprobs = ""
    probs = "static const float emissions[%i][4] = {\n" % len(model)
    pairprobs = "static const float pair_emissions[%i][16] = {\n" % len(model)
    for index in range(len(model)):
        if len(model[index]['emission_bits']) == 0:
            probs += "  {0.0, 0.0, 0.0, 0.0},\n"
            pairprobs += "  {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},\n"
        elif len(model[index]['emission_bits']) == 4:
            probs += "  {%s},\n" % ", ".join(map(lambda x: "%.3f" % x, model[index]['emission_bits']))
            pairprobs += "  {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},\n"
        elif len(model[index]['emission_bits']) == 16:
            probs += "  {0.0, 0.0, 0.0, 0.0},\n"
            pairprobs += "  {%s},\n" % ", ".join(map(lambda x: "%.3f" % x, model[index]['emission_bits']))
        else:
            raise ValueError("shouldn't be")
    probs += "};\n"
    pairprobs += "};\n"

    probs += "inline float getEmission(int pos, char a) {\n"
    probs += "  return emissions[pos][charToIndex(a)];\n"
    probs += "}\n"
    pairprobs += "inline float getPairEmission(int pos, char a, char b) {\n"
    pairprobs += "  return pair_emissions[pos][charToIndex(a, b)];\n"
    pairprobs += "}\n"

    header += probs
    header += pairprobs
    header += "#endif\n"

    return header


def cm2gapc(fp, outname, verbose=None):
    """Reads a CM file and generates two output files (gapL and *.hh)

    Parameters
    ----------
    fp : str
        Filepath to cm file, as provided by Rfam or generated via cmbuild + cmcalibrate
    outname : str
        Prefix for both generated files.

    Returns
    -------
    none, but two files will be written.
    """

    model = parse_cm(fp)
    probs = model2probs(model)

    signature = """
signature sig_cm(alphabet, answer) {
  answer silent_transition(float, answer);
  answer left_transition(float, alphabet, answer; int);
  answer right_transition(float, answer, alphabet; int);
  answer pair_transition(float, alphabet, answer, alphabet; int);
  answer bifurcation_transition(float, float, answer, answer; int);
  answer nil(float, void; int);
  choice [answer] h([answer]);
}
    """

    alg_auto = """
algebra alg_enum auto enum;

algebra alg_count auto count;

algebra alg_cyk implements sig_cm(alphabet=char, answer=float) {
  float silent_transition(float tsc, float x) {
    return tsc + x;
  }
  float left_transition(float tsc, alphabet a, float x; int pos) {
    return tsc + getEmission(pos, a) + x;
  }
  float right_transition(float tsc, float x, alphabet a; int pos) {
    return tsc + getEmission(pos, a) + x;
  }
  float pair_transition(float tsc, alphabet a, float x, alphabet b; int pos) {
    return tsc + getPairEmission(pos, a, b) + x;
  }
  float bifurcation_transition(float tsc_left, float tsc_right, float left, float right; int pos) {
    return tsc_left + tsc_right + left + right;
  }
  float nil(float tsc, void; int pos) {
    return tsc;
  }
  choice [float] h([float] candidates) {
    return list(maximum(candidates));
  }
}

algebra alg_inside extends alg_cyk {
  choice [float] h([float] candidates) {
    return list(bitsum(candidates));
  }
}
    """

    program = """
import "%s.hh"
%s
%s
%s
instance count = gra_cm(alg_count);
instance enumcyk = gra_cm(alg_enum * alg_cyk);
instance cykenum = gra_cm(alg_cyk * alg_enum);
    """ % (os.path.basename(outname), signature, alg_auto, model2grammar(model))

    if verbose is not None:
        print("%s.gap" % outname, file=verbose)
    with open("%s.gap" % outname, "w") as f:
        f.write(program)

    with open("%s.hh" % outname, "w") as f:
        f.write(probs)
