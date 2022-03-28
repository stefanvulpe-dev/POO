#pragma once
#include "Car.h"

class Dacia : public Car {
public:
    Dacia() : Car(50, 5.5, 71.5, 90.5, 65.5, "Dacia") {}
    ~Dacia();
    //virtual double timeNeeded(int length, Weather weather);
    //virtual bool canFinish(int length);
};
