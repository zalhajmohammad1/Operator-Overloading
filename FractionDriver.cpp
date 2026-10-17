#include <iostream>
#include "Fraction.h"

int main() {

    std::cout << std::endl;
    /*
     * function objects to work with the operations
     */
    Fraction fraction1 =  Fraction(2, 4);
    Fraction fraction2 =  Fraction(4, 6);

    Fraction* fraction3 = new Fraction(5, 7);
    Fraction* fraction4 = new Fraction(4, 8);
    /*
     * basic arithmetic operations
     */
    Fraction product1 = fraction1 * fraction2; // result is of type Fraction which is what the multiplication overloaded operator method or function returns, that's why the result should be stored in a corresponding data type variable

    Fraction product2 = fraction1.operator*(7); // both this and the syntax above do the same thing

    Fraction quotient1 = *fraction3 / *fraction4; // 2 fractions being divided

    Fraction quotient2 = fraction2.operator/(8); // a fraction being divided by 8

    Fraction sum1 = fraction1 + *fraction4; // 2 fractions being added

    Fraction sum2 = fraction4->operator+(9); // a fraction being added to 9

    Fraction difference1 = *fraction3 - fraction2; // 2 fractions being subtracted

    Fraction difference2 = fraction3->operator-(20); // a fraction being subtracted by 20

    /*
     * post and pre increment operations for addition and subtraction
     */
    Fraction preIncrementAddition = fraction1++;

    Fraction postIncrementAddition = fraction1++;

    Fraction preIncrementSubtraction = fraction3->operator--()--;

    Fraction postInrementSubtraction = fraction4->operator--()++;

    /*
     * bool operations
     */
    bool equalTo = fraction1 == fraction1;

    bool notEqualTo = fraction3->operator!=(*fraction4);

    bool equalToOrLessThan = fraction4->operator<=(fraction1);

    bool equalToOrGreaterThan = fraction2 >= fraction1;

    bool greaterThan = fraction3->operator>(fraction2);

    bool lessThan = fraction1 < *fraction4;



    /*
     * string streams that store the results of the arithmetic operations
     */
    std::stringstream multiplicationResult1;
    std::stringstream divisionResult1;
    std::stringstream subtractionResult1;
    std::stringstream additionResult1;

    std::stringstream multiplicationResult2;
    std::stringstream divisionResult2;
    std::stringstream subtractionResult2;
    std::stringstream additionResult2;

    /*
     * each string stream saves its corresponding result name, for example, 'multiplicationResult' stores a multiplication product
     * (stringstream variables are technically objects of class stringstream which allows for the overloaded operator to work
     * the stringstream variable is the lhs while the result of a mathematical operation's object variable is the rhs
     * the outputs are being stored using the overloaded '<<' operator
     * (see definition in the .cpp for information on how the operator is stored when called between 2 objects in the driver)
     */
    multiplicationResult1 << product1; //'multiplicationResult is the left hand side 'lhs' and any other objects outputted from it act as the right hand side 'rhs' // since 'multiplicationResult' is of type 'std::stringstream', it can hold multiple strings
    divisionResult1 << quotient1;
    subtractionResult1 << difference1;
    additionResult1 << sum1;

    divisionResult2 << quotient2;
    additionResult2 << sum2;
    subtractionResult2 << difference2;
    multiplicationResult2 << product2;

    /*
     * string streams that store the results of the pre- and post-increments for addition and subtraction
     */
    std::stringstream preIncrementAdditionResult;
    std::stringstream preIncrementSubtractionResult;
    std::stringstream postIncrementAdditionResult;
    std::stringstream postIncrementSubtractionResult;

    preIncrementAdditionResult << preIncrementAddition;
    preIncrementSubtractionResult << preIncrementSubtraction;
    postIncrementAdditionResult << postIncrementAddition;
    postIncrementSubtractionResult << postInrementSubtraction;





    /*
     * a 'finalResult' string stream variable is created that stores all those string streams that stored result values
     * note that the ability for the stored object inside the mathematical result's stringstream variable to output as a fraction relies o['/n the 'toString()' method
     * check the definition in the .cpp for more details.
     *
     */
    std::stringstream finalOutput;
    finalOutput << "The result of 2/4 and 4/6 fractions being multiplied " << multiplicationResult1.str() << std::endl
                << "The result of 2/4 multiplied by 7 is " << multiplicationResult2.str() << std::endl
                << "The result of 5/7 and 4/8 fractions being divided is " << divisionResult1.str() << std::endl
                << "The result of 4/6 divided by 8 is " << divisionResult2.str() << std::endl
                << "The result of 5/7 and 4/8 fractions being added is " << additionResult1.str() << std::endl
                << "The result of 4/8 plus 9 is " << additionResult2.str() << std::endl
                << "The result of 5/7 and 4/6 fractions being subtracted is " << subtractionResult1.str() << std::endl
                << "The result of 5/7 minus 20 is " << subtractionResult2.str() << std::endl << std::endl
                << "The result of a pre increment of 2/4 +1 is " << preIncrementAdditionResult.str() << std::endl
                << "The result of a post increment of 2/4 +1 is " << postIncrementAdditionResult.str() << std::endl
                << "The result of a pre increment of 5/7 -1 is " << preIncrementSubtractionResult.str() << std::endl
                << "The result of a post increment of 4/8 -1 is " << postIncrementSubtractionResult.str() << std::endl;

    /*
     * 'finalResult' then outputs a neat prompt of each operation and their result all in a string format
     */
    std::cout << finalOutput.str();
    std::cout << std::endl;

    /*
     * the following if statements will check whether the boolean variables are true, then will confirm the condition inside the overloaded bool operator method's definition.
     */
    if (equalTo) {
        std::cout << fraction1.getNumerator() << ("/") << fraction1.getDenominator() << " is equal to "
                  << fraction1.getNumerator() << ("/") << fraction1.getDenominator() << std::endl;
    }
        else {
            std::cout << fraction1.getNumerator() << ("/") << fraction1.getDenominator() << " is not equal to "
                  << fraction1.getNumerator() << ("/") << fraction1.getDenominator() << std::endl;
        }
    if (notEqualTo) {
        std::cout << fraction3->getNumerator() << ("/") << fraction3->getDenominator() << " is not equal to "
                  << fraction4->getNumerator() << ("/") << fraction4->getDenominator() << std::endl;
    }
        else {
            std::cout << fraction3->getNumerator() << ("/") << fraction3->getDenominator() << " is equal to "
                  << fraction4->getNumerator() << ("/") << fraction4->getDenominator() << std::endl;
        }
    if (equalToOrLessThan) {
        std::cout << fraction4->getNumerator() << ("/") << fraction4->getDenominator()
                  << " is equal to or less than " << fraction2.getNumerator() << ("/") << fraction2.getDenominator()
                  << std::endl;
    }
        else {
            std::cout << fraction4->getNumerator() << ("/") << fraction4->getDenominator()
                  << " is not equal to or less than " << fraction2.getNumerator() << ("/")
                  << fraction2.getDenominator()
                  << std::endl;
        }
    if (equalToOrGreaterThan) {
        std::cout << fraction2.getDenominator() << ("/") << fraction2.getDenominator()
                  << " is greater than or equal to " << fraction1.getNumerator() << ("/") << fraction1.getDenominator()
                  << std::endl;
    }
        else {
            std::cout << fraction2.getDenominator() << ("/") << fraction2.getDenominator()
                  << " is not greater than or equal to " << fraction1.getNumerator() << ("/") << fraction1.getDenominator()
                  << std::endl;
    }
        if (greaterThan) {
             std::cout << fraction3->getNumerator() << ("/") << fraction3->getDenominator() << " is greater than "
                  << fraction2.getNumerator() << ("/") << fraction2.getDenominator() << std::endl;
    }
        else {
            std::cout << fraction3->getNumerator() << ("/") << fraction3->getDenominator() << " is not greater than "
                      << fraction2.getNumerator() << ("/") << fraction2.getDenominator() << std::endl;
        }
        if (lessThan) {
            std::cout << fraction1.getNumerator() << ("/") << fraction1.getDenominator() << " is less than "
                      << fraction4->getNumerator() << ("/") << fraction4->getDenominator() << std::endl;
        }
            else {
            std::cout << fraction1.getNumerator() << ("/") << fraction1.getDenominator() << " is not less than "
                      << fraction4->getNumerator() << ("/") << fraction4->getDenominator() << std::endl;
        }

Fraction fraction6(3, 7);
            std::cout << fraction6.getDenominator() << fraction6.getNumerator();

    return 0;
}
