#include <cstdio> 
#include <cstdlib> 
#include <cstring>

#include "Student.h"

Student::Student(const char* name) {
	if (this->name == nullptr) {
		this->name = (char*)(malloc(strlen(name) + 1));
		memset(this->name, '\0', strlen(name) + 1);
		memcpy(this->name, name, strlen(name));
	}
	if (this->arr == nullptr) {
		this->arr = (Vector*)(malloc(100 * sizeof(Vector)));
	}
	this->nrOfSubjects = 0;
}

Student::Student(const Student& student) {
	memset(this->name, '\0', strlen(student.name));
	memcpy(this->name, student.name, strlen(student.name));
	memset(this->arr, 0, this->nrOfSubjects * sizeof(Vector)); 
	memcpy(this->arr, student.arr, student.nrOfSubjects * sizeof(Vector)); 
	this->nrOfSubjects = student.nrOfSubjects; 
}

Student::~Student() {
	free(this->name); 
	for (int i = 0; i < this->nrOfSubjects; ++i) {
		free(this->arr[i].subject); 
		this->arr[i].grade = 0;
	}
	this->nrOfSubjects = 0;
}

const char* Student::getName() {
	return this->name;
}

void Student::PrintNote() {
	for (int i = 0; i < this->nrOfSubjects; ++i) {
		printf("\t %s => %d\n", this->arr[i].subject, this->arr[i].grade);
	}
}

Student& Student::operator [] (const char* str) {
	bool ok = false;
	
	for (int i = 0; i < this->nrOfSubjects; ++i) {
		if (strcmp(this->arr[i].subject, str) == 0) {
			ok = true;
			break;
		}
	}

	if (!ok) {
		this->arr[this->nrOfSubjects].subject = (char*)(malloc(strlen(str) + 1));
		memset(this->arr[this->nrOfSubjects].subject, '\0', strlen(str) + 1);
		memcpy(this->arr[this->nrOfSubjects].subject, str, strlen(str));
		this->nrOfSubjects++;
	}

	return *(this);
}

void Student::operator=(int grade) {
	this->arr[this->nrOfSubjects - 1].grade = grade;
}

Student::operator float() {
	if (this->nrOfSubjects > 0) {
		int sum = 0; 
		for (int i = 0; i < this->nrOfSubjects; ++i) {
			sum += this->arr[i].grade; 
		}
		return (float)(sum) / (this->nrOfSubjects);
	}
}
