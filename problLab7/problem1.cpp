#include <stdio.h>
#include "Literali.h"

int main()
{
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;

	printf("Din Kelvin in Celsius: %f\n", a);
	printf("Din Fahrenheit in Celsius: %f\n", b);

	return 0;
}