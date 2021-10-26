// Jeff Caldwell
// CS 2336
// Lab 26

#include <vector>
#include <math.h>

using namespace std;

int meanUsingIndexing(const vector<int>& v) {
  vector<int>::size_type i, end = v.size();
  double total = 0.0;

  for(i = 0; i < end; ++i) {
    total += v[i];
  }

  return (int)(round(total / v.size()));
}

int meanUsingIterators(const vector<int>& v) {
  vector<int>::const_iterator it, end = v.cend();
  double total = 0.0;

  for(it = v.cbegin(); it < end; ++it) {
    total += *it;
  }

  return (int)(round(total / v.size()));
}

int meanUsingPointers(const vector<int>& v) {
  vector<int>::const_pointer ptr, end = v.data() + v.size();
  double total = 0.0;

  for(ptr = v.data(); ptr < end; ++ptr) {
    total += *ptr;
  }

  return (int)(round(total / v.size()));
}