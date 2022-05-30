#ifndef EXT_ALIGNMENT_HH
#define EXT_ALIGNMENT_HH

inline uint32_t hashable_value(const typ_ali& candidate) {
  Rope concat;
  append(concat, candidate.first);
  append(concat, candidate.second);
  return hashable_value(concat);
}

inline bool operator==(const typ_ali& a, const typ_ali& b) {
	return (a.first == b.first) && (a.second == b.second);
}

// a function that realizes the Trace representation of an alignment,
// i.e. Ins, Ins, Del becomes Del, Ins, Ins
// We assume that Del is abbreviated as 'D' and Ins as 'I' in the calling algebra
template<typename X>
inline Rope trace_pushback(char a, const rope::Ref<X> &x) {
	rope::Ref<X> &constx = const_cast<rope::Ref<X>&>(x);
	typename rope::Ref<X>::iterator it = constx.begin();
	
	Rope res;
	if (a == 'I') {
		unsigned int i = 0;
		for (i = 0; i < x.size(); ++i) {
			if (((char) *it) == 'D') {
				append(res, (char) *it);
				++it;
			} else {
				break;
			}
		}
		append(res, a);
		for (unsigned int j = i+1; j <= x.size(); ++j) {
			append(res, (char) *it);
			++it;
		}
	} else {
		append(res, a);
		append(res, x);
	}
	return res;
}
#endif
