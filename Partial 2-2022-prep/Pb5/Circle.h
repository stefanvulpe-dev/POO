#pragma once
#include "Shape.h"

class Circle : public Shape {
private:
	string color;
public: 
	Circle();
	Circle(string color);
	Circle(string name, string color);
	string GetColor() override;
	string GetName() override;
};