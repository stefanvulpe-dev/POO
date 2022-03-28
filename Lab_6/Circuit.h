#pragma once
#include <cstdlib>
#include "Weather.h"
#include "Car.h"

class Circuit
{
private:
    int length, nrOfParticipants, winners;
    double* results;
    Weather weather;
    Car** cars;
public:
    static const int MAX_NR_OF_PARTICIPANTS = 100;

    Circuit(int length, int nrOfParticipants, Weather weather);

    Circuit() : Circuit(0, 0, Weather::Rain)
    {
        this->winners = 0;
        this->cars = (Car**)(malloc(MAX_NR_OF_PARTICIPANTS * sizeof(Car*)));
        this->results = (double*)(malloc(MAX_NR_OF_PARTICIPANTS * sizeof(double)));
    }

    ~Circuit();

    void SetLength(int length);

    void SetWeather(Weather weather);

    void AddCar(Car* car);

    void Race();

    void ShowFinalRanks();

    void ShowWhoDidNotFinish();
};