#include "dna.h"
#include "swap.h"
#include <vector>


/* seqLenLessThan function sorts headers by character length */
bool seqLenLessThan(DNA& item1, DNA& item2) {
	if(item1.getSequence().length() < item2.getSequence().length()) {
		return true;
	}else{
		return false;
	} // end if
} // end seqLenLessThan


/* headerLessThan function lexicographically sorts headers */
bool headerLessThan(DNA& item1, DNA& item2) {
	if(item1.getHeader() < item2.getHeader()) {
		return true;
	}else{
		return false;
	} // end if
} // end headerLessThan


/* partition function calling comparator and swap functions in while loops */
int partition(std::vector<DNA>& v, bool comparator(DNA&, DNA&), int start, int finish) {
	/* Set DNA object named pivot to first element in vector */
	DNA pivot = v[start];
  	int i = start + 1;
	int j = finish;

	/* infinite while loop calling comparator functions, incrementing i and
	*  decrementing j; calling swap function to sort */
	while(true) {
		while((i < j) && (!comparator(v[j], pivot))) j--;
		while((i < j) && (comparator(v[i], pivot))) i++;
		if(i == j) break;
		swap(v, i, j);
	} // end while true

	/* if v[i] >= to pivot, swap v[start] and pivot */
	if(!comparator(v[i], pivot)) return start;
	v[start] = v[i];
	v[i] = pivot;
	return i;
} // end partition method


/* quicksort calls partition, & recursively calls itself twice, changing start & finish*/
void quicksort(std::vector<DNA>& v, bool comparator(DNA&, DNA&), int start, int finish) {

	int i = start;
	int j = finish;

	if(i >= j) return;
		int part = partition(v, comparator, i, j);
			quicksort(v, comparator, i, (part - 1));
			quicksort(v, comparator, (part + 1), j);
} // end quicksort


/* sort function calls quicksort */
std::vector<DNA> sort(std::vector<DNA> v, bool comparator(DNA&, DNA&)) {
	std::vector<DNA> vcopy = v;
	quicksort(vcopy, comparator, 0, vcopy.size() - 1);
	return vcopy;
} // end sorth
