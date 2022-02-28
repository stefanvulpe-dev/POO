#include <cstdio> 
#include "includes/NumberList.h"

#define _CRT_SECURE_NO_WARNINGS

int main()
{
    NumberList list1 = NumberList();
    list1.Init(); 

    list1.Add(11); 
    list1.Add(5);
    list1.Add(4);
    list1.Add(3);
    list1.Add(6);
    list1.Add(25);

    list1.Sort(); 

    list1.Print();

    return 0;
}