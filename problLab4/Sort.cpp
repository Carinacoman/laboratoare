#include "Sort.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stdio.h>



Sort::Sort(int Num, int minn, int maxx)
{
	int i;
	printf("Aici: %d %d %d\n", Num, minn, maxx); //afiseaza parametrii
	srand(time(nullptr)); //initializeaza generatorul de nr aleatoare
	size = Num; //nr de elem
	elemente = new int[size];
	for (i = 0; i < size; i++)
	{
		//printf("%d %d\n", i, elemente[i]);
		printf("i: %d\n", i); //indexul curent
		elemente[i] = minn + rand() % (maxx - minn + 1); //genereaza nr aleator 

	}
}

Sort::Sort(std::initializer_list<int> list)
{
	size = list.size(); //nr elem in lista
	elemente = new int[size]; //aloca vector
	int i = 0;
	for (int num : list) //copiaza toate elem din lista in vector
		elemente[i++] = num;
}

Sort::Sort(int arr[], int Num)
{
	size = Num;
	elemente = new int[size];
	int i = 0;
	for (int i = 0; i < size; i++)
		elemente[i] = arr[i]; //copiaza elem in array
}

Sort::Sort(int count, ...)
{
	size = count;
	elemente = new int[size];
	va_list vl; //creeaza lista de elem
	va_start(vl, count); //incepe parcurgerea
	for (int i = 0; i < size; i++)
	{
		elemente[i] = va_arg(vl, int); //extrage fiecare int din lista
	}
	va_end(vl); //inchide lista
}

Sort::Sort(const char* numbers)
{
	size = 1;
	char* p;
	for (int i = 0; i < strlen(numbers); i++) //numara cate numere sunt
	{
		if (numbers[i] == ',')
			size++;
	}

	elemente = new int[size];

	int j = size - 1;
	elemente[j] = 0;
	for (int i = strlen(numbers) - 1; i >= 0; i--) //parcurgem de la sf la inceput, convertim sirul in vector
	{
		if (numbers[i] != ',')
		{
			elemente[j] = (numbers[i] - '0') * 10 + elemente[j];//construieste nr cifra cu cifra
		}
		else if (numbers[i] == ',')
		{
			j--;
			elemente[j] = 0; //pregatim poz pt urm numar
		}
	}
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 0; i < size; i++)
	{
		int key = elemente[i];
		int j = i - 1;
		while (j >= 0 and ((ascendent and elemente[j] >= key) || (!ascendent and elemente[i] < key)))
		{
			elemente[j + 1] = elemente[j]; //muta elem spre dreapta
			j--;
		}
		elemente[j + 1] = key; //insereaza elem la pozitia corecta
	}
}

int Sort::Partitie(int left, int right, bool ascendent)
{
	int k = elemente[right]; //pivotul
	int i = left - 1;

	for (int j = left; j < right; j++)
	{
		if ((ascendent && elemente[j] < k) || (!ascendent && elemente[j] > k))
		{
			i++;
			std::swap(elemente[i], elemente[j]);
		}
	}
	std::swap(elemente[right], elemente[i + 1]);
	return i + 1; //returneaza indexul pivotului
}

void Sort::QuickSortHelper(int left, int right, bool ascendent)
{
	if (left < right)
	{
		int k = Partitie(left, right, ascendent); //afla poz pivotului
		QuickSortHelper(left, k - 1, ascendent); //sorteaza partea stg
		QuickSortHelper(k + 1, right, ascendent); //sorteaza partea drp
	}
}

void Sort::QuickSort(bool ascendent)
{
	QuickSortHelper(0, size - 1, ascendent); //apeleaza sortarea intreaga
}

void Sort::BubbleSort(bool ascendent)
{
	if (ascendent)
	{
		for (int i = 0; i < size - 1;i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (elemente[i] > elemente[j])
				{
					std::swap(elemente[i], elemente[j]); //daca nu s in ord corecta, le inverseaza
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < size - 1;i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (elemente[i] < elemente[j])
				{
					std::swap(elemente[i], elemente[j]); //schimba pt descresc
				}
			}
		}
	}
}

void Sort::Print()
{
	for (int i = 0; i < size; i++)
		printf("%d ", elemente[i]);
	printf("\n");
}

int Sort::GetElementsCount()
{
	return size;
}

int Sort::GetElementFromIndex(int index)
{
	if (index >= 0 and index < size)
		return elemente[index]; //returneaza valoarea
	return -1; //in cazul in care indexul e invalid
}
