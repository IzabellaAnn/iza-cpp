//
// Created by Iza on 27/06/2020.
//

#ifndef IZA_CPP_RATIONAL_H
#define IZA_CPP_RATIONAL_H


#include <istream>

class Rational
{
public:
    explicit Rational(int numerator, int denominator = 1);
    ~Rational() = default;
    Rational(const Rational& copy);

    int numerator() const { return numer; }
    int denominator() const { return denom; }

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

private:
    int numer;
    int denom;
    int gcdND;

    int calculateGcdND(int a, int b);

    friend std::ostream& operator<<(std::ostream &, const Rational &);

    Rational reciprocal() const;

    Rational negate() const;
};

Rational operator+(const Rational& r, int i);
Rational operator+(int i, const Rational& r);

Rational operator-(const Rational& r, int i);
Rational operator-(int i, const Rational& r);

Rational operator*(const Rational& r, int i);
Rational operator*(int i, const Rational& r);

Rational operator/(const Rational& r, int i);
Rational operator/(int i, const Rational& r);


#endif //IZA_CPP_RATIONAL_H
