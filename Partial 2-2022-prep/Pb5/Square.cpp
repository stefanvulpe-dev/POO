#include "Square.h"

Square::Square() : Shape("Square") { }

Square::Square(string color) {
	this->name = "Square"; 
	this->color = color;
}

Square::Square(string name, string color) {
	this->name = name; 
	this->color = color;
}

string Square::GetColor() {
	return this->color;
}

string Square::GetName() {
	return this->name;
}
