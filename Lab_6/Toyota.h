#pragma once
#include "Car.h"

class Toyota : public Car {
public:
    Toyota() : Car(70, 9.5, 89.6, 105.8, 100.7, "Toyota") {}
    ~Toyota() {}
    virtual double timeNeeded(int length, Weather weather) override;
    virtual bool canFinish(int length) override;
};