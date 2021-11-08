// Jeff Caldwell
// CS 2336
// Lab 34

template<typename T>
void miniVector<T>::insert(int i, const T& item) {
  // Step 0: check preconditions
  if(empty() && i != 0)
    throw underflowError("miniVector insert(): vector is empty");

  if(i < 0 || i > size())
    throw indexRangeError("miniVector insert(): index range error", i, this->size());

  // insert steps
  // 1. push_back(item)
  // 2. move elements to make space for item at required idx
  // 3. place item at index i
  this->push_back(item);

  for(int j = size() - 2; j > i; j--) {
    vArr[j + 1] = vArr[j];
  }

  vArr[i] = item;
}

template<typename T>
void miniVector<T>::erase(int i) {
  if(empty() && i != 0)
    throw underflowError("miniVector insert(): vector is empty");

  if(i < 0 || i > size())
    throw indexRangeError("miniVector insert(): index range error", i, this->size());

  for(int j = i + 1; j < size(); j++) {
    vArr[j - 1] = vArr[j];
  }
  pop_back();
}