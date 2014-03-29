#pragma once

#include "gvehicle.h"
#include "fvehicle.h"

class Aircraft: public GroundVehicle, public FlyingVehicle
{
public:
	Aircraft( int _motor_id, double _wheel_diam, int _turbine_num ):
	  GroundVehicle(_motor_id, _wheel_diam), FlyingVehicle(_motor_id, _turbine_num)
	  {
	  }
	void print_full()
	{
		  GroundVehicle::print_full();
		  FlyingVehicle::print_full();
	}
};
