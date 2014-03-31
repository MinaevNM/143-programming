#include "mstring.h"

#include <iostream>

using namespace std;

int String::size()
{
	return my_size;
}

int String::capacity()
{
	return my_capacity;
}

bool String::empty()
{
    if (my_size)
		return true;
	return false;
}

void String::clear()
{
	my_size = 0;
	my_capacity = MinCapacity;
	delete [] my_str;
	my_str = new char[my_capacity];
}

/*
k = floor(log(n)); k <= log(n); 2^k <= n
S(n) = O(1) + O(2) + O(4) + O(8) + ... + O(2^k) = O(2^(k+1) - 1) =
= O(2^(k + 1)) = O(2 * 2^k) = O(2n) = O(n)
S(n) / n = O(n) / n = O(1)
*/
void String::push_back( char c )
{
	if (my_size + 2 >= my_capacity)
	{
		my_capacity *= 2;
		char * new_str = new char[my_capacity];
		for (int i = 0; i < my_size; i++)
			new_str[i] = my_str[i];
		new_str[my_size++] = c;
		delete [] my_str;
		my_str = new_str;
	}
	else
		my_str[my_size++] = c;
}

void String::pop_back()
{
	if (my_capacity >= 2 * my_size)
	{
		my_capacity /= 2;
		char * new_str = new char[my_capacity];
		my_size--;
		for (int i = 0; i < my_size; i++)
		    new_str[i] = my_str[i];
		delete [] my_str;
		my_str = new_str;
	}
	else
	    my_size--;
}

void String::insert( int pos, const char * str )
{
	int len = strlen(str);
	if (my_size + len + 1 >= my_capacity)
	{
		int k = (int)ceil(log((my_size + len + 1.) / my_capacity) / log(2.0));
		my_capacity *= (int)pow(2., (double)k);
	}
	char * new_str = new char[my_capacity];
	for (int i = 0; i < pos; i++)
		new_str[i] = my_str[i];
	for (int i = pos; i < pos + len; i++)
		new_str[i] = str[i - pos];
	for (int i = pos + len; i < my_size + len; i++)
		new_str[i] = my_str[i - len];
	my_size = my_size + len;
	delete [] my_str;
	my_str = new_str;
}

void String::erase( int pos, int len )
{
	if (my_capacity >= 2 * (my_size - len + 1))
	{
		int k = (int)floor(log((double)my_capacity / max(my_size - len + 1, MinCapacity)) / log(2.));
		my_capacity /= (int)pow(2., (double)k);
	}

	char * new_str = new char[my_capacity];
	
	for (int i = 0; i < pos; i++)
		new_str[i] = my_str[i];
	for (int i = pos + len; i < my_size; i++)
		new_str[i - len] = my_str[i];
	my_size -= len;
	delete [] my_str;
	my_str = new_str;
}

String String::operator+( String str )
{
    String ns("");
	char * s = new char[my_size + 1];
	for (int i = 0; i < my_size; i++)
		s[i] = my_str[i];
	s[my_size] = 0;
	ns.insert(0, s);
	delete [] s;
	s = new char[str.my_size + 1];
	for (int i = 0; i < str.my_size; i++)
		s[i] = str.my_str[i];
	s[str.my_size] = 0;
	ns.insert(my_size, s);
	return ns;
}

void String::operator+=( String str )
{
	char * s = new char[str.my_size + 1];
	for (int i = 0; i < str.my_size; i++)
		s[i] = str[i];
	s[str.my_size] = 0;
	insert(my_size, s);
}

ostream & operator<<( ostream & stream, const String & s )
{
	String h = s;
	for (int i = 0; i < h.size(); i++)
		stream << h[i];
	stream << endl;
	return stream;
}

istream & operator>>( istream & stream, String & s )
{
	char str[101];
	stream >> str;
	s.insert(s.size(), str);
	return stream;
}
