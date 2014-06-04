#pragma once

class Tree
{
	int size;
public:
	struct Node	
	{
		int data;
		Node * Left;
		Node * Right;
		Node * Anc;
		int height;
	};
	Node * Root;
protected:
	bool is_init;
public:
	Tree() : size(0)
	{
	}
	virtual ~Tree()
	{
	}

	virtual void insert( int x ) = 0;
	virtual void remove( Node * p ) = 0;
	
	int get_height( Node * p );
	void recount_height( Node * n );
	Node * findNode( Node * n, int x );
	Node * find( int x );
	Node * minimum( Node * p );
	Node * maximum( Node * p );
	Node * predecessor( const Node * p );
	Node * successor( const Node * p );
	void in_order_traversal();
	void pre_order_traversal();
	void post_order_traversal();
	void breadth_first_traversal();
private:
	Tree & operator=( const Tree & t );
	Tree( const Tree & t );
};