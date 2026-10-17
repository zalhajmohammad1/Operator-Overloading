#include <cmath>
#include <string>
#include <sstream>

#ifndef FRACTION_H
#define FRACTION_H

using namespace std;

/**
 * @class Fraction class
 * @brief Represents a fraction
 */
class Fraction {

private:
    long numerator;
    long denominator;

    void reduce();
    long gcd(long a, long b);

public:

    /**
     * parameterized constructor
     * @param numerator // takes in a numerator integer
     * @param denominator // takes in a denominator integer
     */
    Fraction(long numerator, long denominator);
    /**
     * getter for the numerator
     * @return returns 'numerator'
     */
    long getNumerator();
    /**
     * getter for the denominator
     * @return returns 'denominator'
     */
    long getDenominator();
    /**
     * a toString method that returns the fraction in a fraction format (i.e 2/3)
     * @return returns numerator, '/' , and denominator as a string
     */
    std::string toString();

    /**
     * overloaded multiplication operator
     * @param value // takes in a lhs number to be multiplied by a fraction rhs object
     * @return returns a newly constructed fraction object as the product
     */
    Fraction operator*(long value);
    /**
     * overloaded multiplication operator
     * @param fraction2 // takes in a second fraction as the rhs and multiplies it by the original lhs fraction object
     * @return  returns a newly constructed fraction object as the product
     */
    Fraction operator*(Fraction& fraction2);
    /**
     * overloaded division operator
     * @param value // takes in a second rhs number which the lhs original fraction object is divided by
     * @return returns a newly constructed object as the quotient
     */
    Fraction operator/(long value); //declaring an overloaded operator inside the class scope indicates that the object is automatically a parameter
    /**
     * overloaded division operator
     * @param fraction2 // takes in a second rhs fraction object which the lhs original fraction object is divided by
     * @return returns a newly constructed object as the quotient
     */
    Fraction operator/(Fraction& fraction2);
    /**
     * overloaded addition operator
     * @param fraction2 // takes in a second rhs fraction object which is added to the original lhs fraction object
     * @return returns a newly constructed object as the sum
     */
    Fraction operator+(Fraction& fraction2);
    /**
     * overloaded addition operator
     * @param value // takes in a second rhs number which is added to the original lhs fraction object
     * @return returns a newly constructed object as the sum
     */
    Fraction operator+(long value);
    /**
     * overloaded subtracted operator
     * @param fraction2 // takes in a rhs fraction object which is subtracted from the original lhs fraction object
     * @return returns a newly constructed object as the difference
     */
    Fraction operator-(Fraction& fraction2);
    /**
     * overloaded subtracted operator
     * @param value // takes in a rhs number which is subtracted from the original lhs fraction object
     * @return returns a newly constructed object as the difference
     */
    Fraction operator-(long value);
    /**
     * overloaded pre increment operator
     * @return returns the lhs's changed numerator right away. (+1)
     */
    Fraction& operator++();
    /**
     * overloaded post increment operator
     * @param dummy // empty parameter to distinguish between the post and pre incrementation methods
     * @return returns a newly constructed object which hasen't been changed yet.
     * The next time the operator is called the change on the new object inside the method is called with the change, hence the post incrementation.
     */
    Fraction operator++(int dummy);
    /**
     * overloaded pre decrement operator
     * @return returns the lhs's changed numerator right away. (-1)
     */
    Fraction& operator--();
    /**
     * overloaded post decrement operator
     * @param dummy // empty parameter to distinguish between the post and pre decremental methods
     * @return returns a newly constructed object which hasen't been changed yet.
     * The next time the operator is called the change on the new object inside the method is called with the change, hence the post incrementation.
     */
    Fraction operator--(int dummy);

    /**
     * overloaded equivalency bool operator
     * @param fraction2 // takes in a rhs fraction object that is compared to the original lhs fraction object
     * @return returns true or false for whether the condition is true or not
     */
    bool operator==(Fraction fraction2);
    /**
     * overloaded non equivalency bool operator
     * @param fraction2 // takes in a rhs fraction object that is compared to the original lhs fraction object
     * @return returns true or false for whether the condition is true or not
     */
    bool operator!=(Fraction fraction2);
    /**
     * overloaded greater than bool operator
     * @param fraction2 // takes in a rhs fraction object that is compared to the original lhs fraction object
     * @return returns true or false for whether the condition is true or not
     */
    bool operator>(Fraction fraction2);
    /**
     * overloaded less than bool operator
     * @param fraction2 takes in a rhs fraction object that is compared to the original lhs fraction object
     * @return returns true or false for whether the condition is true or not
     */
    bool operator<(Fraction fraction2);
    /**
     * overloaded greater than or equal to bool operator
     * @param fraction2 takes in a rhs fraction object that is compared to the original lhs fraction object
     * @return returns true or false for whether the condition is true or not
     */
    bool operator>=(Fraction fraction2);
    /**
     * overloaded less than or greater than bool operator
     * @param fraction2 takes in a rhs fraction object that is compared to the original lhs fraction object
     * @return returns true or false for whether the condition is true or not
     */
    bool operator<=(Fraction fraction2);

   //std::ostringstream& operator<<(Fraction* fraction);

};

/**
 * overloaded stream insertion operator
 * @param out // takes a stringstream variable
 * @param fraction // takes a fraction object pointer
 * @return returns the reference of the 'out' stringstream variable with the fraction object's fraction form stored in it as a string, via the 'toString()' method
 */
std::stringstream& operator<<(std::stringstream& out, Fraction* fraction); // both methods declared outside the class to be able to hold 2 parameters without a lhs being one of them
/**
 * overloaded stream insertion operator
 * @param out // takes a stringstream variable
 * @param fraction // takes a fraction object
 * @return returns the reference of the 'out' stringstream variable with the fraction object's fraction form stored in it as a string, via the 'toString()' method
 */
std::stringstream& operator<<(std::stringstream& out, Fraction fraction);
//std::ostringstream& operator<<(ostringstream& out, Fraction* fraction);

#endif //FRACTION_H
