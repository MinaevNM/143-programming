#pragma once
#include <cmath>
#include <iostream>

using namespace std;

class point
{
	double x, y;
public:
	point()
	{
	}

	point( int _x, int _y ) : x(_x), y(_y)
	{
	}

	friend bool operator<( const point & p1, const point & p2 );
	friend ostream & operator<<( ostream & stream, point & p );
	friend istream & operator>>( istream & stream, point & p );
};