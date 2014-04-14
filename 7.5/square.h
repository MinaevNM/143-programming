#pragma once

#include "shape.h"

class square: public shape
{
	double a;	
public:
	square( double _a ) : a(_a)
	{
	}
	double area()
	{
		return a * a;
	}
};