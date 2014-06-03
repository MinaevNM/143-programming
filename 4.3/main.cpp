#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
int separate( T * a, int begin, int end )
{
	T x = a[rand() % (end - begin) + begin];
    int i = begin;
	int j = end;
	while (true)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i < j)
		{
			swap(a[i], a[j]);
			if (a[i] == x && a[j] == x)
				i++;
		}
		else
			return i;
	}
}

template <class T>
void quick_recurs( T * a, int begin, int end )
{
    if (begin < end)
	{
		int separator = separate(a, begin, end);
		quick_recurs(a, begin, separator - 1);
		quick_recurs(a, separator + 1, end);
	}
}

template <class T>
void quick( T * a, int n )
{
	quick_recurs(a, 0, n - 1);
}

void main()
{
	int n;
	int * a, * b;
	cin >> n;
	a = new int[n];
	b = new int[n];
	
	for (int i = 0; i < n; i++)
		a[i] = b[i] = rand();
	
	quick(a, n);
	sort(b, b + n);

	for (int i = 0; i < n-1; i++)
		if (a[i] != b[i])
		{
			cout << "Wrong";
			delete [] a;
			delete [] b;
			return;
		}
	cout << "Correct";
	delete [] a;
	delete [] b;
}