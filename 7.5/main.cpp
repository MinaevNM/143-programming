#include <iostream>

#include "triangle.h"
#include "square.h"
#include "rectangle.h"

using namespace std;

void bubble( shape ** s, int n )
{
	cout << "Sorting..." << endl;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (s[j + 1]->area() < s[j]->area())
				swap(s[j], s[j + 1]);
}

void main()
{
	shape ** s = new shape *[5];

	s[0] = new square(4.);
	s[1] = new rectangle(3., 5.);
	s[2] = new rectangle(2., 10.);
	s[3] = new triangle(1., 2., 2.5);
	s[4] = new triangle(10., 20., 25.);

	for (int i = 0; i < 5; i++)
		cout << "Area " << i + 1 << " = " << s[i]->area() << endl;
	bubble(s, 5);
	for (int i = 0; i < 5; i++)
		cout << "Area " << i + 1 << " = " << s[i]->area() << endl;

}