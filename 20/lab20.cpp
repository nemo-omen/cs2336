// Jeff Caldwell
// CS 2336
// Lab 20

template<typename T>
void mySwap(T& first, T& second) {
  T temp;

  temp = first;
  first = second;
  second = temp;
}

// replace the __outer loop__ with the recursive version
// depth of recursion for this fn is `n - 1`
// though this function runs through the array n times
// each time moving the largest element to the end of the array
template<typename T>
void bubbleSort(T *array, int n) {
  if(n <= 1) {
    return;
  } else {
    for(int i = 0; i < (n - 1); ++i) {
      if(array[i] > array[i + 1]) {
        mySwap(array[i], array[i + 1]);
      }
    }
    bubbleSort(array, n - 1);
  }
}
