#include <set>
#include <iostream>

#include "point.h"

using namespace std;

template <class T>
set<T> set_intersect( set<T> s1, set<T> s2 )
{
	set<T> s;
	for (set<T>::iterator i = s1.begin(); i != s1.end(); i++)
	{
		set<T>::iterator _i = s2.find(*i);
		if (_i != s2.end())
			s.insert(*i);
	}

	return s;
}

template <class T>
set<T> set_union( set<T> s1, set<T> s2 )
{
	set<T> s;
	for (set<T>::iterator i = s1.begin(); i != s1.end(); i++)
		s.insert(*i);
	for (set<T>::iterator i = s2.begin(); i != s2.end(); i++)
		s.insert(*i);
	return s;
}

// Generating subset with specified number 
// Binary representation of number shows which elements should be 
// included
template <class T>
set<T> gen_subset( set<T> s, int number )
{
	set<T> subs;
	set<T>::iterator i = s.begin();

	while (number > 0)
	{
		if (number % 2)
			subs.insert(*i);
		number >>= 1;
		i++;
	}

	return subs;
}

template <class T>
set<set<T>> subset( set<T> s )
{
	int num = s.size();
	int num_subsets = 1 << num;
	set<set<T>> ssub;

	for (int i = 0; i < num_subsets; i++)
		ssub.insert(gen_subset(s, i));

	return ssub;
}

template <class T>
bool check_cl( set<set<T>> s )
{
	for (set<set<T>>::iterator i = s.begin(); i != s.end(); i++)
		for (set<set<T>>::iterator j = i; j != s.end(); j++)
			if (s.find(set_intersect(*i, *j)) == s.end() ||
				s.find(set_union(*i, *j)) == s.end())
				return false;
	return true;		
}

void main()
{
	set<int> s1;
	set<int> s2;
	s1.insert(1);
	s2.insert(2);
	set<set<int>> s;
	s.insert(s1);
	s.insert(s2);
	cout << check_cl(s) << endl;
	set<int> s3;
	s3.insert(1);
	s3.insert(2);
	s.insert(s3);
	cout << check_cl(s) << endl;
	set<int> s4;
	s.insert(s4);
	cout << check_cl(s) << endl << endl << endl;

	set<point> A;
	for (int i = 0; i < 5; i++)
	{
		point p;
		cin >> p;
		A.insert(p);
	}

	set<set<point>> B = subset(A);
	cout << "Set B is: " << endl;
	for (set<set<point>>::iterator i = B.begin(); i != B.end(); i++)
	{
		cout << "{";
		for (set<point>::iterator j = (*i).begin(); j != (*i).end(); j++)
			cout << *j << " ";
		cout << "}" << endl;
	}
	cout << "B is closed: " << check_cl(B) << endl;
}