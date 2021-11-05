// Jeff Caldwell
// CS 2336
// Lab 32

template <typename T>
void exchangeSort(vector<T>& v) {
  // Use pointers!
  typename vector<T>::pointer i, j, begin, end;
  T temp;


  // Evaluate LCV conditions once!
  begin = v.data();
  end = v.data() + v.size();

  // outer loop = n - 1
  for(i = begin; i < end - 1; i++) {
    // inner loop = n - 1
    for(j = i + 1; j < end; j++) {
      if(*j < *i) {
        // Inline swap!
        temp = *j;
        *j = *i;
        *i = temp;
      }
    }
  }
}