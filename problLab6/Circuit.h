#pragma once
#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "Car.h"
#include <iostream>
#define MAX_CARS 10

class Circuit
{
private:
	Car* cars[MAX_CARS];
	int carCount;
	int lenght;
	Weather weather;

public:
	Circuit();
	void SetLength(int len);
	void SetWeather(Weather w);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();

};

#endif