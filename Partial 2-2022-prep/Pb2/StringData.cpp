#include <iostream>
#include "StringData.h"
#include "StringDataException.h"

using namespace std;

StringData::StringData(string name, string value) {
	this->name = name; 
	this->value = value; 
}

void StringData::Add(string toAdd) {
	this->value += toAdd;
}

bool StringData::Subtract(int toSubtract) {
	if (toSubtract > this->value.size()) {
		throw StringDataException(this->value, to_string(toSubtract));
		return false;
	}
	else {
		this->value.erase(this->value.size() - toSubtract, toSubtract);
		return true;
	}
}

void StringData::Print() {
	cout << this->name << " = " << this->value << ";";
}
