#pragma once
class Student
{
	char* Name;
	int Math;
	int Eng;
	int His;

	bool valideGrade(int grade);
public:
	void SetName(const char* InputName, int InputNameSize);
	const char* GetName();
	void SetMath(int number);
	int GetMath();
	void SetEng(int number);
	int GetEng();
	void SetHis(int number);
	int GetHis();
	int Average();
};
