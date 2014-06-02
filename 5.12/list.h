#pragma once
#include <iostream>

using namespace std;

class List
{
private:
	struct Element
	{
		int data;
		Element * next;
		Element * prev;
	};

	int size;
	Element * head;
	Element * tail;

	List & operator=( const List & l )
	{
	}

	List ( const List & l )
	{
	}

public:
	class iterator; 

	iterator begin();
	iterator end();
    iterator insert( iterator position, const int & x );
	iterator erase( iterator position );

	List() : size(0)
	{
		head = new Element;
		tail = new Element;
		head->prev = tail->next = NULL;
		tail->prev = head;
		head->next = tail;
	}

	void push_front( const int & x )
	{
		Element * e = new Element;
		e->data = x;
		e->prev = head;
		e->next = head->next;
		e->next->prev = e;
		head->next = e;
		size++;
	}

	void push_back( const int & x )
	{
		Element * e = new Element;
		e->data = x;
		e->next = tail;
		e->prev = tail->prev;
		e->prev->next = e;
		tail->prev = e;
		size++;
	}

	void pop_front()
	{
		if (head->next == tail)
			return;
		Element * e = head;
		head = head->next;
		head->prev = NULL;
		delete e;
		size--;
	}

	void pop_back()
	{
		if (tail->prev == head)
			return;
		Element * e = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete e;
		size--;
	}

	int & front()
	{
		if (head->next != tail)
			return head->next->data;
	}

	int &back()
	{
		if (tail->prev != head)
			return tail->prev->data;
	}

	bool empty()
	{
		return size ? false : true;
	}

	int get_size()
	{
		return size;
	}

	void clear()
	{
		while (!empty())
			pop_front();
	}

	~List()
	{
		clear();
		delete head;
		delete tail;
	}

	void print()
	{
		Element * e = head->next;
		while (e != tail)
		{
			cout << e->data << " ";
			e = e->next;
		}
		cout << endl;
	}

	void reverse()
	{
		Element * e = head;
		while (e != NULL)
		{
			swap(e->next, e->prev);
			e = e->prev;
		}
		swap(tail, head);
	}
};

class List::iterator
{
	friend class List;

	Element * e;

	iterator( Element * _e ) : e(_e)
	{
	}
public:
	iterator() : e(0)
	{
	}
	
	bool operator==(const iterator &it) const;
	bool operator!=(const iterator &it) const;
	iterator operator++();
	iterator operator--();
	int & operator*() const;
	Element * operator->() const;	
};