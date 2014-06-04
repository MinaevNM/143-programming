#include <iostream>
#include <time.h>

#include "BSTree.h"

using namespace std;

void main()
{
	BSTree * bst = new BSTree();
	for (int i = 0; i < 10; i++)
		bst->insert((rand() % 100));
	bst->in_order_traversal();
	bst->pre_order_traversal();
	bst->post_order_traversal();

	Tree::Node * n = bst->minimum(bst->Root);
	
	while (n != NULL)
	{
		if (n->data % 2 == 0)
			cout << n->data << " ";
		n = bst->successor(n);
	} 
	cout << endl;
	n = bst->maximum(bst->Root);
	while (n != NULL)
	{
		if (n->data % 2 == 1)
			cout << n->data << " ";
		n = bst->predecessor(n);
	}
	cout << endl;
	n = bst->minimum(bst->Root);
	while (n != NULL)
	{
		if (n->data % 3 == 0)
		{
			int t = -1;
			if (bst->successor(n) != NULL)
				t = bst->successor(n)->data;
			bst->remove(n);
			//bst->in_order_traversal();
			if (t == -1)
			{
				if (bst->Root->data % 3 == 0)
					bst->remove(bst->Root);
				n = NULL;
			}
			else
				n = bst->find(t);
		}
		else
			n = bst->successor(n);
	}
	bst->in_order_traversal();
	bst->breadth_first_traversal();
	cout << endl;
	
	delete bst;
	/*
	BSTree * bst = new BSTree();
	bst->insert(5);
	bst->insert(4);
	bst->insert(10);
	bst->in_order_traversal();
	Tree::Node * n = bst->find(4);
	bst->remove(n);
	n = bst->find(5);
	bst->remove(n);
	n = bst->find(10);
	bst->remove(n);
	bst->in_order_traversal();
	bst->insert(14);
	bst->in_order_traversal();*/
}