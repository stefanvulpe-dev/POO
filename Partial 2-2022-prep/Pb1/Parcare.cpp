#include "Parcare.h"

Parcare::Parcare() {
	this->maxCapacity = 0;
	this->arrSize = 0;
	this->carsArr = nullptr;
}

Parcare::~Parcare() {
	for (int i = 0; i < this->arrSize; ++i) {
		delete this->carsArr[i]; 
		this->carsArr[i] = nullptr;
	}
	delete[] this->carsArr;
	this->arrSize = 0;
	this->maxCapacity = 0;
}

void Parcare::Create(int maxCapacity) {
	this->maxCapacity = maxCapacity;
	this->arrSize = 0;
	this->carsArr = new Masina * [maxCapacity];
}

bool Parcare::Add(Masina* car) {
	if (this->arrSize + 1 > maxCapacity) {
		return false; 
	}
	else {
		this->carsArr[this->arrSize] = car;
		this->arrSize++; 
		return true;
	}
}

void Parcare::RemoveByName(string name) {
	Masina* tmp = nullptr;
	for (int i = 0; i < this->arrSize; ++i) {
		if (this->carsArr[i]->GetName() == name) {
			tmp = this->carsArr[i];
			for (int j = i + 1; j < this->arrSize; ++j) {
				this->carsArr[j - 1] = this->carsArr[j];
			}
			delete tmp;
			tmp = nullptr;
			i--;
			this->arrSize--;
		}
	}
}

int Parcare::GetCount() {
	return this->arrSize;
}

bool Parcare::IsFull() {
	return (this->arrSize == this->maxCapacity);
}

void Parcare::ShowAll() {
	cout << "SHOW-ALL: ";
	
	for (int i = 0; i < this->arrSize; ++i) {
		cout << this->carsArr[i]->GetName() << "(" << this->carsArr[i]->GetColor() << ")"; 
		if (i != this->arrSize - 1) {
			cout << ",";
		}
		cout << " ";
	}
	cout << "\n";
}

void Parcare::ShowByColor(string color) {
	cout << "SHOW-COLOR" << "(" << color << "): ";

	for (int i = 0; i < this->arrSize; ++i) {
		if (this->carsArr[i]->GetColor() == color) {
			cout << this->carsArr[i]->GetName(); 
			if (i != this->arrSize - 1) {
				cout << ",";
			}
			cout << " ";
		}
	}

	cout << "\n";
}
