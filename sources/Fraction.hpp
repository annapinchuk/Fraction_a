#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <iostream>

#pragma once

using namespace std;
namespace ariel
{
    class Fraction
    {
        // numerator/denominator
    private:
        int numeator;
        int denominator;

        int gcd(int a, int b); // greatest common divisor for reduce function source:https://clubztutoring.com/ed-resources/math/how-to-reduce-a-fraction/

        void reduce(); // reduce the fraction after operations
    public:
        // constructor
        Fraction(float numeator, float denominator); // float contains int and float
        Fraction(float numeator);
        // getters
        int getNumerator() { return numeator; }
        int getDenominator() { return denominator; }
        // & is more efficient than * (pointer) because it doesn't need to allocate memory source:https://www.programiz.com/cpp-programming/operator-overloading
        // arithmetic operators
        Fraction operator+(const Fraction &num);// const todo: check if const is needed
        Fraction operator+(float num);
        Fraction operator-(const Fraction &num);
        Fraction operator-(float num);
        Fraction operator*(const Fraction &num);
        Fraction operator*(float num);
        Fraction operator/(const Fraction &num);
        Fraction operator/(float num);
        // assignment operators
        Fraction &operator+=(const Fraction &num);
        Fraction &operator+=(float num);
        Fraction &operator-=(const Fraction &num);
        Fraction &operator-=(float num);
        Fraction &operator*=(const Fraction &num);
        Fraction &operator*=(float num);
        Fraction &operator/=(const Fraction &num);
        Fraction &operator/=(float num);
        // increment and decrement operators
        Fraction &operator++();
        Fraction operator++(int);
        Fraction &operator--();
        Fraction operator--(int);
        // comparison operators
        bool operator==(const Fraction &num);
        bool operator==(float num);
        bool operator!=(const Fraction &num);
        bool operator!=(float num);
        bool operator>(const Fraction &num);
        bool operator<(float num);
        bool operator<(const Fraction &num);
        bool operator>(float num);
        bool operator>=(const Fraction &num);
        bool operator>=(float num);
        bool operator<=(const Fraction &num);
        bool operator<=(float num);
        // friend function <<
        friend ostream &operator<<(ostream &out, const Fraction &fraction);
        // friend function >>
        friend istream &operator>>(istream &in, Fraction &fraction);
        // friend function float
        friend float operator+(float num, const Fraction &fraction);
        friend float operator-(float num, const Fraction &fraction);
        friend float operator*(float num, const Fraction &fraction);
        friend float operator/(float num, const Fraction &fraction);
    };
}