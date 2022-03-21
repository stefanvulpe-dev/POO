#pragma once

class Number
{
private:

    char* value; 
    int base; 

public:

    Number(const char* value, int base); 

    Number(const char* value);

    Number(int value);

    Number(const Number& n);

    Number(Number&& n);

    ~Number();

    Number& operator = (Number&& n);

    Number& operator = (const char* value);

    Number& operator = (int value);

    Number& operator -- (); 

    Number& operator -- (int);

    Number& operator += (const Number& n);

    Number& operator -= (const Number& n);

    char operator [] (int index);

    bool operator < (const Number& n);

    bool operator > (const Number& n); 

    bool operator <= (const Number& n);

    bool operator >= (const Number& n);

    bool operator == (const Number& n);

    friend Number operator + (const Number& n1, const Number& n2);

    friend Number operator - (const Number& n1, const Number& n2);
 
    void SwitchBase(int newBase);

    void Print();

    int  GetDigitsCount(); // returns the number of digits for the current number

    int  GetBase(); // returns the current base
};