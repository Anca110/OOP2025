#include<iostream>
#include "NumberList.h"
using namespace std;

int main()
{
	NumberList l;

	l.Init();

	l.Add(3);
	l.Add(7);
	l.Add(5);
	l.Add(8);
	l.Add(4);
	l.Add(6);
	l.Add(2);
	l.Add(1);
	l.Add(9);
	l.Add(0);

	cout << "Lista initiala este:";
		l.Print();

	l.Sort();
	cout << "lista sortata este:";
	l.Print();

	return 0;
}