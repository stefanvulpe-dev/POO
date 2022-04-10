#pragma once
#include "Operation.h"

class Scadere : public Operation {
public:
	int calcul(int t1, int t2) override;
	const char* getName() override;
}; 
