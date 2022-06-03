#pragma once
#include <iostream>
#include "Entry.h"

using namespace std;

class IntegerData : public Entry {
private: 
	int value; 
public:
	IntegerData(string name, string value); 
	void Add(string toAdd) override; 
	bool Subtract(int toSubtract) override;
	void Print() override;
};