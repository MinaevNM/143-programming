#pragma once

#pragma warning(disable: 4244)

#include <iostream>
using namespace std;

class fraq
{
public:
	int p, q;

	fraq() : p(0), q(1)
	{
	}

	fraq( int x ) : p(x), q(1)
	{
	}

	fraq( int x, int y ) : p(x), q(y)
	{
	}

	int getp()
	{
		return p;
	}

	int getq()
	{
		return q;
	}

	int gcd( int a, int b )
	{
		if (b == 0)
			return a;
		return gcd(b, a % b);

	}
	void toStandart()
	{
		int g = gcd(p, q);
		p /= g;
		q /= g;
	}

	fraq operator+( const fraq add )
	{
		fraq f = fraq(p * add.q + q * add.p, q * add.q);
		f.toStandart();
		return f;
	}

	fraq operator-( const fraq subst )
	{
		fraq f = fraq(p * subst.q - q * subst.p, q * subst.q);
		f.toStandart();
		return f;
	}

	fraq operator*( const fraq mult )
	{
		fraq f = fraq(p * mult.p, q * mult.q);
		f.toStandart();
		return f;
	}

	fraq operator/( const fraq div )
	{
		fraq f = fraq(p * div.q, q * div.p);
		f.toStandart();
		return f;
	}

	bool operator<( const fraq f )
	{
		int _p = (*this - f).p;
		int _q = (*this - f).q;
		if (_p * _q < 0)
			return true;
		return false;
	}
	bool operator==( fraq f )
	{
		this->toStandart();
		f.toStandart();
		if (p == f.p && q == f.q)
			return true;
		return false;		
	}

	bool operator!=( fraq f )
	{
		if (!(*this == f))
			return true;
		return false;
	}

	bool operator>( const fraq f )
	{
		if (!(*this < f) && !(*this == f))
			return true;
		return false;
	}

	bool operator>=( const fraq f )
	{
		if (*this == f || *this > f)
			return true;
		return false;
	}

	bool operator<=( const fraq f )
	{
		if (*this == f || *this < f)
			return true;
		return false;
	}

	void operator+=( const fraq f )
	{
		*this = *this + f;
		this->toStandart();
	}
	void operator-=( const fraq f )
	{
		*this = *this - f;
		this->toStandart();
	}
	void operator*=( const fraq f )
	{
		*this = *this * f;
		this->toStandart();
	}
	void operator/=( const fraq f )
	{
		if (f.p == 0)
			return;
		*this = *this / f;
		this->toStandart();
	}

	void print()
	{
		cout << p << "/" << q << endl;
	}
	fraq f_abs()
	{
		return fraq(abs(p), abs(q));
	}
	friend istream & operator>>( istream & stream, fraq & p );
	friend ostream & operator<<( ostream & stream, const fraq & p );
};



