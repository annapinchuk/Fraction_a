// Author: Anna Pinchuk
// Date: 03/05/2023
// Description: Implementation of the class Fraction and tests
// credit to: course staff for the header file, and the functions' descriptions.
#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace ariel;
TEST_CASE("functional test")
{
    Fraction a(5, 3), b(14, 21);
    CHECK(a + b == Fraction(7, 3));
    CHECK(a - b == Fraction(1, 1));
    CHECK(a * b == Fraction(10, 9));
    CHECK(a / b == Fraction(5, 2));
    CHECK(a + 2.421 == Fraction(12263, 3000)); // 2.421 = 2421/1000 -> 2421/1000 + 5/3 = 12263/3000
    CHECK(2.3 * b == Fraction(23, 15));
    CHECK(a > 1.1);
    CHECK(a >= b);
    CHECK(a != b);
    CHECK(a == Fraction(5, 3));
    CHECK(a != Fraction(5, 4));
    CHECK(a < Fraction(5, 2));
    CHECK(a <= Fraction(5, 3));
    CHECK(a++ == Fraction(5, 3));
    CHECK(a == Fraction(8, 3));
    CHECK(--a == Fraction(5, 3));
    CHECK(a == Fraction(5, 3));
    CHECK(a-- == Fraction(5, 3));
    CHECK(a == Fraction(2, 3));
    CHECK(++a == Fraction(5, 3));
    CHECK(a == Fraction(5, 3));
    CHECK(a++ == Fraction(5, 3));
    CHECK(a == Fraction(8, 3));
    CHECK(a-- == Fraction(8, 3));
    CHECK(a == Fraction(5, 3));
    CHECK(--a == Fraction(2, 3));
    CHECK(a == Fraction(2, 3));
}
TEST_CASE("negative vals")
{
    Fraction c(-3, 4), d(1, -3);
    CHECK(c + d == Fraction(-5, 12));
    CHECK(c - d == Fraction(-7, 12));
    CHECK(c * d == Fraction(-1, 4));
    CHECK(c / d == Fraction(9, -4));
}
TEST_CASE("zero vals")
{
    Fraction a(5, 3), b(0, 5), c(1, 0);
    CHECK_THROWS_AS(a / b, std::invalid_argument);
    CHECK_THROWS_AS(c + a, std::overflow_error);
    CHECK_THROWS_AS(b - a, std::underflow_error);
}
TEST_CASE("not float vals")
{
    CHECK_THROWS_AS(Fraction a(123.456789, 987.654321), std::invalid_argument);
}
TEST_CASE("Fraction operators test")
{
    // Test addition
    Fraction a(5, 3), b(14, 21);
    CHECK(a + b == Fraction(7, 3));
    CHECK(b + a == Fraction(7, 3));
    CHECK(a + 2.421f == Fraction(12263, 3000));
    CHECK(2.421f + a == Fraction(12263, 3000));

    // Test subtraction
    Fraction c(4, 7), d(2, 3);
    CHECK(c - d == Fraction(-2, 21));
    CHECK(d - c == Fraction(2, 21));
    CHECK(c - 1.234f == Fraction(-79, 140));
    CHECK(1.234f - c == Fraction(79, 140));

    // Test multiplication
    Fraction e(1, 2), f(2, 3);
    CHECK(e * f == Fraction(1, 3));
    CHECK(f * e == Fraction(1, 3));
    CHECK(e * 1.5f == Fraction(3, 4));
    CHECK(1.5f * e == Fraction(3, 4));

    // Test division
    Fraction g(5, 4), h(3, 2);
    CHECK(g / h == Fraction(5, 6));
    CHECK(h / g == Fraction(8, 5));
    CHECK(g / 1.25f == Fraction(4, 5));
    CHECK(1.25f / g == Fraction(5, 4));

    // Test equality
    Fraction i(3, 5), j(9, 15), k(7, 8);
    CHECK(i == j);
    CHECK(j == i);
    CHECK(i == 0.6f);
    CHECK(0.6f == i);
    CHECK(i != k);
    CHECK(k != i);

    // Test comparison
    CHECK(i < k);
    CHECK(i <= j);
    CHECK(k > i);
    CHECK(k >= j);

    // Test increment and decrement
    Fraction l(2, 5), m(7, 8);
    CHECK(++l == Fraction(7, 5));
    CHECK(l == Fraction(7, 5));
    CHECK(l++ == Fraction(7, 5));
    CHECK(l == Fraction(12, 5));
    CHECK(--m == Fraction(-1, 8));
    CHECK(m == Fraction(-1, 8));
    CHECK(m-- == Fraction(-1, 8));
    CHECK(m == Fraction(-9, 8));

    // Test output and input streams
    std::stringstream ss;
    ss << "2/3";
    ss >> f;
    CHECK(f == ariel::Fraction(2, 3));
}
