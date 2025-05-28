#pragma once
#ifndef FIAT_H
#define FIAT_H

#include "Car.h"

class Fiat : public Car {
public:
	Fiat();
	float GetSpeed(Weather condition)const;
	float getFuelCapacity()const override;
	float GetFuelConsumption()const override;
	const char* GetName()const override;
};

#endif