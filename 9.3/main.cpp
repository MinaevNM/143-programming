#include <iostream>

#include "hash.h"

using namespace std;

void main()
{
	HashTable * h = new HashTable();

	freopen("tale.in", "rt", stdin);

	char s[length];
	char c;
	int pos = 0;
	bool word = true;
	bool flag = true;

	while (flag)
	{
		switch (c = getchar())
		{
		case 0:
			flag = false;
			break;
		case ' ':
		case '.': 
		case ',':
		case '\n':
			if (word)
			{
				for (int i = pos; i < length; i++)
					s[i] = 0;
				h->add(s);
				word = false;
				pos = 0;
			}
			break;
		default:
			if (c < 0 || c > 255)
			{
				for (int i = pos; i < length; i++)
					s[i] = 0;
				h->add(s);
				flag = false;
				break;
			}
			word = true;
			s[pos] = c;
			pos++;
			break;
		}
	}

	for (int i = 0; i < m; i++)
		for (list<pair<char *, int>>::iterator it = h->s[i].begin(); it != h->s[i].end(); it++)
			if (it->second)
				cout << it->first << " - " << it->second << endl;

	delete h;
}