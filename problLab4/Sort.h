#pragma once
#include <initializer_list>
#include <cstdarg>
#include <cstring>
#include <iostream>
class Sort
{
    int* elemente;
    int size;

    void QuickSortHelper(int left, int right, bool ascendent);
    int Partitie(int left, int right, bool ascendent);

public:
    Sort(int Num, int minn, int maxx);
    Sort(std::initializer_list<int>list);
    Sort(int arr[], int Num);
    Sort(int count, ...);
    Sort(const char* numbers);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
