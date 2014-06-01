#include "fraq.h"

fraq abs( fraq f )
{
	return f.f_abs();
}

istream & operator>>( istream & stream, fraq & p ) 
{ 
	int x;
    stream >> x;
	p = fraq(x);
    return stream; 
}

ostream & operator<<( ostream & stream, const fraq & p ) 
{
	stream << p.p << "/" << p.q; 
	return stream; 
} 