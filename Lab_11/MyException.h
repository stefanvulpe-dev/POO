#pragma once
#include <stdexcept> 

using namespace std;

class MyException : public exception {
protected:
	string m_name; 
public: 
	MyException(string name) : m_name(name) {}

	const char* what() const throw() override {
		return m_name.c_str();
	}
};