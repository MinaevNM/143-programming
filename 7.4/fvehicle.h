#pragma once

#include "vehicle.h"

class FlyingVehicle: virtual public Vehicle
{
private:
	int turbine_num;
public:
	FlyingVehicle( int _motor_id, int _turbine_num ) : 
	  Vehicle(_motor_id), turbine_num(_turbine_num)
	{
	}
    void print_turbine()
	{
		cout << "Turbine_num = " << turbine_num << endl;		
	}
    void print_full()
	{
		print_motor();
		print_turbine();
	}
};