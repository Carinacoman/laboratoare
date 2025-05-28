#include "Seat.h"


Seat::Seat()
{
	fuelCap = 40;
	fuelConsm = 10;
	avgSpeed[0] = 80;
	avgSpeed[1] = 100;
	avgSpeed[2] = 70;
}

float Seat::GetSpeed(Weather condition)const
{
	return avgSpeed[static_cast <int>(condition)];
}

float Seat::getFuelCapacity()const
{
	return fuelCap;
}

float Seat::GetFuelConsumption()const
{
	return fuelConsm;
}

const char* Seat::GetName()const
{
	return "Seat";
}
