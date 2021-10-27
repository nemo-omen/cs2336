// Jeff Caldwell
// CS 2336
// Lab 25

template<typename U>
ostream& operator<<(ostream& output, const Accumulator<U>& obj) {
  output << obj.getTotal();
  return output; 
}

// constructor
template <typename T>
Accumulator<T>::Accumulator(const T& value) {
  this->total = value;
}

// return total
template <typename T>
T Accumulator<T>::getTotal() const {
 return this->total;
}

// add (+) value to total
template <typename T>
void Accumulator<T>::addValue(const T& value) {
  this->total += value;
}