#include "Circle.h"

Circle::Circle() : Shape("Circle") { }

Circle::Circle(string color) {
	this->name = "Circle"; 
	this->color = color;
}

Circle::Circle(string name, string color) {
	this->name = name; 
	this->color = color;
}

string Circle::GetColor() {
	return this->color;
}

string Circle::GetName() {
	return this->name;
}
