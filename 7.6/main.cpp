#include <iostream>

#include "eclasses.h"

using namespace std;

int Expression::count = 0;

void main()
{
	Expression::show_count();
    Expression * v = new Var;
    Expression * c = new Const(2);
    Expression * m = new Mult(c->copy(), v->copy());
    Expression * c2 = new Const(7);
    Expression * s = new Sum(v->copy(), c2->copy());
    Expression * si = new Sin(s->copy());
    Expression * co = new Cos(m->copy());
    Expression * e;

    si->print();
    cout << endl;
    cout << si->evaluate(9);
    cout << endl;

    co->print();
    e = co->derivative();
    cout << endl;
    e->print();
    cout << endl;
    cout << e->evaluate(2);
    cout << endl;

    Expression::show_count();

    delete co;
    delete si;
    delete v;
    delete c;
    delete m;
    delete c2;
    delete s;
    delete e;

    Expression::show_count();
}