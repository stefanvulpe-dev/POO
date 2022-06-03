#include "IntegerData.h"
#include "IntegerDataException.h"

IntegerData::IntegerData(string name, string value) {
	this->name = name; 
	this->value = stoi(value);
}

void IntegerData::Add(string toAdd) {
	int newValue = stoi(toAdd) + this->value;
	this->value = newValue;
}

bool IntegerData::Subtract(int toSubtract) {
	if (this->value - toSubtract < 0) {
		throw IntegerDataException(to_string(this->value), to_string(toSubtract));
		return false;
	}
	else {
		this->value -= toSubtract; 
		return true;
	}
}

void IntegerData::Print() {
	cout << this->name << " = " << this->value << ";";
}

