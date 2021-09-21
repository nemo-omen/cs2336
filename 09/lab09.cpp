// Jeff Caldwell
//  CS 2336
//  Lab 09

#include <lab09.h>

// preincrement
Rational& Rational::operator++() {
  Rational inc(1,1);

  *this = *this + inc;

  return *this;
}

// postincrement
Rational Rational::operator++(int) {
  Rational copy = *this;

  ++*this;

  return copy;
}

// predecrement
Rational& Rational::operator--() {
  Rational dec(1,1);

  *this = *this - dec;

  return *this;
}
// postdecrement
Rational Rational::operator--(int) {
  Rational copy = *this;

  --*this;

  return copy;
}