#include "FunctiiGlobale.h"

int compareByName(Student& s1, Student& s2)
{
    if (s1.GetName() == s2.GetName())
        return 0;
    if (s1.GetName() > s2.GetName())
        return 1;
    return -1;
}

int compareByMathGrade(Student& s1, Student& s2)
{
    if (s1.GetMath() == s2.GetMath())
        return 0;
    if (s1.GetMath() > s2.GetMath())
        return 1;
    return -1;
}

int compareByEnglishGrade(Student& s1, Student& s2)
{
    if (s1.GetEng() == s2.GetEng())
        return 0;
    if (s1.GetEng() > s2.GetEng())
        return 1;
    return -1;
}

int compareByHistoryGrade(Student& s1, Student& s2)
{
    if (s1.GetHis() == s2.GetHis())
        return 0;
    if (s1.GetHis() > s2.GetHis())
        return 1;
    return -1;
}

int compareByAverageGrade(Student& s1, Student& s2)
{
    if (s1.Average() == s2.Average())
        return 0;
    if (s1.Average() > s2.Average())
        return 1;
    return -1;
}