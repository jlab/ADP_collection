import numpy as np
import matplotlib.pyplot as plt
import os
import matplotlib.colors as colors
import shutil
import re
from collections import OrderedDict

TYPES = ['match', 'insertion', 'deletion']

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

    # node positions for columns refer to the full alignment
    # However, the model will have less positions due to insertion columns
    map_pos_aln_model = dict()
    with open(fp, 'r') as f:
        entry_started = False
        CM_main_model_section_started = False

        states = dict()
        node = dict()
        for line in f.readlines():
            if line.startswith(('INFERNAL1/a', 'HMMER3/f')):
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
                    node['aln_positions'] = parts[4:6]
                    for p in node['aln_positions']:
                        if p != '-':
                            map_pos_aln_model[int(p)] = int(p)
                    continue
                parts = line.strip().split()
                #print(parts)
                state = dict()

                state['node_type'] = node['type']
                state['node_index'] = node['index']
                state['aln_positions'] = node['aln_positions']

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

    for i, k in enumerate(sorted(map_pos_aln_model.keys())):
        map_pos_aln_model[k] = i+1
    for index in range(len(states)):
        states[index]['model_positions'] = [map_pos_aln_model[int(p)] if p != '-' else '-' for p in states[index]['aln_positions']]

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
                transitions.append("silent_transition(CONST_FLOAT(%f), state_%s_%i; %i)" % (
                    model[index]['transition_bits'][inc],
                    model[model[to_index]['index']]['type'],
                    model[model[to_index]['index']]['index'],
                    index))
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
  answer silent_transition(float, answer; int);
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
  float silent_transition(float tsc, float x; int pos) {
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
import "%s_data.hh"
%s
%s
%s
instance count = gra_cm(alg_count);
instance enumcyk = gra_cm(alg_enum * alg_cyk);
instance cykenum = gra_cm(alg_cyk * alg_enum);
    """ % (os.path.basename(outname), signature, alg_auto, model2grammar(model))

    if verbose is not None:
        print("wrote to '%s.gap'" % outname, file=verbose)
    with open("%s.gap" % outname, "w") as f:
        f.write(program)

    with open("%s_data.hh" % outname, "w") as f:
        f.write(probs)

    return os.path.abspath("%s.gap" % outname)


def model2dot(model):
    """Converts a covariance model into graphviz cdde"""
    dot = "digraph D {\n"

    curr_node_index = None
    edges = ""
    for index in range(len(model)):
        if model[index]['node_index'] != curr_node_index:
            dot += "  subgraph cluster_node_%i {\n" % model[index]['node_index']
            dot += "    label=\"%s_%s\"\n" % (model[index]['node_type'], model[index]['node_index'])
            curr_node_index = model[index]['node_index']

        dot += "    %s_%i;\n" % (model[index]['type'], model[index]['index'])
        for inc in range(model[index]['child_number']):
            to_index = model[index]['child_index'] + inc
            if model[index]['type'] == 'B':
                edges += "    %s_%i -> %s_%i;\n" % (model[index]['type'], model[index]['index'],
                                                    model[model[index]['child_index']]['type'], model[model[index]['child_index']]['index'])
                edges += "    %s_%i -> %s_%i;\n" % (model[index]['type'], model[index]['index'],
                                                    model[model[index]['child_number']]['type'], model[model[index]['child_number']]['index'])
                break
            if to_index in model:
                edges += "    %s_%i -> %s_%i;\n" % (model[index]['type'], model[index]['index'],
                                                    model[model[to_index]['index']]['type'], model[model[to_index]['index']]['index'])

        if ((index+1 < len(model) and curr_node_index != model[index+1]['node_index'])) or (index+1 == len(model)):
            dot += "  }\n"

    dot += edges
    dot += "}\n"

    return dot


def get_accum_state_probability(outside, state):
    if (outside is not None) and (('state_%s' % state, 0) in outside) and (('outside_state_%s' % state, 0) in outside):
        prob = ((outside[('state_%s' % state, 0)] +
            outside[('outside_state_%s' % state, 0)] -
            outside[('state_S_0', 0)].iloc[0,0] -
            outside[('outside_state_S_0', 0)].iloc[0,0]).applymap(lambda x: 2**x)).sum().sum()
        assert(prob >= 0)
        # prob > 1 can happen for repetitive use of insertion states!
        # assert prob <= 1, "prob(%s)=%s > 1!" % (state, prob)
        return prob
    else:
        if (outside is not None):
            print("state %s not found" % state)
        return 0


def _model2backbone_basepairs(model, outside=None, probs=None):
    """Convert multi state covariance model into 3-state linear table + base-pair information"""
    curr_node_index = None

    max_model_column = -1

    backbone = dict()
    basepairs = dict()
    for index in range(len(model)):
        prob = 0
        if outside is not None:
            prob = get_accum_state_probability(outside, '%s_%i' % (model[index]['type'], index))
        if probs is not None:
            key = '%s_%i' % (model[index]['type'], index)
            if key in probs:
                prob = probs[key]
        if model[index]['node_type'] == 'MATL':
            col = int(model[index]['model_positions'][0])
            max_aln_column = max(max_model_column, col)
            row = {'ML': 'match',
                   'IL': 'insertion',
                   'D' : 'deletion'}.get(model[index]['type'])
            backbone[(col, row)] = {'state_index': index, 'prob': prob}
        elif model[index]['node_type'] == 'MATR':
            col = int(model[index]['model_positions'][1])
            max_aln_column = max(max_model_column, col)
            row = {'MR': 'match',
                   'IR': 'insertion',
                   'D' : 'deletion'}.get(model[index]['type'])
            backbone[(col, row)] = {'state_index': index, 'prob': prob}
        elif model[index]['node_type'] == 'MATP':
            col_left = int(model[index]['model_positions'][0])
            col_right = int(model[index]['model_positions'][1])
            max_model_column = max(max_model_column, col_left)
            max_model_column = max(max_model_column, col_right)

            row_left = {'ML': 'match',
                        'IL': 'insertion',
                        'D' : 'deletion'}.get(model[index]['type'])
            row_right = {'ML': 'match',
                         'IL': 'insertion',
                         'D' : 'deletion'}.get(model[index]['type'])
            if model[index]['type'] == 'MP':
                row_left = 'match'
                row_right = 'match'
                basepairs[(col_left, col_right)] = prob
            if (row_left is not None):
                if (col_left, row_left) not in backbone:
                    backbone[(col_left, row_left)] = {'state_index': index, 'prob': prob}
                else:
                    backbone[(col_left, row_left)]['prob'] += prob
                    # the following is a hack to record the ML or MR state index for basepairs instead of MP
                    # since MP would lead to self-loops for base pairs as both columns would have the SAME index
                    backbone[(col_left, row_left)]['state_index'] = max(backbone[(col_left, row_left)]['state_index'], index)
            if (row_right is not None):
                if (col_right, row_right) not in backbone:
                    backbone[(col_right, row_right)] = {'state_index': index, 'prob': prob}
                else:
                    backbone[(col_right, row_right)]['prob'] += prob
                    # see above hack
                    backbone[(col_left, row_left)]['state_index'] = max(backbone[(col_left, row_left)]['state_index'], index)

    return backbone, basepairs, max_model_column


def _backbone2table(backbone):
    rows = {type_: "" for type_ in TYPES}

    cmaps = {'insertion': plt.get_cmap('Blues'),
             'deletion': plt.get_cmap('Reds'),
             'match': plt.get_cmap('Greens')}
    for type_ in TYPES:
        for ((col, _), state) in sorted([x for x in backbone.items() if x[0][1] == type_], key=lambda x: x[0][0]):
            if (type_ in ['match', 'delete']):
                assert 0 <= state['prob'] <= 1.01, "%s %s %s" % (col, state, state['prob'])
            style = ""
            fontstyle = ""
            if (type_ == 'insertion') and (state['prob'] > 1):
                style = "color=\"#ff00ff\" border=\"3\""
                fontstyle = "color=\"#ffffff\""
            rows[type_] += "    <td port='state_%i' bgcolor='%s' %s><font %s>%s: %.2f</font></td>\n" % (
                state['state_index'],
                colors.rgb2hex(cmaps[type_](state['prob'])),
                style,
                fontstyle,
                state['state_index'],
                state['prob'])

    table = "<table border='0' cellborder='0'>\n"
    for type_ in TYPES:
        table += "  <tr>\n" + rows[type_] + "  </tr>\n"
    table += "</table>\n"

    return table


def model2probdot(model, outside=None, probs=None):
    backbone, basepairs, max_model_column = _model2backbone_basepairs(model, outside=outside, probs=probs)

    dot =  "digraph H {\n"
    dot += "  rna [\n"
    dot += "    shape=plaintext\n"
    dot += "    label=<\n"
    dot += _backbone2table(backbone)
    dot += "    >\n"
    dot += "    pos=\"0,0!\"\n"
    dot += "  ];\n"
    cmap_bp = plt.get_cmap('Greens')
    for ((o, c), prob) in basepairs.items():
        o_col = backbone[(o, 'match')]['state_index']
        c_col = backbone[(c, 'match')]['state_index']
        dot_coord_x = (o + c - max_model_column - 1) / 2
        dot_coord_y = (c - o) / 2
        dot += "  center_%i_%i [pos = \"%f,%f!\" label=\"%.2f\"];\n" % (o, c, dot_coord_x, dot_coord_y, prob) # ;\n" % (o_col, c_col)
        dot += "  rna:state_%i -> center_%i_%i [arrowhead=none penwidth=10 color=\"%s\" ];\n" % (o_col, o, c, colors.rgb2hex(cmap_bp(prob)))
        dot += "  rna:state_%i -> center_%i_%i [arrowhead=none penwidth=10 color=\"%s\" ];\n" % (c_col, o, c, colors.rgb2hex(cmap_bp(prob)))

    dot += "}\n"

    return dot


def acm2probdot(fp_acm_gap, probs=None):
    rx_grammar_start = re.compile("grammar\s+(\S+)\s+uses\s+(\S+)\(axiom\s*=\s*(\S+)\)\s*\{")
    rx_grammar_end = re.compile("instance\s+\S+\s*=")

    nodes = []
    edges = []
    map_node_type = dict()
    map_parent2child = dict()
    with open(fp_acm_gap, 'r') as f:
        in_grammar = False
        term_idx = 0
        for line in f.readlines():
            m = rx_grammar_start.search(line)
            if m is not None:
                in_grammar = True
                nodes.append(m[3])
                continue
            if in_grammar:
                m = rx_grammar_end.search(line)
                if m is not None:
                    in_grammar = False
                    continue
                if " = " in line:
                    lhs, rhss = line.split(' # h;')[0].split(" = ")
                    lhs = lhs.strip()
                    nodes.append(lhs)
                    map_node_type[lhs] = list({x for x in [t.split('(')[0] for t in rhss.split(" | ")] if x not in ['Lr', 'lR', 'bg', 'INS', 'DEL']})[0]

                    for rhs in rhss.split(" | "):
                        m = re.findall("(a_\d+)", rhs)
                        for nt in m:
                            if lhs not in map_parent2child:
                                map_parent2child[lhs] = []
                            map_parent2child[lhs].append(nt)
                            nodes.append(nt)
                            edges.append((lhs, nt))

    dot = "digraph H {\n"
    term_idx = 0
    cmap_bp = plt.get_cmap('Greens')
    for node in sorted(set(nodes)):
        if (map_node_type[node] != 'NIL'):
            color = ""
            if (probs is not None) and (node in probs):
                color = "[ label=\"%s: %.2f\" fillcolor=\"%s\" style=filled ]" % (node, probs[node], colors.rgb2hex(cmap_bp(probs[node])))
            dot += "  %s %s;\n" % (node, color)
            if map_node_type[node] == 'PK':
                dot += "  char_%i [ label=\"<\" ];\n" % term_idx
                dot += "  %s -> char_%i;\n" % (node, term_idx)
                term_idx += 1
                dot += "  char_%i [ label=\">\" ];\n" % term_idx
                dot += "  %s -> char_%i;\n" % (node, term_idx)
                term_idx += 1
                children = []
                for child in list(OrderedDict.fromkeys(map_parent2child[node])):
                    if (child != node) and (map_node_type[child] != 'NIL'):
                        children.append(" -> %s" % child)
                dot += "  { rank = same; char_%i %s -> char_%i %s [style = invis]; }\n" % (term_idx-2, children[0], term_idx-1, "".join(children[1:]))
            if map_node_type[node] == 'MAT':
                dot += "  char_%i [ label=\"*\" ];\n" % term_idx
                dot += "  %s -> char_%i;\n" % (node, term_idx)
                children = []
                for child in list(OrderedDict.fromkeys(map_parent2child[node])):
                    if (child != node) and (map_node_type[child] != 'NIL'):
                        children.append(" -> %s" % child)
                if len(children) > 0:
                    dot += "  { rank = same; char_%i %s [style = invis]; }\n" % (term_idx, "".join(children))
                term_idx += 1

    for (f,t) in sorted(set(edges)):
        if (f == t):
            continue
        if (map_node_type[t] != 'NIL'):
            dot += "  %s -> %s;\n" % (f, t)

    dot += "}\n"

    return dot


def patch_report_insideoutside(fp_header, axiom='state_S_0', valid_ntprefixes=['state_D', 'state_IL', 'state_IR', 'state_MP', 'state_ML', 'state_MR'], inplace=True):
    """Replaces the generic report_insideoutside function of gapc with a CM specific one to ease parsing of probabilities"""
    def _reportNT(nt, forloops, nt_idx_inside, nt_idx_outside):
        indent = "  " * len(forloops)
        out = ""
        out += "    List_Ref<double> answers_%s;\n" % nt
        out += "    double eval_%s;\n" % nt
        out += "".join(forloops)
        out += "%s    res_inside = nt_%s(%s);\n" % (indent, nt, nt_idx_inside)
        out += "%s    res_outside = nt_outside_%s(%s);\n" % (indent, nt, nt_idx_outside)
        out += "%s    if (is_not_empty(res_inside) && is_not_empty(res_outside)) {\n" % indent
        out += "%s      push_back(answers_%s, (res_inside + res_outside - res_full - res_empty));\n" % (indent, nt)
        out += "%s    }\n" % indent
        for i in reversed(range(len(forloops))):
            out += "%s    }\n" % ("  " * i)
        out += "    eval_%s = pow(2, h(answers_%s));\n" % (nt, nt)
        out += "    out << \"%s: \" << eval_%s << \"\\n\";\n" % (nt, nt)
        out += "\n"
        return out

    rx_nt_start = re.compile("out << \"start answers (\S+)\(\"(.+?)\"")
    code = ""
    with open(fp_header) as f:
        in_function = False

        # first round: collect for-loops and indices for NT calls, since
        # inside and outside NTs might have different dimensions
        forloops = dict()
        ntcalls = dict()
        stack_fl = []
        lines = iter(f.readlines())
        code_pre = ""
        code_post = ""
        post = False
        for line in lines:
            if 'void report_insideoutside(std::ostream &out) {' in line:
                in_function = True
                code_pre += line
            elif 'template <typename Value> void  print_result(std::ostream &out, Value& res) {' in line:
                in_function = False
                post = True
            if in_function:
                if line.strip().startswith('for ('):
                    stack_fl.append(line)
                m = rx_nt_start.search(line)
                if m is not None:
                    nt = m[1]
                    # obtain true dimensions
                    nt_idx = next(lines).split('(')[-1].split(')')[0]
                    ntcalls[nt] = nt_idx
                    forloops[nt] = stack_fl
                    stack_fl = []
            else:
                if post is False:
                    code_pre += line
                else:
                    code_post += line

        code = ""
        code += "    double res_full = nt_%s(t_0_left_most, t_0_right_most);\n" % axiom
        code += "    double res_empty = nt_outside_%s(t_0_left_most, t_0_right_most);\n" % axiom
        code += "    double res_inside;\n"
        code += "    double res_outside;\n"
        code += "\n"
        for nt in forloops.keys():
            if nt.startswith('outside_'):
                continue
            if any([nt.startswith(c) for c in valid_ntprefixes]):
                code += _reportNT(nt, forloops[nt], ntcalls[nt], ntcalls['outside_%s' % nt])
        code += "  }\n"

    if inplace:
        shutil.copyfile(fp_header, fp_header + '.orig')
        with open(fp_header, "w") as f:
            f.write(code_pre + code + code_post)
    else:
        return code
