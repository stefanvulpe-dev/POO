#pragma once
#include "Animal.h"

class Cow : public Animal {
public: 
	Cow() : Animal("Cow") { }

	string GetName() const {
		return this->name;
	}

	bool CanFly() const {
		return false;
	}

	bool IsAFish() const {
		return false;
	}
};