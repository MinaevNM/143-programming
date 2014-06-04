#pragma once

#include "tree.h"

class BSTree : public Tree
{
public:
	BSTree()
	{
		is_init = false;
		Root = new Node();
		Root->Left = Root->Right = Root->Anc = NULL;
		Root->height = 0;
	}
	~BSTree()
	{
		while (is_init)
			remove(Root);
	}

	Node * insert_recurs( int x, Node * n );
	void insert( int x );
	void remove( Node * p );
private:
	BSTree & operator=( const BSTree & t );
	BSTree( const BSTree & t );
};