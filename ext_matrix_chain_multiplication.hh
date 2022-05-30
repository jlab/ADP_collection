#ifndef EXT_MATRIX_CHAIN_MULTIPLICATION_HH
#define EXT_MATRIX_CHAIN_MULTIPLICATION_HH

// let only candidates pass whose number of colums for the left matrix are equal the number of rows in the right matrix
// otherwise, matrix multiplication cannot be executed
// this is only a semantic test, since we do NOT compute the actual matrix multiplication
inline bool assertMatchingDimension(typ_matrix left, char star, typ_matrix right) {
  return left.cols == right.rows;
}

// same as above for algebra products where alg_minmult is left
template<typename A>
inline bool assertMatchingDimension(std::pair<typ_matrix, A> left, char star, std::pair<typ_matrix, A> right) {
  return assertMatchingDimension(left.first, star, right.first);
}

// same as above for algebra products where alg_minmult is right
template<typename A>
inline bool assertMatchingDimension(std::pair<A, typ_matrix> left, char star, std::pair<A, typ_matrix> right) {
  return assertMatchingDimension(left.second, star, right.second);
}

#endif
