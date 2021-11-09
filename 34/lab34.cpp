// Jeff Caldwell
// CS 2336
// Lab 34

template<typename T>
void miniVector<T>::insert(int i, const T& item) {
  if(empty() && i != 0)
    throw underflowError("miniVector insert(): vector empty");

  if(i < 0 || i > size())
    throw indexRangeError("miniVector insert(): index range error", i, this->size());

  push_back(item);

  for(int j = size() - 2; j >= i; j--) {
    vArr[j + 1] = vArr[j];
  }

  vArr[i] = item;
}


template<typename T>
void miniVector<T>::erase(int i) {
  if(empty())
    throw underflowError("miniVector erase(): vector empty");

  if(i < 0 || i >= size())
    throw indexRangeError("miniVector erase(): index range error", i, size());

  for(int j = i; j < size() - 1; j++) {
    vArr[j] = vArr[j + 1];
  }
  pop_back();
}