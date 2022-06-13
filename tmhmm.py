MAP_LABEL_COLOR = {
    'i': '#b3e2cd',
    'O': '#fdcdac',
    'o': '#cbd5e8',
    'M': '#f4cae4'}


def parse_model(fp: str):
    """Parse original TMHMM model file (currently only 2.0).
    Parameters
    ----------
    fp : str
        Filepath to original TMHMM model file.
        Download at https://services.healthtech.dtu.dk/cgi-bin/sw_request

    Returns
    -------
    Dict of HMM states.
    """
    states = dict()
    with open(fp, 'r') as f:
        content = ''.join([line.strip()+' '
                           for line in f.readlines()
                           if (not line.startswith('#'))])
        for content_state in content.split('}'):
            keyvalues = dict()

            content_state = content_state.strip()
            if content_state == "":
                continue
            statename, statecontent = content_state.split('{')
            statename = statename.strip()

            for field in statecontent.split(';'):
                field = field.strip()
                if field == "":
                    continue
                key = field.split()[0]
                keyvalues[key] = field.split()[1:]
            states[statename] = keyvalues

    # carry over tied transitions
    for name in states:
        if 'tied_trans' in states[name].keys():
            tiedtrans = []
            for i in range(len(states[name]['trans'])):
                tiedtrans.append(states[name]['trans'][i] + ':')
                tiedtrans.append(
                    states[states[name]['tied_trans'][0]]['trans'][2*i+1])
            states[name]['trans'] = tiedtrans
            del states[name]['tied_trans']

    # allow begin -> end transition to parse "" string
    del states['begin']['end']

    return states


def model_to_graphviz(states: dict) -> str:
    """Generates graphviz code to plot the (TM)HMM.

    Parameters
    ----------
    states:
        States of the HMM as obtained from "parse_model".

    Returns
    -------
    String that containes graphviz code.
    """
    # dot graph
    out = "digraph tmhmm {\n"
    for name in states.keys():
        state = states[name]

        if (name == 'header'):
            continue

        label = name
        attr = ""
        if 'label' in state.keys():
            label += '<br/>%s' % state['label'][0]
            attr = 'fillcolor="%s", style=filled' % MAP_LABEL_COLOR[
                state['label'][0]]
        if 'only' in state.keys():
            attr += ', shape="folder"'
        out += "state_%s [ label=<%s> %s ];\n" % (name, label, attr)
        if 'trans' in state.keys():
            if ':' in ''.join(state['trans']):
                for k in range(0, len(state['trans']), 2):
                    prob = float(state['trans'][k+1])
                    threshold = 0
                    out += "state_%s -> state_%s [ penwidth=%.2f %s ];\n" % (
                        name,
                        state['trans'][k].split(':')[0].strip(),
                        max(1, 10 * prob),
                        '' if prob > threshold else ', style="dotted"'
                    )
            else:
                for to in state['trans']:
                    out += "state_%s -> state_%s;\n" % (name, to)
        assert 'tied_trans' not in state.keys()
    out += "}\n"

    return out


def model_to_grammar(states: dict) -> str:
    """Translates model into ADP grammar.

    Parameters
    ----------
    states:
        States of the HMM as obtained from "parse_model".

    Returns
    -------
    String containing source code for grammar component of ADP source code.
    """
    gra = "grammar gra_tmhmm uses sig_tmhmm(axiom = state_begin) {\n"
    for name, state in states.items():
        if (name == 'header'):
            continue

        label = " "
        if 'label' in state.keys():
            assert len(state['label']) == 1
            label = state['label'][0]

        nt_emissions = "emissions_"
        emissions = None
        assert len(
            set(['only', 'tied_letter', 'letter']) & set(state.keys())) == 1
        if 'only' in state.keys():
            nt_emissions += name
            es = {x.split(':')[0]: x.split(':')[-1] for x in state['only']}
            assert abs(sum(map(float, es.values())) - 1) < 0.001
            emissions = ' |\n      '.join(
                ["only(CONST_FLOAT(%s), CHAR('%s'))" % (v, k)
                 for k, v in es.items()])
        elif 'tied_letter' in state.keys():
            assert len(state['tied_letter']) == 1
            nt_emissions += state['tied_letter'][0]
        elif 'letter' in state.keys():
            assert state['letter'] == ['NULL']
            nt_emissions = None
            emissions = None

        assert 'trans' in state.keys()
        nt_transitions = "transitions_%s" % name
        transitions = None
        if ':' in ''.join(state['trans']):
            transitions = ['trans(CONST_FLOAT(%s), state_%s)' % (
                {'1': '1.0',
                 '0': '0.0'}.get(
                    state['trans'][k+1],
                    state['trans'][k+1]),
                state['trans'][k].split(':')[0].strip())
                for k in range(0, len(state['trans']), 2)]
            if 'end' not in state.keys():
                transitions.append("nil(EMPTY)")
            else:
                assert state['end'] == ['0']
            transitions = ' |\n      '.join(transitions)
        else:
            assert False

        gra += "  state_%s = " % name
        if ((nt_emissions is not None)):
            trans = [nt_transitions]
            assert 'tied_trans' not in state.keys()
            trans = trans[0]
            gra += "step(CONST_CHAR('%s'), %s, %s)" % (
                label, nt_emissions, trans)
        else:
            gra += "silent_step(%s)" % nt_transitions
        gra += " # h;\n"

        if (emissions is not None):
            gra += "    %s =\n      %s\n      # h;\n" % (
                nt_emissions, emissions)
        if (transitions is not None):
            gra += "    %s =\n      %s" % (nt_transitions, transitions)
            if ':' in ''.join(state['trans']):
                gra += "\n      # h"
            gra += ";\n"

    gra += "}\n"

    return gra


def generic_sig_algs() -> str:
    sig = "signature sig_tmhmm(alphabet, answer) {\n"
    sig += "  answer silent_step(answer);\n"
    sig += "  answer step(char, answer, answer);\n"
    sig += "  answer nil(void);\n"
    sig += "  answer trans(float, answer);\n"
    sig += "  answer only(float, alphabet);\n"
    sig += "  choice [answer] h([answer]);\n"
    sig += "}\n"

    alg_viterbi = (
        "algebra alg_viterbi implements sig_tmhmm(alphabet=char, "
        "answer=float) {\n"
        "  float silent_step(float x) {\n"
        "    return x;\n"
        "  }\n"
        "  float step(char label, float e, float t) {\n"
        "    return e*t;\n"
        "  }\n"
        "  float nil(void) {\n"
        "    return 1;\n"
        "  }\n"
        "  float trans(float prob, float x) {\n"
        "    return prob * x;\n"
        "  }\n"
        "  float only(float prob, char emission) {\n"
        "    return prob;\n"
        "  }\n"
        "  choice [float] h([float] candidates) {\n"
        "    return list(maximum(candidates));\n"
        "  }\n"
        "}\n")

    alg_viterbi_bit = (
        "algebra alg_viterbi_bit extends alg_viterbi {\n"
        "  float step(char label, float e, float t) {\n"
        "    return log(1.0/e) + t;\n"
        "  }\n"
        "  float nil(void) {\n"
        "    return 0.0;\n"
        "  }\n"
        "  float trans(float prob, float x) {\n"
        "    return log(1.0/prob) + x;\n"
        "  }\n"
        "  choice [float] h([float] candidates) {\n"
        "    return list(minimum(candidates));\n"
        "  }\n"
        "}\n"
    )

    alg_label = (
        "algebra alg_label implements sig_tmhmm(alphabet=char,"
        " answer=Rope) {\n"
        "  Rope silent_step(Rope x) {\n"
        "    return x;\n"
        "  }\n"
        "  Rope step(char label, Rope e, Rope t) {\n"
        "    Rope res;\n"
        "    append(res, label);\n"
        "    append(res, t);\n"
        "    return res;\n"
        "  }\n"
        "  Rope nil(void) {\n"
        "    Rope res;\n"
        "    return res;\n"
        "  }\n"
        "  Rope trans(float prob, Rope x) {\n"
        "    return x;\n"
        "  }\n"
        "  Rope only(float prob, char emission) {\n"
        "    Rope res;\n"
        "    return res;\n"
        "  }\n"
        "  choice [Rope] h([Rope] candidates) {\n"
        "    return unique(candidates);\n"
        "  }\n"
        "}\n"
    )

    return [sig, alg_viterbi, alg_viterbi_bit, alg_label]


def generate_gapc(fp_model: str, fp_output: str):
    model = parse_model(fp_model)

    grammar = model_to_grammar(model)
    comps = generic_sig_algs()
    sig = comps.pop(0)
    algs = comps

    with open(fp_output, 'w') as f:
        f.write("type Rope = extern\n\n")
        f.write(sig+"\n")
        f.write('algebra alg_enum auto enum;\n\n')
        f.write('algebra alg_count auto count;\n\n')
        for alg in algs:
            f.write(alg+"\n")
        f.write(grammar+"\n")
        f.write('instance dummy = gra_tmhmm(alg_enum);\n')
