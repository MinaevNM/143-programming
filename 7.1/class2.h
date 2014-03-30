#pragma once

#include "class1.h"

class B: public A
{
	double c;
public:
	B( double p1, double p2, double p3 );
	double addX( double x );
	void print();
};
