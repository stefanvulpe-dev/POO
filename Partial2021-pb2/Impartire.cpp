#pragma once
#include "Impartire.h"

int Impartire::calcul(int t1, int t2) {
	if (t2 != 0) {
		return (t1 / t2);

	}
	else {
		printf("Eroare, nu se poate efectua impartirea la 0\n");
		return -1;
	}
}

const char* Impartire::getName() {
	return "Impartire";
}