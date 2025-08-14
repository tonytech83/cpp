// #include <iostream>
#pragma once
#include <sstream>
#include <string>
using namespace std;

class Fraction {
    int numerator;
    int denominator;

public:
    Fraction() : numerator(0), denominator(0) {} // Default constructor

    Fraction(const int num, const int denom) : numerator(num), denominator(denom) {}

    [[nodiscard]] int getNumerator() const { return this->numerator; }

    [[nodiscard]] int getDenominator() const { return this->denominator; }

    auto operator<(const Fraction &other) const {
        return this->numerator * other.denominator < other.numerator * this->denominator;
    }

    auto operator==(const Fraction &other) const -> bool {
        // Fraction a = this->reduce();
        // Fraction b = other.reduce();
        return this->numerator == other.numerator && this->denominator == other.denominator;
    }

    auto operator+(const Fraction &other) const -> Fraction {
        return {this->numerator + other.numerator, this->denominator + other.denominator};
    }

    auto operator-(const Fraction &other) const -> Fraction {
        return {this->numerator - other.numerator, this->denominator - other.denominator};
    }

    auto reduce() -> void {
        const int n = this->numerator > this->denominator ? this->numerator : this->denominator;

        for (int i(n); i >= 1; i--) {
            if (this->numerator % i == 0 && this->denominator % i == 0) {
                this->numerator /= i;
                this->denominator /= i;
                return;
            }
        }
    }

    [[nodiscard]] auto getFraction() const -> string {
        ostringstream oss;
        oss << this->getNumerator() << "/" << this->getDenominator();
        return oss.str();
    }

    // Prefix ++
    Fraction &operator++() {
        ++numerator;
        ++denominator;
        return *this;
    }

    // Postfix ++
    Fraction operator++(int) {
        const Fraction temp = *this;
        numerator++;
        denominator++;
        return temp;
    }
};

inline ostream &operator<<(ostream &os, const Fraction &frac) {
    os << frac.getNumerator() << "/" << frac.getDenominator();
    return os;
}

inline istream &operator>>(istream &is, Fraction &frac) {
    int nom, denom;
    is >> nom >> denom;
    frac = Fraction(nom, denom);
    return is;
}
