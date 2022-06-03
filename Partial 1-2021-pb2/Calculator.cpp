#pragma once
#include <cstdio> 
#include <cstdlib>
#include <cstring>
#include "Calculator.h"

Calculator::Calculator() {
	if (this->arr == nullptr) {
		this->arr = (Operation**)(malloc(sizeof(Operation*)));
		memset(this->arr, 0, sizeof(Operation*));
	}
	this->arr_size = 0;
}

Calculator::~Calculator() {
	for (int i = 0; i < this->arr_size; ++i) {
		free(this->arr[i]);
	}
	free(this->arr); 
	this->arr_size = 0;
}

void Calculator::Compute(int t1, int t2) {
	for (int i = 0; i < this->arr_size; ++i) {
		printf("%s(%d,%d) = %d\n", this->arr[i]->getName(), t1, t2, this->arr[i]->calcul(t1, t2));
	}
}

bool Calculator::operator[](const char* str) {
	for (int i = 0; i < this->arr_size; ++i) {
		if (strcmp(this->arr[i]->getName(), str) == 0)
			return true;
	}
	return false;
}

void Calculator::operator+=(Operation* op) {
	if (!this->operator[](op->getName())) {
		this->arr = (Operation**)(realloc(this->arr, (this->arr_size + 1) * sizeof(Operation*)));
		this->arr[this->arr_size] = op;
		this->arr_size++;
	}
}

void Calculator::operator-=(const char* str) {
	bool ok = false;
	int poz;
	for (int i = 0; i < this->arr_size && !ok; ++i) {
		if (strcmp(this->arr[i]->getName(), str) == 0) {
			ok = true;
			poz = i;
		}
	}

	if (ok) {
		free(this->arr[poz]);
		this->arr[poz] = nullptr;
		for (int i = poz + 1; i < this->arr_size; ++i) {
			this->arr[i - 1] = this->arr[i];
		}
		this->arr[this->arr_size - 1] = nullptr;
		this->arr_size--;
	}
}

Calculator::operator int() {
	return (this->arr_size);
}


