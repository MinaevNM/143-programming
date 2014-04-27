#pragma once
#pragma warning(disable: 4996)

#include <vector>

const int m = 149;
const int length = 9;

using namespace std;

class HashTable
{
public:
	vector<int> v;
	vector<int> a;
	vector<char *> s;

	HashTable()
	{
		v = vector<int>(m);
		s = vector<char *>(m);
		a = vector<int>(length);

		for (int i = 0; i < length; i++)
			a[i] = rand() % m;	
		for (int i = 0; i < m; i++)
			s[i] = new char[length];
    }

	void add( char * _s )
	{
		int h = 0;

		for (int i = 0; i < length; i++)
			h += a[i] * _s[i];
		h %= m;
		v[h]++;
		strcpy(s[h], _s);
	}
};