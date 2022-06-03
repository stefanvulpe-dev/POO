#pragma once
#include <iostream> 
#include <string>

using namespace std;

class Shape {
protected: 
	string name;
public: 
	Shape();
	Shape(string name);
	virtual string GetName() = 0;
	virtual string GetColor() = 0;
};