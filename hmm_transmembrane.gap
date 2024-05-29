type Rope = extern

signature sig_transmembrane(alphabet, answer) {
  answer transition(float, alphabet, answer, answer);
  answer transitionend(float, answer);
  answer emission(float, alphabet);
  answer nil(void);
  choice [answer] h([answer]);
}

algebra alg_enum auto enum;
algebra alg_count auto count;
algebra alg_tikz auto tikz;

algebra alg_viterbi implements sig_transmembrane(alphabet=char, answer=float) {
  float transition(float transition, char state, float emission, float x) {
    return transition * emission * x;
  }  
  float transitionend(float transition, float x) {
    return transition * x;
  }  
  float emission(float emission, char a) {
    return emission;
  }
  float nil(void) {
    return 1.0;
  }
  choice [float] h([float] candidates) {
    return list(maximum(candidates));
  }
}
algebra alg_fwd extends alg_viterbi {
  choice [float] h([float] candidates) {
    return list(sum(candidates));
  }
}

algebra alg_states implements sig_transmembrane(alphabet=char, answer=Rope) {
  Rope transition(float transition, char state, Rope emission, Rope x) {
    Rope res;
    append(res, state);
    append(res, x);
    return res;
  }
  Rope transitionend(float transition, Rope x) {
    return x;
  }
  Rope emission(float emission, char a) {
    Rope res;
    return res;
  }
  Rope nil(void) {
    Rope res;
    append(res, '$');
    return res;
  }
  choice [Rope] h([Rope] candidates) {
    return candidates;
  }
}

algebra alg_structure implements sig_transmembrane(alphabet=char, answer=Rope) {
  Rope transition(float transition, char state, Rope emission, Rope x) {
    Rope res;
    if (state == 'T') {
      append(res, 'I');
    } else {
      append(res, 'O');
    }
    append(res, x);
    return res;
  }
  Rope transitionend(float transition, Rope x) {
    return x;
  }
  Rope emission(float emission, char a) {
    Rope res;
    return res;
  }
  Rope nil(void) {
    Rope res;
    append(res, '$');
    return res;
  }
  choice [Rope] h([Rope] candidates) {
    return unique(candidates);
  }
}

/*
st_ short for state, em_ short for emission
*/
grammar gra_transmembrane uses sig_transmembrane(axiom=st_init) {
  st_init = transition(CONST_FLOAT(0.89), CONST_CHAR('e'), em_ext, st_ext)
          | transition(CONST_FLOAT(0.01), CONST_CHAR('T'), em_trans, st_trans)
          | transition(CONST_FLOAT(0.08), CONST_CHAR('i'), em_int, st_int)
          | transitionend(CONST_FLOAT(0.02), st_end)
          # h;

  st_ext = transition(CONST_FLOAT(0.49), CONST_CHAR('e'), em_ext,   st_ext)
         | transition(CONST_FLOAT(0.05), CONST_CHAR('i'), em_int,   st_int)
         | transition(CONST_FLOAT(0.44), CONST_CHAR('T'), em_trans, st_trans)
         | transitionend(CONST_FLOAT(0.02), st_end)
         # h;

  st_trans = transition(CONST_FLOAT(0.05), CONST_CHAR('e'), em_ext,   st_ext)
           | transition(CONST_FLOAT(0.34), CONST_CHAR('i'), em_int,   st_int)
           | transition(CONST_FLOAT(0.59), CONST_CHAR('T'), em_trans, st_trans)
           | transitionend(CONST_FLOAT(0.02), st_end)
           # h;

  st_int = transition(CONST_FLOAT(0.05), CONST_CHAR('e'), em_ext,   st_ext)
         | transition(CONST_FLOAT(0.79), CONST_CHAR('i'), em_int,   st_int)
         | transition(CONST_FLOAT(0.14), CONST_CHAR('T'), em_trans, st_trans)
         | transitionend(CONST_FLOAT(0.02), st_end)
         # h;
         
  st_end = nil(EMPTY)
         # h;

  em_ext = emission(CONST_FLOAT(0.15), CHAR('A'))
         | emission(CONST_FLOAT(0.15), CHAR('C'))
         | emission(CONST_FLOAT(0.60), CHAR('G'))
         | emission(CONST_FLOAT(0.10), CHAR('T'))
         # h;

  em_trans = emission(CONST_FLOAT(0.3), CHAR('A'))
           | emission(CONST_FLOAT(0.4), CHAR('C'))
           | emission(CONST_FLOAT(0.2), CHAR('G'))
           | emission(CONST_FLOAT(0.1), CHAR('T'))
           # h;

  em_int = emission(CONST_FLOAT(0.1), CHAR('A'))
         | emission(CONST_FLOAT(0.1), CHAR('C'))
         | emission(CONST_FLOAT(0.6), CHAR('G'))
         | emission(CONST_FLOAT(0.2), CHAR('T'))
         # h;
}

/*
example inputs: GCGGCCGA
*/

instance test = gra_transmembrane(alg_states);
