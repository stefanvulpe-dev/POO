#pragma once

class Sort
{
private: 
    int * arr, nr_elem; 
public:
    //random
    Sort(int nr_elem, int min, int max);

    //initialization list
    Sort(int nr_elem);

    //vector
    Sort(int * vector, int nr_elem);

    //variadic
    Sort(int count, ...); 

    //String
    Sort(char * s);

    void InsertSort(bool ascendent=false);

    void QuickSort(int low, int high, bool ascendent=false);

    void BubbleSort(bool ascendent=false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);
};