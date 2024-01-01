type typ_access = (float mean, float yield)
type Rope = extern

signature sig_bst(alphabet, answer) {
  answer branch(answer, answer, answer);
  answer leaf(answer);
  answer nil(void);
  answer keypair(int, alphabet, float, alphabet);
  choice [answer] h([answer]);
}

algebra alg_enum auto enum;
algebra alg_count auto count;
algebra alg_tikz auto tikz;

// It is not trivial to see why this computation works.
// You should first draw out an example tree and compute the mean access time by hand.
// The idea is, that you need to know the "depth" of an element within the tree.
// You can than compute the mean access time as the sum of key probabilities * key depth
// In ADP, you construct the trees buttom up, i.e. you don't know the depth!!
// The trick is, that whenever you go one level up, you repreat addition of the "yield"
// seen so far to the regular mean access time from left and right components plus the new key
// AND you need to update the yield. Thus, we need a tuple as answer type.
algebra alg_mean_access_time implements sig_bst(alphabet=char, answer=typ_access) {
  typ_access branch(typ_access left, typ_access entry, typ_access right) {
    typ_access res;
    res.mean = left.mean + right.mean + left.yield + right.yield + entry.mean;
    res.yield = left.yield + right.yield + entry.yield;
    return res;
  }
  typ_access leaf(typ_access entry) {
    return entry;
  }
  typ_access nil(void) {
    typ_access res;
    res.mean = 0.0;
    res.yield = 0.0;
    return res;
  }
  typ_access keypair(int key, alphabet sep, float access_probability, alphabet delimiter) {
    typ_access res;
    res.mean = access_probability;
    res.yield = access_probability;
    return res;
  }
  choice [typ_access] h([typ_access] candidates) {
    return list(minimum(candidates));
  }
}

// note that branch(nil, X, nil) and leaf(X) both collapse to the
// pretty print: "(X)", i.e. they are semantically ambiguous!
algebra alg_pretty implements sig_bst(alphabet=char, answer=Rope) {
  Rope branch(Rope left, Rope x, Rope right) {
    Rope res;
    append(res, '(');
    if (left != "") {
    	append(res, left);
    	append(res, ' ');
    }
    append(res, x);
    if (right != "") {
    	append(res, ' ');
    	append(res, right);
    }
    append(res, ')');
    return res;
  }
  Rope leaf(Rope x) {
    Rope res;
    append(res, '(');
    append(res, x);
    append(res, ')');
    return res;
  }
  Rope nil(void) {
    Rope res;
    return res;
  }
  Rope keypair(int key, char sep, float access_probability, char delimiter) {
    Rope res;
    append(res, key);
    return res;
  }
  choice [Rope] h([Rope] candidates) {
    return unique(candidates);
  }
}

grammar gra_bst uses sig_bst(axiom = bstree) {
  bstree = branch(bstree, entry, bstree)
	 | leaf(entry)
	 | nil(EMPTY)
	 # h;
	
  entry = keypair(INT, CHAR(':'), FLOAT, CHAR(',')) # h;
}

instance enum = gra_bst(alg_enum);
instance count = gra_bst(alg_count);
instance matpp = gra_bst(alg_mean_access_time * alg_pretty);
instance ppmat = gra_bst(alg_pretty * alg_mean_access_time);
instance ppcount = gra_bst(alg_pretty * alg_count);
instance matppcount = gra_bst(alg_mean_access_time * alg_pretty * alg_count);

/* example input (note the trailing , at the end of each input!)
   "1:0.22,3:0.18,4:0.2,8:0.05,10:0.25,11:0.02,15:0.08,"

   corresponds to the following table:
   key	prob
   1	0.22
   3	0.18
   4	0.2
   8	0.05
   10	0.25
   11	0.02
   15	0.08
*/
