#pragma once
#include "Animal.h" 

class Shark : public Animal {
public: 
	Shark() : Animal("Shark") { }

	string GetName() const {
		return this->name;
	}

	bool CanFly() const {
		return false;
	}

	bool IsAFish() const {
		return true;
	}
};