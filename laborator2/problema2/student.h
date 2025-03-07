#include<iostream>
using namespace std;

class Student 
{
private:
	char nume[200];
	float mathgrade;
	float englishgrade;
	float historygrade;

public:
	Student();
	void setname(const char* nume);// char* sire, char doar un caracter
	void setmathgrade(int nume);
	void setenglishgrade(int nume);
	void sethistorygrade(int nume);

	char* getnume();
	int getmathgrade();
	int getenglishgrade();
	int gethistorygrade();
	float medianote();

		//char *sir = new char[200], poti sa o pui direct in functie
	
};