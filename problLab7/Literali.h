#pragma once

float operator"" _Kelvin(unsigned long long k)
{
	return static_cast<float>(k - 273.15);
}
float operator"" _Fahrenheit(unsigned long long f)
{
	return static_cast<float>((f - 32) / 1.8);
}