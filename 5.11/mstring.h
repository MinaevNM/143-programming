#pragma once
#include <cmath>
#include <iostream>

using namespace std;

const int MinCapacity = 4;
class String
{
private:
	char * my_str;
	int my_size;
	int my_capacity;
public:
	String() : my_size(0), my_capacity(MinCapacity)
    {
		my_str = new char[my_capacity];
	}

	String( const char * str )
	{
		my_capacity = MinCapacity;
		int len = strlen(str);
		if (my_capacity <= len + 1)
		{
			int k = (int)ceil(log((len + 1.) / my_capacity) / log(2.0));
			my_capacity *= (int)pow(2., (double)k);
		}
		my_size = len;
		my_str = new char[my_capacity];
		memcpy(my_str, str, len);		
	}

	String( const String & obj )
	{
		my_size = obj.my_size;
		my_capacity = obj.my_capacity;
		my_str = new char[my_capacity];
		memcpy(my_str, obj.my_str, my_size);	    
	}

	String & operator=( const String &obj )
	{
		delete [] my_str;
		my_size = obj.my_size;
		my_capacity = obj.my_capacity;
		my_str = new char[my_capacity];
		memcpy(my_str, obj.my_str, my_size);	    		
	}

	~String()
	{
		delete [] my_str;
	}

	int size();
	int capacity();
	bool empty();
	void clear();
	void push_back( char c );
	void pop_back();
	void insert( int pos, const char * str );
	void erase( int pos, int len = 1 );
	String operator+( const String str );
	void operator+=( const String s );
	char & operator[]( int index )
    {
	    if (index >= 0 && index < my_size)
	        return my_str[index];
	    return my_str[0];
    }
};

ostream & operator<<( ostream & stream, const String & s );
istream & operator>>( istream & stream, String & s );
