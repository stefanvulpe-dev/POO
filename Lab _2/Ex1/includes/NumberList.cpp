#include <cstdio>
#include "NumberList.h"

#define _CRT_SECURE_NO_WARNINGS

NumberList::NumberList(int count) 
{
    this -> count = 0;
}

void NumberList::Init () 
{
    this -> count = 0;
}

bool NumberList::Add(int x)
{
    if(this -> count >= 10)
    {
        return false;
    }
    else
    {
        this -> numbers[this -> count] = x;
        this -> count ++; 
        return true;
    }
}

void NumberList::Sort()
{
    int i, key, j; 

    for(int i = 1 ; i < this -> count; ++ i)
    {
        key = this -> numbers[i]; 
        j = i - 1;

        while((j >= 0) && (this -> numbers[j] > key))
        {
            this -> numbers[j + 1] = this -> numbers[j]; 
            j = j - 1; 
        }
        this -> numbers[j + 1] = key;
    }
}

void NumberList::Print()
{
    for(int i = 0; i < this -> count; ++ i)
    {
        printf("%d ", this -> numbers[i]);
    }
}