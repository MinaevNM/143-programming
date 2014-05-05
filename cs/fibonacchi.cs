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
        public void print( Node n )
        {
            if (n == null)
                return;
            print(n.Left);
            Console.Write(" {0} ", n.key);
            print(n.Right);
        }

        // Recursive function to find maximal 
        public int recurs_max( Node n, int max_key )
        {
            if (n == null)
                return max_key;
            // Choose maximal key from: 
            // Current maximal key
            // Maximal key from left tree
            // Maximal key from right tree
            // Current node key
            return Math.Max(Math.Max(recurs_max(n.Left, max_key), recurs_max(n.Right, max_key)), Math.Max(max_key, n.key));
        }

        // Find maximal key in the tree
        public int max()
        {
            if (Root == null)
                return 0;
            return recurs_max(Root, Root.key);
        }

        public void outPath(List<Node> path)
        {
            foreach (Node n in path)
                Console.Write("{0} ", n.key);
            Console.WriteLine();
        }
        public void findFib(List<int> fib, List<Node> path, Node nd )
        {
            List<Node> _path = new List<Node>();
            foreach (Node n in path)
                _path.Add(n);
            if (nd == null)
                return;
            _path.Add(nd);
            foreach (int i in fib)
                if (i == nd.key)
                {
                    outPath(_path);
                    break;
                }
            findFib(fib, _path, nd.Left);
            findFib(fib, _path, nd.Right);
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
            int max = t.max();
            Console.WriteLine("Maximal key in tree: {0}", max);
            List<int> fib = new List<int>();
            int fib1 = 1, fib2 = 2;
            fib.Add(1);
            while (fib2 <= max)
            {
                int tmp = fib2;
                fib.Add(fib2);
                fib2 += fib1;
                fib1 = tmp;
            }
            Console.Write("Fibonacchi numbers from 1 to maximal key: ");
            foreach (int i in fib)
                Console.Write("{0} ", i);
            Console.WriteLine();
            // Create List of Nodes - path to node in tree
            List<Node> path = new List<Node>();
            Console.WriteLine("Pathes to fibonacchi nodes:");
            t.findFib(fib, path, t.Root);
        }
    }
}
