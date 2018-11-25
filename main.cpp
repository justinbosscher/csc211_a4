#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "dna.h"
#include "sort.h"
#include "swap.h"
using namespace std;


int main() {
//cout<<"hello"<<endl;
  //DNA Test objects
  DNA test1 = DNA(">a", "G");
  DNA test2 = DNA(">f", "T");
  DNA test3 = DNA(">c", "A");
  DNA test4 = DNA(">r", "C");

  // Place DNA Test Objects in vector, testV
  vector <DNA> v = {test1, test2, test3, test4};

  // 2 sort method tests, one for each bool comparator function
  sort(v, &headerLessThan);
  for(int i = 0; i < (int)v.size(); i++) {
      cout << "header: " << v[i].getHeader() << endl;
  }
 /* sort(v, &headerLessThan);
  for(int i = 0; i < (int)v.size(); i++) {
    cout << "header: " << v[i].getHeader()<< endl;
}*/
  return 0;
}
