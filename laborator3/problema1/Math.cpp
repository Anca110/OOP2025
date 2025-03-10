
#include "Math.h"
#include<iostream>
#include<stdarg.h>// pt (...)
#include<string.h>
#include<stdlib.h>// pt malloc/ realloc
using namespace std;

int Math::Add(int a, int b)
{
	return a + b;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b)
{
	return static_cast<int>(a + b);// pt ca functia returneaza de tip int, dar parametrii sunt double
}
int Math::Add(double a, double b, double c)
{
	return static_cast<int>(a + b + c);
}
int Math::Mul(int a, int b)
{
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
 }
int Math::Mul(double a, double b)
{
	return static_cast<int>(a * b);
}
int Math::Mul(double a, double b, double c)
{
	return static_cast<int>(a * b * c);
}

int Math::Add(int count, ...)
{
	va_list vl;// fac o variabila-lista de tip va_list
	va_start(vl, count);// va_start primeste acea lista de argumente si count=numarul de argumente
	int s = 0;
	for (int i = 0; i <= count; i++)
	{
		int val = va_arg(vl, int);//val primeste cate un argument din lista
		s = s + val;
	}
	return s;
}

char* Math::Add(const char* str1, const char* str2)
{
	if (str1 == nullptr or str2 == nullptr)
		return nullptr;
	int sizetoaloc=0;
	sizetoaloc = strlen(str1) + strlen(str2) + 1;// +1 pt null de la un sir

	//aloc memorie daca nu a fost deja alocata 
	char* cuv = (char*)malloc(sizetoaloc);
	//void* memset(void* dest, int valoare, size_t numar_bytes);- seteaza zona de memorie cu o anumita valoare
	memset(cuv, 0, sizetoaloc);
	if (cuv != nullptr)// verifica daca malloc a reusit 
	{
		//cuv are alocat un nr de sizetoaloc bytes
		memcpy(cuv, str1, strlen(str1));//pun str1 care face parte din cuv pe un numar de strlen(str1) bytes
		memcpy(cuv + strlen(str1), str2, strlen(str2));//pun de la pozitia cuv+strlen(str1)
	}
	return cuv;
}