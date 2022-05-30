#ifndef EXT_SATISFIABILITY_HH
#define EXT_SATISFIABILITY_HH

template <typename Iterator>
inline List_Ref<Rope> remove_diverse(std::pair<Iterator, Iterator> i) {
  List_Ref<Rope> answers; // init list, that should hold all selected candidates

  for (Iterator it = i.first; it != i.second; ++it) {
    Rope val = *it;
    if (val != Rope("diverse")) {
      push_back(answers, val);
    }
  }
  return unique(answers);
}

#endif
