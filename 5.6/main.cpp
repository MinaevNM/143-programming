#include <iostream>

#include "queue.h"

using namespace std;

void print( Queue q )
{
	int size = q.get_size();
	for (int i = 0; i < size; i++)
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void main()
{
	Queue * q = new Queue();

	/* Testing Queue methods 
	for (int i = 0; i < 10; i++)
		q->push(i);
    print(*q);
	q->push(190);
	print(*q);
	q->pop();
	print(*q);
	q->pop();
	q->pop();
	print(*q);
	q->push(11);
	print(*q);
	q->push(12);
	q->push(13);
	print(*q);
	q->push(15);
	print(*q);
	delete q; */

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		q->push(i + 1);

	while (!q->empty())
	{
		for (int i = 1; i <= m - 1; i++)
		{
			int x = q->front();
			q->pop();
			q->push(x);
		}
		cout << q->front() << " ";
		q->pop();
	}

	delete q;
}
   
