#pragma once
#include "Student.h"

class Catalog {
private: 
	Student** studentsArray;
	int studentsCounter;
public:
	Catalog(); 
	~Catalog(); 
	int getCount(); 
	Student& operator[](const char* str);
	Student& operator[](int index);
	void operator += (const char* str);
};