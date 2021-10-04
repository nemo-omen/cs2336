// Jeff Caldwell
// CS 2336
// Lab 21

template <typename T>
// n = size of array
const T *linearSearch(const T *array, int n, T itemToFind) {
  if(n == 0) return nullptr;

  if(*array == itemToFind) {
    return array;
  } else {
    return linearSearch(array + 1, n - 1, itemToFind);
  }
}