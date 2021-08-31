// Jeff Caldwell
// CS 2336
// Lab 03

#include <lab03.h>
#include<cmath>

Rational Rational::add(const Rational& addend) const {
    Rational sum; // create a local Rational object
    int myLCM = lcm(this->getDenominator(), addend.getDenominator());

    int lhs = myLCM / this->getDenominator() * this->getNumerator();
    int rhs = myLCM / addend.getDenominator() * addend.getNumerator();

    // manipulate the data members of local object
    sum.setNumerator(lhs + rhs);
    sum.setDenominator(myLCM);
    sum.reduce();

    // return local object

    return sum;
}

Rational Rational::additiveInverse() const {

}

Rational Rational::subtract(const Rational& subtrahend) const {

}

Rational Rational::multiply(const Rational& multiplicand) const {

}

Rational Rational::multiplicativeInverse() const {

}

Rational Rational::divide(const Rational& divisor) const {

}

ostream& Rational::print(ostream& os) const {

}

istream& Rational::read(istream& is) {

}

int Rational::lcm(int m, int n) const {                         // lcm(m, n) = (m * n) / gcd(m, n)
    if(m == 0 && n == 0) {
        return 0;
    } else {
        return abs(m * n) / gcd(m, n);
    }
}