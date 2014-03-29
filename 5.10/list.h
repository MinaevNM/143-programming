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
	List() : size(0), head(NULL), tail(NULL)
	{
	}

	void push_front( const int & x )
	{
		Element * e = new Element;
		e->data = x;
		e->prev = NULL;
		if (head == NULL)
		{
			e->next = NULL;
			tail = head = e;
		}
		else
		{
			e->next = head;
			head->prev = e;
			head = e;
		}
		size++;
	}

	void push_back( const int & x )
	{
		Element * e = new Element;
		e->data = x;
		e->next = NULL;
		if (tail == NULL)
		{
			e->prev = NULL;
			tail = head = e;
		}
		else
		{
			e->prev = tail;
			tail->next = e;
			tail = e;
		}
		size++;
	}

	void pop_front()
	{
		if (head == NULL)
			return;
		Element * e = head;
		if (size == 1)
		{
			tail = head = NULL;
			delete e;
			size--;
			return;
		}
		head = head->next;
		delete e;
		if (head != NULL)
		    head->prev = NULL;
		size--;
	}

	void pop_back()
	{
		if (tail == NULL)
			return;
		Element * e = tail;
		if (size == 1)
		{
			tail = head = NULL;
		    delete e;
			size--;
			return;
		}
		tail = tail->prev;
		delete e;
		if (tail != NULL)
		    tail->next = NULL;
		size--;
	}

	int & front()
	{
		return head->data;
	}

	int &back()
	{
		return tail->data;
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
	}

	void print()
	{
		Element * e = head;
		while (e != NULL)
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
