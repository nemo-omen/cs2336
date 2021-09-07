// Jeff Caldwell
// CS 2336
// Lab 06

#include <lab06.h>

IntegerSet IntegerSet::Union(const IntegerSet& otherSet) const {
  IntegerSet unionSet;
  for(uint e = 0; e < N; ++e) {
    if((isMember(e) || otherSet.isMember(e)) && !unionSet.isMember(e)) {
      unionSet.insertElement(e);
    } else {
      unionSet.deleteElement(e);
    }
  }
  return unionSet;
}

IntegerSet IntegerSet::intersection(const IntegerSet& otherSet) const {
  IntegerSet intersectionSet;
  for(uint e = 0; e < N; ++e) {
    if(isMember(e) && otherSet.isMember(e) && !intersectionSet.isMember(e)) {
      intersectionSet.insertElement(e);
    } else {
      intersectionSet.deleteElement(e);
    }
  }
  return intersectionSet;
}

IntegerSet IntegerSet::difference(const IntegerSet& otherSet) const {
  IntegerSet differenceSet;
  for(uint e = 0; e < N; ++e) {
    if(isMember(e) && !otherSet.isMember(e) && !differenceSet.isMember(e)) {
      differenceSet.insertElement(e);
    } else {
      differenceSet.deleteElement(e);
    }
  }
  return differenceSet;
}

IntegerSet IntegerSet::symmetricDifference(const IntegerSet& otherSet) const {
  IntegerSet symmetricDifferenceSet;
  IntegerSet tempIntersection = intersection(otherSet);
  for(uint e = 0; e < N; ++e) {
    if(!tempIntersection.isMember(e)) {
      if(isMember(e) || otherSet.isMember(e)) {
        symmetricDifferenceSet.insertElement(e);
      } else {
        symmetricDifferenceSet.deleteElement(e);
      }
    }
  }
  return symmetricDifferenceSet;
}
