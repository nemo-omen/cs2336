// Jeff Caldwell
// CS 2336
// Lab 11

#include <lab11.h>

// Test for equality
bool IntegerSet::operator==(const IntegerSet& rhs) const {
  for(uint e = 0; e < N; ++e) {
    if((this->isMember(e) && !(rhs.isMember(e))) || (!(this->isMember(e)) && rhs.isMember(e))) {
      // if either set contains elements the other does not
      // return `false`
      return false;
    }
  }

  // otherwise, return true
  return true;
}

// Subset
bool IntegerSet::operator<=(const IntegerSet& rhs) const {
  for(uint e = 0; e < N; ++e) {
    if((this->isMember(e) && (!rhs.isMember(e)))) {
      // if `rhs` is missing elements that *this contains, eject!
      return false;
    }
  }

  // otherwise, we must have a subset
  return true;
}

// Proper Subset
bool IntegerSet::operator< (const IntegerSet& rhs) const {
  if(this->cardinality() == rhs.cardinality()) {
    // if cardinality is the same, it can't be a proper subset
    return false;
  }

  for(uint e = 0; e < N; ++e) {
    if((this->isMember(e) && (!rhs.isMember(e)))) {
      // likewise, if rhs does not have all elements
      // of *this, it's also not a subset
      return false;
    }
  }

  // otherwise, return true
  return true;
}