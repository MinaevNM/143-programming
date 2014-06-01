#include <iostream>
#include <set>

using namespace std;

void main()
{
	int N, M;

	cin >> N >> M;

	int * timetable = new int[N];
	memset(timetable, 0, N * sizeof(int));
	set<pair<int, pair<int, int>>> s;

	for (int i = 0; i < M; i++)
	{
		int t, c;
		cin >> t >> c;

		s.insert(make_pair(-c, make_pair(t, i + 1)));		
	}

	int max = 0;
	for (set<pair<int, pair<int, int>>>::iterator it = s.begin(); it != s.end(); it++)
		for (int i = it->second.first - 1; i >= 0; i--)
			if (timetable[i] == 0)
			{
				timetable[i] = it->second.second;
				max += it->first;
				break;
			}

	cout << -max << endl;
	for (int i = 0; i < N; i++)
		cout << timetable[i] <<  " ";
	cout << endl;
}