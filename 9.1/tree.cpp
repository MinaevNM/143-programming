#include <iostream>
#include <queue>

#include "tree.h"

using namespace std;

int Tree::get_height( Node * p )
{
	if (p == NULL)
		return -1;
	return p->height;
}

int _max( int x, int y )
{
	if (x < y)
		return y;
	return x;
}

void Tree::recount_height( Node * n )
{
	Node * e = n;

	while (e != NULL)
	{
		int left = 0, right = 0;
		if (e->Left != NULL)
			left = e->Left->height;
		if (e->Right != NULL)
			right = e->Right->height;
		if (e->Left == NULL && e->Right == NULL)
			e->height = 0;
		else
			e->height = _max(left, right) + 1;
		e = e->Anc;
	}
}

Tree::Node * Tree::findNode( Tree::Node * n, int x )
{
	if (n == NULL)
		return NULL;
	if (n->data == x)
		return n;
	if (n->data > x)
		return findNode(n->Left, x);
	return findNode(n->Right, x);
}

Tree::Node * Tree::find( int x )
{
	return findNode(Root, x);
}

Tree::Node * Tree::minimum( Tree::Node * p )
{
	if (p == NULL)
		return NULL;
	Tree::Node * n = p;
	while (n->Left != NULL)
		n = n->Left;
	return n;
}

Tree::Node * Tree::maximum( Tree::Node * p )
{
	if (p == NULL)
		return NULL;
	Tree::Node * n = p;
	while (n->Right != NULL)
		n = n->Right;
	return n;
}

Tree::Node * Tree::predecessor( const Tree::Node * p )
{
	if (p == NULL)
		return NULL;
	if (p->Left == NULL)
	{
		if (p->Anc == NULL)
			return NULL;
		Node * n = new Node();
		Node * old = new Node();
		n = p->Anc;
		if (p->Anc->Left == p)
			old = p->Anc->Left;
		else
			old = p->Anc->Right;
		if (p->Anc->Anc == NULL)
			return n;
		while (n != NULL && old == n->Left)
		{
			old = n;
			n = n->Anc;
		}
		return n;
	}
	return Tree::maximum(p->Left);
}

Tree::Node * Tree::successor( const Tree::Node * p )
{
	if (p == NULL)
		return NULL;
	if (p->Right == NULL)
	{
		if (p->Anc == NULL)
			return NULL;
		Node * n = new Node();
		Node * old = new Node();
		n = p->Anc;
		if (p->Anc->Left == p)
			old = p->Anc->Left;
		else
			old = p->Anc->Right;
		if (p->Anc->Anc == NULL)
			return n;
		while (n != NULL && old == n->Right)
		{
			old = n;
			n = n->Anc;
		}
		return n;
	}
	return Tree::minimum(p->Right);
}
void in_recurs_traversal( Tree::Node * n )
{
	if (n == NULL)
		return;
	in_recurs_traversal(n->Left);
	cout << " " << n->data << "(" << n->height << ")" << " ";
	in_recurs_traversal(n->Right);
}

void pre_recurs_traversal( Tree::Node * n )
{
	if (n == NULL)
		return;
	cout << " " << n->data << " ";
	pre_recurs_traversal(n->Left);
	pre_recurs_traversal(n->Right);
}

void post_recurs_traversal( Tree::Node * n )
{
	if (n == NULL)
		return;
	post_recurs_traversal(n->Left);
	post_recurs_traversal(n->Right);
	cout << " " << n->data << " ";
}

void Tree::in_order_traversal()
{
	if (!is_init)
		return;
	in_recurs_traversal(Root);
	cout << endl;
}

void Tree::pre_order_traversal()
{
	if (!is_init)
		return;
	pre_recurs_traversal(Root);
	cout << endl;
}

void Tree::post_order_traversal()
{
	if (!is_init)
		return;
	post_recurs_traversal(Root);
	cout << endl;
}

void Tree::breadth_first_traversal()
{	
	if (!is_init)
		return;

	queue<Node *> q;

	q.push(Root);

	while (!q.empty())
	{
		Tree::Node * e = q.front();
		q.pop();
		cout << e->data <<  " ";
		if (e->Left != NULL)
			q.push(e->Left);
		if (e->Right != NULL)
			q.push(e->Right);
	}

}