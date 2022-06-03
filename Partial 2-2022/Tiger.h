#pragma once
#include "Feline.h"

class Tiger : public Feline {
public:
	Tiger() : Feline("Tiger", 100) { }

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