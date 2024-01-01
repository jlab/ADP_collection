import "ext_matrix_chain_multiplication.hh"

// make sure first element of this tuple is the one we want to base our choice function off.
type typ_matrix = (int num_operations, int rows, int cols)
type Rope = extern

signature sig_matmult(alphabet, answer) {
  answer single(alphabet, int, alphabet, int, alphabet);
  answer mult(answer, alphabet, answer);
  choice [answer] h([answer]);
}

algebra alg_enum auto enum;
algebra alg_count auto count;
algebra alg_tikz auto tikz;

algebra alg_minmult implements sig_matmult(alphabet=char, answer=typ_matrix) {
  typ_matrix single(char openBracket, int rows, char cross, int cols, char closeBracket) {
    typ_matrix res;
    res.rows = rows;
    res.cols = cols;
    // just creating a single matrix without any multiplications, therefore no operations yet:
    res.num_operations = 0;
    return res;
  }
  typ_matrix mult(typ_matrix left, char star, typ_matrix right) {
    typ_matrix res;
    res.rows = left.rows;
    res.cols = right.cols;
    // add number of operations for current multiplication
    // (since left.cols == right.rows must hold, we could replace left.cols with right.rows)
    res.num_operations = left.rows * left.cols * right.cols;
    // don't forget number of operations from previous multiplications:
    res.num_operations = res.num_operations + left.num_operations + right.num_operations;
    return res;
  }
  choice [typ_matrix] h([typ_matrix] candidates) {
    // tricky: we are chosing the minimum here on a data type with three fields. Why does this work?
    // because a) rows and cols must always have the same values, since this is the dimension of the
    // matrix multiplication result (note: we here only care for the order of multiplications, not
    // the result itself)
    // b) the "minimum" function is implemented such that it operates on the first field of a tuple
    return list(minimum(candidates));
  }
}

algebra alg_pretty implements sig_matmult(alphabet=char, answer=Rope) {
  Rope single(char openBracket, int rows, char cross, int cols, char closeBracket) {
    Rope res;
    append(res, '[');
    append(res, rows);
    // we are here replacing the x char from the input with , for educational purposes
    append(res, ',');
    append(res, cols);
    append(res, ']');
    return res;
  }
  Rope mult(Rope left, char star, Rope right) {
    Rope res;
    append(res, '(');
    append(res, left);
    append(res, '*');
    append(res, right);
    append(res, ')');
    return res;
  }
  choice [Rope] h([Rope] candidates) {
    return candidates;
  }
}

algebra alg_depth implements sig_matmult(alphabet=char, answer=int) {
  int single(char openBracket, int rows, char cross, int cols, char closeBracket) {
    return 0;
  }
  int mult(int left, char star, int right) {
    if (left > right) {
      return left + 1;
    } else {
      return right + 1;
    }
  }
  choice [int] h([int] candidates) {
    return candidates;
  }
}

algebra alg_kdepth extends alg_depth {
  choice [int] h([int] candidates) {
    return unique(candidates);
  }
}


grammar gra_matmult uses sig_matmult(axiom = formula) {
  // note: right now, we "accept" impossible matrix chains,
  //       i.e. left.cols is not enforced to be right.rows
  formula = single(CHAR('('), INT, CHAR('x'), INT, CHAR(')'))
          | mult(formula, CHAR('*'), formula)
	  # h;
}

grammar gra_matmult_assert uses sig_matmult(axiom = formula) {
  // take care when applying the assertMatchingDimensions:
  // 1) instance must contain alg_minmult
  // 2) parenthesis become important in algebra products: alg_minmult * alg_enum * alg_count implicitly is
  //    (alg_minmult * alg_enum) * alg_count, which will fail to compile
  //    use explicit parenthesis like: alg_minmult * (alg_enum * alg_count)
  formula = single(CHAR('('), INT, CHAR('x'), INT, CHAR(')'))
          | mult(formula, CHAR('*'), formula) suchthat_overlay assertMatchingDimension
	  # h;
}

/*
example inputs: (2x10)*(10x50)*(50x10)*(10x1)*(1x20)*(20x20)
*/

instance minmult = gra_matmult(alg_minmult);
instance ppminmult = gra_matmult(alg_pretty * alg_minmult);
instance depthminmultpp = gra_matmult(alg_depth * alg_minmult * alg_pretty);
instance minmultdepthpp = gra_matmult(alg_minmult * alg_depth * alg_pretty);
instance kdepthminmultpp = gra_matmult(alg_kdepth * alg_minmult * alg_pretty);

instance reject_wrong_candidates = gra_matmult_assert(alg_minmult);
instance assert_minmultenum = gra_matmult_assert(alg_minmult * alg_enum);
instance assert_minmultenumcount = gra_matmult_assert(alg_minmult * (alg_enum * alg_count));
