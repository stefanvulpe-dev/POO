#pragma once
#include <string>

using namespace std;

class Animal {
protected:
	string name;
public: 
	Animal() : name("") { }
	Animal(string name) : name(name) { }
	virtual string GetName() const = 0;
	virtual bool CanFly() const = 0; 
	virtual bool IsAFish() const = 0;
};
