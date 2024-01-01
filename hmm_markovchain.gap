type Rope = extern

signature sig_dinuc(alphabet, answer) {
  answer transition(float, alphabet, answer);
  answer transitionend(float, answer);
  answer nil(void);
  choice [answer] h([answer]);
}

algebra alg_enum auto enum;
algebra alg_count auto count;
algebra alg_tikz auto tikz;

algebra alg_prob implements sig_dinuc(alphabet=char, answer=float) {
  float transition(float transition, char symbol, float x) {
    return transition * x;
  }  
  float transitionend(float transition, float x) {
    return transition * x;
  }  
  float nil(void) {
    return 1.0;
  }
  choice [float] h([float] candidates) {
    return list(maximum(candidates));
  }
}

algebra alg_pretty implements sig_dinuc(alphabet=char, answer=Rope) {
  Rope transition(float transition, char state, Rope x) {
    Rope res;
    append(res, state);
    append(res, x);
    return res;
  }
  Rope transitionend(float transition, Rope x) {
    Rope res;
    append(res, x);
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

grammar gra_dinuc uses sig_dinuc(axiom=state_init) {
  state_init = transition(CONST_FLOAT(0.249), CHAR('A'), state_A)
             | transition(CONST_FLOAT(0.249), CHAR('C'), state_C)
             | transition(CONST_FLOAT(0.249), CHAR('G'), state_G)
             | transition(CONST_FLOAT(0.249), CHAR('T'), state_T)
             | transitionend(CONST_FLOAT(0.004), state_end)
             ;

  state_A = transition(CONST_FLOAT(0.299), CHAR('A'), state_A)
          | transition(CONST_FLOAT(0.204), CHAR('C'), state_C)
          | transition(CONST_FLOAT(0.284), CHAR('G'), state_G)
          | transition(CONST_FLOAT(0.209), CHAR('T'), state_T)
          | transitionend(CONST_FLOAT(0.004), state_end)
          ;

  state_C = transition(CONST_FLOAT(0.321), CHAR('A'), state_A)
          | transition(CONST_FLOAT(0.297), CHAR('C'), state_C)
          | transition(CONST_FLOAT(0.077), CHAR('G'), state_G)
          | transition(CONST_FLOAT(0.301), CHAR('T'), state_T)
          | transitionend(CONST_FLOAT(0.004), state_end)
          ;

  state_G = transition(CONST_FLOAT(0.247), CHAR('A'), state_A)
          | transition(CONST_FLOAT(0.245), CHAR('C'), state_C)
          | transition(CONST_FLOAT(0.297), CHAR('G'), state_G)
          | transition(CONST_FLOAT(0.207), CHAR('T'), state_T)
          | transitionend(CONST_FLOAT(0.004), state_end)
          ; 

  state_T = transition(CONST_FLOAT(0.176), CHAR('A'), state_A)
          | transition(CONST_FLOAT(0.238), CHAR('C'), state_C)
          | transition(CONST_FLOAT(0.291), CHAR('G'), state_G)
          | transition(CONST_FLOAT(0.291), CHAR('T'), state_T)
          | transitionend(CONST_FLOAT(0.004), state_end)
          ;
          
  state_end = nil(EMPTY);
}

instance ins_ppprobenum = gra_dinuc(alg_pretty * alg_prob * alg_enum);
