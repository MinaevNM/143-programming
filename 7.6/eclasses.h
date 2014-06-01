#pragma once

#include "expression.h"

class Var : public Expression
{
public:
	~Var()
	{
	}
	void print();
	double evaluate( double x );
	Expression * derivative();
	Expression * copy(); 
};

class Const : public Expression
{
	double c;
public:
	Const( double _c ) : c(_c)
	{
	}
	~Const()
	{
	}
	void print();
	double evaluate( double x );
	Expression * derivative();
	Expression * copy();
};

class Sum : public Expression
{
	Expression * add1;
	Expression * add2;

public :
	Sum( Expression * _add1, Expression * _add2 ) : add1(_add1), add2(_add2)
	{
	}
	~Sum()
	{
		delete add1;
		delete add2;
	}
	void print();
	double evaluate( double x );
	Expression * derivative();
	Expression * copy();
};

class Mult : public Expression
{
	Expression * mult1;
	Expression * mult2;

public :
	Mult( Expression * _mult1, Expression * _mult2 ) : mult1(_mult1), mult2(_mult2)
	{
	}
	~Mult()
	{
		delete mult1;
		delete mult2;
	}
	void print();
	double evaluate( double x );
	Expression * derivative();
	Expression * copy();
};

class Sin : public Expression
{
	Expression * arg;
	
public :
	Sin( Expression * _arg ) : arg(_arg)
	{
	}
	~Sin()
	{
		delete arg;
	}
	void print();
	double evaluate( double x );
	Expression * derivative();
	Expression * copy();
};

class Cos : public Expression
{
	Expression * arg;
	
public :
	Cos( Expression * _arg ) : arg(_arg)
	{
	}
	~Cos()
	{
		delete arg;
	}
	void print();
	double evaluate( double x );
	Expression * derivative();
	Expression * copy();
};

class Neg : public Expression
{
	Expression * arg;

public:
	Neg( Expression * _arg ) : arg(_arg)
	{
	}
	~Neg()
	{
		delete arg;
	}

	void print();
	double evaluate( double x );
	Expression * derivative();
	Expression * copy();
};

class Divide : public Expression
{
	Expression * div;
	Expression * divisor;

public:
	Divide( Expression * _div, Expression * _divisor ) : div(_div), divisor(_divisor)
	{
	}
	~Divide()
	{
		delete div;
		delete divisor;
	}

	void print();
	double evaluate( double x );
	Expression * copy();
	Expression * derivative();
};

class Substract : public Expression
{
	Expression * minuend;
	Expression * subtr;

public:
	Substract( Expression * _minuend, Expression * _subtr ) : minuend(_minuend), subtr(_subtr)
	{
	}
	~Substract()
	{
		delete minuend;
		delete subtr;
	}
	void print();
	double evaluate( double x );
	Expression * derivative();
	Expression * copy();
};