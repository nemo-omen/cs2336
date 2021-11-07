// Jeff Caldwell
// CS 2336
// Lab 33

template <typename T>
void shellSort(vector<T>& v) {
  typename vector<T>::size_type k, n = v.size();
  typename vector<T>::pointer aPtr, bPtr;

  for(k = 1; k <= n/9; k = 3 * k + 1) {}

  while(k > 1) {
    for(uint i = 0; i <= k - 1; i++) {
      vector<T> sublist;
      uint j = 0;

      for(aPtr = v.data () + i; aPtr < v.data() + v.size(); aPtr+= k) {
        sublist.emplace_back(*aPtr);
      }

      insertionSort(sublist);

      for(bPtr = v.data() + i; bPtr < v.data() + v.size(); bPtr+= k, j++) {
        *bPtr = *(sublist.data() + j);
      }
    }
    k /= 3;
  }
  insertionSort(v);
}