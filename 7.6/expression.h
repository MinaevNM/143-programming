#pragma once

#include <iostream>

using namespace std;

class Expression
{
	static int count;
public:
	virtual void print() = 0;
	virtual double evaluate( double x ) = 0;
	virtual Expression * derivative() = 0;
	Expression()
	{
		count++;
	}
    static void show_count()
	{
		cout << "Count: " << count << endl;
	}
	virtual Expression * copy()= 0;
	virtual ~Expression()
	{
		count--;
	}
};



