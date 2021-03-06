// Jeff Caldwell
// CS 2336
// Lab 08

#include <lab08.h>

//overloaded output operator for printing IntegerSet set to
//output stream out
ostream& operator<<(ostream& out, const IntegerSet& set) {
    if(set.cardinality() > 0) {
    uint count = 0;                  
    out << "{";                      
    for(uint e = 0; e < N; ++e) {
      if(set.isMember(e)) {
        count ++;                    
        if(count < set.cardinality()) {
          out << e << ",";          
        } else {
          out << e;                 
        }
      }
    }

    out << "}" << endl;             
  } else {
    out << static_cast<char>(216) << endl;
  }
  return out;
}

// if e is valid and not a member of the set, insert e into set
// this is the same as insertElement()
IntegerSet IntegerSet::operator+(uint e) const {
    IntegerSet mySet(*this); 
    
    if (isValid(e) && !isMember(e)){
        uint myWord = bitVector[word(e)];
        int n = bit(e);
        
        myWord = setBit(myWord, n, 1);
        mySet.bitVector[word(e)] = myWord;
    }
    
    return mySet;        
}

// if e is valid and a member of the set, delete e from set
// this is the same as deleteElement()
IntegerSet IntegerSet::operator-(uint e) const {
  IntegerSet set(*this);

  if(isValid(e) && isMember(e)) {
    uint myWord = bitVector[word(e)];
    int n = bit(e);

    myWord = setBit(myWord, n, 0);
    set.bitVector[word(e)] = myWord;
  }
  return set;
}

// complement of a Set
IntegerSet IntegerSet::operator-() const {
  IntegerSet comp;
  
  for(uint e = 0; e < N; ++e) {
    if(!isMember(e)) {
      comp = comp + e;
    } else {
      comp = comp - e;
    }
  }
  return comp;
}

// *this = rhs
IntegerSet& IntegerSet::operator=(const IntegerSet& rhs) {
      for (uint e = 0; e < N; ++e){
        if (rhs.isMember(e)){
          uint myWord = bitVector[word(e)];
          int n = bit(e);
          
          myWord = setBit(myWord, n, 1);
          bitVector[word(e)] = myWord;
        }
        else{
          uint myWord = bitVector[word(e)];
          int n = bit(e);
          
          myWord = setBit(myWord, n, 0);
          bitVector[word(e)] = myWord;
        }
      }
    return *this;
}