#pragma once
#include "Shape.h"

class Square : public Shape {
private:
	string color;
public:
	Square();
	Square(string color);
	Square(string name, string color);
	string GetColor() override;
	string GetName() override;
};