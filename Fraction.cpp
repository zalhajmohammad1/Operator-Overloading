#include "Fraction.h"
#include <iostream>
#include <sstream>


Fraction::Fraction(long numerator, long denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    this->reduce();
try {

    if (this->denominator == 0)
    throw this->denominator;
}
catch (int a){
    std::cout << "Denominator cannot equal zero." << std::endl;
    a = 1;
    this->denominator = a;
}

if (this->denominator < 0) {
    this->numerator = this->numerator * -1;
    this->denominator = this->denominator * -1;
}

}


long Fraction::getDenominator() {
    return denominator;
}

long Fraction::getNumerator() {
    return numerator;
}


Fraction operator+(long value, Fraction& fraction2) {
    Fraction fraction1 = Fraction(value + fraction2.getNumerator(), value+ fraction2.getDenominator());

    return fraction1;

}


Fraction Fraction::operator+(Fraction& fraction2) {

    /*
     * 1/2 + 2/3
     * = 1 * 3 / 2 * 3 + 2 * 2 / 3 * 2
     * = 7/6
     */

    Fraction fractionResult = Fraction(
            this->getNumerator() * fraction2.getDenominator() + fraction2.getNumerator() * this->getDenominator(),
            fraction2.getDenominator() * this->getDenominator());

   // fractionResult.reduce();
    return fractionResult;

}


     Fraction Fraction::operator+(long value) {

        Fraction fractionResult = Fraction(value * this->denominator + this->numerator * 1, this->denominator * 1);

        return fractionResult;
    }


Fraction Fraction::operator-(Fraction &fraction2) {

    Fraction fractionResult = Fraction(
            this->getNumerator() * fraction2.getDenominator() - fraction2.getNumerator() * this->getDenominator(),
            this->getDenominator() * fraction2.getDenominator());

    return fractionResult;
}



Fraction Fraction::operator-(long value) {

    Fraction fractionResult = Fraction(this->numerator * 1 - value * this->denominator, this->getDenominator() * 1);

    return fractionResult;

}


Fraction Fraction::operator*(Fraction &fraction2) {

    Fraction fractionResult = Fraction(this->numerator * fraction2.numerator,
                                       this->denominator * fraction2.denominator);
    return fractionResult;
}


Fraction Fraction::operator*(long value) {

    Fraction fractionResult = Fraction(this->getNumerator() * value, this->getDenominator() * 1);

    return fractionResult;
}

Fraction Fraction::operator/(Fraction &fraction2) {

    Fraction fractionResult = Fraction(this->getNumerator() * fraction2.getDenominator(),
                                       this->getDenominator() * fraction2.getNumerator());

    return fractionResult;
}

Fraction Fraction::operator/(long value) {

    Fraction fractionResult = Fraction(this->getNumerator() * 1, this->getDenominator() * value);

    return fractionResult;
}

Fraction& Fraction::operator++() {
    this->numerator += 1;
    return *this;
}


Fraction Fraction::operator++(int dummy) {
    Fraction fractionResult = Fraction(numerator, denominator);
    this->numerator += 1; // changes the original instance's numerator from the driver
    return fractionResult; // returns unchanged clone object (only thing we really changed is the 'this->' which is the driver's object's numerator.
}           //the return value returns the clone object's value, which is unchanged.

Fraction &Fraction::operator--() {
    this->numerator -= 1; // this->numerator -1; by itself doesn't store the value anywhere. this->numerator -= 1 stores the value inside the numerator
    return *this;
}


Fraction Fraction::operator--(int dummy) {
    Fraction fractionResult = Fraction(numerator, denominator);
    this->numerator -= 1;
    return fractionResult;

}


//make denominators equal to one another then compare numerator // or // cross multiply and compare

bool Fraction::operator==(Fraction fraction2) {

    return this->numerator * fraction2.denominator == this->denominator * fraction2.numerator;

}

bool Fraction::operator!=(Fraction fraction2) {

    return !(this->numerator * fraction2.denominator == this->denominator * fraction2.numerator);
}

bool Fraction::operator<(Fraction fraction2) {

    return this->numerator * fraction2.denominator < this->denominator * fraction2.numerator;
}

bool Fraction::operator<=(Fraction fraction2) {


   return !(this->numerator * fraction2.denominator > this->denominator * fraction2.numerator);



}

bool Fraction::operator>(Fraction fraction2) {

   return this->numerator * fraction2.denominator > this->denominator * fraction2.numerator;

}

bool Fraction::operator>=(Fraction fraction2) {

    return !(this->numerator * fraction2.denominator < this->denominator * fraction2.numerator);

}















/*
 * The reduce method reduces the fraction and simplifies
 * the sign of the fraction resulting in only the numerator
 * being positive or negative.
 */
    void Fraction::reduce() {
        // store if the fraction is positive or negative.
        bool isNegative;
        if ((denominator < 0 && numerator < 0) || (denominator > 0 && numerator > 0)) {
            isNegative = false;
        } else {
            isNegative = true;
        }

        // reset the numerator and denominator to positive
        numerator = abs(numerator);
        denominator = abs(denominator);

        // get the greatest common denominator
        long greatest_common_denominator = gcd(numerator, denominator);

        // reduce the fraction
        numerator = numerator / greatest_common_denominator;
        denominator = denominator / greatest_common_denominator;

        // set the numerator to negative if the fraction was negative.
        if (isNegative) numerator = numerator * -1;

    }

/*
 * The gcd method returns the greatest common denominator of two numbers.
 * The method uses a beautiful, compact, little recursive algorithm that
 * we'll discuss more when we get to recursion.
 */
    long Fraction::gcd(long a, long b) {
        if (a == 0) { return b; }
        return gcd(b % a, a);
    }


std::string Fraction::toString() {

        std::stringstream ss;
        ss << numerator << "/" << denominator;
        return ss.str();
    }


std::stringstream& operator<<(std::stringstream& out, Fraction* fraction){

        out << fraction->toString();
        return out;
    }
std::stringstream& operator<<(std::stringstream& out, Fraction fraction){ //rhs and lhs are parameters of objects, meaning in the driver only 2 objects can be used with this overloaded method

        out << fraction.toString();
        return out;
    }