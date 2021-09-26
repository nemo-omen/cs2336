// Jeff Caldwell
// CS 2336
// Lab 18

#include <iostream>
#include <bits.h>

using namespace std;

void printBase32(int num, ostream& os) {
  if(num != 0) {
    uint unum = static_cast<uint>(num);
    printBase32(unum >> 5, os);
    uint theBits = getBits(unum, 0, 5);

    if(theBits > 9) {
      os << (char)(theBits + 55);
    } else {
      os << theBits;
    }
    
  } else {
    return;
  }
}