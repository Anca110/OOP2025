#include<iostream>
#include "student.h"
using namespace std;

void Student::setname(const char* numestudent)
{
	strcpy(nume, numestudent);
}
void Student::setmathgrade(int notamate)
{
	if(notamate >= 1 && notamate <= 10)
	{
		mathgrade=notamate;
	}
}

void Student::setenglishgrade(int notaengleza)
{
	if (notaengleza >= 1 && notaengleza <= 10)
	{
		englishgrade = notaengleza;
	}
}

void Student::sethistorygrade(int notaistorie)
{
	if (notaistorie >= 1 && notaistorie <= 10)
	{
		historygrade=notaistorie;
	}
}

char* Student::getnume()
{
	return nume;
}

int Student::getmathgrade()
{
	return mathgrade;
}

int Student::getenglishgrade()
{
	return englishgrade;
}

int Student::gethistorygrade()
{
	return historygrade;
}

float Student::medianote()
{
	float media = (mathgrade + englishgrade + historygrade)/3.0;
	return media;
}

