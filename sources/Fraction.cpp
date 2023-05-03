#include "Fraction.hpp"
using namespace ariel;
Fraction::Fraction(float numeator, float denominator)
{
    if (denominator == 0)
    {
        throw invalid_argument("denominator can't be 0");
    }
    this->numeator = numeator;
    this->denominator = denominator;
    reduce();
}
Fraction::Fraction(float numeator)
{
    this->numeator = numeator;
    this->denominator = 1;
}
int Fraction::gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void Fraction::reduce()
{
    int gcd = this->gcd(this->numeator, this->denominator);
    this->numeator /= gcd;
    this->denominator /= gcd;
}
// the furmula is (a/b) + (c/d) = (a*d + b*c)/(b*d)
Fraction Fraction::operator+(const Fraction &other)
{
    int newNumeator = this->numeator * other.denominator + other.numeator * this->denominator;
    int newDenominator = this->denominator * other.denominator;
    Fraction newFraction(newNumeator, newDenominator);
    return newFraction;
}
Fraction Fraction::operator+(float other)
{
    // float + fraction need to add float to the fraction
    // so we need to convert the float (multiply the float by 1000 and save in int )to fraction and then gcd and the denominator is 1000
    int newother = other * 1000;
    Fraction newFraction(newother, 1000);
    Fraction newFraction2 = *this + newFraction;
    return newFraction2;
}
// the furmula is (a/b) - (c/d) = (a*d - b*c)/(b*d)
Fraction Fraction::operator-(const Fraction &other)
{
    int newNumeator = this->numeator * other.denominator - other.numeator * this->denominator;
    int newDenominator = this->denominator * other.denominator;
    Fraction newFraction(newNumeator, newDenominator);
    return newFraction;
}
Fraction Fraction::operator-(float other)
{
    int newother = other * 1000;
    Fraction newFraction(newother, 1000);
    Fraction newFraction2 = *this - newFraction;
    return newFraction2;
}
// the furmula is (a/b) * (c/d) = (a*c)/(b*d)
Fraction Fraction::operator*(const Fraction &other)
{
    int newNumeator = this->numeator * other.numeator;
    int newDenominator = this->denominator * other.denominator;
    Fraction newFraction(newNumeator, newDenominator);
    return newFraction;
}
Fraction Fraction::operator*(float other)
{
    int newother = other * 1000;
    Fraction newFraction(newother, 1000);
    Fraction newFraction2 = *this * newFraction;
    return newFraction2;
}
// the furmula is (a/b) / (c/d) = (a*d)/(b*c)
Fraction Fraction::operator/(const Fraction &other)
{
    int newNumeator = this->numeator * other.denominator;
    int newDenominator = this->denominator * other.numeator;
    Fraction newFraction(newNumeator, newDenominator);
    return newFraction;
}
Fraction Fraction::operator/(float other)
{
     int newother = other * 1000;
    Fraction newFraction(newother, 1000);
    Fraction newFraction2 = *this / newFraction;
    return newFraction2;
}
// the furmula is (a/b) += (c/d) = (a*d + b*c)/(b*d)
Fraction &Fraction::operator+=(const Fraction &other)
{
    int newNumeator = this->numeator * other.denominator + other.numeator * this->denominator;
    int newDenominator = this->denominator * other.denominator;
    this->numeator = newNumeator;
    this->denominator = newDenominator;
    reduce();
    return *this;
}
Fraction &Fraction::operator+=(float other)
{
    int newNumeator = this->numeator + other * this->denominator;
    int newDenominator = this->denominator;
    this->numeator = newNumeator;
    this->denominator = newDenominator;
    reduce();
    return *this;
}
Fraction &Fraction::operator-=(const Fraction &other)
{
    int newNumeator = this->numeator * other.denominator - other.numeator * this->denominator;
    int newDenominator = this->denominator * other.denominator;
    this->numeator = newNumeator;
    this->denominator = newDenominator;
    reduce();
    return *this;
}
Fraction &Fraction::operator-=(float other)
{
    int newNumeator = this->numeator - other * this->denominator;
    int newDenominator = this->denominator;
    this->numeator = newNumeator;
    this->denominator = newDenominator;
    reduce();
    return *this;
}
Fraction &Fraction::operator*=(const Fraction &other)
{
    int newNumeator = this->numeator * other.numeator;
    int newDenominator = this->denominator * other.denominator;
    this->numeator = newNumeator;
    this->denominator = newDenominator;
    reduce();
    return *this;
}
Fraction &Fraction::operator*=(float other)
{
    int newNumeator = this->numeator * other;
    int newDenominator = this->denominator;
    this->numeator = newNumeator;
    this->denominator = newDenominator;
    reduce();
    return *this;
}
Fraction &Fraction::operator/=(const Fraction &other)
{
    int newNumeator = this->numeator * other.denominator;
    int newDenominator = this->denominator * other.numeator;
    this->numeator = newNumeator;
    this->denominator = newDenominator;
    reduce();
    return *this;
}
Fraction &Fraction::operator/=(float other)
{
    int newNumeator = this->numeator;
    int newDenominator = this->denominator * other;
    this->numeator = newNumeator;
    this->denominator = newDenominator;
    reduce();
    return *this;
}
Fraction &Fraction::operator++()
{
    this->numeator += this->denominator;
    return *this;
}
Fraction Fraction::operator++(int)
{
    Fraction temp = *this;
    ++*this;
    return temp;
}
Fraction &Fraction::operator--()
{
    this->numeator -= this->denominator;
    return *this;
}
Fraction Fraction::operator--(int)
{
    Fraction temp = *this;
    --*this;
    return temp;
}
bool Fraction::operator==(const Fraction &other)
{
    return this->numeator == other.numeator && this->denominator == other.denominator;
}
bool Fraction::operator==(float other)
{
    return this->numeator == other * this->denominator;
}
bool Fraction::operator!=(const Fraction &other)
{
    return !(*this == other);
}
bool Fraction::operator!=(float other)
{
    return !(*this == other);
}
bool Fraction::operator>(const Fraction &other)
{
    return this->numeator * other.denominator > other.numeator * this->denominator;
}
bool Fraction::operator>(float other)
{
    return this->numeator > other * this->denominator;
}
bool Fraction::operator<(const Fraction &other)
{
    return this->numeator * other.denominator < other.numeator * this->denominator;
}
bool Fraction::operator<(float other)
{
    return this->numeator < other * this->denominator;
}
bool Fraction::operator>=(const Fraction &other)
{
    return *this > other || *this == other;
}
bool Fraction::operator>=(float other)
{
    return *this > other || *this == other;
}
bool Fraction::operator<=(const Fraction &other)
{
    return *this < other || *this == other;
}
bool Fraction::operator<=(float other)
{
    return *this < other || *this == other;
}

ostream &ariel::operator<<(ostream &out, const Fraction &fraction) // not working without ariel::
{
    out << fraction.numeator << "/" << fraction.denominator;
    return out;
}
istream &ariel::operator>>(istream &in, Fraction &fraction) // not working without ariel::
{
    in >> fraction.numeator >> fraction.denominator;
    return in;
}

float ariel::operator+(float other, const Fraction &fraction) // not working without ariel::
{
    return other + fraction.numeator / fraction.denominator;
}
float ariel::operator-(float other, const Fraction &fraction) // not working without ariel::
{
    return other - fraction.numeator / fraction.denominator;
}
float ariel::operator*(float other, const Fraction &fraction)
{
    return other * fraction.numeator / fraction.denominator;
}
float ariel::operator/(float other, const Fraction &fraction)
{
    return other / fraction.numeator * fraction.denominator;
}
