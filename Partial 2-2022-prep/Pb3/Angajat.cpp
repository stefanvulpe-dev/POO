#include "Angajat.h"

Angajat::Angajat() {
	this->salariu = 0; 
	this->id = 0; 
	this->nume = "";
}

Angajat::Angajat(string nume, int salariu, int id) {
	this->nume = nume; 
	this->salariu = salariu; 
	this->id = id;
}

Angajat::~Angajat() {
	this->salariu = 0;
	this->id = 0;
	this->nume = "";
}

string Angajat::GetNume() const {
	return this->nume;
}

int Angajat::GetSalariu() const {
	return this->salariu;
}

bool Angajat::SetSalariu(int salariu) {
	if (this->salariu == 0) {
		this->salariu = salariu; 
		return true;
	}
	return false;
}
