import rna
input rna

signature sig_rna(alphabet, answer) {
  answer pair(Subsequence, answer, Subsequence);
  answer sadd(Subsequence, answer);
  answer adds(answer, Subsequence);
  answer fork(answer, answer);
  answer nil(void);
  answer single(Subsequence);
  choice [answer] h([answer]);
}

algebra alg_enum auto enum;
algebra alg_count auto count;
algebra alg_tikz auto tikz;

algebra alg_dotBracket implements sig_rna(alphabet=char, answer=string) {
  string pair(Subsequence lb, string x, Subsequence rb) {
    string res;
    append(res, '(');
    append(res, x);
    append(res, ')');
    return res;
  }
  string sadd(Subsequence b, string x) {
    string res;
    append(res, '.');
    append(res, x);
    return res;
  }
  string adds(string x, Subsequence b) {
    string res;
    append(res, x);
    append(res, '.');
    return res;
  }
  string fork(string x, string y) {
    string res;
    append(res, x);
    append(res, y);
    return res;
  }
  string nil(void) {
    string r;
    return r;
  }
  string single(Subsequence b) {
    string res;
    append(res, '.');
    return res;
  }
  choice [string] h([string] candidates) {
    return candidates;
  }
}

/*
a second version of the dot Bracket algebra,
but here identical representations get collapsed
through the application of "unique"
*/
algebra alg_dotBracketUnique extends alg_dotBracket {
  choice [string] h([string] candidates) {
    return unique(candidates);
  }
}

algebra alg_bpmax implements sig_rna(alphabet=char, answer=int) {
  int pair(Subsequence lb, int x, Subsequence rb) {
    return x+1;
  }
  int sadd(Subsequence b, int x) {
    return x;
  }
  int adds(int x, Subsequence b) {
    return x;
  }
  int fork(int x, int y) {
    return x+y;
  }
  int nil(void) {
    return 0;
  }
  int single(Subsequence b) {
    return 0;
  }
  choice [int] h([int] candidates) {
    return list(maximum(candidates));
  }
}

/* 
DE04: "Evaluation of several lightweight stochastic context-free grammars for RNA secondary structure prediction"
Robin D Dowell and Sean R Eddy
       BMC Bioinformatics 2004
       https://doi.org/10.1186/1471-2105-5-71 
RR09: "Ambiguity Analysis of RNA SecondaryStructure Prediction Grammars"
       Raphael Reitzig
       Bachelor's thesis 2009
       http://reitzig.github.io/assets/pdf/ambiguity-analysis-of-RNA-grammars.pdf
*/

/* 
DE04: "We first implemented two structurally ambiguous grammars G1 and G2"
      "any S =>e derivation in a parse tree could also be S => SS => eS => ee"
Definition of Ruth Nussinov 1978
Prototype grammar of Infernal

--> ambiguous
*/
grammar gra_g1 uses sig_rna(axiom=S) {
  S = pair(BASE, S, BASE) with basepairing
    | sadd(BASE, S)
    | adds(S, BASE)
    | fork(S, S)
    | nil(EMPTY)
    # h;
}

/* 
DE04 "G2 extends [G1] to include base pair stacking parameters."
--> ambiguous
*/
grammar gra_g2 uses sig_rna(axiom=S) {
  S = pair(BASE, P, BASE) with stackpairing
    | sadd(BASE, S)
    | adds(S, BASE)
    | fork(S, S)
    | nil(EMPTY)
    # h;
	
  P = pair(BASE, P, BASE) with basepairing
    | S
    # h;
}

/* 
DE04 "Four unambiguous grammars: G3, G4, G5, G6"
     "Each of the four grammars was conjectured to be unambiguous by inspection. Each one also passed the empirical test for ambiguity described in Methods, using the test set of 2455 Rfam sequences"
     "G3 was developed by RDD"
     "G3 imposes a minimum hairpin loop length of one nucleotide,"
     "G3 and G6 can not emit an empty string"
RR08 "it is proven that G3 is unambiguous with regards to secondary structures
--> un-ambiguous
*/
grammar gra_g3 uses sig_rna(axiom=S) {
  S = pair(BASE, S, BASE) with basepairing
    | sadd(BASE, L)
    | adds(R, BASE)
    | fork(L, S)
    # h;
  
  L = pair(BASE, S, BASE) with basepairing
    | sadd(BASE, L)
    # h;
	
  R = adds(R, BASE)
    | nil(EMPTY)
    # h;
}

/* 
DE04 "We challenged Graeme Mitchison to make a smaller one, and he produced G4"
     "G4 and G5 do not impose mini-mum hairpin loop lengths"
     "G4 and G5 can emit empty strings"  
RR09 "G4 is unambiguous with regards to secondary structures"
--> un-ambiguous
*/
grammar gra_g4 uses sig_rna(axiom=S) {
  S = sadd(BASE, S)
    | T
    | nil(EMPTY)
    # h;

  T = adds(T, BASE)
    | pair(BASE, S, BASE) with basepairing
      // original production rule is TaSa' which would translate
      // to xxx(T, BASE, S, BASE) making application of basepair
      // filter more complicated. Since h is not applied, it is
      // equivalent to the below:
    | fork(T, pair(BASE, S, BASE) with basepairing)
    # h;
}

/* 
DE04 "The ultracompact G5 grammar is from Ivo Hofacker"
     "G4 and G5 do not impose mini-mum hairpin loop lengths"
     "G4 and G5 can emit empty strings"  
RR09 "proving G5 to be unambiguous withregards to secondary structures"
--> un-ambiguous
*/
grammar gra_g5 uses sig_rna(axiom=S) {
  S = sadd(BASE, S)
      // original production rule is aSa'S, see comment in g4
    | fork(pair(BASE, S, BASE) with basepairing, S)
    | nil(EMPTY)
    # h;
}

/* 
DE04 "G6 is the Knudsen/Hein grammar utilized in the Pfold package"
     "G6 has aminimum of two" (unpaired bases in each hairpin loop)
     "G3 and G6 can not emit an empty string"
RR09 "G6 is unambiguous with regards to secondary structures"
--> un-ambiguous
*/
grammar gra_g6 uses sig_rna(axiom=S) {
  S = fork(L,S)
    | L
    # h;
  
  L = pair(BASE, F, BASE) with basepairing
    | single(BASE)
    # h;
	
  F = pair(BASE, F, BASE) with basepairing
    | fork(L, S)
    # h;
}

/*
Comparing carefully with original recurrences, g5 is Ruth Nussinov's original grammar!
Somehow, the additional rule adds(S, BASE) sneaked into text book versions of her grammar,
making it ambiguous!
*/
grammar gra_nussinov uses sig_rna(axiom=S) {
  S = sadd(BASE, S)
    | adds(S, BASE)
    | fork(pair(BASE, S, BASE) with basepairing, S)
    | nil(EMPTY)
    # h;
}

/*
example inputs: CCAGACUGAAGAUCUGGAG
*/

instance ins_g1_count = gra_g1(alg_count);
instance ins_g2_count = gra_g2(alg_count);
instance ins_g3_count = gra_g3(alg_count);
instance ins_g4_count = gra_g4(alg_count);
instance ins_g5_count = gra_g5(alg_count);
instance ins_g6_count = gra_g6(alg_count);

instance ins_g3_dbcount = gra_g3(alg_dotBracket * alg_count);
instance ins_g4_dbcount = gra_g4(alg_dotBracket * alg_count);
instance ins_g5_dbcount = gra_g5(alg_dotBracket * alg_count);
instance ins_g6_dbcount = gra_g6(alg_dotBracket * alg_count);

instance ins_g3_bpmaxdb = gra_g3(alg_bpmax * alg_dotBracket);
instance ins_g4_bpmaxdb = gra_g4(alg_bpmax * alg_dotBracket);
instance ins_g5_bpmaxdb = gra_g5(alg_bpmax * alg_dotBracket);
instance ins_g6_bpmaxdb = gra_g6(alg_bpmax * alg_dotBracket);

instance ins_nussinov_enumcount = gra_nussinov(alg_enum * alg_count);
instance ins_nussinov_dbucount = gra_nussinov(alg_dotBracketUnique * alg_count);
