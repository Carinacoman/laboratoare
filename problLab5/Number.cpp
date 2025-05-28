#include "Number.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>


int CharToInt(char c)
{
	if (c >= '0' and c <= '9')
		return c - '0';
	if (c >= 'A' and c <= 'F')
		return c - 'A' + 10;
	return -1;
}

char IntToChar(int x)
{
	if (x >= 0 and x <= 9)
		return x + '0';
	if (x >= 10 and x <= 15)
		return 'A' + (x - 10);
	return '?';
}

int Number::InBaza10() const
{
	int valoare = 0;
	for (int i = 0; i < strlen(val); i++)
	{
		valoare = valoare * bas + CharToInt(val[i]);
	}
	return valoare;
}

char* Number::DinBaza10(int DecValue, int newBase)
{


	if (DecValue == 0) // Caz special pentru 0
	{
		char* zeroStr = new char[2];
		strcpy_s(zeroStr, strlen(zeroStr), "0");
		return zeroStr;
	}

	int i = 0;
	char oglindit[32];

	while (DecValue)
	{
		oglindit[i++] = IntToChar(DecValue % newBase);
		DecValue /= newBase;
	}

	oglindit[i] = '\0';

	char* rezult = new char[i + 1];
	for (int j = 0; j < i; j++)
	{
		rezult[j] = oglindit[i - j - 1]; // Invers?m caracterele
	}
	rezult[i] = '\0';
	return rezult;

}

Number::Number(const char* value, int base)
{
	size = strlen(value) + 1;
	val = new char[size];
	strcpy_s(val, size, value);
	if (base >= 2 and base <= 16)
		bas = base;
	else
		printf("Introduceti alta baza pentru %s \n", val);
}

Number::Number(int Dec)
{
	bas = 10;
	char* Value = DinBaza10(Dec, 10);

	size = strlen(Value) + 1;
	val = new char[size];
	strcpy_s(val, size, Value);
}

Number::Number(const Number& other) //copy
{
	bas = other.bas;
	size = other.size;
	val = new char[size];
	strcpy_s(val, size, other.val);
}

Number::Number(Number&& other) //move
{
	val = other.val;
	bas = other.bas;
	size = other.size;
	other.val = nullptr;
}

Number::~Number()
{
	delete[] val;
	val = nullptr;
}

Number& Number::operator=(Number&& other)
{
	if (this != &other) {
		delete[] val;
		val = other.val;
		bas = other.bas;
		size = other.size;
		other.val = nullptr;
	}
	return *this;
}

Number& Number::operator=(const char* str)
{
	delete[] val;
	size = strlen(str) + 1;
	val = new char[size];
	strcpy_s(val, size, str);
	return *this;
}

Number& Number::operator=(int decimalValue)
{
	char* Decimal = DinBaza10(decimalValue, 10);

	delete[] val;

	size = strlen(Decimal) + 1;
	val = new char[size];
	strcpy_s(val, size, Decimal);
	bas = 10;

	delete[] Decimal;

	return *this;
}

Number& Number::operator+=(const Number& other)
{
	*this = *this + other;
	return *this;
}

char Number::operator[](int index)
{
	if (index < GetDigitsCount() and index >= 0)
		return val[index];
	else
		return '?';
}


void Number::SwitchBase(int newBase)
{
	if (newBase < 2 || newBase > 16)
	{
		printf("Baza trebuie sa fie intre 2 si 16 \n");
	}

	int DecValue = InBaza10();
	char* NewValue = DinBaza10(DecValue, newBase);

	delete[] val;
	val = nullptr;

	size = strlen(NewValue) + 1;
	val = new char[size];
	strcpy_s(val, size, NewValue);
	bas = newBase;

	delete[] NewValue;
}

void Number::Print()
{
	printf("%s \n", val);
}

int Number::GetDigitsCount()
{
	return strlen(val);
}

int Number::GetBase()
{
	return bas;
}

bool Number::operator>(const Number& other)
{
	if (InBaza10() > other.InBaza10())
		return true;
	return false;
}

bool Number::operator<(const Number& other)
{
	if (InBaza10() < other.InBaza10())
		return true;
	return false;
}

bool Number::operator>=(const Number& other)
{
	if (InBaza10() >= other.InBaza10())
		return true;
	return false;
}

bool Number::operator<=(const Number& other)
{
	if (InBaza10() <= other.InBaza10())
		return true;
	return false;
}

bool Number::operator==(const Number& other)
{
	if (InBaza10() == other.InBaza10())
		return true;
	return false;
}

Number& Number::operator--()
{
	strcpy_s(val, size, val + 1);
	return *this;
}

Number Number::operator--(int)
{
	val[strlen(val) - 1] = '\0';
	size = size - 1;
	return *this;
}


Number operator+(const Number& n1, const Number& n2)
{
	int baseFinal = std::max(n1.bas, n2.bas);
	int val1 = n1.InBaza10();
	int val2 = n2.InBaza10();
	int suma = val1 + val2;

	char* newValue = Number::DinBaza10(suma, baseFinal);
	return Number(newValue, baseFinal);
}

Number operator-(const Number& n1, const Number& n2)
{
	int baseFinal = std::max(n1.bas, n2.bas);
	int val1 = n1.InBaza10();
	int val2 = n2.InBaza10();
	int dif = val1 - val2;

	if (dif < 0) {
		printf("Rezultatul este negativ, care nu este suportat în aceast? implementare.\n");
		return Number("0", baseFinal);
	}

	char* newValue = Number::DinBaza10(dif, baseFinal);
	return Number(newValue, baseFinal);
}