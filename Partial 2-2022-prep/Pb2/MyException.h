#pragma once
#include <stdexcept>
#include <string>
using namespace std;

class MyException : exception {
protected:
	string name; 
public: 
	MyException(string name) : name(name) { }
	const char* what() const throw() override {
		return name.c_str();
	}
};