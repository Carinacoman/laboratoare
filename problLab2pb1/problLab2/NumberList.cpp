#include "NumberList.h"
#include <stdio.h>

void NumberList::Init()
{
	this->count = 0; //seteaza nr de elem la 0 
}

bool NumberList::Add(int x)
{
	if (this->count < 10) //adauga nr in lista doar daca nu s a atins limita de 10 elem
	{
		this->numbers[this->count] = x;
		this->count++;
		return true;
	}
	else {
		return false;
	}
}

void NumberList::Sort() //sortare crescatoare
{
	for (int i = 0; i < this->count - 1;i++)
	{
		for (int j = i + 1; j < this->count;j++)
		{
			if (this->numbers[i] > this->numbers[j]) //bubble sort
			{
				int aux = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
			}
		}
	}
}

void NumberList::Print()
{
	printf("Vectorul: ");
	for (int i = 0; i < this->count; i++)
	{
		printf("%d ", this->numbers[i]); //afiseaza elem din vector
	}
	printf("\n");
}
