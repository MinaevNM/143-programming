#include <cmath>
#include "fraction.h"

int NOD(int first, int second)
{
    if (!(first * second))
        return max(first, second);
    while (first != second)
    {
        if (first > second)
            first -= second;
        else
            second -= first;
    }
    return first;
}

Fraction fracAbso(const Fraction &anything)
{
    return (anything > 0)? anything : anything * (-1);
}

void Fraction::reduction()
{
	int myNod = NOD(abs(mNumerator), mDenominator);

    mNumerator /= myNod;
    mDenominator /= myNod;
}

bool operator <(const Fraction &first, const Fraction &second)
{
    return (first - second).mNumerator < 0;
}

bool operator >(const Fraction &first, const Fraction &second)
{
    return second < first;
}

bool operator ==(const Fraction &first, const Fraction &second)
{
    return !(first < second) && !(second < first);
}

bool operator !=(const Fraction &first, const Fraction &second)
{
    return !(first == second);
}
/*
istream &operator >>(istream &stream, Fraction &frac)
{
    double value = 0;
    stream >> value;
    frac = Fraction(value);
    return stream;
}
*/
ostream &operator <<(ostream &stream, const Fraction &frac)
{
    stream << frac.mNumerator;
    if (frac.mDenominator != 1)
        stream << "/" << frac.mDenominator;
    return stream;
}

Fraction operator +(const Fraction &first, const Fraction &second)
{
    int mNumerator = first.mNumerator * second.mDenominator + second.mNumerator * first.mDenominator;
    int mDenominator = first.mDenominator * second.mDenominator;
    return Fraction(mNumerator, mDenominator);
}

Fraction operator -(const Fraction &first, const Fraction &second)
{
    int mNumerator = first.mNumerator * second.mDenominator - second.mNumerator * first.mDenominator;
    int mDenominator = first.mDenominator * second.mDenominator;
    return Fraction(mNumerator, mDenominator);
}

Fraction operator *(const Fraction &first, const Fraction &second)
{
    int mNumerator = first.mNumerator * second.mNumerator;
    int mDenominator = first.mDenominator * second.mDenominator;
    return Fraction(mNumerator, mDenominator);
}

Fraction operator /(const Fraction &first, const Fraction &second)
{
    int mNumerator = first.mNumerator * second.mDenominator;
    int mDenominator = first.mDenominator * second.mNumerator;
    return Fraction(mNumerator, mDenominator);
}

Fraction Fraction::operator +=(const Fraction &anything)
{
    *this = *this + anything;
    return *this;
}

Fraction Fraction::operator -=(const Fraction &anything)
{
    *this = *this - anything;
    return *this;
}

Fraction Fraction::operator *=(const Fraction &anything)
{
    *this = *this * anything;
    return *this;
}

Fraction Fraction::operator /=(const Fraction &anything)
{
    *this = *this / anything;
    return *this;
}

