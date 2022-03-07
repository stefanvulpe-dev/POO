#include "Math.h"
#include <cstring>
#include <cstdlib>   
#include <cstdarg> 

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
    return a + b;
}

int Math::Add(double a, double b, double c)
{
    return a + b + c;
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
    return a * b;
}

int Math::Mul(double a, double b, double c)
{
    return a * b * c;
}

int Math::Add(int count, ...)
{
    va_list vl ;
    va_start(vl, count); 
    
    int sum = 0; 

    for(int i = 0; i < count; ++ i)
    {
        sum += va_arg(vl, int);
    }
    va_end(vl); 
    
    return sum;
}

const char * Math::Add(const char * str1, const char * str2)
{
    if(str1 == nullptr || str2 == nullptr)
    {
        return nullptr;
    }
    else
    {
        int sizeForAlloc = strlen(str1) + strlen(str2) + 1; 
        char * str3 = (char *) malloc(sizeForAlloc);
        memset(str3, 0, sizeForAlloc);
        memcpy(str3, str1, strlen(str1)); 
        memcpy(str3 + strlen(str1), str2, strlen(str2)); 
        return (const char *) str3;
    }
}