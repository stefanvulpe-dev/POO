#include "Programator.h"

Programator::Programator() : Angajat(), cod("") { }

Programator::Programator(string nume, int salariu, int id) : Angajat(nume, salariu, id) { }

Programator::~Programator() {
	this->salariu = 0;
	this->id = 0;
	this->nume = "";
	this->cod = "";
}

string Programator::GetCode() const {
	return this->cod;
}

void Programator::Add(string cod) {
	this->cod += cod;
}

void Programator::Lucreaza() {
	cout << "[" << this->nume << "]:\n" << this->cod;
}
