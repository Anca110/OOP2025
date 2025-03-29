#pragma once
#include<iostream>
class Number
{
private:
    char* value;
    int base;

public:
    Number(const char* numar, int base);
    Number(int value);
    Number(const Number& obiect);//copy constructor
    Number(Number&& obiect);//move constructor
    Number& operator=(int value);
    Number& operator=(const char* value);
    Number& operator=(Number&& obiect);
    ~Number();

    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount();
    int GetBase();

    friend Number operator+(const Number& a, const Number& b);//pt a acesa membrii private ai clasei(fara o metoda get)
    friend Number operator-(const Number& a, const Number& b);

    Number& operator--();
    Number operator--(int);

    char& operator[](int index);//operator de indexare
    bool operator<(const Number& obiect);
    bool operator>(const Number& obiect);//compar doua obiecte de tip number
    bool operator<=(const Number& obiect);
    bool operator>=(const Number& obiect);
    bool operator==(const Number& obiect);
    bool operator!=(const Number& obiect);

    static int ToDecimal(const char* value, int base);
};

