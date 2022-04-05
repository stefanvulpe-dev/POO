#include <cstring>
#include <cstdlib>

#include "Car.h"

using namespace std;

Car::Car(){
	this->name = nullptr; 
	this->model = nullptr; 
	this->horsePower = 0; 
	this->fuelCapacity = 0;
}

Car::Car(const char* name, const char* model, int horsePower, float fuelCapacity) {
	this->name = (char*)(malloc(strlen(name) + 1));
	this->model = (char*)(malloc(strlen(model) + 1));

	memset(this->name, '\0', strlen(name) + 1);
	memset(this->model, '\0', strlen(model) + 1);
	
	memcpy(this->name, name, strlen(name));
	memcpy(this->model, model, strlen(model));
	
	
	this->horsePower = horsePower; 
	this->fuelCapacity = fuelCapacity;
}

Car::Car(const Car& car) {
	memcpy(this->name, name, strlen(name));
	memcpy(this->model, model, strlen(model));
	this->horsePower = car.horsePower; 
	this->fuelCapacity = car.fuelCapacity; 
}

Car::Car(Car&& car) {
	memcpy(this->name, name, strlen(name));
	memcpy(this->model, model, strlen(model));
	
	this->horsePower = car.horsePower;
	this->fuelCapacity = car.fuelCapacity;

	car.name = nullptr; 
	car.model = nullptr; 
	car.fuelCapacity = 0; 
	car.horsePower = 0;
}

Car::~Car() {
	free(this->name); 
	free(this->model); 
	this->name = nullptr;
	this->model = nullptr;
	this->horsePower = 0; 
	this->fuelCapacity = 0;
}

const char* Car::getName() {
	return this->name;
}

const char* Car::getModel() {
	return this -> model;
}

int Car::getHorsePower() {
	return this->horsePower;
}

float Car::getFuelCapacity() {
	return this->fuelCapacity;
}

bool operator < (const Car& car1, const Car& car2) {
	return (car1.horsePower < car2.horsePower);
}

bool operator == (const Car& car1, const Car& car2) {
	if (strcmp(car1.name, car2.name) == 0) {
		return true;
	}
	return false;
}
