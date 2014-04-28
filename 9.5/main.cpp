#include <map>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void main()
{
	map<int, string> m;

	ifstream file("dict.txt");

	int x;
	int oldx;
	string s;

	file >> x >> s;
	oldx = -1;
	while (oldx != x)
	{
		m[x] = s;
		oldx = x;
		file >> x >> s;		
	}

	cin >> x;

	while (x)
	{
		if (!m[x].empty())
		    cout << m[x] << " ";
		cin >> x;
	}
	cout << endl;
 
	file.close();
}