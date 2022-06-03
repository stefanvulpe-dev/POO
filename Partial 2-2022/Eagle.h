#pragma once
#include "Animal.h"

class Eagle : public Animal {
public: 
	Eagle() : Animal("Eagle") { }

	string GetName() const {
		return this->name;
	}

	bool CanFly() const {
		return true;
	}

	bool IsAFish() const {
		return false;
	}
};