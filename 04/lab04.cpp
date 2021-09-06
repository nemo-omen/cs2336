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
  if(isValid(e) && isMember(e)) {
    uint myWord = bitVector[word(e)];
    int n = bit(e);

    myWord = setBit(myWord, n, 0);
    bitVector[word(e)] = myWord;
  }
}


IntegerSet IntegerSet::complement() const {
  IntegerSet comp;
  
  for(uint e = 0; e < N; ++e) {
    if(!isMember(e)) {
      comp.insertElement(e);      // if e is not a member, insert e
    } else {
      comp.deleteElement(e);      // otherwise, delete e
    }
  }
  return comp;
}

ostream& IntegerSet::print(ostream& os) const {
  if(cardinality() > 0) {
    uint count = 0;                 // keep track of the number of elements
    os << "{";                      // open with a left brace
    for(uint e = 0; e < N; ++e) {
      if(isMember(e)) {
        count ++;                   // increase count on element discovery
        if(count < cardinality()) {
          os << e << ",";           // if less than cardinality. print e with a comma
        } else {
          os << e;                  // else just print e
        }
      }
    }

    os << "}" << endl;              // wrap it up with a closing brace
  } else {
    os << static_cast<char>(216) << endl;
  }
  return os;
}

bool IntegerSet::isValid(uint e) const {
  return (0 <= e && e < N);         // Dr. Motl's handy formula
}