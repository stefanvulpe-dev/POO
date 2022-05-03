#include <cstdio>

#include "MyVector.h"
#include "Car.h"


float operator""_Kelvin(unsigned long long int x) {
    return (1.0f * x) - 273.15f;
}

float operator""_Fahrenheit(unsigned long long int x) {
    return (1.0f * x - 32) / 1.8f;
}

bool cmpTwoCars1(Car& car1, Car& car2) {
    return (car1.getHorsePower() < car2.getHorsePower());
}

bool cmpTwoCars2(Car& car1, Car& car2) {
    if (strcmp(car1.getName(), car2.getName()) == 0) {
        return true;
    }
    return false;
}

int main() {
    float a = 300_Kelvin;

    float b = 120_Fahrenheit;

    printf("Kelvin to Celsius: %.2f\nFahrenheit to Celsius %.2f\n", a, b);

    MyVector<Car> arrayOfCars; 

    arrayOfCars.push(new Car("Mazda", "CX-5", 200, 55.5f));

    arrayOfCars.push(new Car("Audi", "A4", 150, 50.0f));

    arrayOfCars.push(new Car("Toyota", "RAV4", 210, 65.5f));

    arrayOfCars.push(new Car("Skoda", "Octavia", 150, 45.5f));

    arrayOfCars.printArray();

    arrayOfCars.remove(2); 

    printf("Array after the remove of third element: ");

    arrayOfCars.printArray();

    arrayOfCars.remove(1);

    printf("Array after the remove of second element: ");

    arrayOfCars.printArray();

    arrayOfCars.insert(new Car("Porsche", "Macan", 300, 60.5f), 2);

    printf("Array after insertion: ");

    arrayOfCars.printArray();

    printf("Last element is: %s\n", arrayOfCars.pop().getName());

    arrayOfCars.set(new Car("BMW", "525d", 175, 44.5f), 2);
    
    printf("Array: ");

    arrayOfCars.printArray();

    printf("Number of elements in the arr: %d\n", arrayOfCars.count());

    Car car("BMW", "320d", 150, 44.5f); 

    printf("First index of %s: %d\n", car.getName(), arrayOfCars.firstIndexOf(&car, &cmpTwoCars2));

    arrayOfCars.sort(&cmpTwoCars1);

    printf("Sorted arr: "); 

    arrayOfCars.printArray();

    arrayOfCars.deleteVector();

    return 0;
}
