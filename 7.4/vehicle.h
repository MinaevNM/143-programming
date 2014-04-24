#pragma once

#include <iostream>

using namespace std;

class Vehicle
{
private:
	int motor_id;
public:
	Vehicle( int _motor_id ): motor_id(_motor_id)
	{
	}
	void print_motor()
	{
		cout << "Motor_id = " << motor_id << endl;
	}
};