import "ext_satisfiability.hh"

type Rope = extern

signature sig_sat(alphabet, answer) {
  answer addliteral(answer, answer);
  answer addclause(answer, alphabet, answer);
  answer emptyformula(void);
  answer emptyclause(void);
  answer assigntrue(alphabet);
  answer assignfalse(alphabet);
  choice [answer] h([answer]);
}

algebra alg_count auto count;
algebra alg_enum auto enum;
algebra alg_tikz auto tikz;

/* 
This algebra removes all candidates from the search space that do not
satisfy the SAT formula. The formula is satisfied if all clauses are
satisfied. A clause is satisfied if there is at least one assigntrue
with a positive literal or a assignfalse with a negative literal.  It
does not assure that the assigned byte vectors for all clauses are
equal. To assure this too, use the product algebra (alg_sat * alg_eqa) but
not (alg_eqa * alg_sat) due to slightly different definition of * in
Bellman's GAP, compared to Haskell ADP
*/
/*
Unfortunately, we cannot use data type bool, since this would result
in a conflict in the generated code between testing for is_empty of
a candidate and assigning the value "false". 
*/
algebra alg_sat implements sig_sat(alphabet=char, answer=int) {
  int addliteral(int l, int c) {
    if ((l > 0) || (c > 0)) {
      return 1;
    } else {
      return 0;
    }
  }
  int addclause(int c, char x, int f) {
    if ((c > 0) && (f > 0)) {
      return 1;
    } else {
      return 0;
    }
  }
  int emptyformula(void) {
    return 1;
  }
  int emptyclause(void) {
    return 0;
  }
  int assigntrue(char t) {
    // assigning a missing literal '-' results in false 
    if (t == 'P') {
      return 1;
    } else {
      return 0;
    }
  }
  int assignfalse(char f) {
    // assigning a missing literal '-' results in false
    if (f == 'N') {
      return 1;
    } else {
      return 0;
    }
  }
  scoring choice [int] h([int] candidates) {
    // We are kind of abusing "maximum" here, as we are
    // not looking for the max value, but only intend to
    // remove all 0 = false candidates.
    return list(maximum(candidates));
  }
}

/* 
assures that the assignments are equal for all clauses. This algebra
only assures that the assigned byte vectors for all clauses are equal
completely independent of the satisfyability of the formula.
*/
algebra alg_eqa implements sig_sat(alphabet=char, answer=Rope) {
  Rope addliteral(Rope l, Rope c) {
    Rope res;
    append(res, l);
    append(res, c);
    return res;
  }
  Rope addclause(Rope c, char x, Rope f) {
    if (c != f) {
      Rope d;
      append(d, "diverse", 7);
      return d;
    } else {
      return c;
    }
  }
  Rope emptyformula(void) {
    Rope res;
    return res;	  
  }
  Rope emptyclause(void) {
    Rope res;
    return res;	  
  }
  Rope assigntrue(char t) {
    Rope res;
    append(res, "T");
    return res;	  
  }
  Rope assignfalse(char f) {
    Rope res;
    append(res, "F");
    return res;	  
  }
  kscoring choice [Rope] h([Rope] candidates) {
    return remove_diverse(candidates);
  }
}

algebra alg_pretty implements sig_sat(alphabet=char, answer=Rope) {
  Rope addliteral(Rope l, Rope c) {
    Rope res;
    append(res, l);
    append(res, c);
    return res;
  }
  Rope addclause(Rope c, char x, Rope f) {
    Rope res;
    append(res, c);
    append(res, x);
    append(res, f);
    return res;
  }
  Rope emptyformula(void) {
    Rope res;
    return res;
  }
  Rope emptyclause(void) {
    Rope res;
    return res;
  }
  Rope assigntrue(char t) {
    Rope res;
    append(res, '1');
    return res;
  }
  Rope assignfalse(char f) {
    Rope res;
    append(res, '0');
    return res;
  }
  choice [Rope] h([Rope] candidates) {
    return candidates;
  }
}

grammar gra_sat uses sig_sat(axiom=selection) {
  selection = formula 
	    # h; // make choice once all candidates are evaluated
	
  formula = addliteral(literal, clause)
	  | addclause(clause, CHAR('&'), formula)
	  | emptyformula(EMPTY)
	  ; // no choice, since Bellman's principle is violated

  clause = addliteral(literal, clause)
	 | emptyclause(EMPTY)
	 ; // no choice, since Bellman's principle is violated

  literal = assigntrue(lit)
	  | assignfalse(lit)
	  ; // no choice, since Bellman's principle is violated

  lit = CHAR('P')
      | CHAR('N')
      | CHAR('-')
      ; // no choice, since Bellman's principle is violated
}

/*
example inputs: PP-&-NP
*/

instance ins_enum = gra_sat(alg_enum);
instance ins_pp = gra_sat(alg_pretty);

instance ins_sateqapp = gra_sat(alg_sat * alg_eqa * alg_pretty);

