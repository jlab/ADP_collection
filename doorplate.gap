type Rope = extern

signature sig_doorplate(alphabet, answer) {
  answer root(answer);
  answer floor(Rope, answer, Rope, answer);
  answer nil(void);
  answer office(Rope, answer, answer, Rope, answer);
  answer officeid(Rope, Rope, Rope);
  answer person(Rope, Rope, Rope, answer);
  choice [answer] h([answer]);
}

algebra alg_enum auto enum;
algebra alg_count auto count;
algebra alg_tikz auto tikz;

algebra alg_pretty implements sig_doorplate(alphabet=char, answer=Rope) {
  Rope root(Rope x) {
    Rope res;
    append(res, "==== candidate starts ====\n", 27);
    append(res, x);
    append(res, "==========================\n", 27);
    return res;
  }
  Rope floor(Rope tagopen, Rope x_offices, Rope tagclose, Rope x) {
    Rope res;
    append(res, "floor:\n", 7);
    append(res, x_offices);
    append(res, x);
    return res;
  }
  Rope nil(void) {
    Rope res;
    return res;
  }
  Rope office(Rope tagopen, Rope value_id, Rope x_persons, Rope tagclose, Rope x) {
    Rope res;
    append(res, value_id);
    append(res, x_persons);
    append(res, "\n", 1);
    append(res, x);
    return res;
  }
  Rope officeid(Rope tagopen, Rope value, Rope tagclose) {
    Rope res;
    append(res, "  room-id: '", 12);
    append(res, value);
    append(res, "'\n", 2);
    return res;
  }
  Rope person(Rope tagopen, Rope value, Rope tagclose, Rope x) {
    Rope res;
    append(res, "    person: '", 13);
    append(res, value);
    if (x != "") {
      append(res, "'\n", 2);
      append(res, x);
    }
    return res;
  }
  choice [Rope] h([Rope] candidates) {
    return candidates;
  }
}

grammar gra_doorplate uses sig_doorplate(axiom=start) {
  start = root(floors)
	# h;

  floors = floor(ROPE("<floor>"), offices, ROPE("</floor>"), floors)
         | nil(EMPTY)
         # h;
	
  offices = office(ROPE("<office>"), id, persons, ROPE("</office>"), offices)
	  | nil(EMPTY)
	  # h;

  id = officeid(ROPE("<id>"), ROPE, ROPE("</id>"))
     # h;
	
  persons = person(ROPE("<person>"), ROPE, ROPE("</person>"), persons)
	  | nil(EMPTY)
	  # h;
}

instance test = gra_doorplate(alg_enum);
instance pp = gra_doorplate(alg_pretty);
instance count = gra_doorplate(alg_count);

// example input:
// "<floor><office><id>M3-114</id><person>Stefan</person></office><office><id>M3-107</id><person>Maddis</person><person>Jan</person></office></floor>"

// note that there are multiple parse tree possible, because e.g. 
// algebra function "person" need to start with "<person>" and end with "</person>".
// A valid parse is "<person>Maddis</person>". However, also valid is "<person>Maddis</person><person>Jan</person>".
