#include "Volvo.h"

Volvo::Volvo()
{
	fuelCap = 60;
	fuelConsm = 8;
	avgSpeed[0] = 100;
	avgSpeed[1] = 120;
	avgSpeed[2] = 90;
}

float Volvo::GetSpeed(Weather condition)const
{
	return avgSpeed[static_cast <int>(condition)];
}

float Volvo::getFuelCapacity()const
{
	return fuelCap;
}

float Volvo::GetFuelConsumption()const
{
	return fuelConsm;
}

const char* Volvo::GetName()const
{
	return "Volvo";
}