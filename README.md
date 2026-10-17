# Fraction Exact-Arithmetic Library

This is a C++ math library I built to handle fractions exactly without losing precision to floating-point rounding errors. The project is an extensive exercise in **Operator Overloading**, rewriting standard mathematical, relational, and stream behaviors so fraction objects look and feel like native C++ data types.

The test driver targets explicit verification pathways, combining inline math configurations with deep stream diagnostics to guarantee calculation accuracy.

## Key Features
* **Full Arithmetic Suite:** Overloaded `+`, `-`, `*`, and `/` operators to handle interactions between two fractions, as well as equations mixing a fraction with a standard `long` integer.
* **Automatic Simplification:** Uses a private Greatest Common Divisor (`gcd`) helper function to automatically reduce fractions to their lowest terms upon creation or after math operations (e.g., `2/4` automatically reduces to `1/2`).
* **Advanced Increment/Decrement:** Implemented both pre-increment (`++f`) and post-increment (`f++`) logic, utilizing an internal dummy integer parameter to correctly signal timing mechanics to the C++ compiler.
* **Stream Insertion Integration:** Overloaded the standard `<<` stream operators outside the class scope so fraction objects can be piped directly into `std::stringstream` configurations seamlessly.

## Sample Terminal Output
When the driver runs its arithmetic validations and stream-routing logic, it formats and flushes a complete mathematical proof summary directly to the console:

```text
The result of 2/4 and 4/6 fractions being multiplied is 1/3
The result of 2/4 multiplied by 7 is 7/2
The result of 5/7 and 4/8 fractions being divided is 10/7
The result of 4/6 divided by 8 is 1/12
The result of 5/7 and 4/8 fractions being added is 17/14
The result of 4/8 plus 9 is 19/2
The result of 5/7 and 4/6 fractions being subtracted is 1/21
The result of 5/7 minus 20 is -135/7

The result of a pre increment of 2/4 +1 is 3/2
The result of a post increment of 2/4 +1 is 1/2
The result of a pre increment of 5/7 -1 is -2/7
The result of a post increment of 4/8 -1 is 1/2

1/2 is equal to 1/2
5/7 is not equal to 1/2
1/2 is equal to or less than 2/3
```

## Tech Used
* C++
* CMake (for CLion configurations)

## How to Run
1. Clone this repository down to your environment.
2. Open the project folder directly inside CLion.
3. Allow CMake to process the local compilation targets, then build and run the main test driver.
