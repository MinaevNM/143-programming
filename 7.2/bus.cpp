#include <iostream>

#include "bus.h"

using namespace std;

int Bus::moveForward( int len )
{
	int d = Car::moveForward(len);
	money += pass * d;
	return d;
}

int Bus::get_money()
{
	return money;
}

void Bus::busEnter( int x )
{
	pass += x;
}

void Bus::busLeave( int x )
{
	pass = max(0, pass - x);
}
