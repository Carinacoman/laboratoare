#include "Sort.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stdio.h>



Sort::Sort(int Num, int minn, int maxx)
{
	int i;
	printf("Aici: %d %d %d\n", Num, minn, maxx);
	srand(time(nullptr));
	size = Num;
	elemente = new int[size];
	for (i = 0; i < size; i++)
	{
		//printf("%d %d\n", i, elemente[i]);
		printf("i: %d\n", i);
		elemente[i] = minn + rand() % (maxx - minn + 1);

	}
}

Sort::Sort(std::initializer_list<int> list)
{
	size = list.size();
	elemente = new int[size];
	int i = 0;
	for (int num : list)
		elemente[i++] = num;
}

Sort::Sort(int arr[], int Num)
{
	size = Num;
	elemente = new int[size];
	int i = 0;
	for (int i = 0; i < size; i++)
		elemente[i] = arr[i];
}

Sort::Sort(int count, ...)
{
	size = count;
	elemente = new int[size];
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < size; i++)
	{
		elemente[i] = va_arg(vl, int);
	}
	va_end(vl);
}

Sort::Sort(const char* numbers)
{
	size = 1;
	char* p;
	for (int i = 0; i < strlen(numbers); i++)
	{
		if (numbers[i] == ',')
			size++;
	}

	elemente = new int[size];

	int j = size - 1;
	elemente[j] = 0;
	for (int i = strlen(numbers) - 1; i >= 0; i--)
	{
		if (numbers[i] != ',')
		{
			elemente[j] = (numbers[i] - '0') * 10 + elemente[j];
		}
		else if (numbers[i] == ',')
		{
			j--;
			elemente[j] = 0;
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
			elemente[j + 1] = elemente[j];
			j--;
		}
		elemente[j + 1] = key;
	}
}

int Sort::Partitie(int left, int right, bool ascendent)
{
	int k = elemente[right];
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
	return i + 1;
}

void Sort::QuickSortHelper(int left, int right, bool ascendent)
{
	if (left < right)
	{
		int k = Partitie(left, right, ascendent);
		QuickSortHelper(left, k - 1, ascendent);
		QuickSortHelper(k + 1, right, ascendent);
	}
}

void Sort::QuickSort(bool ascendent)
{
	QuickSortHelper(0, size - 1, ascendent);
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
					std::swap(elemente[i], elemente[j]);
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
					std::swap(elemente[i], elemente[j]);
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
		return elemente[index];
	return -1;
}