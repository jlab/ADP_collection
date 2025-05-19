import "ext_alignment.hh"

input raw
type Rope = extern
type typ_ali = (Rope first, Rope second)

signature sig_alignments(alphabet, answer) {
  answer Ins(Subsequence, answer);
  answer Del(answer, Subsequence);
  answer Ers(alphabet, answer, alphabet);
  answer Sto(alphabet);
  choice [answer] h([answer]);
}

algebra alg_enum auto enum;
algebra alg_count auto count;
algebra alg_tikz auto tikz;

algebra alg_similarity implements sig_alignments(alphabet=char, answer=int) {
  int Ins(Subsequence a, int x) {
    int alpha = -3;  // gap opening cost, according to https://rna.informatik.uni-freiburg.de/Teaching/index.jsp?toolName=Waterman-Smith-Beyer
    int beta = -1;  // gap enlargement const
    return x + (alpha + beta * size(a));
  }
  int Del(int x, Subsequence b) {
    int alpha = -3;  // gap opening cost, according to https://rna.informatik.uni-freiburg.de/Teaching/index.jsp?toolName=Waterman-Smith-Beyer
    int beta = -1;  // gap enlargement const
    return x + (alpha + beta * size(b));
  }
  int Ers(alphabet a, int x, alphabet b) {
    if (a == b) {
      return x +1;
    } else {
      return x -1;
    }
  }
  int Sto(alphabet sep) {
    return 0;
  }
  
  choice [int] h([int] candidates) {
    return list(maximum(candidates));
  }
}

/*
pair-wise global alignment
*/
grammar gra_WatermanSmithBeyer uses sig_alignments(axiom=A) {
  A = Ins(REGION, A)
    | Del(A, REGION)
    | Ers(CHAR, A, CHAR)
    | Sto(CHAR('@'))
    # h;
}


/*
example inputs: ZEITGEIST@TIEZIERF
*/
instance ins_WatermanSmithBeyer_count = gra_WatermanSmithBeyer(alg_count);
