// Jeff Caldwell
// CS 2336
// Lab 22

template<typename T>
const T *binarySearch(const T *first, const T *last, T itemToFind) {
  const T *middle;

  if (first > last) 
    return nullptr; // base case 1

  // find the middle
  // (distance between ptrs) / (2 elements) = int
  // add to *first to make sure it's a ptr
  middle = (first + (last - first) / 2);

  // base case 2
  if(*middle == itemToFind) {
    return middle;
  }

  if(*middle < itemToFind) {
  // recursive case 1
    return binarySearch(middle + 1, last, itemToFind);
  } else {
  // recursive case 2
    return binarySearch(first, middle - 1, itemToFind);
  }
}