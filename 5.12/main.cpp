#include <iostream>

#include "list.h"

using namespace std;

void main()
{
	List l;
	for (int i = 0; i < 5; i++)
	{
		l.push_front(rand() % 20);
		l.push_back(rand() % 20);
	}
	l.print();

	for (List::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";
	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		l.pop_back();
		l.pop_front();
	}

	cout << l.get_size() << endl;
	
	for (List::iterator it = --(l.end()); it != l.begin(); --it)
		cout << *it << " ";
	cout << *l.begin() << endl;

	int max = *(l.begin());
	for (List::iterator it = l.begin(); it != l.end(); ++it)
		if (*it > max)
			max = *it;
	cout << max << endl;
		
	for (List::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";
	cout << endl;

	for (List::iterator it = l.begin(); it != l.end(); ++it)
		if (*it % 2 == 0)
			l.insert(it, *it - 1);

	for (List::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";
	cout << endl;

	for (List::iterator it = l.begin(); it != l.end(); ++it)
		if (*it % 3 == 0)
		{
			it = l.erase(it);
			--it;
		}

	for (List::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";
	cout << endl;
}