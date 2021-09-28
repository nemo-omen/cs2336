// Jeff Caldwell
// CS 2336
// Lab 17

#include <iostream>
#include <bits.h>

using namespace std;

void printHexadecimal(int num, ostream& os) {
  if(num != 0) {
    uint unum = static_cast<uint>(num);
    printHexadecimal(unum >> 4, os);
    int theBits = getBits(unum, 0, 4);

    if(theBits < 10) {
      os << theBits;
    } else {
      os << static_cast<char>(theBits - 10 + 'A');
    }

  } else {
    return;
  }
}