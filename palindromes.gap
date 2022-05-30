import "ext_palindrome.hh"

type Rope = extern

signature sig_palindrome(alphabet, answer) {
  answer match(alphabet, answer, alphabet);
  answer cadd(alphabet, answer);
  answer end(void);
  answer skipl(alphabet, answer);
  answer skipr(answer, alphabet);
  choice [answer] h([answer]);
}

algebra alg_enum auto enum;
algebra alg_count auto count;

algebra alg_pretty implements sig_palindrome(alphabet = char, answer = Rope) {
  Rope match(alphabet a, Rope x, alphabet b) {
    Rope res;
    append(res, a);
    append(res, x);
    append(res, b);
    return res;
  }
  Rope cadd(alphabet a, Rope l) {
    Rope res;
    append(res, '_');
    append(res, l);
    return res;
  }
  Rope end(void) {
    Rope res;
    return res;
  }
  Rope skipl(alphabet a, Rope x) {
    Rope res;
    append(res, '>');
    append(res, x);
    return res;
  }
  Rope skipr(Rope x, alphabet b) {
    Rope res;
    append(res, x);
    append(res, '<');
    return res;
  }
  choice [Rope] h([Rope] candList) {
    return candList;
  }
}

algebra alg_palScore implements sig_palindrome(alphabet = char, answer = int) {
  int match(alphabet a, int x, alphabet b) {
    return x + 1;
  }
  int cadd(alphabet a, int l) {
    return l;
  }
  int end(void) {
    return 0;
  }
  int skipl(alphabet a, int x) {
    return x;
  }
  int skipr(int x, alphabet b) {
    return x;
  }
  choice [int] h([int] candList) {
    return list(maximum(candList));
  }
}

grammar gra_palindrome uses sig_palindrome(axiom = palin) {
  palin = match(CHAR, palin, CHAR) with samechar
        | loop
        # h;

  loop = cadd(CHAR, loop)
       | end(EMPTY)
       # h;
}

grammar gra_palloc uses sig_palindrome(axiom = skip_l) {
  skip_l = skipl(CHAR, skip_l)
         | skip_r
         # h;

  skip_r = skipr(skip_r, CHAR)
         | palin
         # h;

  palin = match(CHAR, palin, CHAR) with samechar
        | loop
        # h;

  loop = cadd(CHAR, loop)
       | end(EMPTY)
       # h;
}


instance enum = gra_palindrome(alg_enum);
instance loc = gra_palloc(alg_palScore * alg_pretty);

instance palin_pp = gra_palindrome(alg_pretty);
instance palloc_pp = gra_palloc(alg_pretty);
instance palin_count = gra_palindrome(alg_count);
instance palloc_count = gra_palloc(alg_count);
instance palin_scorecount = gra_palindrome(alg_palScore * alg_count);
instance palloc_scorecount = gra_palloc(alg_palScore * alg_count);
