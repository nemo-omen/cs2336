// Jeff Caldwell
// CS 2336
// Lab 29

#include <algorithm>

template<typename T>
bool nextPermutation(vector<T>& v) {                  
  typename vector<T>::size_type i;
  typename vector<T>::size_type j;
  
  for(i = v.size() - 1; i >= 1; --i) {
    if(i <= v.size() && v[i] < v[i + 1]) {
      // cout << "step" << i << ": " << "i->" << v[i] << " ";
      for(j = v.size(); j > i; j--) {
        if(v[j] > v[i]) {
          // cout << "j->" << v[j] << " ";
          swap(v[j], v[i]);
          reverse(v.begin() + 1, v.end());
          cout << "v: " << v << '\n';
        }
      }
    // return true;
    } else {
    return false;
    }
  }
  cout << '\n';
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