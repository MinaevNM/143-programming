#pragma once
#pragma warning(disable: 4996)

#include <vector>
#include <list>

const int m = 149;
const int length = 9;

using namespace std;

class HashTable
{
public:
	vector<int> a;
	vector<list<pair<char *, int>>> s;

	HashTable()
	{
		s = vector<list<pair<char *, int>>>(m);
		a = vector<int>(length);

		for (int i = 0; i < length; i++)
			a[i] = rand() % m;	
	}

	void add( char * _s )
	{
		int h = 0;

		for (int i = 0; i < length; i++)
			h += a[i] * _s[i];
		h %= m;

		bool flag = true;
		for (list<pair<char *, int>>::iterator it = s[h].begin(); it != s[h].end(); it++)
			if (!strcmp(it->first, _s))
			{
				flag = false;
				it->second++;
				break;
			}
		if (flag)
		{
			pair<char *, int> p;
			p.first = new char[length];
			strcpy(p.first, _s);
			p.second = 1;
			s[h].push_back(p);
		}
	}
};