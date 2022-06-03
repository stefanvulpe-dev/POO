#include "Repo.h"

Repo::Repo() {
	this->arr = nullptr;
	this->size = 0;
}

Repo::~Repo() {
	for (int i = 0; i < this->size; ++i) {
		delete this->arr[i];
		this->arr[i] = nullptr;
	}
	delete[] this->arr; 
	this->arr = nullptr;
	this->size = 0;
}

Shape* Repo::GetShape(string shapeType, string color) {
	for (int i = 0; i < this->size; ++i) {
		if (this->arr[i]->GetName() == shapeType && this->arr[i]->GetColor() == color) {
			return this->arr[i];
		}
	}
	
	if (shapeType == "Circle") {
		return new Circle("Circle", color);
	}
	else if (shapeType == "Rectangle") {
		return new Rectangle("Rectangle", color);
	}
	else if (shapeType == "Square") {
		return new Square("Square", color);
	}

	return nullptr;
}

void Repo::Add(Shape* shape) {
	if (this->size == 0) {
		this->arr = new Shape*[1];
		this->arr[0] = shape; 
		this->size++;
	}
	else {
		auto ptr = this->arr; 
		this->arr = new Shape*[this->size + 1];
		memcpy(this->arr, ptr, this->size * sizeof(Shape*)); 
		delete ptr;
		this->arr[this->size] = shape; 
		this->size++;
	}
}

void Repo::Remove(string info) {
	for (int i = 0; i < this->size - 1; ++i) {
		if (this->arr[i]->GetName() == info || this->arr[i]->GetColor() == info) {
			auto ptr = this->arr[i];
			for (int j = i + 1; j < this->size; ++j) {
				this->arr[j - 1] = this->arr[j];
			}
			delete ptr; 
			ptr = nullptr; 
			i--; 
			this->size--;
		}
	}

	if (this->arr[this->size - 1]->GetName() == info || this->arr[this->size - 1]->GetColor() == info) {
		delete this->arr[this->size - 1]; 
		this->arr[this->size - 1] = nullptr;
		this->size--;
	}
}

void Repo::PrintAll() {
	for (int i = 0; i < this->size; ++i) {
		cout << "Shape: " << this->arr[i]->GetName() << "\n";
		cout << "Color: " << this->arr[i]->GetColor() << "\n";
	}
	cout << "----\n";
}

Repo& Repo::operator+=(Shape* shape) {
	if (this->size == 0) {
		this->arr = new Shape*[1];
		this->arr[0] = shape; 
		this->size++; 
		return *this;
	}
	else {
		auto ptr = this->arr; 
		this->arr = new Shape*[this->size + 1];
		memcpy(this->arr, ptr, this->size * sizeof(Shape*));
		delete ptr;
		this->arr[this->size] = shape;
		this->size++;
		return *this;
	}
}
