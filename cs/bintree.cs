using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sonya
{
    // Tree node class
    class Node
    {
        public int key;
        public Node Left;
        public Node Right;
    }

    // Tree class
    class Tree
    {
        // Tree root
        public Node Root;

        // Tree constructor
        public Tree()
        {
        }

        // add new key to tree
        public void add(int _key)
        {
            if (Root == null)
            {
                Root = new Node();
                Root.key = _key;
                Root.Left = Root.Right = null;
                return;
            }
            Node n = Root;
            Node old = Root;
            while (n != null)
            {
                if (_key == n.key)
                    return;
                if (_key > n.key)
                {
                    old = n;
                    n = n.Right;
                }
                else
                {
                    old = n;
                    n = n.Left;
                }
            }
            Node newnode = new Node();
            newnode.key = _key;
            newnode.Left = null;
            newnode.Right = null;
            if (_key > old.key)
                old.Right = newnode;
            else
                old.Left = newnode;

        }

        // Print tree
        public void print(Node n)
        {
            if (n == null)
                return;
            print(n.Left);
            Console.Write("{0} ", n.key);
            print(n.Right);
        }

        public void findKey(Node n, int _key)
        {
            if (n == null)
                return;
            if (n.Left != null && n.Left.key == _key)
            {
                n.Left = null;
                return;
            }
            if (n.Right != null && n.Right.key == _key)
            {
                n.Right = null;
                return;
            }
            findKey(n.Left, _key);
            findKey(n.Right, _key);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Tree t = new Tree();

            t.add(9);
            t.add(7);
            t.add(8);
            t.add(3);
            t.add(5);
            t.add(2);
            t.add(21);
            t.add(13);
            t.add(34);
            Console.Write("Tree keys are: ");
            t.print(t.Root);
            Console.WriteLine();
            t.findKey(t.Root, 3);
            Console.WriteLine("Subtree started with 3 deleted");
            Console.Write("Tree keys are: ");
            t.print(t.Root);
            Console.WriteLine();

            t.findKey(t.Root, 21);
            Console.WriteLine("Subtree started with 21 deleted");
            Console.Write("Tree keys are: ");
            t.print(t.Root);
            Console.WriteLine();

            t.findKey(t.Root, 7);
            Console.WriteLine("Subtree started with 7 deleted");
            Console.Write("Tree keys are: ");
            t.print(t.Root);
            Console.WriteLine();
        }
    }
}
