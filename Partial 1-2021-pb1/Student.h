#pragma once

struct Vector {
	char* subject;
	int grade;
};

class Student {
private: 
	char* name;
	Vector *arr;
	int nrOfSubjects;
public: 
	Student(const char* name);
	Student(const Student& student);
	~Student(); 
	const char* getName(); 
	void PrintNote();
	Student& operator [] (const char* str);
	void operator = (int grade);
	operator float();
};