#include "Manager.h"

Manager::Manager() : Angajat(), numeEchipa(""), echipa(0) { }

Manager::Manager(string numeEchipa, string nume, int salariu, int id) : Angajat(nume, salariu, id), numeEchipa(numeEchipa) { }

Manager::~Manager() {
	this->numeEchipa = ""; 
}

bool Manager::Angajeaza(Angajat* angajat) {
	for (int i = 0; i < this->echipa.size(); ++i) {
		if (this->echipa[i]->id == angajat->id) {
			return false;
		}
	}
	this->echipa.insert(this->echipa.end(), angajat); 
	return true;
}

bool Manager::Concediaza(Angajat* angajat) {
	for (int i = 0; i < this->echipa.size() - 1; ++i) {
		if (this->echipa[i]->id == angajat->id) {
			for (int j = i + i; j < this->echipa.size(); ++j) {
				this->echipa[j - 1] = this->echipa[j];
			}
			this->echipa.pop_back();
			return true;
		}
	}
	
	if (this->echipa[this->echipa.size() - 1]->id == angajat->id) {
		this->echipa.pop_back();
		return true;
	}

	return false;
}

Angajat* Manager::GetAngajat(int id) const {
	for (int i = 0; i < this->echipa.size(); ++i) {
		if (this->echipa[i]->id == id) {
			return this->echipa[i];
		}
	}
	return nullptr;
}

void Manager::Lucreaza() {
	cout << "================\n";
	cout << this->numeEchipa << "\n"; 
	
	for (int i = 0; i < this->echipa.size(); ++i) {
		this->echipa[i]->Lucreaza();
	}

	cout << "================\n";
}
