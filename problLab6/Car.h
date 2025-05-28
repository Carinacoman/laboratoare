#pragma once
#ifndef CAR_H
#define CAR_H
#include "Weather.h"

class Car
{
protected:
	float fuelCap;
	float fuelConsm;
	float avgSpeed[3];
public:
	virtual ~Car() {}
	virtual float GetSpeed(Weather condition)const = 0;
	virtual float getFuelCapacity() const = 0;
	virtual float GetFuelConsumption() const = 0;
	virtual const char* GetName() const = 0;
};

#endif