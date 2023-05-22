import "ext_alignment.hh"

input raw
type Rope = extern
type typ_ali = (Rope first, Rope second)

signature sig_alignments(alphabet, answer) {
  answer Ins(alphabet, answer);
  answer Del(answer, alphabet);
  answer Ers(alphabet, answer, alphabet);
  answer Sto(alphabet);
	
  answer Region(Rope, answer);
  answer RegionEnd(Rope, answer);
  answer Region_Pr(Rope, answer);
  answer Region_PrEnd(answer, Rope);
  answer Region_Pr_Pr(answer, Rope);
  answer Region_Pr_PrEnd(answer, Rope);
	
  answer Insx(alphabet, answer);
  answer Delx(answer, alphabet);

  choice [answer] h([answer]);
}

algebra alg_enum auto enum;
algebra alg_count auto count;

algebra alg_similarity implements sig_alignments(alphabet=char, answer=int) {
  int Ins(alphabet a, int x) {
    return x -2;
  }
  int Del(int x, alphabet b) {
    return x -2;
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
	
  int Region(Rope aleft, int x) {
    return x;
  }
  int RegionEnd(Rope aright, int x) {
    return x;
  }
  int Region_Pr(Rope aleft, int x) {
    return x;
  }
  int Region_PrEnd(int x, Rope bright) {
    return x;
  }
  int Region_Pr_Pr(int x, Rope bleft) {
    return x;
  }
  int Region_Pr_PrEnd(int x, Rope bright) {
    return x;
  }
	
  // this is slightly different form http://rna.informatik.uni-freiburg.de/Teaching/index.jsp?toolName=Gotoh#
  // as there Ins + Insx is computed for first blank, we here score Ins for first blank and Insx for all following ones
  int Insx(alphabet a, int x) {
    return x -1;
  }
  int Delx(int x, alphabet b) {
    return x -1;
  }

  choice [int] h([int] candidates) {
    return list(maximum(candidates));
  }
}


algebra alg_countmanual implements sig_alignments(alphabet=char, answer=int) {
  int Ins(alphabet a, int x) {
    return x;
  }
  int Del(int x, alphabet b) {
    return x;
  }
  int Ers(alphabet a, int x, alphabet b) {
    return x;
  }
  int Sto(alphabet sep) {
    return 1;
  }
	
  int Region(Rope aleft, int x) {
    return x;
  }
   int RegionEnd(Rope aright, int x) {
    return x;
  }
  int Region_Pr(Rope aleft, int x) {
    return x;
  }
  int Region_PrEnd(int x, Rope bright) {
    return x;
  }
  int Region_Pr_Pr(int x, Rope bleft) {
    return x;
  }  
  int Region_Pr_PrEnd(int x, Rope bright) {
    return x;
  }
	
  int Insx(alphabet a, int x) {
    return x;
  }
  int Delx(int x, alphabet b) {
    return x;
  }

  choice [int] h([int] candidates) {
    return list(sum(candidates));
  }
}

algebra alg_pretty implements sig_alignments(alphabet=char, answer=typ_ali) {
  typ_ali Ins(alphabet a, typ_ali x) {
    typ_ali res;
    append(res.first, a);
    append(res.first, x.first);
    append(res.second, '-');
    append(res.second, x.second);
    return res;
  }
  typ_ali Del(typ_ali x, alphabet b) {
    typ_ali res;
    append(res.first, '-');
    append(res.first, x.first);
    append(res.second, b);
    append(res.second, x.second);
    return res;
  }
  typ_ali Ers(alphabet a, typ_ali x, alphabet b) {
    typ_ali res;
    append(res.first, a);
    append(res.first, x.first);
    append(res.second, b);
    append(res.second, x.second);
    return res;
  }
  typ_ali Sto(alphabet sep) {
    typ_ali res;
    return res;
  }
	
  typ_ali Region(Rope afirst, typ_ali x) {
    typ_ali res;
    append(res.first, afirst);
    append(res.first, x.first);
	  
    append(res.second, '_', size(afirst));
    append(res.second, x.second);
    return res;
  }
  typ_ali RegionEnd(Rope asecond, typ_ali x) {
    typ_ali res;
    append(res.first, x.first);
    append(res.first, asecond);
	  
    append(res.second, x.second);
    append(res.second, '_', size(asecond));
    return res;
  }
  typ_ali Region_Pr(Rope afirst, typ_ali x) {
    typ_ali res;
    append(res.first, afirst);
    append(res.first, x.first);
	  
    append(res.second, '_', size(afirst));
    append(res.second, x.second);
    return res;
  }
  typ_ali Region_PrEnd(typ_ali x, Rope bsecond) {
    typ_ali res;
    append(res.first, x.first);
    append(res.first, '_', size(bsecond));
	  
    append(res.second, x.second);
    append_reverse(res.second, bsecond);
    return res;
  }
  typ_ali Region_Pr_Pr(typ_ali x, Rope bfirst) {
    typ_ali res;
    append(res.first, '_', size(bfirst));
    append(res.first, x.first);
	  
    append_reverse(res.second, bfirst);
    append(res.second, x.second);
    return res;
  }
  typ_ali Region_Pr_PrEnd(typ_ali x, Rope bsecond) {
    typ_ali res;
    append(res.first, x.first);
    append(res.first, '_', size(bsecond));
	  
    append(res.second, x.second);
    append_reverse(res.second, bsecond);
    return res;
  }
	
  // this is slightly different form http://rna.informatik.uni-freiburg.de/Teaching/index.jsp?toolName=Gotoh#
  // as there Ins + Insx is computed for first blank, we here score Ins for first blank and Insx for all following ones
  typ_ali Insx(alphabet a, typ_ali x) {
    typ_ali res;
    append(res.first, a);
    append(res.first, x.first);
    append(res.second, '=');
    append(res.second, x.second);
    return res;
  }
  typ_ali Delx(typ_ali x, alphabet b) {
    typ_ali res;
    append(res.first, '=');
    append(res.first, x.first);
    append(res.second, b);
    append(res.second, x.second);
    return res;
  }

  choice [typ_ali] h([typ_ali] candidates) {
    return candidates;
  }
}

// a special pretty print algebra that uses the same symbol '-' for all types of gapc
// this illustrates semantic ambiguity and is e.g. used as the introductory example
// in the lecture slides.
algebra alg_pretty_onegap extends alg_pretty {
  typ_ali Region(Rope afirst, typ_ali x) {
    typ_ali res;
    append(res.first, afirst);
    append(res.first, x.first);
	  
    append(res.second, '-', size(afirst));
    append(res.second, x.second);
    return res;
  }
  typ_ali RegionEnd(Rope asecond, typ_ali x) {
    typ_ali res;
    append(res.first, x.first);
    append(res.first, asecond);
	  
    append(res.second, x.second);
    append(res.second, '-', size(asecond));
    return res;
  }
  typ_ali Region_Pr(Rope afirst, typ_ali x) {
    typ_ali res;
    append(res.first, afirst);
    append(res.first, x.first);
	  
    append(res.second, '-', size(afirst));
    append(res.second, x.second);
    return res;
  }  
  typ_ali Region_PrEnd(typ_ali x, Rope bsecond) {
    typ_ali res;
    append(res.first, x.first);
    append(res.first, '-', size(bsecond));
	  
    append(res.second, x.second);
    append(res.second, bsecond);
    return res;
  }
  typ_ali Region_Pr_Pr(typ_ali x, Rope bfirst) {
    typ_ali res;
    append(res.first, '-', size(bfirst));
    append(res.first, x.first);
 	  
    append(res.second, bfirst);
    append(res.second, x.second);
    return res;
  }
  typ_ali Region_Pr_PrEnd(typ_ali x, Rope bsecond) {
    typ_ali res;
    append(res.first, x.first);
    append(res.first, '-', size(bsecond));
	  
    append(res.second, x.second);
    append_reverse(res.second, bsecond);
    return res;
  }
  typ_ali Insx(alphabet a, typ_ali x) {
    typ_ali res;
    append(res.first, a);
    append(res.first, x.first);
    append(res.second, '-');
    append(res.second, x.second);
    return res;
  }
  typ_ali Delx(typ_ali x, alphabet b) {
    typ_ali res;
    append(res.first, '-');
    append(res.first, x.first);
    append(res.second, b);
    append(res.second, x.second);
    return res;
  }
}

// an algebra that computes a Trace representation of an Alignment,
// i.e. we arbitraily say that Insertions cannot preceed Deletions (could be vice versa)
algebra alg_editops implements sig_alignments(alphabet=char, answer=Rope) {
  Rope Ins(alphabet a, Rope x) {
    Rope res;
    res = trace_pushback('I', x);
    return res;
  }
  Rope Del(Rope x, alphabet b) {
    Rope res;
    append(res, 'D');
    append(res, x);
    return res;
  }
  Rope Ers(alphabet a, Rope x, alphabet b) {
    Rope res;
    append(res, 'E');
    append(res, x);
    return res;
  }
  Rope Sto(alphabet sep) {
    Rope res;
    append(res, '.');
    return res;
  }
	
  Rope Region(Rope aleft, Rope x) {
    Rope res;
    append(res, '1');
    append(res, x);
    return res;
  }
  Rope RegionEnd(Rope aright, Rope x) {
    Rope res;
    append(res, '1');
    append(res, x);
    return res;
  }
  Rope Region_Pr(Rope aleft, Rope x) {
    Rope res;
    append(res, '2');
    append(res, x);
    return res;
  }  
  Rope Region_PrEnd(Rope x, Rope bright) {
    Rope res;
    append(res, '2');
    append(res, x);
    return res;
  }
  Rope Region_Pr_Pr(Rope x, Rope bleft) {
    Rope res;
    append(res, '3');
    append(res, x);
    return res;
  }
  Rope Region_Pr_PrEnd(Rope x, Rope bright) {
    Rope res;
    append(res, '3');
    append(res, x);
    return res;
  }
	
  // this is slightly different form http://rna.informatik.uni-freiburg.de/Teaching/index.jsp?toolName=Gotoh#
  // as there Ins + Insx is computed for first blank, we here score Ins for first blank and Insx for all following ones
  Rope Insx(alphabet a, Rope x) {
    Rope res;
    append(res, 'i');
    append(res, x);
    return res;
  }
  Rope Delx(Rope x, alphabet b) {
    Rope res;
    append(res, 'd');
    append(res, x);
    return res;
  }

  choice [Rope] h([Rope] candidates) {
    return unique(candidates);
  }
}



// pair-wise global alignment
grammar gra_needlemanwunsch uses sig_alignments(axiom=A) {
  A = Ins(CHAR, A)
    | Del(A, CHAR)
    | Ers(CHAR, A, CHAR)
    | Sto(CHAR('@'))
    # h;
}

/* a grammar that enumerates all traces but not all alignments
   difference:  X-   and  -X   are two different alignments, but the same trace
                -Y        Y-
   this is because there is no evidence that could tell us if deletion came before insertion
   or vice versa.
*/
grammar gra_traces uses sig_alignments(axiom=A) {
  A = Ins(CHAR, I)
    | Del(D, CHAR)
    | R
    # h;

  D = Ins(CHAR, I)
    | Del(D, CHAR)
    | R
    # h;
    
  I = Ins(CHAR, I)
    | R
    # h;

  R = Ers(CHAR, A, CHAR)
    | Sto(CHAR('@'))
    # h;
}

// pair-wise semiglobal alignment, i.e. long in short
grammar gra_semiglobal uses sig_alignments(axiom=S) {
  S = Region(ROPE0, A)
    # h;
	
  A = Ins(CHAR, A)
    | Del(A, CHAR)
    | Ers(CHAR, A, CHAR)
    | RegionEnd(ROPE0, P)
    # h;
	
  P = Sto(CHAR('@'))
    # h;
}

// pair-wise end-gap-free alignment, e.g. for assembly
grammar gra_endgapfree uses sig_alignments(axiom=S) {
  S = Region_Pr(ROPE0, A)
    # h;
	
  A = Ins(CHAR, A)
    | Del(A, CHAR)
    | Ers(CHAR, A, CHAR)
    | Region_PrEnd(P, ROPE0)
    # h;

  P = Sto(CHAR('@'))
    # h;
}

// pair-wise local alignment, e.g. BLAST
grammar gra_smithwaterman uses sig_alignments(axiom=S) {
  S = Region(ROPE0, T)
    # h;

  T = Region_Pr_Pr(A, ROPE0)
    # h;
	
  A = Ins(CHAR, A)
    | Del(A, CHAR)
    | Ers(CHAR, A, CHAR)
    | RegionEnd(ROPE0, R)
    # h;

  R = Region_Pr_PrEnd(P, ROPE0)
    # h;
	
  P = Sto(CHAR('@'))
    # h;
}

// pair-wise global alignment with affine gap costs
grammar gra_gotoh uses sig_alignments(axiom=A) {
  A = Ins(CHAR, xIns)
    | Del(xDel, CHAR)
    | Ers(CHAR, A, CHAR)
    | Sto(CHAR('@'))
    # h;

  xIns = Insx(CHAR, xIns)
       | A
       # h;

  xDel = Delx(xDel, CHAR)
       | A
       # h;
}

instance ins_needlemanwunsch_count = gra_needlemanwunsch(alg_count);
instance ins_semiglobal_count = gra_semiglobal(alg_count);
instance ins_endgapfree_count = gra_endgapfree(alg_count);
instance ins_smithwaterman_count = gra_smithwaterman(alg_count);
instance ins_gotoh_count = gra_gotoh(alg_count);
instance ins_traces_count = gra_traces(alg_count);

instance ins_needlemanwunsch_similaritycount = gra_needlemanwunsch(alg_similarity * alg_count);
instance ins_semiglobal_similaritycount = gra_semiglobal(alg_similarity * alg_count);
instance ins_endgapfree_similaritycount = gra_endgapfree(alg_similarity * alg_count);
instance ins_smithwaterman_similaritycount = gra_smithwaterman(alg_similarity * alg_count);
instance ins_gotoh_similaritycount = gra_gotoh(alg_similarity * alg_count);

instance ins_needlemanwunsch_similaritypp = gra_needlemanwunsch(alg_similarity * alg_pretty);
instance ins_semiglobal_similaritypp = gra_semiglobal(alg_similarity * alg_pretty);
instance ins_endgapfree_similaritypp = gra_endgapfree(alg_similarity * alg_pretty);
instance ins_smithwaterman_similaritypp = gra_smithwaterman(alg_similarity * alg_pretty);
instance ins_gotoh_similaritypp = gra_gotoh(alg_similarity * alg_pretty);

instance test = gra_smithwaterman(alg_pretty * alg_enum);
instance ins_traces_ppcount = gra_traces(alg_pretty * alg_count);

// used in lecture as example of how to compile:
instance ins_gotoh_pp = gra_gotoh(alg_pretty_onegap);
instance ins_gotoh_ppenum = gra_gotoh(alg_pretty_onegap * alg_enum);
instance ins_gotoh_countmanual = gra_gotoh(alg_countmanual);

instance ins_trace_similarity = gra_traces(alg_similarity);
instance ins_needlemanwunsch_similarity = gra_needlemanwunsch(alg_similarity);

instance ins_nweditopscount = gra_needlemanwunsch(alg_editops * alg_count);
