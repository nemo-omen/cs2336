// Jeff Caldwell
// CS 2336
// Lab 02

#include <lab02.h>
#include <iostream>
#include <cmath>

Rational::Rational()                                    // default constructor
  :Rational(0, 1) {
  }

Rational::Rational(int num, int denom) {                // additional constructor
  setNumerator(num);
  setDenominator(denom);
}

void Rational::setNumerator(int num) {                  // set numerator to num
  data.first = num;
}

void Rational::setDenominator(int denom) {              // set denominator to denom
  data.second = (denom == 0) ? 1 : denom;
}


int  Rational::getNumerator() const {                   // return numerator
  return data.first;
}

int  Rational::getDenominator() const {                 // return denominator
  return data.second;
}

void Rational::reduce() {                               // Reduce to lowest terms and
  int g = gcd(getNumerator(), getDenominator());

  if(getDenominator() < 0)
    g = -g;

  setNumerator(getNumerator() / g);
  setDenominator(getDenominator() / g);

}                                                       // normalize


int Rational::gcd(int m, int n) const {                 // returns the gcd of m and n                                     

  if(m == 0)
    return abs(n);
  else if(n == 0)
    return abs(m);

  else { // using Euclid's Algorithm
    m = abs(m);
    n = abs(n);
    int rem = m % n;
    
    while(rem != 0) {
      m = n;
      n = rem;
      rem = m % n;
    }

    return n;
  }
}