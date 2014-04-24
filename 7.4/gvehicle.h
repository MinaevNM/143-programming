#pragma once
#include "vehicle.h"

class GroundVehicle: virtual public Vehicle
{
private:
	double wheel_diam;
public:
	GroundVehicle( int _motor_id, double _wheel_diam ) : 
	  Vehicle(_motor_id), wheel_diam(_wheel_diam)
	{
	}
    void print_full()
	{
		print_motor();
		cout << "Wheel_diam = " << wheel_diam << endl;
	}
};