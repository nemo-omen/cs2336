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
  return 0;
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

    bitVector[word(e)] = bit(myWord, n, 0);
  }
}

IntegerSet IntegerSet::compliment() const {
  return IntegerSet();
}

ostream& IntegerSet::print(ostream& os) const {
  cout << "Blahblah" << endl;
}

bool IntegerSet::isValid(uint e) const {
  return true;
}