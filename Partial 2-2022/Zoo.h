#pragma once
#include <vector>
#include "Animal.h"
#include "Feline.h"

using namespace std; 

class Zoo {
private: 
	vector<Animal*> animals; 
public: 
	Zoo(); 
	~Zoo();
	vector <Animal*> GetFishes() const;
	vector <Animal*> GetBirds() const;
	vector <Animal*> GetMammals() const;
	vector <Feline*> GetFelines() const;
	int GetTotalAnimals() const;
	void operator +=(Animal* animal); 
	bool operator() (string name);
};