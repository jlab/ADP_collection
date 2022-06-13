signature sig_tmhmm(alphabet, answer) {
  answer silent_step(answer);
  answer step(char, answer, answer);
  answer nil(void);
  answer trans(float, answer);
  answer only(float, alphabet);
  choice [answer] h([answer]);
}

algebra alg_viterbi implements sig_tmhmm(alphabet=char, answer=float) {
  float silent_step(float x) {
    return x;
  }
  float step(char label, float e, float t) {
    return e*t;
  }
  float nil(void) {
    return 1;
  }
  float trans(float prob, float x) {
    return prob * x;
  }
  float only(float prob, char emission) {
    return prob;
  }
  choice [float] h([float] candidates) {
    return list(maximum(candidates));
  }
}

algebra alg_viterbi_bit extends alg_viterbi {
  float step(char label, float e, float t) {
    return log(1.0/e) + t;
  }
  float nil(void) {
    return 0.0;
  }
  float trans(float prob, float x) {
    return log(1.0/prob) + x;
  }
  choice [float] h([float] candidates) {
    return list(minimum(candidates));
  }
}

algebra alg_label implements sig_tmhmm(alphabet=char, answer=Rope) {
  Rope silent_step(Rope x) {
    return x;
  }
  Rope step(char label, Rope e, Rope t) {
    Rope res;
    append(res, label);
    append(res, t);
    return res;
  }
  Rope nil(void) {
    Rope res;
    return res;
  }
  Rope trans(float prob, Rope x) {
    return x;
  }
  Rope only(float prob, char emission) {
    Rope res;
    return res;
  }
  choice [Rope] h([Rope] candidates) {
    return unique(candidates);
  }
}
