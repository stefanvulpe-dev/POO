#include "Rectangle.h"

Rectangle::Rectangle() : Shape("Rectangle") { }

Rectangle::Rectangle(string color) {
	this->name = "Rectangle";
	this->color = color;
}

Rectangle::Rectangle(string name, string color) {
	this->name = name; 
	this->color = color;
}

string Rectangle::GetColor() {
	return this->color;
}

string Rectangle::GetName() {
	return this->name;
}
