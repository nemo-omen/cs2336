// Jeff Caldwell
// CS 2336
// Lab 04

#include <lab04.h>

IntegerSet::IntegerSet() {
  allocateStorage();

  // loop through the universe (0, 1 .., (N - 1)), calling
  // deleteElement for each possible element
  for (uint e = 0; e < N; ++e) {
    deleteElement(e);
  }
}

IntegerSet::IntegerSet(const IntegerSet& otherSet) {
  allocateStorage();
  for(uint e = 0; e < N; ++e) {
    if(otherSet.isMember(e)) {
      insertElement(e); // insertElement if it is a member of otherSet
    } else {
      deleteElement(e); // otherwise, delete
    }
  }
}

IntegerSet::~IntegerSet() {
  // every call to `new` needs to be paired with a call to `delete`
  // so the dynamically allocated memory is returned
  delete [] bitVector;
}


bool IntegerSet::isMember(uint e) const {
  if(isValid(e)) {
    uint myWord = bitVector[word(e)];
    int n = bit(e);
    return getBit(myWord, n);
  }

  return false;
}

uint IntegerSet::cardinality() const {
  int count = 0;
  for(uint e = 0; e < N; ++e) {
    if(isMember(e)) {
      count ++;
    }
  }
  return count;
}

void IntegerSet::insertElement(uint e) {
  if(isValid(e) && !isMember(e)) {
    uint myWord = bitVector[word(e)];
    int n = bit(e);

    myWord = setBit(myWord, n, 1);
    bitVector[word(e)] = myWord;
  }
}

void IntegerSet::deleteElement(uint e) {
  if(isValid(e) && !isMember(e)) {
    uint myWord = bitVector[word(e)];
    int n = bit(e);

    myWord = setBit(myWord, n, 0);
    bitVector[word(e)] = myWord;
  }
}

IntegerSet IntegerSet::complement() const {
  IntegerSet comp;
  //manipulate the local object
  // create the opposite -- ie, if
  // e is not a member, insert it
  // else delete it
  for(uint e = 0; e < N; ++e) {
    if(!isMember(e)) {
      comp.insertElement(e);
    } else {
      comp.deleteElement(e);
    }
  }
  return comp;
}

ostream& IntegerSet::print(ostream& os) const {
  if(cardinality() > 0) {
    os << "{";
    for(uint e = 0; e < N; ++e) {
      if(isMember(e)) {
        if(e != N - 1) {
          os << e << ",";
        } else {
          os << e;
        }
      }
    }
    os << "}" << endl;
  } else {
    os << static_cast<char>(216) << endl;
  }
  return os;
}

bool IntegerSet::isValid(uint e) const {
  bool isValid;
  if(0 <= e && e < N) {
    isValid = true;
  } else {
    isValid = false;
  }
  return isValid;
}