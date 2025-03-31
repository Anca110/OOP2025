#pragma once
#include<iostream>
using namespace std;
class Complex
{
private:
    double real_data;  
    double imag_data; 

public:
    Complex();//constructor default                        
    Complex(double real, double imag);//constructor cu parametri

    bool is_real() const;//verificã dacã partea imag e 0
    double real() const;
    double imag() const;
    double abs() const;//modul
    Complex conjugate() const;//conjugat

    Complex& operator()(double real, double imag);//& pt ca returnez un obiect deja creat *this (nu unul nou)

    Complex& operator++();// prefix ++ =>returneaza referinta la acelasi obiect
    Complex& operator--();
    Complex operator++(int);//postfix      
    Complex operator--(int);     

    friend Complex operator+(const Complex& l, const Complex& r);
    friend Complex operator+(const Complex& l, double r);
    friend Complex operator+(double l, const Complex& r);

    friend Complex operator-(const Complex& l, const Complex& r);
    friend Complex operator-(const Complex& l, double r);
    friend Complex operator-(double l, const Complex& r);

    friend Complex operator*(const Complex& l, const Complex& r);
    friend Complex operator*(const Complex& l, double r);
    friend Complex operator*(double l, const Complex& r);

    friend Complex operator-(const Complex& obiect);//minus unar; din a(2,4)=> b=-a inversez semnul lui a

    friend bool operator==(const Complex& l, const Complex& r);
    friend bool operator!=(const Complex& l, const Complex& r);

    friend ostream& operator<<(ostream& out, const Complex& c);//friend ii da aceses la membrii privati ai clasei
    //ostream& operator<< TIP DE DATA PE CARE O RETURNEAZA; & RETURNEAZA UN OBIECT DEJA CREAT; ostream& out PARAMETRU FUNCTIE PRIN CARE AFISEZ CELALALT PARAMETRU; out NUMELE PARAMETRULUI
};
//ostream& operator<<(ostream& out, const Complex& c);//!!!!!!! daca obiectul din stanga nu face parte din clasa mea=> friend in clasa ca sa aceseze mebrii obiectului din dreapta care face parte din clasa
////globala pt ca out face parte din alta clasa

