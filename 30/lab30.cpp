// Jeff Caldwell
// CS 2336
// Lab 30

#include <iostream>
#include <IntegerSet.h>
using namespace std;

void sieveOfEratosthenes(IntegerSet& prime) {
  for (uint i = 2; i < prime.size(); i++) {
    if((i * i) < prime.size()) {
      if(prime.isMember(i)) {
        for(uint j = i + i; j < prime.size(); j+= i) {
          prime.reset(j);
        }
      }
    }
  }
}

ostream& operator<<(ostream& os, const IntegerSet& intSet) {
  for(uint i = 0; i < intSet.size(); i++) {
    if(intSet.isMember(i)) {
      os << i << '\n';
    }
  }
  return os;
}