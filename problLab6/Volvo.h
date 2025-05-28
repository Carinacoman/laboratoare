#pragma once
#ifndef VOLVO_H
#define VOLVO_H

#include "Car.h"

class Volvo : public Car {
public:
	Volvo();
	float GetSpeed(Weather condition)const;
	float getFuelCapacity()const override;
	float GetFuelConsumption()const override;
	const char* GetName()const override;
};

#endif