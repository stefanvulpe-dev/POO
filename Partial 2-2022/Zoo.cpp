#include "Zoo.h"

Zoo::Zoo() {
	this->animals = vector<Animal*>(0);
}

Zoo::~Zoo() {
	for (int i = 0; i < this->animals.size(); ++i) {
		delete this->animals[i];
	}
}

vector<Animal*> Zoo::GetFishes() const {
	vector<Animal*> v; 
	
	for (int i = 0; i < this->animals.size(); ++i) {
		if (this->animals[i]->IsAFish()) {
			v.push_back(this->animals[i]);
		}
	}
	return v;
}

vector<Animal*> Zoo::GetBirds() const {
	vector<Animal*> v;

	for (int i = 0; i < this->animals.size(); ++i) {
		if (this->animals[i]->CanFly()) {
			v.push_back(this->animals[i]);
		}
	}
	return v;
}

vector<Animal*> Zoo::GetMammals() const {
	vector<Animal*> v;

	for (int i = 0; i < this->animals.size(); ++i) {
		if (!this->animals[i]->IsAFish() && !this->animals[i]->CanFly()) {
			v.push_back(this->animals[i]);
		}
	}
	return v;
}

vector<Feline*> Zoo::GetFelines() const {
	vector<Feline*> v;

	for (int i = 0; i < this->animals.size(); ++i) {
		auto x = dynamic_cast<Feline*>(this->animals[i]);
		if (x != nullptr) {
			v.push_back(x);
		}
	}
	return v;
}

int Zoo::GetTotalAnimals() const {
	return this->animals.size();
}

void Zoo::operator+=(Animal* animal) {
	this->animals.push_back(animal);
}

bool Zoo::operator()(string name) {
	for (int i = 0; i < this->animals.size(); ++i) {
		if (this->animals[i]->GetName() == name) {
			return true;
		}
	}
	return false;
}

