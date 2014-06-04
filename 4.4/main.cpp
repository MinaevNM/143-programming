#include <iostream>

using namespace std;

template <class T>
void rise_element( T * a, int n, int k )
{
	int left, right;
	bool fleft, fright;

	left = right = 0;
	fleft = fright = false;

	if (2 * k + 1 < n)
		left = a[2 * k + 1];
	else
		fleft = true;
	if (2 * k + 2 < n)	
		right = a[2 * k + 2];
	else
		fright = true;

	if (fleft && fright)
		return; 
	if (!fright && right > a[k])
		swap(a[2 * k + 2], a[k]);
	rise_element(a, n, 2 * k + 2);
	if (!fleft && left > a[k])
		swap(a[2 * k + 1], a[k]);
	rise_element(a, n, 2 * k + 1);
}

template <class T>
void add_to_heap( T * a, int n, int k )
{
	if (k == 0)
		return;
	if (a[k] > a[k / 2])
		swap(a[k], a[k / 2]);
	add_to_heap(a, n, k / 2);
}

template <class T>
void build_heap( T * a, int n )
{
    for (int i = 0; i < n; i++)
        add_to_heap(a, i + 1, i);
}

template <class T>
void heapsort( T * a, int n )
{
	build_heap(a, n);
	
	for (int i = 0; i < n - 1; i++)
	{
		swap(a[0], a[n - 1 - i]);
		rise_element(a, n - i - 1, 0);
	}
}

void main()
{
    int n;
	int * a;

    cin >> n;
	a = new int[n];

	for (int i = 0; i < n; i++)
		a[i] = rand();
    heapsort(a, n);

    for (int i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1])
		{
			cout << "Wrong";
			delete [] a;
			return;
		}
	cout << "Correct";
	delete [] a;
}