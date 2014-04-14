#pragma once

#include <cmath>
#include "shape.h"


class triangle : public shape
{
	double a, b, c;

public:
	triangle( double _a, double _b, double _c ) : a(_a), b(_b), c(_c)
	{
	}

	double area()
	{
		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
};