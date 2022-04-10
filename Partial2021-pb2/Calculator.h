#pragma once
#include "Operation.h"

class Calculator {
private:
	Operation** arr;
	int arr_size;
public: 
	Calculator();
	~Calculator();
	void Compute(int t1, int t2); 
	bool operator [] (const char* str);
	void operator += (Operation * op); 
	void operator -= (const char* str); 
	operator int();
};