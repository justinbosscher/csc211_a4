#ifndef _swap_h
#define _swap_h

#include <vector>

/*
Takes a std::vector, and two indices. Can take any vector b/c of the syntax
"template" and "<typename T>"
Swaps the elements of the vector at those two indices.
*/
template <typename T> void swap(std::vector<T> &v, size_t i, size_t j) {
	T t = v[i];
	v[i] = v[j];
	v[j] = t;
} // end swap method template


#endif
