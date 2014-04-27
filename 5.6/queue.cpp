#include "queue.h"

bool Queue::empty()
{
	if (size == 0)
		return true;
	return false;
}

bool Queue::full()
{
	if (size == Max)
		return true;
	return false;
}

int Queue::get_size()
{
	return size;
}

int Queue::front()
{
    return a[first];
}

void Queue::push( int x )
{
	if (full())
		return;

    a[next] = x;
    if(next + 1 < Max)
        next++;
    else
	    next = 0;

	size++;
}

void Queue::pop()
{
    if(empty())
		return;

	if(first + 1 < Max)
        first++;
    else
        first = 0;

	size--;
}