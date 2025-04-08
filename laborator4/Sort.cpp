
#include "Sort.h"
#include<iostream>
#include<stdio.h>// pt random
#include<time.h>// pt random
#include<stdlib.h>//pt random
#include<stdarg.h>//pt variadic

using namespace std;

Sort::Sort(int numar_elemente, int min_element, int max_element)//constructor care genereaza nr random (cu minimul si maximul de elelemente generate)
{
	int* vector_elemente = new int[numar_elemente];//aloc memorie pt vector
	srand(time(0));// nr generate sa fie diferite in functie de timpul actual de rulare
	for (int i = 0; i < numar_elemente; i++)
	{
		vector_elemente[i] = min_element + rand() % (max_element - min_element + 1);//rand() → returnează un număr aleator mare;% (max - min + 1) → îl limitează la o valoare între 0 și (max - min); + min_element → deplasează rezultatul ca să fie în intervalul dorit [min, max]
		cout << vector_elemente[i] << " ";
	}

}

/*Sort::Sort(initializer_list<int> lista)//???????????
{
	numar_elemente = lista.size();  // Aflãm numãrul de elemente din listã
	vector_elemente = new int[numar_elemente];  // Alocãm memorie pentru vector

	int i = 0;
	for (int num : lista) {  // Copiem elementele în vector
		vector_elemente[i++] = num;
		cout << vector_elemente[i] << endl;
	}
}*/


Sort::Sort(int* vector, int numar_elemente)
{
	vector_elemente = new int[numar_elemente];
	for (int i = 0; i < numar_elemente; i++) 
	{
		vector_elemente[i] = vector[i];
		cout << vector_elemente[i] <<" ";
	}
}

Sort::Sort(int numar_elemente, ...)
{
	vector_elemente = new int[numar_elemente];
	va_list vl;
	va_start(vl, numar_elemente);//initializez lista
	for (int i = 0; i < numar_elemente; i++)
	{
		vector_elemente[i] = va_arg(vl, int);//extrag fiecare element din lista vl ca un int
		cout << vector_elemente[i] << " ";
	}
	va_end(vl);
}

Sort::Sort(char* sir)
{
	numar_elemente = 1;//am cel putin un nr
	for (int i = 0; sir[i] != '\0'; i++) 
	{
		if (sir[i] == ',')
		{
			numar_elemente++;
		}
	}
	vector_elemente = new int[numar_elemente];

	int nr = 0;
	int j = 0;//pt lungimea vectoruli de numere
	for (int i = 0; sir[i] != '\0'; i++) 
	{
		if (sir[i] >= '0' && sir[i] <= '9')
		{
			 nr = nr * 10 + (sir[i] - '0');
		}
		else 
		if (sir[i] == ',')
		{
			vector_elemente[j] = nr;
			nr = 0;//resetez pt urmatorul nr
			j++;
		}
	}
	vector_elemente[j] = nr;//pt ultimul nr dupa care nu mai urmeaza ,
}


void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < numar_elemente; ++i)
	{
		int key = vector_elemente[i];
		int j = i - 1;
		while (j >= 0 && ((ascendent && vector_elemente[j] > key) ||(!ascendent && vector_elemente[j] < key)))
		{
			vector_elemente[j + 1] = vector_elemente[j];
			j = j - 1;
		}
		vector_elemente[j + 1] = key;
	}
}

void Sort::QuickSort(bool ascendent)
{
	quickSort(0, numar_elemente - 1, ascendent);
}
int Sort::partition(int low, int high, bool ascendent)
{
	int pivot = vector_elemente[high];//ultiml element
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) 
	{
		if ((ascendent && vector_elemente[j] < pivot) ||(!ascendent && vector_elemente[j] > pivot)) 
		{
			i++;
			swap(vector_elemente[i], vector_elemente[j]);
		}
	}
	swap(vector_elemente[i + 1], vector_elemente[high]);//i unde e ultimul element mai mic decat pivotul=> pun pe urmatorul
	return i + 1;
}
void Sort::quickSort(int low, int high, bool ascendent)
{
	if (low < high)
	{
		int pi = partition(low, high, ascendent);

		quickSort(low, pi - 1, ascendent);
		quickSort(pi + 1, high, ascendent);
	}
}

void Sort::BubbleSort(bool ascendent)
{
	bool swapped;

	for (int i = 0; i < numar_elemente - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < numar_elemente - i - 1; j++)
		{
			if ((ascendent && vector_elemente[j] > vector_elemente[j + 1]) || (!ascendent && vector_elemente[j] < vector_elemente[j + 1]))
			{
				swap(vector_elemente[j], vector_elemente[j + 1]);
				swapped = true;
			}
		}//e deja sortat daca nu s a facut schimbari
		if (!swapped)
			break;
	}
}

void Sort::Print()
{
	for (int i = 0; i < numar_elemente; i++)
	{
		cout << vector_elemente[i] << " ";
	}
	cout << endl;
}

int Sort::GetElementsCount()
{
	return numar_elemente;
}

int Sort::GetElementFromIndex(int index) 
{
	if (index < 0 || index >= numar_elemente)
	{
		cerr << "nu exista acest index" << endl;
		return -1;
	}
	return vector_elemente[index];
}
