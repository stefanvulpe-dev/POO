#include "Mazda.h"

bool Mazda::canFinish(int length)
{
    double fuelNeeded = double(length / 100) * (this->fuelConsumption);
    if (fuelNeeded > this->fuelCapacity)
    {
        return false;
    }
    return true;
}

double Mazda::timeNeeded(int length, Weather weather)
{
    if (canFinish(length))
    {
        switch (weather)
        {
        case Rain:
            return double(length / this->averageSpeedOnRain);
            break;

        case Sunny:
            return double(length / this->averageSpeedOnSunny);
            break;

        case Snow:
            return double(length / this->averageSpeedOnSnow);
            break;
        }
    }
}