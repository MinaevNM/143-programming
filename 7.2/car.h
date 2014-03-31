#pragma once

enum
{
	NORTH = 0,
	EAST  = 1,
	SOUTH = 2,
	WEST  = 3
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
};
