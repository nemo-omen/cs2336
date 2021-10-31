// Jeff Caldwell
// CS 2336
// Lab 29

#include <algorithm>

template<typename T>
bool nextPermutation(vector<T>& v) {
  typename vector<T>::size_type i, j, k, l;

  // if our vector is only one element
  // there is no permutation
  if(v.size() <= 1) return false;

  // first loop - we're comparing the next-to-last
  // element to the last element and looping back
  // from there
  for(k = v.size() - 2; k >= 0; k--) {
    if(v[k] < v[k + 1]) {
      // once we find an element with a lower value
      // than its rightmost neighbor, assign its value
      // to i and break out of the loop
      i = k;
      break;
    }
  }

  // second loop - we're now comparing the last
  // element to i and working backward
  for(l = v.size() - 1; l > i; l--) {
    if(v[l] > v[i]) {
      // we've found an element that's larger than
      // i, so we assign it to j
      j = l;

      // flip it and reverse it
      swap(v[i], v[j]);
      reverse(v.begin() + i + 1, v.end());

      // we have a permutation!
      return true;
    }
  }

  // if we've reached this point it means that
  // no element is smaller than its rightmost neighbor
  // so we reverse the whole vector
  reverse(v.begin(), v.end());

  // and return false
  return false;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  vector<T> copy(v);

  typename vector<T>::size_type i;

  for(i = 0; i < copy.size(); ++i) {
    os << copy[i];
  }
  
  return os;
}