#include "Math.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <cstring>

int Math::Add(int a, int b)
{
    return a + b;
}

int Math::Add(int a, int b, int c)
{
    return a + b + c;
}

double Math::Add(double a, double b)
{
    return a + b;
}

double Math::Add(double a, double b, double c)
{
    return a + b + c;
}

int Math::Mul(int x, int y)
{
    return x * y;
}

int Math::Mul(int x, int y, int z)
{
    return x * y * z;
}

double Math::Mul(double x, double y)
{
    return x * y;
}

double Math::Mul(double x, double y, double z)
{
    return x * y * z;
}

int Math::Add(int count, ...)
{
    int i;
    int val = 0;
    va_list vl;
    va_start(vl, count);
    for (i = 0; i < count; i++)
    {
        val += va_arg(vl, int); //extrage cate un elem si il aduna
    }
    va_end(vl);
    return val;
}

char* Math::Add(const char* s1, const char* s2)
{
    if (s1 == nullptr || s2 == nullptr)
        return nullptr;

    int size;

    size = strlen(s1) + strlen(s2) + 1;
    char* newsir = new char[size];
    newsir[0] = '\0';
    strcat_s(newsir, size, s1); //concatenare s1
    strcat_s(newsir, size, s2); //concatenare s2
    newsir[size - 1] = '\0';
    return newsir;
}
