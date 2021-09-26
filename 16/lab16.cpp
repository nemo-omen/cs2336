// Jeff Caldwell
// CS 2336
// Lab 16

#include <iostream>
#include <bits.h>

using namespace std;

void printOctal(int num, ostream& os) {
  if(num != 0) {
    uint unum = static_cast<uint>(num);
    printOctal(unum >> 3, os);
    os << getBits(unum, 0, 3);
  } else {
    return;
  }
}