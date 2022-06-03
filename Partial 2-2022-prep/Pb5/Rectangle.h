#pragma once
#include "Shape.h"

class Rectangle : public Shape {
private:
	string color;
public:
	Rectangle();
	Rectangle(string color);
	Rectangle(string name, string color);
	string GetColor() override;
	string GetName() override;
};