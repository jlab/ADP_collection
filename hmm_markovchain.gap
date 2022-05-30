type Rope = extern

signature sig_dinuc(alphabet, answer) {
  answer transition(float, alphabet, answer);
  answer nil(void);
  choice [answer] h([answer]);
}

algebra alg_enum auto enum;
algebra alg_count auto count;

algebra alg_prob implements sig_dinuc(alphabet=char, answer=float) {
  float transition(float transition, char symbol, float x) {
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
  Rope nil(void) {
    Rope res;
    return res;
  }
  choice [Rope] h([Rope] candidates) {
    return candidates;
  }
}

grammar gra_dinuc uses sig_dinuc(axiom=init) {
  init = transition(CONST_FLOAT(0.25), CHAR('A'), state_A)
       | transition(CONST_FLOAT(0.25), CHAR('C'), state_C)
       | transition(CONST_FLOAT(0.25), CHAR('G'), state_G)
       | transition(CONST_FLOAT(0.25), CHAR('T'), state_T)
       ;

  state_A = transition(CONST_FLOAT(0.300), CHAR('A'), state_A)
          | transition(CONST_FLOAT(0.205), CHAR('C'), state_C)
          | transition(CONST_FLOAT(0.285), CHAR('G'), state_G)
          | transition(CONST_FLOAT(0.210), CHAR('T'), state_T)
          | nil(EMPTY)
          ;

  state_C = transition(CONST_FLOAT(0.322), CHAR('A'), state_A)
          | transition(CONST_FLOAT(0.298), CHAR('C'), state_C)
          | transition(CONST_FLOAT(0.078), CHAR('G'), state_G)
          | transition(CONST_FLOAT(0.302), CHAR('T'), state_T)
          | nil(EMPTY)
          ;

  state_G = transition(CONST_FLOAT(0.248), CHAR('A'), state_A)
          | transition(CONST_FLOAT(0.246), CHAR('C'), state_C)
          | transition(CONST_FLOAT(0.298), CHAR('G'), state_G)
          | transition(CONST_FLOAT(0.208), CHAR('T'), state_T)
          | nil(EMPTY)
          ; 

  state_T = transition(CONST_FLOAT(0.177), CHAR('A'), state_A)
          | transition(CONST_FLOAT(0.239), CHAR('C'), state_C)
          | transition(CONST_FLOAT(0.292), CHAR('G'), state_G)
          | transition(CONST_FLOAT(0.292), CHAR('T'), state_T)
          | nil(EMPTY)
          ;
}

instance ins_ppprobenum = gra_dinuc(alg_pretty * alg_prob * alg_enum);
