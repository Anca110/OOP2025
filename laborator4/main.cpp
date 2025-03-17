#include"Sort.h"
#include<iostream>
using namespace std;

int main()
{
    Sort s1(10, 1, 100);//constructor cu nr random
    s1.Print();

    int v[] = { 10, 20, 5, 7, 1 };
    Sort s2(v, 5);//constructor cu vector existent
    s2.Print();

    Sort s3(6, 50, 40, 30, 20, 10, 5);//constructor cu variadic
    s3.Print();

    char sir[] = "12,45,23,8,90,34,76";
    Sort s4(sir);//constructor cu sir
    s4.Print();

    Sort s5();

    cout << "Nr de elemente in s4: " << s4.GetElementsCount() << endl;
    cout << "Elementul de pe pozitia 2 in s4: " << s4.GetElementFromIndex(2) << endl;
    cout << "Elementul de pe pozitia 10 in s4: " << s4.GetElementFromIndex(10) << endl;

    s2.InsertSort(true);// Sortare crescãtoare
    s2.Print();

    s3.QuickSort(true);
    s3.Print();

    s4.BubbleSort(false);
    s4.Print();

	return 0;
}