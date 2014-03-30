#include <iostream>
#include "class2.h"

using namespace std;

void main()
{
  A a(1, 5);
  a.print();
  cout << endl << a.addX(4) << endl;
  a.print();
  cout << endl << a.addX(2) << endl;
  a.print();
  cout << endl << a.addX(6) << endl;
  a.print();

  cout << endl << endl;
  B b(1, 2, 5);
  b.print();
  cout << b.addX(3) << endl;
  b.print();
  cout << b.addX(0) << endl;
  b.print();
  cout << b.addX(2.5) << endl;
  b.print();
}
