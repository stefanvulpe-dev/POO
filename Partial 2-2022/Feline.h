#pragma once
#include "Animal.h"

class Feline : public Animal {
protected: 
	int speed;
public: 
	Feline(string name, int speed) : Animal(name), speed(speed) { }
	virtual int GetSpeed() const = 0;
	virtual string GetName() const = 0;
	virtual bool CanFly() const = 0;
	virtual bool IsAFish() const = 0;
};