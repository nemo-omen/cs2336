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
    return Rational(this->getNumerator() * -1, this->getDenominator());
}

Rational Rational::subtract(const Rational& subtrahend) const {
    return this->add(subtrahend.additiveInverse());
}

Rational Rational::multiply(const Rational& multiplicand) const {
    return Rational();
}

Rational Rational::multiplicativeInverse() const {
    return Rational();
}

Rational Rational::divide(const Rational& divisor) const {
    return Rational();
}

ostream& Rational::print(ostream& os) const {
    os << this->getNumerator() << '/' << this->getDenominator();
    return os;
}

istream& Rational::read(istream& is) {
    int num, denom;

    if(is >> num >> denom) {
        this->setNumerator(num);
        this->setDenominator(denom);
    } else {
        this->setNumerator(0);
        this->setDenominator(1);
    }
    return is;
}

int Rational::lcm(int m, int n) const {                         // lcm(m, n) = (m * n) / gcd(m, n)
    if(m == 0 && n == 0) {
        return 0;
    } else {
        return abs(m * n) / gcd(m, n);
    }
}