#include "list.h"

List::iterator List::begin()
{
	return iterator(head->next);
}

List::iterator List::end()
{
	return iterator(tail);
}

List::iterator List::insert( List::iterator position, const int & x )
{
	Element * e = new Element;
	e->data = x;
	e->prev = position->prev;
	e->next = position.operator->();
	e->prev->next = e;
	e->next->prev = e;
	size++;
	return iterator(e);
}

List::iterator List::erase( List::iterator position )
{
	Element * e = position.operator->();
	e->next->prev = e->prev;
	e->prev->next = e->next;
	position = iterator(e);
	++position;
	size--;
	delete e;
	return position;
}

bool List::iterator::operator==( const List::iterator &it ) const
{
	if (e == it.e)
		return true;
	return false;
}

bool List::iterator::operator!=( const List::iterator &it ) const
{
	if (e != it.e)
		return true;
	return false;
}	

List::iterator List::iterator::operator++()
{   
	if (e->next != NULL)
		e = e->next;
	iterator i(e);
	return i;
}

List::iterator List::iterator::operator--()
{   
	if (e->prev != NULL)
		e = e->prev;
	iterator i(e);
	return i;
}

int & List::iterator::operator*() const 
{
	return e->data;
}

List::Element * List::iterator::operator->() const 
{
	return e;
}

