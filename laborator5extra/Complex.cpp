
#include "Complex.h"
#include<iostream>
#include <cmath>
using namespace std;

//constructori
Complex::Complex()
{
	this->real_data = 0;
	this->imag_data = 0;

	cout<< "CONSTRUCTOR DEFAULT\n";
}// constructor default; permite crearea unui obiect fara sa i dai parametru ( " " 0 false-  obiectul sa contina valori nedeterminate)

Complex::Complex(double real, double imag)
{
   this-> real_data = real;
   this-> imag_data = imag;

   cout << "CONSTRUCTOR CU PARAMETRII"<<": " << this->real_data << "+" << this->imag_data << "i";
   cout << endl;
}

//metode

bool Complex::is_real() const//const- functia nu modifica nimic in interiorul obiectului
{
	if (this->real_data == 0)
		return true;
	else
		return false;
}

double Complex::real() const
{ 
	return this->real_data;
}

double Complex::imag() const 
{ 
	return this->imag_data;
}

double Complex::abs() const
{
	double r = this->real_data;
	double i = this->imag_data;
	double rezultat =sqrt(r * r + i * i);
	return rezultat;

	cout << "MODULUL :" << rezultat;
	cout << endl;
}

Complex Complex::conjugate() const //const promite ca nu modifica obiectul pentru care apelez(adc this)
{
	double r = this->real_data;
	double i = this->imag_data;
	Complex rezultat(r, -i);//aici apelez constructorul cu parametrii pt a mi crea un obiect numit rezultat

	cout << "CONJUGATUL:" << r << "+" << i << "i";
		cout << endl;
	return rezultat;
}

//operatori
//& pt ca modifica acelasi obiect si vreau sa l returnez pe el nu o copie
Complex& Complex::operator()(double real, double imag)//operator pt apel de functii; care mi modifica valorile create ale unui obiect cu un constructor cu cele din operator
{
	this->real_data = real;
	this->imag_data = imag;
	return *this;
}

//prefix
Complex& Complex::operator++()//inclementeaza partea reala cu 1
{ 
	this->real_data++; 
	return *this; 
}
Complex& Complex::operator--()
{ 
	this->real_data--;
	return *this;
}
//postix
Complex Complex::operator++(int)
{
	Complex aux = *this;//ii fac o copie pt ca la postfix se returneaza copia
	this->real_data++;
	return aux;
}

Complex Complex::operator--(int)
{
	Complex aux = *this;
	this->real_data--;
	return aux;
}

//friends
Complex operator+(const Complex& l, const Complex& r)
{
	double real = l.real_data + r.real_data;
	double imag = l.imag_data + r.imag_data;
	return Complex(real, imag);
}


Complex operator+(const Complex& l, double r)
{
	double real = l.real_data + r;
	double imag = l.imag_data;
	return Complex(real, imag);
}


Complex operator+(double l, const Complex& r) 
{
	double real = l + r.real_data;
	double imag = r.imag_data;
	return Complex(real, imag);
}

Complex operator-(const Complex& l, const Complex& r)
{
	double real = l.real_data - r.real_data;
	double imag = l.imag_data - r.imag_data;
	return Complex(real, imag);
}

Complex operator-(const Complex& l, double r) 
{
	double real = l.real_data - r;
	double imag = l.imag_data;
	return Complex(real, imag);
}


Complex operator-(double l, const Complex& r)
{
	double real = l - r.real_data;
	double imag = -r.imag_data;
	return Complex(real, imag);
}

Complex operator*(const Complex& l, const Complex& r) 
{
	double real = l.real_data * r.real_data - l.imag_data * r.imag_data;
	double imag = l.real_data * r.imag_data + l.imag_data * r.real_data;
	return Complex(real, imag);
}


Complex operator*(const Complex& l, double r)
{
	double real = l.real_data * r;
	double imag = l.imag_data * r;
	return Complex(real, imag);
}


Complex operator*(double l, const Complex& r)
{
	double real = l * r.real_data;
	double imag = l * r.imag_data;
	return Complex(real, imag);
}

Complex operator-(const Complex& obiect)
{
	return Complex(-obiect.real_data, -obiect.imag_data);//apelez constructorul pt a crea un obiect dar cu semnul schimbat
}

bool operator==(const Complex& l, const Complex& r)//verif egalitatea dintre 2 nr complexe- obiecte
{
	if (l.real_data == r.real_data && l.imag_data == r.imag_data)
		return true;
	else
		return false;
}

bool operator!=(const Complex& l, const Complex& r)//verifica inegalitatea dintre 2 obiecte
{
	if (l.real_data != r.real_data || l.imag_data != r.imag_data)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, const Complex& c) 
{
	if (c.real_data == 0 && c.imag_data == 0)
	{
		out << "0";
	}

	else if (c.imag_data == 0) 
	{
		out << c.real_data;
	}

	else if (c.real_data == 0)
	{
		out << c.imag_data << "i";
	}

	else 
	{
		out << c.real_data;

		if (c.imag_data >= 0) 
		{
			out << " + " << abs(c.imag_data) << "i";
		}
		else
		{
			out << " - " << abs(c.imag_data) << "i";
		}
	}

	return out;
}













