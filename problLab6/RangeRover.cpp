#include "RangeRover.h"

RangeRover::RangeRover()
{
	fuelCap = 70;
	fuelConsm = 10;
	avgSpeed[0] = 110;
	avgSpeed[1] = 140;
	avgSpeed[2] = 85;
}

float RangeRover::GetSpeed(Weather condition)const
{
	return avgSpeed[static_cast <int>(condition)];
}

float RangeRover::getFuelCapacity()const
{
	return fuelCap;
}

float RangeRover::GetFuelConsumption()const
{
	return fuelConsm;
}

const char* RangeRover::GetName()const
{
	return "RangeRover";
}
