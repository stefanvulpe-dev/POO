#include <cstdio> 
#include <cstring> 

#include "includes/Sort.h"

#define _CRT_SECURE_NO_WARNINGS

int main()
{   
    Sort list1(5, 10, 50);

    Sort list2(5);

    int * v = new int[10]{11, 21, 14, 15, 12, 31, 32, 56, 87, 10};

    Sort list3(v, 10);

    Sort list4(5, 5, 8, 6, 9, 4);

    char str[] = "7,60,3,9,8,10,25";

    Sort list5(str);

    list1.Print();

    list2.Print();

    list3.Print(); 

    list4.Print();

    list5.Print();

    list1.InsertSort(true);

    printf("Lista 1 sortata cu InsertSort(): ");

    list1.Print();

    list2.QuickSort(0, 9);

    printf("Lista 2 sortata cu QuickSort(): ");

    list2.Print();

    list5.BubbleSort();
    
    printf("Lista 5 sortata cu BubbleSort(): ");

    list5.Print();

    list4.QuickSort(0, list4.GetElementsCount() - 1, true);

    printf("Lista 4 sortata cu QucikSort(): ");

    list4.Print();

    return 0;
}