#include <cmath>
#include <iostream>

#include "car.h"

using namespace std;

void Car::rotateRight()
{
	dir = (dir + 1) % 4;
}

void Car::rotateLeft()
{
	dir = (dir + 3) % 4;
}

int Car::moveForward( int len )
{
	int d;
	int nx, ny;
	switch (dir)
	{
	case NORTH:
		ny = min(5, y + len);
		d = abs(ny - y);
		y = ny;
		break;
	case EAST:
		nx = min(5, x + len);
		d = abs(nx - x);
		x = nx;
		break;
	case SOUTH:
		ny = max(-5, y - len);
		d = abs(ny - y);
		y = ny;
		break;
	case WEST:
		nx = max(-5, x - len);
		d = abs(nx - x);
		x = nx;
		break;
	}
	return d;
}

void Car::print()
{
	cout << "x = " << x << ", y = " << y << ", direction - ";
	switch (dir)
	{
	case NORTH:
		cout << "NORTH";
		break;
	case EAST:
		cout << "EAST";
		break;
	case SOUTH:
		cout << "SOUTH";
		break;
	case WEST:
		cout << "WEST";
		break;
	}
	cout << endl;
}
