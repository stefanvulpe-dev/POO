#pragma once
#include "Feline.h"

class Lion : public Feline {
public:
	Lion() : Feline("Lion", 80) { }

	int GetSpeed() const {
		return this->speed;
	}

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