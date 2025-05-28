#include "Bmw.h"

Bmw::Bmw()
{
	fuelCap = 55;
	fuelConsm = 10;
	avgSpeed[0] = 110;
	avgSpeed[1] = 140;
	avgSpeed[2] = 85;
}

float Bmw::GetSpeed(Weather condition)const
{
	return avgSpeed[static_cast <int>(condition)];
}

float Bmw::getFuelCapacity()const
{
	return fuelCap;
}

float Bmw::GetFuelConsumption()const
{
	return fuelConsm;
}

const char* Bmw::GetName()const
{
	return "Bmw";
}