#include <algorithm>
#include <utility>

template<typename T>
pair<T, int> modeUsingIndexing(const vector<T>& v) {
  vector<T> copy(v);                  // O(n)
  sort(copy.begin(), copy.end());     // O(n log n)

  pair<T, int> myMode;
  T tempMode;
  int tempCount = 1;
  typename vector<T>::size_type i;

  myMode.first = copy[0];
  myMode.second = 1;

  tempMode = copy[0];

  for(i = 1; i < copy.size(); ++i) {  // O(n)
    if(copy[i] == tempMode) {
      ++tempCount;
    } else {
      tempCount = 1;
      tempMode = copy[i];
    }

    if(tempCount > myMode.second) {
      myMode.second = tempCount;
      myMode.first = tempMode;
    }

  }

  return myMode;
}

template<typename T>
pair<T, int> modeUsingIterators(const vector<T>& v) {
  vector<T> copy(v);                  // O(n)
  sort(copy.begin(), copy.end());     // O(n log n)

  pair<T, int> myMode;
  T tempMode;
  int tempCount = 1;
  typename vector<T>::iterator it;

  myMode.first = copy[0];
  myMode.second = 1;

  tempMode = copy[0];
  
  for(it = copy.begin() + 1; it < copy.end(); ++it) {  // O(n)
    if(*it == tempMode) {
      ++tempCount;
    } else {
      tempCount = 1;
      tempMode = *it;
    }

    if(tempCount > myMode.second) {
      myMode.second = tempCount;
      myMode.first = tempMode;
    }
  }

  return myMode;
}

template<typename T>
pair<T, int> modeUsingPointers(const vector<T>& v) {
  vector<T> copy(v);                  // O(n)
  sort(copy.begin(), copy.end());     // O(n log n)

  pair<T, int> myMode;
  T tempMode;
  int tempCount = 1;
  typename vector<T>::pointer ptr;

  myMode.first = copy[0];
  myMode.second = 1;

  tempMode = copy[0];
  
  for(ptr = copy.data() + 1; ptr < copy.data() + copy.size(); ++ptr) {  // O(n)
    if(*ptr == tempMode) {
      ++tempCount;
    } else {
      tempCount = 1;
      tempMode = *ptr;
    }

    if(tempCount > myMode.second) {
      myMode.second = tempCount;
      myMode.first = tempMode;
    }
  }

  return myMode;
}