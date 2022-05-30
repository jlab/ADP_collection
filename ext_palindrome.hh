#ifndef EXT_PALINDROME_HH
#define EXT_PALINDROME_HH

inline bool samechar(Basic_Sequence<char> seq, unsigned int t_0_i, unsigned int t_0_j) {
  return seq[t_0_i] == seq[t_0_j - 1];
}

#endif
