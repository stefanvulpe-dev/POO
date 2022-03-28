#pragma once
#include "Weather.h"

class Car
{
protected:
    const char* name;
    int fuelCapacity;
    double fuelConsumption, averageSpeedOnRain, averageSpeedOnSunny, averageSpeedOnSnow;
public:
    Car(int fuelCapacity, double fuelConsumption, double averageSpeedOnRain, double averageSpeedOnSun, double averageSpeedOnSnow, const char* name) : fuelCapacity(fuelCapacity), fuelConsumption(fuelConsumption), averageSpeedOnSnow(averageSpeedOnSnow), averageSpeedOnSunny(averageSpeedOnSun), averageSpeedOnRain(averageSpeedOnRain), name(name) {}

    Car() : Car(0, 0, 0, 0, 0, nullptr) {}

    ~Car() {}

    virtual double timeNeeded(int length, Weather weather) = 0;

    virtual bool canFinish(int length) = 0;

    const char* getName()
    {
        return this->name;
    }

    int getFuelCapacity()
    {
        return this->fuelCapacity;
    }
};