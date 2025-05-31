#include "Number.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>


int CharToInt(char c) //converteste un caract in val sa numerica
{
	if (c >= '0' and c <= '9')
		return c - '0';
	if (c >= 'A' and c <= 'F')
		return c - 'A' + 10;
	return -1;
}

char IntToChar(int x) //converteste un numar in caracter
{
	if (x >= 0 and x <= 9)
		return x + '0';
	if (x >= 10 and x <= 15)
		return 'A' + (x - 10);
	return '?';
}

int Number::InBaza10() const //converteste nr curent din baza sa in baza 10
{
	int valoare = 0;
	for (int i = 0; i < strlen(val); i++)
	{
		valoare = valoare * bas + CharToInt(val[i]);
	}
	return valoare;
}

char* Number::DinBaza10(int DecValue, int newBase) //converteste din baza 10 in alta baza(2-16)
{


	if (DecValue == 0) // Caz special pentru 0
	{
		char* zeroStr = new char[2];
		strcpy_s(zeroStr, strlen(zeroStr), "0");
		return zeroStr;
	}

	int i = 0;
	char oglindit[32];//temporar e rezultatul in ordine inversa

	while (DecValue)
	{
		oglindit[i++] = IntToChar(DecValue % newBase);
		DecValue /= newBase;
	}

	oglindit[i] = '\0';

	char* rezult = new char[i + 1];
	for (int j = 0; j < i; j++)
	{
		rezult[j] = oglindit[i - j - 1]; // Inversam caracterele
	}
	rezult[i] = '\0';
	return rezult;

}

Number::Number(const char* value, int base) //constructor cu valoare si baza
{
	size = strlen(value) + 1;
	val = new char[size];
	strcpy_s(val, size, value);
	if (base >= 2 and base <= 16)
		bas = base;
	else
		printf("Introduceti alta baza pentru %s \n", val);
}

Number::Number(int Dec) //constructor din int(baza 10)
{
	bas = 10;
	char* Value = DinBaza10(Dec, 10);

	size = strlen(Value) + 1;
	val = new char[size];
	strcpy_s(val, size, Value);
}

Number::Number(const Number& other) //copy constructor
{
	bas = other.bas;
	size = other.size;
	val = new char[size];
	strcpy_s(val, size, other.val);
}

Number::Number(Number&& other) //move constructor
{
	val = other.val;
	bas = other.bas;
	size = other.size;
	other.val = nullptr; //dezactiveaza sursa
}

Number::~Number() //destructor
{
	delete[] val;
	val = nullptr;
}

Number& Number::operator=(Number&& other)
{ //move
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
{ //asignare din string
	delete[] val;
	size = strlen(str) + 1;
	val = new char[size];
	strcpy_s(val, size, str);
	return *this;
}

Number& Number::operator=(int decimalValue)
{ //asignare din nr intreg
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
{ //returneaza cifra de la pozitia index
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

	int DecValue = InBaza10(); //convertim in baza 10
	char* NewValue = DinBaza10(DecValue, newBase); //apoi convertim in baza noua

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

Number& Number::operator--() //sterge primul caracter
{
	strcpy_s(val, size, val + 1);
	return *this;
}

Number Number::operator--(int) //sterge ultimul caracter
{
	val[strlen(val) - 1] = '\0';
	size = size - 1;
	return *this;
}


Number operator+(const Number& n1, const Number& n2) //aduna 2 nr in baza maxima
{
	int baseFinal = std::max(n1.bas, n2.bas);
	int val1 = n1.InBaza10();
	int val2 = n2.InBaza10();
	int suma = val1 + val2;

	char* newValue = Number::DinBaza10(suma, baseFinal);
	return Number(newValue, baseFinal);
}

Number operator-(const Number& n1, const Number& n2) // scade 2 numere, daca rez e negativ, returnam 0
{
	int baseFinal = std::max(n1.bas, n2.bas);
	int val1 = n1.InBaza10();
	int val2 = n2.InBaza10();
	int dif = val1 - val2;

	if (dif < 0) {
		printf("Rezultatul este negativ, care nu este suportat în aceasta implementare.\n");
		return Number("0", baseFinal);
	}

	char* newValue = Number::DinBaza10(dif, baseFinal);
	return Number(newValue, baseFinal);
}
