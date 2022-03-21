#include <cstdio> 
#include <cstdlib> 
#include <cstring>
#include <cmath>

#include "Number.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

Number::Number(const char* value, int base)
{
    this -> value = (char*)(malloc(256));
    memcpy(this -> value, value, 256);
    this -> base = base;
}

Number::Number(const char* value)
{
    this -> value = (char*)(malloc(256));
    memcpy(this -> value, value, 256);
    this -> base = 10;
}

Number::Number(int value)
{
    this -> value = (char*)(malloc(256));

    char* num = (char*)(malloc(256)); 
    int k = 0;

    do {
        num[k ++] = (value % 10) + '0'; 
        value /= 10;
    } while(value != 0);

    num[k] = '\0';

    memset(this -> value, '\0', k + 1);

    memcpy(this -> value, strrev(num), k);
    
    this -> base = 10;
    
    free(num);
}

Number::Number(const Number& n)
{
    memset(this -> value, 0, strlen(n.value) + 1);
    memcpy(this -> value, n.value, strlen(n.value));
    this -> base = n.base;
}

Number::Number(Number&& n)
{
    memset(this -> value, '\0', strlen(n.value) + 1);
    memcpy(this -> value, n.value, strlen(n.value));

    this -> base = n.base;

    n.value = nullptr;
    n.base = 0;
}

Number::~Number()
{
    free(this -> value); 
    this -> base = 0;
}

Number& Number::operator = (Number&& n)
{
    memset(this -> value, '\0', strlen(n.value) + 1);
    memcpy(this -> value, n.value, strlen(n.value)); 
    
    this -> base = n.base;

    n.value = nullptr;
    n.base = 0;

    return (*this);
}

Number& Number::operator = (const char* value)
{
    int a = 0, k = 0, p = 1;
    char* num = (char*)malloc(256);

    for(int i = strlen(value) - 1; i >= 0; -- i)
    {
        p = 1; 
        int j = strlen(value) - i - 1;
        while(j > 0)
        {
            p *= 10; 
            j --;
        }
        a += ((value[i] >= 'A') ? ((value[i] - 55) * p) : ((value[i] - '0') * p));
    }

    while(a != 0)
    {
        num[k ++] = char(((a % this -> base >= 10) ? ((a % this -> base) % 10 + 'A') : (a % this -> base + '0')));
        a /= this -> base; 
    }

    num[k] = '\0';

    memset(this -> value, '\0', k + 1);
    
    memcpy(this -> value, strrev(num), k);

    //printf("%s\n", this -> value);

    free(num);

    return (*this);
}

Number& Number::operator = (int value)
{
    int k = 0;
    char* num = (char*)(malloc(256));

    while(value != 0)
    {
        num[k ++] = char(((value % this -> base >= 10) ? ((value % this -> base) % 10 + 'A') : (value % this -> base + '0')));
        value /= this -> base; 
    }

    num[k] = '\0';

    memset(this -> value, '\0', k + 1);

    memcpy(this -> value, strrev(num), k);

    free(num);
    
    return (*this);
}

Number& Number::operator -- ()
{
    memcpy(this -> value, this -> value + 1, strlen(this -> value) - 1);
    this -> value[strlen(this -> value) - 1] = '\0';
    return (*this);
}

Number& Number::operator -- (int)
{
    this -> value[strlen(this -> value) - 1] = '\0';
    return (*this);
}

Number& Number::operator += (const Number& n)
{
    Number n1 = (*this) + n;
    
    memset(this -> value, '\0', strlen(n1.value) + 1);
    
    memcpy(this -> value, n1.value, strlen(n1.value));

    this -> base = n1.base; 

    delete &n1; 

    return (*this);
}

Number& Number::operator -= (const Number& n)
{
    Number n1 = (*this) - n;
    
    memset(this -> value, '\0', strlen(n1.value) + 1);
    
    memcpy(this -> value, n1.value, strlen(n1.value));

    this -> base = n1.base; 

    delete &n1; 

    return (*this);
}

Number operator + (const Number& n1, const Number& n2)
{
    int maxBase, k = 0, a = 0, b = 0, p, c;
    char* num = (char*)(malloc(256));

    if(n1.base > n2.base)
    {
        maxBase = n1.base;
    }
    else 
    {
        maxBase = n2.base;
    }

    //convert first to base 10
    for(int i = strlen(n1.value) - 1; i >= 0; -- i)
    {
        p = 1; 
        int j = strlen(n1.value) - i - 1;
        while(j > 0)
        {
            p *= n1.base; 
            j --;
        }
        a += ((n1.value[i] >= 'A') ? ((n1.value[i] - 55) * p) : ((n1.value[i] - '0') * p));
    }

    //convert second to base 10
    for(int i = strlen(n2.value) - 1; i >= 0; -- i)
    {
        p = 1; 
        int j = strlen(n2.value) - i - 1;
        while(j > 0)
        {
            p *= n2.base; 
            j --;
        }
        b += ((n2.value[i] >= 'A') ? ((n2.value[i] - 55) * p) : ((n2.value[i] - '0') * p));
    }

    c = a + b; 

    while(c != 0)
    {
        num[k ++] = char(((c % maxBase >= 10) ? ((c % maxBase) % 10 + 'A') : (c % maxBase + '0')));
        c /= maxBase; 
    }

    num[k] = '\0';

    Number newNumber(strrev(num), maxBase);

    free(num);

    return newNumber;
}

Number operator - (const Number& n1, const Number& n2)
{
    int maxBase, k = 0, a = 0, b = 0, p, c;
    char* num = (char*)(malloc(256));

    if(n1.base > n2.base)
    {
        maxBase = n1.base;
    }
    else 
    {
        maxBase = n2.base;
    }

    //convert first to base 10
    for(int i = strlen(n1.value) - 1; i >= 0; -- i)
    {
        p = 1; 
        int j = strlen(n1.value) - i - 1;
        while(j > 0)
        {
            p *= n1.base; 
            j --;
        }
        a += ((n1.value[i] >= 'A') ? ((n1.value[i] - 55) * p) : ((n1.value[i] - '0') * p));
    }

    //convert second to base 10
    for(int i = strlen(n2.value) - 1; i >= 0; -- i)
    {
        p = 1; 
        int j = strlen(n2.value) - i - 1;
        while(j > 0)
        {
            p *= n2.base; 
            j --;
        }
        b += ((n2.value[i] >= 'A') ? ((n2.value[i] - 55) * p) : ((n2.value[i] - '0') * p));
    }

    c = abs(a - b); 

    while(c != 0)
    {
        num[k ++] = char(((c % maxBase >= 10) ? ((c % maxBase) % 10 + 'A') : (c % maxBase + '0')));
        c /= maxBase; 
    }

    num[k] = '\0';

    Number newNumber(strrev(num), maxBase);

    free(num);

    return newNumber;
}

char Number::operator [] (int index)
{
    if(index >= 0 && index < strlen(this -> value))
    {
        return this -> value[strlen(this -> value) - index - 1];
    }
    return '\0';
}

bool Number::operator < (const Number& n)
{
    Number n1(this -> value, this -> base); 
    Number n2(n.value, n.base);  

    n1.SwitchBase(10);
    n2.SwitchBase(10);

    if(strcmp(n1.value, n2.value) < 0)
    {
        return true;
    }

    return false;
}

bool Number::operator > (const Number& n)
{
    Number n1(this -> value, this -> base); 
    Number n2(n.value, n.base);

    n1.SwitchBase(10);
    n2.SwitchBase(10);

    if(strcmp(n1.value, n2.value) > 0)
    {
        return true;
    }
    
    return false;
}

bool Number::operator <= (const Number& n)
{
    Number n1(this -> value, this -> base); 
    Number n2(n.value, n.base);

    n1.SwitchBase(10);
    n2.SwitchBase(10);

    if(strcmp(n1.value, n2.value) <= 0)
    {
        return true;
    }
    
    return false;
}

bool Number::operator >= (const Number& n)
{
    Number n1(this -> value, this -> base); 
    Number n2(n.value, n.base);

    n1.SwitchBase(10);
    n2.SwitchBase(10);

    if(strcmp(n1.value, n2.value) >= 0)
    {
        return true;
    }
    
    return false;
}

bool Number::operator == (const Number& n)
{
    Number n1(this -> value, this -> base); 
    Number n2(n.value, n.base);

    n1.SwitchBase(10);
    n2.SwitchBase(10);

    if(strcmp(n1.value, n2.value) == 0)
    {
        return true;
    }
    
    return false;
}

void Number::SwitchBase(int newBase)
{
    if(this -> base != newBase)
    {
        int a = 0, k = 0, p = 1;
        char* num = (char*)(malloc(256));

        for(int i = strlen(this -> value) - 1; i >= 0; -- i)
        {
            p = 1; 
            int j = strlen(this ->value) - i - 1;
            while(j > 0)
            {
                p *= this -> base; 
                j --;
            }
            a += ((this -> value[i] >= 'A') ? ((this -> value[i] - 55) * p) : ((this -> value[i] - '0') * p));
        }

        while(a != 0)
        {
            num[k ++] = char(((a % newBase >= 10) ? ((a % newBase) % 10 + 'A') : (a % newBase + '0')));
            a /= newBase; 
        }

        num[k] = '\0';

        memset(this -> value, '\0', k + 1); 

        memcpy(this -> value, strrev(num), k);

        this -> base = newBase;
    
        free(num);
    }   
}

void Number::Print()
{
    printf("%s\n", this -> value); 
}

int Number::GetDigitsCount()
{
    return strlen(this -> value);
}

int Number::GetBase()
{
    return this -> base;
}