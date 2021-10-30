// Jeff Caldwell
// CS 2336
// Lab 28


template<typename T>
bool Frequency<T>::operator==(const T rhs) const {
  return this->getValue() == rhs;
}

template<typename T>
bool Frequency<T>::operator< (const Frequency<T> rhs) const {
  return  this->getFrequency() < rhs.getFrequency();
}

template<typename T>
vector<Frequency <T>> distribution(const vector<T>& v) {
  vector<Frequency <T>> myDistribution;
  typename vector<T>::const_pointer ptr, end = v.data() + v.size();
  typename vector<Frequency<T>>::iterator findItr;

  for(ptr = v.data(); ptr < end; ++ptr) {
    findItr = find(myDistribution.begin(), myDistribution.end(), *ptr);

    if(findItr == myDistribution.end()) {
      myDistribution.emplace_back(Frequency<T>(*ptr));
    } else {
      findItr->increment();
    }
  }

  return myDistribution;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<Frequency<T>>& v) {
  vector<Frequency<T>> copy(v);
  typename vector<Frequency<T>>::const_pointer ptr, end = copy.data() + copy.size();

  for(ptr = copy.data(); ptr < end; ++ptr) {
    out << ptr->getValue() << " -> " << ptr->getFrequency() << endl;
  }
  return out;
}