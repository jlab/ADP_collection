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
    map_state_label = dict()
    for name, state in states.items():
        # skip the header "state", which defined the alphabet
        if (name == 'header'):
            continue

        # normalize label
        # - use first char
        # - use ' ' if no label is given
        label = " "
        if 'label' in state.keys():
            assert len(state['label']) == 1
            label = state['label'][0]
        map_state_label['state_%s' % name] = label

        # normalize transitions
        # - from 'a:', 'b', 'c:', 'd' build dict {'a': 'b', 'c': 'd'}
        # - add 'nil': '0' if ending parse in this state is allowed
        # - use float format instead of int, i.e. 0.0 instead of 0
        norm_transitions = None
        if ':' in ''.join(state['trans']):
            norm_transitions = {state['trans'][k].split(':')[0]:
                {'1': '1.0',
                 '0': '0.0'}.get(
                     state['trans'][k+1],
                     state['trans'][k+1]) for k in range(0, len(state['trans']), 2)}
            if 'end' not in state.keys():
                norm_transitions.update({'end': '1.0'})
            else:
                assert state['end'] == ['0']
        else:
            assert False


        # transform emission information into GAP rules
        nt_emissions = "emit_"
        emissions = None
        assert len(
            set(['only', 'tied_letter', 'letter']) & set(state.keys())) == 1
        if 'only' in state.keys():
            nt_emissions += name
            es = {x.split(':')[0]: x.split(':')[-1] for x in state['only']}
            assert abs(sum(map(float, es.values())) - 1) < 0.001
            emissions = ["    emission(CONST_FLOAT(%s), CHAR('%s'))" % (v, k)
                         for k, v in es.items()]
        elif 'tied_letter' in state.keys():
            assert len(state['tied_letter']) == 1
            nt_emissions += state['tied_letter'][0]
        elif 'letter' in state.keys():
            assert state['letter'] == ['NULL']
            nt_emissions = None
            emissions = None

        # transform transition information into GAP production rules
        code_transitions = []
        for to_state, prob in norm_transitions.items():
            if (emissions is None) and (nt_emissions is None):
                if to_state == "end":
                    code_transitions.append('    state_end')
                else:
                    code_transitions.append('    silent_transition(CONST_FLOAT(%s), state_%s)' % (prob, to_state))
            else:
                code_transitions.append('    transition(CONST_CHAR(\'%s\'), CONST_FLOAT(%s), %s, state_%s)' % (label, prob, nt_emissions, to_state))


        gra += '  state_%s =\n%s\n    # h;\n' % (name, ' |\n'.join(code_transitions))
        if emissions is not None:
            gra += '  emit_%s =\n%s\n    # h;\n' % (name, ' |\n'.join(emissions))

        gra += "\n"

    gra += '  state_end = nil(EMPTY) # h;\n'
    gra += "}\n"

    return gra, map_state_label


def generic_sig_algs() -> str:
    sig = "signature sig_tmhmm(alphabet, answer) {\n"
    sig += "  answer silent_transition(float, answer);\n"
    sig += "  answer transition(char, float, answer, answer);\n"
    sig += "  answer nil(void);\n"
    sig += "  answer emission(float, alphabet);\n"
    sig += "  choice [answer] h([answer]);\n"
    sig += "}\n"

    alg_viterbi = (
        "algebra alg_viterbi implements sig_tmhmm(alphabet=char, "
        "answer=float) {\n"
        "  float silent_transition(float prob, float t) {\n"
        "    return prob * t;\n"
        "  }\n"
        "  float transition(char label, float prob, float e, float t) {\n"
        "    return prob * e * t;\n"
        "  }\n"
        "  float nil(void) {\n"
        "    return 1.0;\n"
        "  }\n"
        "  float emission(float prob, char emission) {\n"
        "    return prob;\n"
        "  }\n"
        "  choice [float] h([float] candidates) {\n"
        "    return list(maximum(candidates));\n"
        "  }\n"
        "}\n")
        
    alg_fwd_scaled = (
        "algebra alg_fwd_scaled extends alg_viterbi {\n"
        "  float emission(float prob, char emission) {\n"
        "    /* 43.38 is a scaling factor against numeric instability,\n"
        "     * as candidate probabilities tend to become very small.\n"
        "     * The value is 1 / 25%-percentil of all emission probabilities\n"
        "     * in the TMHMM2 model; but in principle can be any value > 1.\n"
        "     */\n"
        "    return 43.38 * prob;\n"
        "  }\n"
        "  float normalize_derivative(float q, float pfunc) {\n"
        "    return q / pfunc;\n"
        "  }\n"
        "  choice [float] h([float] candidates) {\n"
        "    return list(sum(candidates));\n"
        "  }\n"
        "}\n")

    alg_viterbi_bit = (
        "algebra alg_viterbi_bit extends alg_viterbi {\n"
        "  float silent_transition(float prob, float t) {\n"
        "    return log(1.0/prob) + t;\n"
        "  }\n"
        "  float transition(char label, float prob, float e, float t) {\n"
        "    return log(1.0/prob) + e + t;\n"
        "  }\n"
        "  float nil(void) {\n"
        "    return 0.0;\n"
        "  }\n"
        "  float emission(float prob, char emission) {\n"
        "    return log(1.0/prob);\n"
        "  }\n"
        "  choice [float] h([float] candidates) {\n"
        "    return list(minimum(candidates));\n"
        "  }\n"
        "}\n"
    )

    alg_fwd_bit = (
        "algebra alg_fwd_bit extends alg_viterbi_bit {\n"
        "  float normalize_derivative(float q, float pfunc) {\n"
        "    return exp(pfunc - q);\n"
        "  }\n"
        "  synoptic choice [float] h([float] candidates) {\n"
        "    return list(negexpsum(candidates));\n"
        "  }\n"
        "}\n"
    )

    alg_label = (
        "algebra alg_label implements sig_tmhmm(alphabet=char,"
        " answer=Rope) {\n"
        "  Rope silent_transition(float prob, Rope x) {\n"
        "    return x;\n"
        "  }\n"
        "  Rope transition(char label, float prob, Rope e, Rope t) {\n"
        "    Rope res;\n"
        "    append(res, label);\n"
        "    append(res, t);\n"
        "    return res;\n"
        "  }\n"
        "  Rope nil(void) {\n"
        "    Rope res;\n"
        "    return res;\n"
        "  }\n"
        "  Rope emission(float prob, char emission) {\n"
        "    Rope res;\n"
        "    return res;\n"
        "  }\n"
        "  choice [Rope] h([Rope] candidates) {\n"
        "    return unique(candidates);\n"
        "  }\n"
        "}\n"
    )

    return [sig, alg_viterbi, alg_fwd_scaled, alg_viterbi_bit, alg_fwd_bit,
            alg_label]


def generate_gapc(fp_model: str, fp_output: str):
    model = parse_model(fp_model)

    grammar = model_to_grammar(model)[0]
    comps = generic_sig_algs()
    sig = comps.pop(0)
    algs = comps

    with open(fp_output, 'w') as f:
        f.write("import \"ext_hmm.hh\"\n")
        f.write("type Rope = extern\n\n")
        f.write(sig+"\n")
        f.write('algebra alg_enum auto enum;\n\n')
        f.write('algebra alg_count auto count;\n\n')
        for alg in algs:
            f.write(alg+"\n")
        f.write(grammar+"\n")
        f.write('instance dummy = gra_tmhmm(alg_enum);\n')
