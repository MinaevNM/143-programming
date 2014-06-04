#include <iostream>

#include "BSTree.h"


Tree::Node * BSTree::insert_recurs( int x, Tree::Node * n )
{
	Node * e = new Node();
	e->Left = e->Right = NULL;
	e->data = x;
	e->height = 0;

	if (x > n->data)
	{
		if (n->Right != NULL)
     		e = insert_recurs(x, n->Right);
		else
		{
			e->Anc = n;
			n->Right = e;
			return e;
		}
	}
	else if (x < n->data)
	{
		if (n->Left != NULL)
			e = insert_recurs(x, n->Left);
    	else
		{
			e->Anc = n;
			n->Left = e;
			return e;
		}
	}
	else 
	    return NULL;

	return e;
}

void BSTree::insert( int x )
{
	if (!is_init)
	{
		Root->data = x;
		is_init = true;
		return;
	}
	Tree::Node * e;
	if ((e = insert_recurs(x, Root)) != NULL)
		recount_height(e->Anc);
}

void BSTree::remove( Tree::Node * p )
{
	if (p == NULL)
		return;
	if (p->Left == NULL && p->Right == NULL)
	{
		if (p == Root)
		{
			is_init = false;
			return;
		}
		if (p == p->Anc->Left)
			p->Anc->Left = NULL;
		else
			p->Anc->Right = NULL;
		recount_height(p->Anc);
		delete p;
		return;
	}
	if (p->Left == NULL && p->Right != NULL)
	{
		if (p == Root)
		{
			Root = p->Right;
			Root->Anc = NULL;
			delete p;
			return;
		}
		if (p->Anc->Right == p)
			p->Anc->Right = p->Right;
		else
			p->Anc->Left = p->Right;
		p->Right->Anc = p->Anc;
		recount_height(p->Anc);
		delete p;
		return;
	}

	if (p->Right == NULL && p->Left != NULL)
	{
		if (p == Root)
		{
			Root = p->Left;
			Root->Anc = NULL;
			delete p;
			return;
		}
		if (p->Anc->Right == p)
			p->Anc->Right = p->Left;
		else
			p->Anc->Left = p->Left;
		p->Left->Anc = p->Anc;
		recount_height(p->Anc);
		delete p;
		return;
	}

	Node * n = successor(p);
	p->data = n->data;
	if (n->Anc->Left == n)
		n->Anc->Left = n->Right;
	if (n->Anc->Right == n)
		n->Anc->Right = n->Right;
	if (n->Right != NULL)
		n->Right->Anc = n->Anc;
	recount_height(n->Anc);
	delete n;
}
