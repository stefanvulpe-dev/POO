#pragma once
class Car {
	private:
		char* name; 
		char* model; 
		int horsePower; 
		float fuelCapacity; 
	public:
		Car(); 
		Car(const char* name, const char* model, int horsePower, float fuelCapacity);
		Car(const Car& car); 
		Car(Car&& car); 
		~Car(); 
		const char* getName();
		const char* getModel();
		int getHorsePower();
		float getFuelCapacity();
		friend bool operator < (const Car& car1, const Car& car2);
		friend bool operator == (const Car& car1, const Car& car2);
};