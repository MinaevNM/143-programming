#include <iostream>
#include <cmath>
#pragma once

using namespace std;

class Fraction
{
public:
    Fraction() :
        mNumerator(0),
        mDenominator(1)
    {}
    Fraction(int value) :
        mNumerator(value),
        mDenominator(1)
    {}
    Fraction(int numerator, int denominator) :
        mNumerator(numerator)
    {
        if (denominator < 0)
            mNumerator = - numerator;
        mDenominator = abs(denominator);
        reduction();
    }

    friend bool operator <(const Fraction &first, const Fraction &second);
    friend bool operator >(const Fraction &first, const Fraction &second);
    friend bool operator ==(const Fraction &first, const Fraction &second);
    friend bool operator !=(const Fraction &first, const Fraction &second);

    friend ostream &operator <<(ostream &stream, const Fraction &frac);
    friend istream &operator >>(istream &stream, Fraction &frac);

    friend Fraction operator +(const Fraction &first, const Fraction &second);
    friend Fraction operator -(const Fraction &first, const Fraction &second);
    friend Fraction operator *(const Fraction &first, const Fraction &second);
    friend Fraction operator /(const Fraction &first, const Fraction &second);

    Fraction operator +=(const Fraction &anything);
    Fraction operator -=(const Fraction &anything);
    Fraction operator *=(const Fraction &anything);
    Fraction operator /=(const Fraction &anything);

//private:
    int mNumerator;
    unsigned mDenominator;

    void reduction();
};

Fraction fracAbso(const Fraction &anything);
