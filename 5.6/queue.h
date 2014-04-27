#pragma once

const int Max = 150;	

class Queue
{
	int a[Max];
	int first;
	int next;
	int size;
	
public:
	Queue() : first(0), next(0), size(0)
	{
	}

	bool empty();
	bool full();
	int get_size();
	int front();
	void push( int x );
	void pop();
};