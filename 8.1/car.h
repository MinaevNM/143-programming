#pragma once

enum
{
	NORTH = 0,
	EAST  = 1,
	SOUTH = 2,
	WEST  = 3
};

class OffTheField
{
public:
	int x, y;
	OffTheField( int _x , int _y ) : x(_x), y(_y)
	{
	}
};

class WrongDirection
{
public:
	int dir;
	WrongDirection( int _dir ) : dir(_dir)
	{
	}
};

class Car
{
    int x, y;
	int dir;

public:
	Car( int _x, int _y, int _dir ) : x(_x), y(_y), dir(_dir)
	{
	}
	Car() : x(0), y(0), dir(0)
	{
	}
	void rotateRight();
	void rotateLeft();
	int moveForward( int len );
	void print();
	void update( int _x, int _y, int _dir );
};