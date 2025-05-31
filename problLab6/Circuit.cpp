#include "Circuit.h"
#include <stdio.h>
#include <stdlib.h>


Circuit::Circuit() //constructor
{
	carCount = 0; //initial nu exista masini in circuit
	lenght = 0; //lungimea traseului in km
	weather = Weather::Sunny; //vremea implicita 
}

void Circuit::SetLength(int len) //setare lungime circuit
{
	lenght = len;
}

void Circuit::SetWeather(Weather w) //setare vreme
{
	weather = w;
}

void Circuit::AddCar(Car* car) //adauga masina in array
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
		float speed = cars[i]->GetSpeed(weather); //obt viteza in fct de vreme
		float fuelNeeded = (lenght / 100.0) * cars[i]->GetFuelConsumption(); //consum estimat
		if (fuelNeeded > cars[i]->getFuelCapacity()) //daca nu are combustibil suficient
		{
			cars[i] = nullptr; //masina nu termina cursa, o eliminam
		}
	}
}

void Circuit::ShowFinalRanks()
{
	struct Result //structura temporara pt rezultat
	{
		Car* car;
		float time;
	}result[MAX_CARS];

	int count = 0;
	for (int i = 0; i < carCount; i++)
	{
		if (cars[i] != nullptr) //doar masinile care au terminat
		{
			result[count].car = cars[i];
			result[count].time = lenght / cars[i]->GetSpeed(weather);//timpul=dist/viteza
			count++;
		}
	}

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count;j++)
		{
			if (result[i].time > result[j].time) //cea mai rapida masina trece in fata
			{
				Result aux;
				aux = result[i];
				result[i] = result[j];
				result[j] = aux;
			}
		}
	}

	printf("Clasament final: \n"); //afisare rezultate

	for (int i = 0; i < count; i++)
	{
		printf("%s - Timp: %f ore\n", result[i].car->GetName(), result[i].time);
	}
}

void Circuit::ShowWhoDidNotFinish() //afisare masini care n au terminat cursa
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
