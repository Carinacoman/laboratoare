#include <stdio.h>
#include "Student.h"
#include "FunctiiGlobale.h"
#include <iostream>


int main()
{
    Student student1, student2;

    student1.SetName("Alice", 5);
    student1.SetMath(9);
    student1.SetEng(8);
    student1.SetHis(7);

    student2.SetName("Bob", 3);
    student2.SetMath(7);
    student2.SetEng(9);
    student2.SetHis(8);

    std::cout << "Comparison by Name: " << compareByName(student1, student2) << std::endl;
    std::cout << "Comparison by Math Grade: " << compareByMathGrade(student1, student2) << std::endl;
    std::cout << "Comparison by English Grade: " << compareByEnglishGrade(student1, student2) << std::endl;
    std::cout << "Comparison by History Grade: " << compareByHistoryGrade(student1, student2) << std::endl;
    std::cout << "Comparison by Average Grade: " << compareByAverageGrade(student1, student2) << std::endl;


    return 0;
}