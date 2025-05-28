#include "Circuit.h"
#include <stdio.h>
#include <stdlib.h>


Circuit::Circuit()
{
	carCount = 0;
	lenght = 0;
	weather = Weather::Sunny;
}

void Circuit::SetLength(int len)
{
	lenght = len;
}

void Circuit::SetWeather(Weather w)
{
	weather = w;
}

void Circuit::AddCar(Car* car)
{
	if (carCount < MAX_CARS)
		cars[carCount++] = car;
	else
		printf("Circuitul este plin! NU se mai pot adauga masini! \n");
}

void Circuit::Race()
{
	for (int i = 0; i < carCount;i++)
	{
		float speed = cars[i]->GetSpeed(weather);
		float fuelNeeded = (lenght / 100.0) * cars[i]->GetFuelConsumption();
		if (fuelNeeded > cars[i]->getFuelCapacity())
		{
			cars[i] = nullptr; //masina nu termina cursa
		}
	}
}

void Circuit::ShowFinalRanks()
{
	struct Result
	{
		Car* car;
		float time;
	}result[MAX_CARS];

	int count = 0;
	for (int i = 0; i < carCount; i++)
	{
		if (cars[i] != nullptr)
		{
			result[count].car = cars[i];
			result[count].time = lenght / cars[i]->GetSpeed(weather);
			count++;
		}
	}

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count;j++)
		{
			if (result[i].time > result[j].time)
			{
				Result aux;
				aux = result[i];
				result[i] = result[j];
				result[j] = aux;
			}
		}
	}

	printf("Clasament final: \n");

	for (int i = 0; i < count; i++)
	{
		printf("%s - Timp: %f ore\n", result[i].car->GetName(), result[i].time);
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	int k = 0;
	printf("Masini care nu au terminat cursa:\n");
	for (int i = 0; i < carCount; i++)
	{

		if (cars[i] == nullptr)
			k++;
	}
	if (!k)
		printf("Toate masinile au terminat cursa.\n");
	else
		printf("%d masini nu au terminat cursa", k);
}