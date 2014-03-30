#include <iostream>

#include "class1.h"

using namespace std;

A::A( double p1, double p2 )
{
	a = max(p1, p2);
	b = min(p1, p2);
}

double A::addX( double x )
{
	if (a >= x && b < x)
		swap(b, x);
	else if (a < x)
	{
		swap(a, x);
		swap(b, x);
	}
	return x;

}
	
void A::print()
{
	cout << "a = " << a << ", b = " << b; 
}
