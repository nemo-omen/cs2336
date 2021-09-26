// Jeff Caldwell
// CS 2336
// Lab 14

#include <iostream>
#include <bits.h>

using namespace std;

void printBinary(int num, ostream& os) {
  if(num != 0) {
    uint unum = static_cast<uint>(num);
    printBinary(unum >> 1, os);
    os << getBit(unum, 0);
  } else {
    return;
  }
}