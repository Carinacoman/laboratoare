#pragma once
class NumberList
{
    int numbers[10];
    int count;
public:
    void Init();          
    bool Add(int x);      // adauga X la lista de nr si mareste nr de elem
    // daca sunt mai mult de 9 elem, functia returneaza fals
    void Sort();          // sorteaza nr din vector
    void Print();         // afiseaza vectorul
};
