#include <iostream>

#include "list.h"

using namespace std;

void main()
{
	// List methods testing
	/*
	List l;

    for (int i = 0; i < 5; i++)
	{
		l.push_front(i);
		cout << l.get_size() << endl;
		l.print();
	}
	
    for (int i = 0; i < 5; i++)
	{
		l.push_back(i);
		cout << l.get_size() << endl;
		l.print();
	}
	for (int i = 0; i < 5; i++)
	{
		l.pop_back();
		l.pop_front();
		cout << l.get_size() << endl;
		l.print();
	}
	l.clear();
	cout << l.get_size() << endl;
	l.print();
	l.reverse();
	l.print();*/
	/*
	List l;

	int x;
	cin >> x;
	while (x)
	{
		l.push_back(x);
		cin >> x;
	}

	long res = 0;
	while (!l.empty())
	{
		res +=  l.front() * l.back();
		l.pop_back();
		l.pop_front();
	}

	cout << res << endl;*/

	List l;
	l.push_front(2);
	l.pop_back();
	l.print();
	l.push_front(4);
	l.pop_back();
	l.print();
	l.push_back(2);
	l.pop_front();
	l.print();
}
