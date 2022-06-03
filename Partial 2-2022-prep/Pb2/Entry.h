#pragma once
#include <iostream>
#include <string>

using namespace std; 

class Entry {
protected:
	string name;
public: 
	Entry();
	Entry(string name); 
	string GetName(); 
	virtual void Add(string toAdd) = 0; 
	virtual bool Subtract(int toSubtract) = 0;
	virtual void Print() = 0;
};