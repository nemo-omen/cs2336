// Jeff Caldwell
// CS 2336
// Lab 10

#include <lab10.h>

// union
IntegerSet IntegerSet::operator+(const IntegerSet& rhs) const {
  IntegerSet unionSet;
  for(uint e = 0; e < N; ++e) {
    if((this->isMember(e) || rhs.isMember(e))) {
      unionSet = unionSet + e;
    }
  }
  return unionSet;
}

// intersection
IntegerSet IntegerSet::operator*(const IntegerSet& rhs) const {
  IntegerSet intersectionSet;
  for(uint e = 0; e < N; ++e) {
    if(isMember(e) && rhs.isMember(e)) {
      intersectionSet = intersectionSet + e;
    }
  }
  return intersectionSet;
}

// difference
IntegerSet IntegerSet::operator-(const IntegerSet& rhs) const {
  IntegerSet differenceSet;
  for(uint e = 0; e < N; ++e) {
    if(isMember(e) && !rhs.isMember(e)) {
      differenceSet = differenceSet + e;
    }
  }
  return differenceSet;
}

// symmetric diff
IntegerSet IntegerSet::operator/(const IntegerSet& rhs) const {
  IntegerSet symmetricDifferenceSet;
  IntegerSet tempIntersection = *this * rhs;
  
  for(uint e = 0; e < N; ++e) {
    if(!tempIntersection.isMember(e)) {
      if(isMember(e) || rhs.isMember(e)) {
        symmetricDifferenceSet = symmetricDifferenceSet + e;
      }
    }
  }
  return symmetricDifferenceSet;
}
