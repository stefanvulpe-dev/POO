#pragma once
#include "Car.h"

class Ford : public Car {
public:
    Ford() : Car(60, 6.0, 75.5, 92.5, 68.4, "Ford") {}
    ~Ford() {}
    virtual double timeNeeded(int length, Weather weather) override;
    virtual bool canFinish(int length) override;
};