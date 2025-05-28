#include "Fiat.h"


Fiat::Fiat()
{
	fuelCap = 30;
	fuelConsm = 10;
	avgSpeed[0] = 60;
	avgSpeed[1] = 65;
	avgSpeed[2] = 40;
}

float Fiat::GetSpeed(Weather condition)const
{
	return avgSpeed[static_cast <int>(condition)];
}

float Fiat::getFuelCapacity()const
{
	return fuelCap;
}

float Fiat::GetFuelConsumption()const
{
	return fuelConsm;
}

const char* Fiat::GetName()const
{
	return "Fiat";
}