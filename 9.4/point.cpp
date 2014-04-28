#include "point.h"

using namespace std;

ostream & operator<<( ostream & stream, point & p )
{
	cout << "(" << p.x << "; " << p.y << ")";
	return stream;
}

istream & operator>>( istream & stream, point & p )
{
	cin >> p.x >> p.y;
	return stream;
}

bool operator<( const point & p1, const point & p2 )   
{
    if (p1.x < p2.x || (abs(p1.x - p2.x) < 1e-5 &&	p1.y < p2.y))
        return true;
	return false;
}