type Rope = extern

signature sig_genefinder(alphabet, answer) {
  answer utr5(alphabet, answer);
  answer orf(Rope, answer, answer);
  answer nil(void);
  answer nextcodon(Rope, char, float, answer);
  answer stopcodon(Rope);
  answer utr3(alphabet, answer);
  choice [answer] h([answer]);
}

algebra alg_count auto count;
algebra alg_enum auto enum;
algebra alg_tikz auto tikz;

algebra alg_translate implements sig_genefinder(alphabet=char, answer=Rope) {
  Rope utr5(alphabet b, Rope x) {
    Rope res;
    append(res, x);
    return res;
  }
  Rope orf(Rope startcodon, Rope x, Rope utr3) {
    Rope res;
    append(res, "s");
    append(res, x);
    append(res, utr3);
    return res;
  }
  Rope nil(void) {
    Rope res;
    return res;
  }
  Rope nextcodon(Rope codon, char aa, float prob, Rope x) {
    Rope res;
    append(res, aa);
    append(res, x);
    return res;
  }
  Rope stopcodon(Rope stopcodon) {
    Rope res;
    append(res, '*');
    return res;
  }
  Rope utr3(alphabet b, Rope x) {
    Rope res;
    append(res, x);
    return res;
  }
  choice [Rope] h([Rope] candidates) {
    return unique(candidates);
  }
}

algebra alg_score implements sig_genefinder(alphabet=char, answer=double) {
  double utr5(alphabet b, double x) {
    return x;
  }
  double orf(Rope startcodon, double x, double utr3) {
    return x;
  }
  double nil(void) {
    return 0;
  }
  double nextcodon(Rope codon, char aa, float prob, double x) {
    // prob come as promille, we need to normalize them here: prob/1000
    // compare to background frequency 1/#AA = 1/64
    // log(2) compute as bit scores
    return log((prob/1000.0) / (1.0/64.0)) / log(2) + x;
  }
  double stopcodon(Rope stopcodon) {
    return 0;
  }
  double utr3(alphabet b, double x) {
    return 0;
  }
  choice [double] h([double] candidates) {
    return list(maximum(candidates));
  }
}

grammar gra_genefinder uses sig_genefinder(axiom = start) {
  start = utr5(CHAR, start)
	| orf(ROPE("AUG"), codons, addutr3)
	| nil(EMPTY)
	# h;
  
  codons = nextcodon(ROPE("UUU"), CONST_CHAR('F'), CONST_FLOAT(23.5), codons)
         | nextcodon(ROPE("UUC"), CONST_CHAR('F'), CONST_FLOAT( 9.2), codons)
         | nextcodon(ROPE("UUA"), CONST_CHAR('L'), CONST_FLOAT(12.1), codons)
         | nextcodon(ROPE("UUG"), CONST_CHAR('L'), CONST_FLOAT( 8.5), codons)
         | nextcodon(ROPE("CUU"), CONST_CHAR('L'), CONST_FLOAT( 9.2), codons)
         | nextcodon(ROPE("CUC"), CONST_CHAR('L'), CONST_FLOAT( 1.4), codons)
         | nextcodon(ROPE("CUA"), CONST_CHAR('L'), CONST_FLOAT(11.4), codons)
         | nextcodon(ROPE("CUG"), CONST_CHAR('L'), CONST_FLOAT(44.1), codons)
         | nextcodon(ROPE("AUU"), CONST_CHAR('I'), CONST_FLOAT(22.0), codons)
         | nextcodon(ROPE("AUC"), CONST_CHAR('I'), CONST_FLOAT(11.4), codons)
         | nextcodon(ROPE("AUA"), CONST_CHAR('I'), CONST_FLOAT(18.5), codons)
         | nextcodon(ROPE("AUG"), CONST_CHAR('M'), CONST_FLOAT(24.2), codons)
         | nextcodon(ROPE("GUU"), CONST_CHAR('V'), CONST_FLOAT(15.6), codons)
         | nextcodon(ROPE("GUC"), CONST_CHAR('V'), CONST_FLOAT( 9.2), codons)
         | nextcodon(ROPE("GUA"), CONST_CHAR('V'), CONST_FLOAT(18.5), codons)
         | nextcodon(ROPE("GUG"), CONST_CHAR('V'), CONST_FLOAT(24.9), codons)
         | nextcodon(ROPE("UCU"), CONST_CHAR('S'), CONST_FLOAT(12.1), codons)
         | nextcodon(ROPE("UCC"), CONST_CHAR('S'), CONST_FLOAT(10.0), codons)
         | nextcodon(ROPE("UCA"), CONST_CHAR('S'), CONST_FLOAT(19.2), codons)
         | nextcodon(ROPE("UCG"), CONST_CHAR('S'), CONST_FLOAT( 9.2), codons)
         | nextcodon(ROPE("CCU"), CONST_CHAR('P'), CONST_FLOAT( 8.5), codons)
         | nextcodon(ROPE("CCC"), CONST_CHAR('P'), CONST_FLOAT( 3.6), codons)
         | nextcodon(ROPE("CCA"), CONST_CHAR('P'), CONST_FLOAT(12.8), codons)
         | nextcodon(ROPE("CCG"), CONST_CHAR('P'), CONST_FLOAT(16.3), codons)
         | nextcodon(ROPE("ACU"), CONST_CHAR('T'), CONST_FLOAT(18.5), codons)
         | nextcodon(ROPE("ACC"), CONST_CHAR('T'), CONST_FLOAT(10.7), codons)
         | nextcodon(ROPE("ACA"), CONST_CHAR('T'), CONST_FLOAT(19.2), codons)
         | nextcodon(ROPE("ACG"), CONST_CHAR('T'), CONST_FLOAT(19.9), codons)
         | nextcodon(ROPE("GCU"), CONST_CHAR('A'), CONST_FLOAT(19.2), codons)
         | nextcodon(ROPE("GCC"), CONST_CHAR('A'), CONST_FLOAT(12.8), codons)
         | nextcodon(ROPE("GCA"), CONST_CHAR('A'), CONST_FLOAT(24.9), codons)
         | nextcodon(ROPE("GCG"), CONST_CHAR('A'), CONST_FLOAT(10.7), codons)
         | nextcodon(ROPE("UAU"), CONST_CHAR('Y'), CONST_FLOAT(29.1), codons)
         | nextcodon(ROPE("UAC"), CONST_CHAR('Y'), CONST_FLOAT(10.0), codons)
         | nextcodon(ROPE("UAA"), CONST_CHAR('*'), CONST_FLOAT( 0.7), codons)
         | nextcodon(ROPE("UAG"), CONST_CHAR('*'), CONST_FLOAT( 0.0), codons)
         | nextcodon(ROPE("CAU"), CONST_CHAR('H'), CONST_FLOAT( 9.2), codons)
         | nextcodon(ROPE("CAC"), CONST_CHAR('H'), CONST_FLOAT( 5.0), codons)
         | nextcodon(ROPE("CAA"), CONST_CHAR('Q'), CONST_FLOAT(15.6), codons)
         | nextcodon(ROPE("CAG"), CONST_CHAR('Q'), CONST_FLOAT(28.4), codons)
         | nextcodon(ROPE("AAU"), CONST_CHAR('N'), CONST_FLOAT(24.9), codons)
         | nextcodon(ROPE("AAC"), CONST_CHAR('N'), CONST_FLOAT(21.3), codons)
         | nextcodon(ROPE("AAA"), CONST_CHAR('K'), CONST_FLOAT(18.5), codons)
         | nextcodon(ROPE("AAG"), CONST_CHAR('K'), CONST_FLOAT(14.9), codons)
         | nextcodon(ROPE("GAU"), CONST_CHAR('D'), CONST_FLOAT(24.9), codons)
         | nextcodon(ROPE("GAC"), CONST_CHAR('D'), CONST_FLOAT(18.5), codons)
         | nextcodon(ROPE("GAA"), CONST_CHAR('E'), CONST_FLOAT(27.7), codons)
         | nextcodon(ROPE("GAG"), CONST_CHAR('E'), CONST_FLOAT(24.9), codons)
         | nextcodon(ROPE("UGU"), CONST_CHAR('C'), CONST_FLOAT( 5.7), codons)
         | nextcodon(ROPE("UGC"), CONST_CHAR('C'), CONST_FLOAT( 2.8), codons)
         | nextcodon(ROPE("UGA"), CONST_CHAR('*'), CONST_FLOAT( 2.1), codons)
         | nextcodon(ROPE("UGG"), CONST_CHAR('W'), CONST_FLOAT(19.9), codons)
         | nextcodon(ROPE("CGU"), CONST_CHAR('R'), CONST_FLOAT(18.5), codons)
         | nextcodon(ROPE("CGC"), CONST_CHAR('R'), CONST_FLOAT(10.0), codons)
         | nextcodon(ROPE("CGA"), CONST_CHAR('R'), CONST_FLOAT( 7.8), codons)
         | nextcodon(ROPE("CGG"), CONST_CHAR('R'), CONST_FLOAT( 7.8), codons)
         | nextcodon(ROPE("AGU"), CONST_CHAR('S'), CONST_FLOAT(24.9), codons)
         | nextcodon(ROPE("AGC"), CONST_CHAR('S'), CONST_FLOAT(12.8), codons)
         | nextcodon(ROPE("AGA"), CONST_CHAR('R'), CONST_FLOAT(10.0), codons)
         | nextcodon(ROPE("AGG"), CONST_CHAR('R'), CONST_FLOAT(12.1), codons)
         | nextcodon(ROPE("GGU"), CONST_CHAR('G'), CONST_FLOAT(24.9), codons)
         | nextcodon(ROPE("GGC"), CONST_CHAR('G'), CONST_FLOAT(16.3), codons)
         | nextcodon(ROPE("GGA"), CONST_CHAR('G'), CONST_FLOAT(27.0), codons)
         | nextcodon(ROPE("GGG"), CONST_CHAR('G'), CONST_FLOAT(32.7), codons)
	 // three designated stop codons:
	 | stopcodon(ROPE("UAG"))
	 | stopcodon(ROPE("UGA"))
	 | stopcodon(ROPE("UAA"))
	 # h;

  addutr3 = utr3(CHAR, addutr3)
	  | nil(EMPTY)
	  # h;
}

instance ins_aa = gra_genefinder(alg_translate);
instance ins_aacount = gra_genefinder(alg_translate * alg_count);
instance ins_scoreaa = gra_genefinder(alg_score * alg_translate);
instance ins_aascore = gra_genefinder(alg_translate * alg_score);
instance ins_count = gra_genefinder(alg_count);

// example input "AAUAUGUCUGUUAAUGCAAUGGCGGCGAUUGAGUUUUCCAAGUAGAAUGAGGAUG"
