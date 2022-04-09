#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Catalog.h"
#include "Student.h" 


Catalog::Catalog(){ 
	if (this->studentsArray == nullptr) {
		this->studentsArray = (Student**)(malloc(100 * sizeof(Student*)));
	}
	this->studentsCounter = 0; 
}

Catalog::~Catalog() {
	for (int i = 0; i < this->studentsCounter; ++i) {
		free(this->studentsArray[i]); 
	}
	free(this->studentsArray);
}

int Catalog::getCount() {
	return this->studentsCounter;
}

Student& Catalog::operator [] (const char* str) {
	for (int i = 0; i < this->studentsCounter; ++i) {
		if (strcmp(this->studentsArray[i]->getName(), str) == 0) {
			return *(this->studentsArray[i]);
		}
	}
}

Student& Catalog::operator [] (int index) {
	if (index >= 0 && index < this->studentsCounter) {
		return *(this->studentsArray[index]);
	}
}

void Catalog::operator += (const char* str) {
	Student* s = new Student(str); 
	this->studentsArray[this->studentsCounter] = s; 
	this->studentsCounter++;
}
