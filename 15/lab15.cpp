// Jeff Caldwell
// CS 2336
// Lab 15

#include <iostream>
#include <bits.h>

using namespace std;

void printQuaternary(int num, ostream& os) {
  if(num != 0) {
    uint unum = static_cast<uint>(num);
    printQuaternary(unum >> 2, os);
    os << getBits(unum, 0, 2);
  } else {
    return;
  }
}