// Jeff Caldwell
// CS 2336
// Lab 07

#include <lab07.h>

// overloaded input operator initializes Rational rat from input stream in
istream& operator>>(istream& in, Rational& rat) {
  int num, denom; 
    
    if (in >> num >> denom)
    {
        rat.setNumerator(num);
        rat.setDenominator(denom);
    }
    else
    {
        rat.setNumerator(0);
        rat.setDenominator(1);
    }
    
    return in;
}

// overloaded output operator prints Rational rat to output stream out
ostream& operator<<(ostream& out, const Rational& rat) {
    out << rat.getNumerator() << '/' << rat.getDenominator();
    return out;
}

Rational& Rational::operator=(const Rational& rhs) {                // *this = rhs;
  if (this != &rhs) //avoid self assignment
    {
        this->setNumerator(rhs.getNumerator());
        this->setDenominator(rhs.getDenominator());
    }
    return *this;
}

Rational Rational::operator+(const Rational& addend) const {        // returns *this + addend
  //declare a local object
    Rational sum; 
    int lhs, rhs;
    
    int myLCM = lcm(this->getDenominator(), addend.getDenominator());
    
    lhs = myLCM / this->getDenominator() * this->getNumerator();
    rhs = myLCM / addend.getDenominator() * addend.getNumerator();
    
    //manipulate the local objects data
    sum.setNumerator(lhs + rhs);
    sum.setDenominator(myLCM);
    sum.reduce();
    
    //return the local object
    return sum;
}

Rational Rational::operator-() const {                              // returns -(*this)
  return  Rational(this->getNumerator() * -1, this->getDenominator());
}

Rational Rational::operator-(const Rational& subtrahend) const {    // returns *this - subtrahend
    //return this-> add(subtrahend.additiveInverse());
    return *this + -subtrahend;
}

Rational Rational::operator*(const Rational& multiplicand) const {  // returns *this * multiplicand
  Rational product;

  product.setNumerator(this->getNumerator() * multiplicand.getNumerator());
  product.setDenominator(this->getDenominator() * multiplicand.getDenominator());

  product.reduce();

  return product;
}

Rational Rational::operator/(const Rational& divisor) const {       // returns *this / divisor
  return *this * divisor.multiplicativeInverse();
}

bool Rational::operator==(const Rational& rhs) const {        
  return (*this - rhs).getNumerator() == 0;
}

bool Rational::operator!=(const Rational& rhs) const {              // *this != rhs
  return !(*this == rhs);
}

bool Rational::operator< (const Rational& rhs) const {              // *this <  rhs
  return (*this - rhs).getNumerator() < 0;
}

bool Rational::operator<=(const Rational& rhs) const {              // *this <= rhs
  if(*this < rhs || *this == rhs) {
    return true;
  } else {
    return false;
  }
}

bool Rational::operator> (const Rational& rhs) const {              // *this >  rhs 
  return (*this - rhs).getNumerator() > 0;
}

bool Rational::operator>=(const Rational& rhs) const {              // *this >= rhs
  if(*this > rhs || *this == rhs) {
    return true;
  } else {
    return false;
  }
}