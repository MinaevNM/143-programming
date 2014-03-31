#include <iostream>

#include "mstring.h"

using namespace std;

void main()
{
	String s("abcd");
	cout << s.size() << " " << s.capacity() << endl;
	cout << s;
	s.insert(2, "bbbbbbb");
	cout << s;
	cout << s.size() << " " << s.capacity() << endl;
	s.insert(2, "hhhhh");
	cout << s.size() << " " << s.capacity() << endl;
	s.erase(2, 10);
	cout << s;
	cout << s.size() << " " << s.capacity() << endl;
	String h("aa");
	cout << h;
	h += String("abc");
	cout << h;
	cout << h + s;
	cout << (h + s).size() << " " << (h + s).capacity() << endl;
}
