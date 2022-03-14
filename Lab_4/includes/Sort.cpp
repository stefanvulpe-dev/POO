#include <iostream>
#include <cstdio> 
#include <cstdlib> 
#include <cstring>
#include <cstdarg>
#include <time.h>

#include "Sort.h"

using namespace std;

Sort::Sort(int nr_elem, int min_elem, int max_elem)
{
    this -> nr_elem = nr_elem;

    this -> arr = (int *)(malloc(this -> nr_elem * sizeof(int)));

    time_t t; 
    srand((unsigned)time(&t));
    
    for(int i = 0; i < nr_elem; ++ i)
    {
        this -> arr[i] = min_elem + rand() % (max_elem - min_elem + 1);
    }
}

Sort::Sort(int nr_elem): nr_elem(nr_elem), arr(new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {}

Sort::Sort(int * vector, int nr_elem)
{
    if(nr_elem < this -> nr_elem)
    {
        this -> arr = (int *)(realloc(this -> arr, nr_elem * sizeof(int)));
    }
    else 
    {
        this -> arr = (int *)(malloc(nr_elem * sizeof(int)));
    }

    this -> nr_elem = nr_elem;

    memcpy(this -> arr, vector, nr_elem * sizeof(int)); 
}


Sort::Sort(int count, ...)
{
    this -> arr = (int *) (malloc(count * sizeof(int)));

    this -> nr_elem = count;

    int val;

    va_list vl; 
    va_start(vl, count); 
    
    for(int i = 0; i < count; ++ i)
    {
        val = va_arg(vl, int); 
        this -> arr[i] = val;
    }

    va_end(vl);
}

Sort::Sort(char * s)
{
    int count = 0;

    int * v = new int[strlen(s) - 1]; 

    char * p = strtok(s, ",");

    while(p != nullptr)
    {
        //string to number
        int nr = 0, prod = 1;

        for(int i = strlen(p) - 1; i >= 0; -- i)
        {
            nr = nr + (p[i] - '0') * prod; 
            prod *= 10;
        }

        v[count ++] = nr;

        p = strtok(nullptr, ",");
    }

    this -> arr = (int *)(malloc(count * sizeof(int)));

    this -> nr_elem = count;

    memcpy(this -> arr, v, count * sizeof(int));

    delete v;
}

void Sort::InsertSort(bool ascendent)
{
    int i, key, j;

    for (i = 1; i < this -> nr_elem; i++)
    {
        key = this -> arr[i];
        j = i - 1;

        if(ascendent == true)
        {
            while (j >= 0 && this -> arr[j] > key)
            {
                this -> arr[j + 1] = this -> arr[j];
                j = j - 1;
            }
        }
        else
        {
            while (j >= 0 && this -> arr[j] < key)
            {
                this -> arr[j + 1] = this -> arr[j];
                j = j - 1;
            }
        }
        this -> arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high, bool ascendent)
{
    int pivot = arr[high];
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++)
    {

        if(ascendent == true)
        {
            if (arr[j] < pivot)
            {
                i++; 
                swap(arr[i], arr[j]);
            }
        }
        else
        {
            if (arr[j] > pivot)
            {
                i++; 
                swap(arr[i], arr[j]);
            }
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void Sort::QuickSort(int low, int high, bool ascendent)
{
    if (low < high)
    {
        int pi = partition(this -> arr, low, high, ascendent);

        QuickSort(low, pi - 1, ascendent);
        QuickSort(pi + 1, high, ascendent);
    }
}

void Sort::BubbleSort(bool ascendent)
{
    int i, j;

    for (i = 0; i < this -> nr_elem - 1; i ++)   
    {
        for (j = 0; j < this -> nr_elem - i - 1; j ++)
        {
            if(ascendent == true)
            {
                if (this -> arr[j] > this -> arr[j+1])
                    swap(this -> arr[j], this -> arr[j+1]);
            }
            else
            {
                if (this -> arr[j] < this -> arr[j+1])
                    swap(this -> arr[j], this -> arr[j+1]);
            }
        }
    }
}

void Sort::Print()
{
    for(int i = 0; i < this -> nr_elem; ++ i)
    {
        printf("%d ", this -> arr[i]);
    }
    printf("\n");
}

int Sort::GetElementsCount()
{
    return this -> nr_elem;
}

int Sort::GetElementFromIndex(int index)
{
    if(index > 0 && index < this -> nr_elem)
        return this -> arr[index];
    return 0;
}