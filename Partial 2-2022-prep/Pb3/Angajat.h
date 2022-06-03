#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Angajat {
protected: 
	int salariu, id; 
	string nume;
public: 
	Angajat(); 
	Angajat(string nume, int salariu, int id);
	~Angajat();
	string GetNume() const; 
	int GetSalariu() const; 
	bool SetSalariu(int salariu); 
	virtual void Lucreaza() = 0; 
	friend class Manager;
};