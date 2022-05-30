type Rope = extern

signature sig_casino(alphabet, answer) {
  answer transition_start_fair(float, answer, answer);
  answer transition_start_loaded(float, answer, answer);
  answer transition_fair_fair(float, answer, answer);
  answer transition_fair_loaded(float, answer, answer);
  answer transition_loaded_fair(float, answer, answer);
  answer transition_loaded_loaded(float, answer, answer);
  
  answer emission_fair_1(float, alphabet);
  answer emission_fair_2(float, alphabet);
  answer emission_fair_3(float, alphabet);
  answer emission_fair_4(float, alphabet);
  answer emission_fair_5(float, alphabet);
  answer emission_fair_6(float, alphabet);
  answer emission_loaded_1(float, alphabet);
  answer emission_loaded_2(float, alphabet);
  answer emission_loaded_3(float, alphabet);
  answer emission_loaded_4(float, alphabet);
  answer emission_loaded_5(float, alphabet);
  answer emission_loaded_6(float, alphabet);
  answer nil(void);
  
  choice [answer] h([answer]);
}

algebra alg_enum auto enum;
algebra alg_count auto count;

algebra alg_viterbi implements sig_casino(alphabet=char, answer=float) {
  float transition_start_fair(float transition, float emission, float x) {
    return transition * emission * x;
  }
  float transition_start_loaded(float transition, float emission, float x) {
    return transition * emission * x;
  }
  float transition_fair_loaded(float transition, float emission, float x) {
    return transition * emission * x;
  }
  float transition_fair_fair(float transition, float emission, float x) {
    return transition * emission * x;
  }
  float transition_loaded_loaded(float transition, float emission, float x) {
    return transition * emission * x;
  }
  float transition_loaded_fair(float transition, float emission, float x) {
    return transition * emission * x;
  }
  
  float emission_fair_1(float emission, char a) {
    return emission;
  }
  float emission_fair_2(float emission, char a) {
    return emission;
  }
  float emission_fair_3(float emission, char a) {
    return emission;
  }
  float emission_fair_4(float emission, char a) {
    return emission;
  }
  float emission_fair_5(float emission, char a) {
    return emission;
  }
  float emission_fair_6(float emission, char a) {
    return emission;
  }
  float emission_loaded_1(float emission, char a) {
    return emission;
  }

  float emission_loaded_2(float emission, char a) {
    return emission;
  }
  float emission_loaded_3(float emission, char a) {
    return emission;
  }
  float emission_loaded_4(float emission, char a) {
    return emission;
  }
  float emission_loaded_5(float emission, char a) {
    return emission;
  }
  float emission_loaded_6(float emission, char a) {
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

algebra alg_states implements sig_casino(alphabet=char, answer=Rope) {
  Rope transition_start_fair(float transition, Rope emission, Rope x) {
    Rope res;
    append(res, 'F');
    append(res, x);
    return res;
  }
  Rope transition_start_loaded(float transition, Rope emission, Rope x) {
    Rope res;
    append(res, 'L');
    append(res, x);
    return res;
  }
  Rope transition_fair_loaded(float transition, Rope emission, Rope x) {
    Rope res;
    append(res, 'L');
    append(res, x);
    return res;
  }
  Rope transition_fair_fair(float transition, Rope emission, Rope x) {
    Rope res;
    append(res, 'F');
    append(res, x);
    return res;
  }
  Rope transition_loaded_loaded(float transition, Rope emission, Rope x) {
    Rope res;
    append(res, 'L');
    append(res, x);
    return res;
  }
  Rope transition_loaded_fair(float transition, Rope emission, Rope x) {
    Rope res;
    append(res, 'F');
    append(res, x);
    return res;
  }
  
  Rope emission_fair_1(float emission, char a) {
    Rope res;
    return res;
  }
  Rope emission_fair_2(float emission, char a) {
    Rope res;
    return res;
  }
  Rope emission_fair_3(float emission, char a) {
    Rope res;
    return res;
  }
  Rope emission_fair_4(float emission, char a) {
    Rope res;
    return res;
  }
  Rope emission_fair_5(float emission, char a) {
    Rope res;
    return res;
  }
  Rope emission_fair_6(float emission, char a) {
    Rope res;
    return res;
  }
  Rope emission_loaded_1(float emission, char a) {
    Rope res;
    return res;
  }
  Rope emission_loaded_2(float emission, char a) {
    Rope res;
    return res;
  }
  Rope emission_loaded_3(float emission, char a) {
    Rope res;
    return res;
  }
  Rope emission_loaded_4(float emission, char a) {
    Rope res;
    return res;
  }
  Rope emission_loaded_5(float emission, char a) {
    Rope res;
    return res;
  }
  Rope emission_loaded_6(float emission, char a) {
    Rope res;
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

algebra alg_mult implements sig_casino(alphabet=char, answer=Rope) {
  Rope transition_start_fair(float transition, Rope emission, Rope x) {
    Rope res;
    append(res, transition);
    append(res, '*');
    append(res, emission);
    append(res, '*');
    append(res, x);
    return res;
  }
  Rope transition_start_loaded(float transition, Rope emission, Rope x) {
    Rope res;
    append(res, transition);
    append(res, '*');
    append(res, emission);
    append(res, '*');
    append(res, x);
    return res;
  }
  Rope transition_fair_loaded(float transition, Rope emission, Rope x) {
    Rope res;
    append(res, transition);
    append(res, '*');
    append(res, emission);
    append(res, '*');
    append(res, x);
    return res;
  }
  Rope transition_fair_fair(float transition, Rope emission, Rope x) {
    Rope res;
    append(res, transition);
    append(res, '*');
    append(res, emission);
    append(res, '*');
    append(res, x);
    return res;
  }
  Rope transition_loaded_loaded(float transition, Rope emission, Rope x) {
    Rope res;
    append(res, transition);
    append(res, '*');
    append(res, emission);
    append(res, '*');
    append(res, x);
    return res;
  }
  Rope transition_loaded_fair(float transition, Rope emission, Rope x) {
    Rope res;
    append(res, transition);
    append(res, '*');
    append(res, emission);
    append(res, '*');
    append(res, x);
    return res;
  }
  
  Rope emission_fair_1(float emission, char a) {
    Rope res;
    append(res, emission);
    return res;
  }
  Rope emission_fair_2(float emission, char a) {
    Rope res;
    append(res, emission);
    return res;
  }
  Rope emission_fair_3(float emission, char a) {
    Rope res;
    append(res, emission);
    return res;
  }
  Rope emission_fair_4(float emission, char a) {
    Rope res;
    append(res, emission);
    return res;
  }
  Rope emission_fair_5(float emission, char a) {
    Rope res;
    append(res, emission);
    return res;
  }
  Rope emission_fair_6(float emission, char a) {
    Rope res;
    append(res, emission);
    return res;
  }
  Rope emission_loaded_1(float emission, char a) {
    Rope res;
    append(res, emission);
    return res;
  }
  Rope emission_loaded_2(float emission, char a) {
    Rope res;
    append(res, emission);
    return res;
  }
  Rope emission_loaded_3(float emission, char a) {
    Rope res;
    append(res, emission);
    return res;
  }
  Rope emission_loaded_4(float emission, char a) {
    Rope res;
    append(res, emission);
    return res;
  }
  Rope emission_loaded_5(float emission, char a) {
    Rope res;
    append(res, emission);
    return res;
  }
  Rope emission_loaded_6(float emission, char a) {
    Rope res;
    append(res, emission);
    return res;
  }
  Rope nil(void) {
    Rope res;
    append(res, 1.0);
    return res;
  }
  choice [Rope] h([Rope] candidates) {
    return unique(candidates);
  }
}


grammar gra_casino uses sig_casino(axiom=start) {
  start = transition_start_fair(CONST_FLOAT(0.5), fair_emission, fair)
        | transition_start_loaded(CONST_FLOAT(0.5), loaded_emission, loaded)
        # h;

  fair  = transition_fair_fair(CONST_FLOAT(0.95), fair_emission, fair)
        | transition_fair_loaded(CONST_FLOAT(0.05), loaded_emission, loaded)
	| nil(EMPTY)
        # h;
	
  loaded  = transition_loaded_loaded(CONST_FLOAT(0.9), loaded_emission, loaded)
        | transition_loaded_fair(CONST_FLOAT(0.1), fair_emission, fair)
	| nil(EMPTY)
        # h;
	
  fair_emission = emission_fair_1(CONST_FLOAT(0.166666667), CHAR('1'))
		| emission_fair_2(CONST_FLOAT(0.166666667), CHAR('2'))
		| emission_fair_3(CONST_FLOAT(0.166666667), CHAR('3'))
		| emission_fair_4(CONST_FLOAT(0.166666667), CHAR('4'))
		| emission_fair_5(CONST_FLOAT(0.166666667), CHAR('5'))
		| emission_fair_6(CONST_FLOAT(0.166666667), CHAR('6'))
		# h;

  loaded_emission = emission_loaded_1(CONST_FLOAT(0.1), CHAR('1'))
		  | emission_loaded_2(CONST_FLOAT(0.1), CHAR('2'))
		  | emission_loaded_3(CONST_FLOAT(0.1), CHAR('3'))
		  | emission_loaded_4(CONST_FLOAT(0.1), CHAR('4'))
		  | emission_loaded_5(CONST_FLOAT(0.1), CHAR('5'))
		  | emission_loaded_6(CONST_FLOAT(0.5), CHAR('6'))
		  # h;
}

instance enum = gra_casino(alg_enum);
instance viterbistatesmult = gra_casino(alg_viterbi * alg_states * alg_mult);
instance fwd = gra_casino(alg_fwd);
instance multviterbistates = gra_casino(alg_mult * alg_viterbi * alg_states);
