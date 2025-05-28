#pragma once
class Number
{
    char* val;
    int bas;
    int size;



public:
    Number(const char* value, int base); // where base is between 2 and 16
    Number(int Dec);
    Number(const Number& other); // Copy constructor
    Number(Number&& other); // Move constructor
    ~Number();

    int InBaza10() const;
    static char* DinBaza10(int DecValue, int newBase);

    Number& operator=(Number&& other); // Move assignment
    Number& operator=(const char* str);
    Number& operator=(int decimalValue);

    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);
    Number& operator+=(const Number& other);

    char operator[](int index);

    bool operator>(const Number& other);
    bool operator<(const Number& other);
    bool operator>=(const Number& other);
    bool operator<=(const Number& other);
    bool operator==(const Number& other);
    bool operator!=(const Number& other);

    Number& operator--(); // Prefix decrement
    Number operator--(int); // Postfix decrement

    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base
};