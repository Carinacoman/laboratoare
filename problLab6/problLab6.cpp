#include <stdlib.h>
#include <stdio.h>
#include "Circuit.h"
#include "Volvo.h"
#include "Bmw.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Car.h"
#include "Weather.h"



int main()
{

	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Rain);
	c.AddCar(new Volvo());
	c.AddCar(new Bmw());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());
	c.Race();
	c.ShowFinalRanks(); // afiseaza fiecare masina cand termina circuitul de la cel mai rapid
	c.ShowWhoDidNotFinish(); // afiseaza masinile care nu termina circuitul
	return 0;
}
