#include<iostream>
#include "NumberList.h"
using namespace std;

//tip functie, nume clasa, :: pt ca functia e din clasa, functia
void NumberList::Init()
{
	count = 0;
}

bool NumberList::Add(int x) 
{
    if (count>=10) 
        return false;//lista e plina, are 10 elemente
    else
    numbers[count++]=x;
    return true;
}

void NumberList::Sort()
{
    for (int i=0; i<count-1; i++) 
    {
        for (int j=0; j< count-i-1; j++)
        {
            if (numbers[j]>numbers[j+1])
            {
                int aux = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = aux;
            }
        }
    }
}

void NumberList::Print()
{
    for (int i = 0; i <= count; i++)
        cout << numbers[i] << " ";
}