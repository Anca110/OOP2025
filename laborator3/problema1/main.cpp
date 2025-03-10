#include<iostream>
#include "Math.h"
using namespace std;

int main()
{
	cout << "suma a doua nr intregi:" << Math::Add(3, 5) << endl;
	cout << "suma a 3 nr intregi:" << Math::Add(3, 5, 6) << endl;
	cout << "suma a doua nr de tip double:" << Math::Add(3.5, 5.7) << endl;
	cout << "suma a 3 nr de tip double:" << Math::Add(3.6, 5.4, 2.5) << endl;

	cout << "produsul a doua nr intregi:" << Math::Add(2, 5) << endl;
	cout << "produsul a 3 nr intregi:" << Math::Add(3, 5, 4) << endl;
	cout << "produsul a doua nr de tip double:" << Math::Add(3.5, 0.7) << endl;
	cout << "produsul a 3 nr de tip double:" << Math::Add(3.1, 5.4, 6.5) << endl;

	cout << "suma a mai multe nr este:" << Math::Add(1, 2, 3, 4, 5) << endl;

	char* cuv= Math::Add("Hello ", "World!");
	cout << "concatenare siruri :" << cuv << endl;
	free(cuv);//eliberez memoria dupa ce il afisez


	return 0;
}