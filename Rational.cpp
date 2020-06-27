//
// Created by Iza on 27/06/2020.
//

#include "Rational.h"

Rational::Rational(int numerator, int denominator) {
    int g = calculateGcdND(numerator, denominator);
    this->gcdND = g;
    this->numer = numerator / g;
    this->denom = denominator / g;
    if (this->denom < 0) { this->denom = -this->denom; this->numer = -this->numer; }
}

Rational::Rational(const Rational &copy) {
    this->gcdND = copy.gcdND;
    this->numer = copy.numer;
    this->denom = copy.denom;
}

int Rational::calculateGcdND(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return calculateGcdND(b, a % b);
    }
}

Rational Rational::reciprocal() const {
    return Rational(this->denom, this->numer);
}

Rational Rational::negate() const {
    return Rational(-this->numer, this->denom);
}

Rational Rational::operator+(const Rational &other) const {
    int numerator = (this->numer * other.denom) + (this->denom * other.numer);
    int denominator = this->denom * other.denom;

    return Rational(numerator, denominator);
}

Rational Rational::operator-(const Rational &other) const {
    return Rational(this->operator+(other.negate()));
}

Rational Rational::operator*(const Rational &other) const {
    return Rational(this->numer * other.numer, this->denom * other.denom);
}

Rational Rational::operator/(const Rational &other) const {
    const Rational &rational = other.reciprocal();
    return Rational(this->operator*(rational));
}


std::ostream &operator<<(std::ostream& out, const Rational& r) {
    out << r.numerator() << '/' << r.denominator();
    return out;
}

Rational operator+(const Rational &r, int i) {
    return r + Rational(i, 1);
}

Rational operator+(int i, const Rational &r) {
    return Rational(i, 1) + r;
}

Rational operator-(const Rational &r, int i) {
    return r - Rational(i, 1);
}

Rational operator-(int i, const Rational &r) {
    return Rational(i, 1) - r;
}

Rational operator*(const Rational &r, int i) {
    return r * Rational(i, 1);
}

Rational operator*(int i, const Rational &r) {
    return Rational(i, 1) * r;
}

Rational operator/(const Rational &r, int i) {
    return r / Rational(i, 1);
}

Rational operator/(int i, const Rational &r) {
    return Rational(i, 1) / r;
}
