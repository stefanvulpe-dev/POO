#pragma once
#include <cstring>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

class Repo {
private: 
	Shape** arr; 
	int size;
public: 
	Repo();
	~Repo();
	Shape* GetShape(string shapeType, string color); 
	void Add(Shape* shape); 
	void Remove(string info); 
	void PrintAll();
	Repo& operator +=(Shape* shape);
};