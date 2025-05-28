#include "Student.h"
#include <stdlib.h>
#include <cstring>

bool Student::valideGrade(int grade)
{
	return grade >= 1 and grade <= 10;
}

void Student::SetName(const char* InputName, int InputNameSize)
{
	this->Name = new char[InputNameSize + 1];
	memcpy(this->Name, InputName, InputNameSize);
	this->Name[InputNameSize] = '\0';

}

const char* Student::GetName()
{
	return this->Name;
}

void Student::SetMath(int number)
{
	this->Math = number;
}

int Student::GetMath()
{
	return this->Math;
}

void Student::SetEng(int number)
{
	this->Eng = number;
}

int Student::GetEng()
{
	return this->Eng;
}

void Student::SetHis(int number)
{
	this->His = number;
}

int Student::GetHis()
{
	return this->His;
}

int Student::Average()
{
	return (this->Math + this->Eng + this->His) / 3.0;
}