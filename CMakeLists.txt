cmake_minimum_required(VERSION 3.17)
project(Fractions)

set(CMAKE_CXX_STANDARD 14)

add_executable(Fractions_Driver FractionDriver.cpp Fraction.cpp Fraction.h)

add_executable(Base_fraction_test
        tests/FractionTest.cpp
        Fraction.cpp
        Fraction.h
        tests/catch.hpp
        )

add_executable(Addition_Subtraction_test
        tests/AdditionSubtractionTest.cpp
        Fraction.cpp
        Fraction.h
        tests/catch.hpp
        )

add_executable(Multi_Division_test
        tests/MultiplicationDivisionTest.cpp
        Fraction.cpp
        Fraction.h
        tests/catch.hpp
        )

add_executable(Comparison_test
        tests/ComparisonTest.cpp
        Fraction.cpp
        Fraction.h
        tests/catch.hpp
        )

add_executable(Stream_test
        tests/StreamTest.cpp
        Fraction.cpp
        Fraction.h
        tests/catch.hpp
)

add_executable(Assignment_test
        tests/Assignment_Test.cpp
        Fraction.cpp
        Fraction.h
        tests/catch.hpp
)