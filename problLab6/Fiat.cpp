#include "Fiat.h"


Fiat::Fiat()
{
	fuelCap = 30; //capacitatea rezervorului
	fuelConsm = 10; //consum, 10L/100km
	//viteza medie in fct de vreme
	avgSpeed[0] = 60;
	avgSpeed[1] = 65;
	avgSpeed[2] = 40;
}

float Fiat::GetSpeed(Weather condition)const
{
	return avgSpeed[static_cast <int>(condition)]; //se transf in index pt array ul avgSpeed
}

float Fiat::getFuelCapacity()const //returneaza capacitatea rezervorului
{
	return fuelCap;
}

float Fiat::GetFuelConsumption()const //returneaza consumul masinii
{
	return fuelConsm;
}

const char* Fiat::GetName()const
{
	return "Fiat";
}
