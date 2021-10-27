#include <algorithm>
#include <utility>

template<typename T>
pair<T, int> modeUsingIndexing(const vector<T>& v) {
  vector<T> copy(v);                  // O(n)
  sort(copy.begin(), copy.end());     // O(n log n)

  pair<T, int> myMode;
  typename vector<T>::size_type i;

  myMode.first = copy[0];
  myMode.second = 1;
  
  for(i = 0; i < copy.size(); ++i) {  // O(n)

  }

  return myMode;
}

template<typename T>
pair<T, int> modeUsingIterators(const vector<T>& v) {
  vector<T> copy(v);                  // O(n)
  sort(copy.begin(), copy.end());     // O(n log n)

  pair<T, int> myMode;
  typename vector<T>::iterator it;

  myMode.first = *(copy.begin());
  myMode.second = 1;
  
  for(it = copy.begin(); it < copy.end(); ++it) {  // O(n)

  }

  return myMode;
}

template<typename T>
pair<T, int> modeUsingPointers(const vector<T>& v) {
  vector<T> copy(v);                  // O(n)
  sort(copy.begin(), copy.end());     // O(n log n)

  pair<T, int> myMode;
  typename vector<T>::pointer ptr;

  myMode.first = *(copy.data());
  myMode.second = 1;
  
  for(ptr = copy.data(); ptr < copy.data() + copy.size(); ++ptr) {  // O(n)

  }

  return myMode;
}