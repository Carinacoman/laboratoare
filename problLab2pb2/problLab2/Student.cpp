#include "Student.h"
#include <stdlib.h>
#include <cstring>

bool Student::valideGrade(int grade)
{
	return grade >= 1 and grade <= 10; //verif daca e nota valida
}

void Student::SetName(const char* InputName, int InputNameSize) //alocare dinamica pt numele studentului
{
	this->Name = new char[InputNameSize + 1];
	memcpy(this->Name, InputName, InputNameSize);
	this->Name[InputNameSize] = '\0';
	//if(this->Name != nullprt) //sterge numele anterior
		//delete[] this->Name;

}

const char* Student::GetName()
{
	return this->Name; //returneaza pointerul catre numele studentului
}
//seteaza si returneaza notele la mate, engl, ist
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

int Student::Average() //calc media aritmetica
{
	return (this->Math + this->Eng + this->His) / 3.0;
}
