#pragma once 

#include "shape.h"

class rectangle : public shape
{
	double a, b;
public:
	rectangle( double _a, double _b ) : a(_a), b(_b)
	{
	}
	double area()
	{
		return  a * b;
	}
};