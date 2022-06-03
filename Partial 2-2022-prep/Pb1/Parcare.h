#pragma once
#include <iostream>
#include "Masina.h"

using namespace std;

class Parcare {
private: 
	int maxCapacity, arrSize;
	Masina** carsArr;
public: 
	Parcare();
	~Parcare();
	void Create(int maxCapacity); 
	bool Add(Masina*); 
	void RemoveByName(string name);
	int GetCount(); 
	bool IsFull(); 
	void ShowAll(); 
	void ShowByColor(string color); 
};