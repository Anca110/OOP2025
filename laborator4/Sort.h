#pragma once
class Sort
{
    int* vector_elemente;
    int numar_elemente;
public:
    Sort(int numar_elemente, int min_element, int max_element);

    /*Sort(initializer_list<int> lista);*/

    Sort(int* vector, int numar_elemente);

    Sort(int numar_elemente, ...);

    Sort(char* sir);



    void InsertSort(bool ascendent = false);

    void quickSort(int low, int high, bool ascendent);
    int partition(int low, int high, bool ascendent);
    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);
};

