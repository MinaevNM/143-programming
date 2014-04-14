#pragma once

#include "car.h"

class Bus : public Car
{
	int money;
	int pass;

public:
	Bus() : Car(), money(0), pass(0)
	{
	}
	Bus( int _x, int _y, int _dir, int _money, int _pass ) 
		: Car(_x, _y, _dir), money(_money), pass(_pass)
	{
	}
	int moveForward( int len );
	int get_money();
	void busEnter( int x );
	void busLeave( int x );
};