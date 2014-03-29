#pragma once

#include "vehicle.h"

class FlyingVehicle: public Vehicle
{
private:
	int turbine_num;
public:
	FlyingVehicle( int _motor_id, int _turbine_num ) : 
	  Vehicle(_motor_id), turbine_num(_turbine_num)
	{
	}
  void print_full()
	{
		print_motor();
		cout << "Turbine_num = " << turbine_num << endl;
	}
};
