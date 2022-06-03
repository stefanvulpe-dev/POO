#pragma once
#include "Angajat.h"

class Programator : public Angajat {
private: 
	string cod; 
public: 
	Programator(); 
	Programator(string nume, int salariu, int id); 
	virtual ~Programator();
	string GetCode() const;
	void Add(string cod);
	void Lucreaza() override; 
};