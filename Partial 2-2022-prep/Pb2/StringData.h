#pragma once
#include "Entry.h"

class StringData : public Entry {
private:
	string value; 
public: 
	StringData(string name, string value); 
	void Add(string toAdd) override; 
	bool Subtract(int toSubtract) override;
	void Print() override;
};