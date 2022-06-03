#pragma once
#include "Angajat.h"

class Manager : public Angajat {
private: 
	vector<Angajat*> echipa; 
	string numeEchipa; 
public: 
	Manager(); 
	Manager(string numeEchipa, string nume, int salariu, int id);
	~Manager(); 
	bool Angajeaza(Angajat* angajat);
	bool Concediaza(Angajat* angajat); 
	Angajat* GetAngajat(int id) const;
	void Lucreaza() override;
};