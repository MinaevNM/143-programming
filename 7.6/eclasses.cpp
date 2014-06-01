#include <iostream>
#include <cmath>

#include "eclasses.h"

using namespace std;

void Const::print()
{
	cout << c;
}

double Const::evaluate( double x )
{
	return c;
}

Expression * Const::derivative()
{
	return new Const(0);
}

Expression * Const::copy()
{
	return new Const(c);
}

void Var::print()
{
	cout << "x";
}

double Var::evaluate( double x )
{
	return x;
}

Expression * Var::derivative()
{
	return new Const(1);
}

Expression * Var::copy()
{
    return new Var;
}

void Sum::print()
{
	cout << "(";
	add1->print();
	cout << " + ";
	add2->print();
	cout << ")";
}

double Sum::evaluate( double x )
{
	return add1->evaluate(x) + add2->evaluate(x);
}

Expression * Sum::derivative()
{
	return new Sum(add1->derivative(), add2->derivative());
}

Expression * Sum::copy()
{
	return new Sum(add1->copy(), add2->copy());
}

void Mult::print()
{
	cout << "(";
	mult1->print();
	cout << " * ";
	mult2->print();
	cout << ")";
}

double Mult::evaluate( double x )
{
	return mult1->evaluate(x) * mult2->evaluate(x);
}

Expression * Mult::derivative()
{
	return new Sum(new Mult(mult1->derivative(), mult2->copy()),
		new Mult(mult2->derivative(), mult1->copy()));
}

Expression * Mult::copy()
{
	return new Mult(mult1->copy(), mult2->copy());
}

void Sin::print()
{
	cout << "sin(";
	arg->print();
	cout << ")";
}

double Sin::evaluate( double x )
{
	return sin(arg->evaluate(x));
}

Expression * Sin::derivative()
{
	return new Mult(new Cos(arg->copy()), arg->derivative());
}

Expression * Sin::copy()
{
	return new Sin(arg->copy());
}

void Cos::print()
{
	cout << "cos(";
	arg->print();
	cout << ")";
}

double Cos::evaluate( double x )
{
	return cos(arg->evaluate(x));
}

Expression * Cos::derivative()
{
	return new Mult(new Neg(new Sin(arg->copy())), arg->derivative());
}

Expression * Cos::copy()
{
	return new Cos(arg->copy());
}

void Neg::print()
{
	cout << "-(";
	arg->print();
	cout << ")";
}

double Neg::evaluate( double x )
{
	return -arg->evaluate(x);
}

Expression * Neg::derivative()
{
	return new Neg(arg->derivative());
}

Expression * Neg::copy()
{
	return new Neg(arg->copy());
}

void Divide::print()
{
	cout << "(";
	div->print();
	cout << " / ";
	divisor->print();
	cout << ")";
}

double Divide::evaluate( double x )
{
	if (abs(divisor->evaluate(x)) < 1e-5)
		return div->evaluate(x) / (divisor->evaluate(x) + 1e-2);
	return div->evaluate(x) / divisor->evaluate(x);
}

Expression * Divide::copy()
{
	return new Divide(div->copy(), divisor->copy());
}

Expression * Divide::derivative()
{
	return new Divide(new Substract(new Mult(div->derivative(), divisor->copy()),new Mult(div->copy(),divisor->derivative())),new Mult(div->copy(),divisor->copy()));
}


void Substract::print()
{
	cout << "(";
	minuend->print();
	cout << " - ";
	subtr->print();
	cout << ")";
}

double Substract::evaluate( double x )
{
	return minuend->evaluate(x) - subtr->evaluate(x);
}

Expression * Substract::derivative()
{
	return new Substract(minuend->derivative(), subtr->derivative());
}

Expression * Substract::copy()
{
	return new Substract(minuend->copy(), subtr->copy());
}