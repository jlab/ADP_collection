signature sig_tmhmm(alphabet, answer) {
  answer silent_transition(float, answer);
  answer transition(char, float, answer, answer);
  answer nil(void);
  answer emission(float, alphabet);
  choice [answer] h([answer]);
}

algebra alg_viterbi implements sig_tmhmm(alphabet=char, answer=float) {
  float silent_transition(float prob, float t) {
    return prob * t;
  }
  float transition(char label, float prob, float e, float t) {
    return prob * e * t;
  }
  float nil(void) {
    return 1.0;
  }
  float emission(float prob, char emission) {
    return prob;
  }
  choice [float] h([float] candidates) {
    return list(maximum(candidates));
  }
}

algebra alg_fwd_scaled extends alg_viterbi {
  float emission(float prob, char emission) {
    /* 43.38 is a scaling factor against numeric instability,
     * as candidate probabilities tend to become very small.
     * The value is 1 / median of all emission probabilities
     * in the TMHMM2 model; but in principle can be any value > 1.
     */
    return 22.56 * prob;
  }
  float normalize_derivative(float q, float pfunc) {
    return q / pfunc;
  }
  choice [float] h([float] candidates) {
    return list(sum(candidates));
  }
}

algebra alg_viterbi_bit extends alg_viterbi {
  float silent_transition(float prob, float t) {
    return log(1.0/prob) + t;
  }
  float transition(char label, float prob, float e, float t) {
    return log(1.0/prob) + e + t;
  }
  float nil(void) {
    return 0.0;
  }
  float emission(float prob, char emission) {
    return log(1.0/prob);
  }
  choice [float] h([float] candidates) {
    return list(minimum(candidates));
  }
}

algebra alg_fwd_bit extends alg_viterbi_bit {
  float normalize_derivative(float q, float pfunc) {
    return exp(pfunc - q);
  }
  choice [float] h([float] candidates) {
    return list(negexpsum(candidates));
  }
}

algebra alg_label implements sig_tmhmm(alphabet=char, answer=Rope) {
  Rope silent_transition(float prob, Rope x) {
    return x;
  }
  Rope transition(char label, float prob, Rope e, Rope t) {
    Rope res;
    append(res, label);
    append(res, t);
    return res;
  }
  Rope nil(void) {
    Rope res;
    return res;
  }
  Rope emission(float prob, char emission) {
    Rope res;
    return res;
  }
  choice [Rope] h([Rope] candidates) {
    return unique(candidates);
  }
}
