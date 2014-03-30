#include <iostream>

#include "class2.h"

using namespace std;

double min3( double x, double y, double z )
{
	return min(x, min(y, z));
}

B::B( double p1, double p2, double p3 ) : A(p1, p2)
{
	A::addX(p3);
	c = min3(p1, p2, p3);
}

double B::addX( double x )
{
	if (x >= c)
	{
		double t = c;
		c = A::addX(x);
		return t;
	}
	else
	    return x;
}
	
void B::print()
{
	A::print();
	cout << ", c = " << c << endl; 
}
