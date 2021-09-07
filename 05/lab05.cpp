// Jeff Caldwell
// CS 2336
// Lab 05

#include <lab05.h>

/**
 * Equality operators : == and !=
 * Relational operators : <, <=, >=, >
 * 
 * == : write code
 * != : !(==)
 * < : write code
 * <= : (<) || (==)
 * >= : !(<)
 * > : !(<=) = !((<) || (==)) = `!(<) && !(==)` DeMorgan's Law (when you distribute a `not` over an `or` it becomes an `and`)
 */

bool Rational::isEqualTo(const Rational& other) const {               // *this == other
  int myLCM = lcm(this->getDenominator(), other.getDenominator());

  int lhs = myLCM / this->getDenominator() * this->getNumerator();
  int rhs = myLCM / other.getDenominator() * other.getNumerator();

  return lhs == rhs;
};

bool Rational::isNotEqualTo(const Rational& other) const {            // *this != other
return !(this->isEqualTo(other));
};

bool Rational::isLessThan(const Rational& other) const {              // *this < other
  int myLCM = lcm(this->getDenominator(), other.getDenominator());

  int lhs = myLCM / this->getDenominator() * this->getNumerator();
  int rhs = myLCM / other.getDenominator() * other.getNumerator();

  return lhs < rhs;
};

bool Rational::isLessThanOrEqualTo(const Rational& other) const {     // *this <= other
  return (isLessThan(other) || isEqualTo(other));
};

bool Rational::isGreaterThan(const Rational& other) const {           // *this > other
  return (!(isLessThan(other)) && !(isEqualTo(other)));
};

bool Rational::isGreaterThanOrEqualTo(const Rational& other) const {  // *this >= other
  return !(isLessThan(other));
};