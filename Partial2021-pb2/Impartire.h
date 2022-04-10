#pragma once
#include <cstdio>
#include "Operation.h"

class Impartire : public Operation {
public:
	int calcul(int t1, int t2) override;
	const char* getName() override;
};