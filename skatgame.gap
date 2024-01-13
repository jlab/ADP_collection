type Rope = extern

signature sig_skat(alphabet, answer) {
  answer card(alphabet, Rope);
  answer skat(answer, answer);
  answer trick(answer, answer, answer);
  answer hand(answer, answer, answer, answer, answer, answer, answer, answer, answer, answer, answer);
  choice [answer] h([answer]);
}

algebra alg_enum auto enum;
algebra alg_count auto count;
algebra alg_tikz auto tikz;

algebra alg_pretty implements sig_skat(alphabet=char, answer=Rope) {
  Rope card(char suit, Rope face) {
    Rope res;
    if (face == Rope("A")) {
       append(res, "ace", 3);
    }
    if (face == Rope("K")) {
       append(res, "king", 4);
    }
    if (face == Rope("Q")) {
       append(res, "queen", 5);
    }
    if (face == Rope("J")) {
       append(res, "jack", 4);
    }
    if (face == Rope("10") || face == Rope("9") || face == Rope("8") || face == Rope("7")) {
       append(res, face);
    }
    append(res, " of ", 4);
    if (suit == char('c')) {
      append(res, "clubs", 5);
    }
    if (suit == char('s')) {
      append(res, "spades", 6);
    }
    if (suit == char('h')) {
      append(res, "hearts", 6);
    }
    if (suit == char('d')) {
      append(res, "diamonds", 8);
    }
    return res;
  }
  Rope skat(Rope a, Rope b) {
    Rope res;
    append(res, a);
    append(res, " & ", 3);
    append(res, b);
    append(res, "\n", 1);
    return res;
  }
  Rope trick(Rope a, Rope b, Rope c) {
    Rope res;
    append(res, a);
    append(res, " & ", 3);
    append(res, b);
    append(res, " & ", 3);
    append(res, c);
    append(res, "\n", 1);
    return res;
  }
  Rope hand(Rope skat, Rope t1, Rope t2, Rope t3, Rope t4, Rope t5, Rope t6, Rope t7, Rope t8, Rope t9, Rope t10) {
    Rope res;
    append(res, "skat:\n  ", 8);
    append(res, skat);
    append(res, "tricks:\n", 8);
    append(res, "   1: ", 6);
    append(res, t1);
    append(res, "   2: ", 6);
    append(res, t2);
    append(res, "   3: ", 6);
    append(res, t3);
    append(res, "   4: ", 6);
    append(res, t4);
    append(res, "   5: ", 6);
    append(res, t5);
    append(res, "   6: ", 6);
    append(res, t6);
    append(res, "   7: ", 6);
    append(res, t7);
    append(res, "   8: ", 6);
    append(res, t8);
    append(res, "   9: ", 6);
    append(res, t9);
    append(res, "  10: ", 6);
    append(res, t10);
    return res;
  }
  choice [Rope] h([Rope] candidates) {
    return candidates;
  }
}

grammar gra_skat uses sig_skat(axiom=Deal) {
  Card = card(Suit, Face) # h;
  
  Suit = CHAR('c') // clubs = Kreutz
       | CHAR('s') // spades = Pik
       | CHAR('h') // hearts = Herz
       | CHAR('d') // diamonds = Karo
       ; // note the missing application of h

  Face = ROPE("A") // ace = Ass
       | ROPE("K") // king = Koenig
       | ROPE("Q") // queen = Dame
       | ROPE("J") // jack = Bube
       | ROPE("10")
       | ROPE("9")
       | ROPE("8")
       | ROPE("7")
       ; // note the missing application of h
	
  Skat = skat(Card, Card) 
       # h;

  Trick = trick(Card, Card, Card)
        # h;
  
  Deal = hand(Skat, Trick, Trick, Trick, Trick, Trick, Trick, Trick, Trick, Trick, Trick)
       # h;
}

/*
Unfortunately, we cannot use Unicode characters for suits, thus we need to encode
those as single characters. An example input string would look like:
*/
/*
example inputs: d10s7dJsJh8dAdQd7c7cAhAhJd8hQh7s8cJh10c8sKhKs9c9dKsQs10d9cQcKh9c10sA
*/

instance pp = gra_skat(alg_pretty);
instance count = gra_skat(alg_count);

