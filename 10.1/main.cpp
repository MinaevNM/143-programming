#include <iostream>

using namespace std;

void main()
{
	int n;
	int * a;
	int * d;

	cin >> n;
	a = new int[n];
	d = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	memset(d, 0, n * sizeof(int));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[j] < a[i])
				d[i] = max(d[i], d[j] + 1);

	int dmax = d[0];
	int nmax = 0;
	for (int i = 1; i < n; i++)
		if (d[i] > dmax)
		{
			dmax = d[i];
			nmax = i;
		}

	cout << dmax + 1 << endl;
	int * seq = new int[dmax + 1];
	for (int i = dmax; i >= 0; i--)
	{
		seq[i] = a[nmax];
		for (int j = nmax; j >= 0; j--)
			if (d[j] == d[nmax] - 1)
			{
				nmax = j;
				break;
			}
	}
	
	for (int i = 0; i < dmax + 1; i++)
		cout << seq[i] << " ";

	delete a;
	delete d;
	delete seq;
}
