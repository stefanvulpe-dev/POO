#include <iostream>
#include <cstdio> 
#include <cstdlib>
#include <cstring>

#include "Circuit.h"
#include "Weather.h"
#include "Car.h"

using namespace std;

Circuit::Circuit(int length, int nrOfParticipants, Weather weather)
{
    this->length = length;
    this->nrOfParticipants = nrOfParticipants;
    this->winners = 0;
    this->weather = weather;

    if (this->cars == nullptr)
    {
        this->cars = (Car**)(malloc(MAX_NR_OF_PARTICIPANTS * sizeof(Car*)));
        this->results = (double*)(malloc(MAX_NR_OF_PARTICIPANTS * sizeof(double)));
    }
}

Circuit::~Circuit()
{
    if (this->cars != nullptr)
    {
        free(this->cars);
    }
    if (this->results != nullptr)
    {
        free(this->results);
    }
}

void Circuit::SetLength(int length)
{
    this->length = length;
}

void Circuit::SetWeather(Weather weather)
{
    this->weather = weather;
}

void Circuit::AddCar(Car* car)
{
    if (this->nrOfParticipants < MAX_NR_OF_PARTICIPANTS && this->cars != nullptr)
    {
        int cnt = this->nrOfParticipants++;
        this->cars[cnt] = car;
    }
}

void Circuit::Race()
{
    for (int i = 0; i < this->nrOfParticipants; ++i)
    {
        if (this->cars[i]->canFinish(this->length))
        {
            this->results[this -> winners ++] = this->cars[i]->timeNeeded(this->length, this->weather);
        }
    }
}

void Circuit::ShowFinalRanks()
{
    bool ok;
    do {
        ok = true; 

        for (int i = 0; i < this->winners - 1; ++i)
        {
            if (this->results[i] > this->results[i + 1])
            {
                swap(this->results[i], this->results[i + 1]); 
                ok = false;
            }
        }
    } while (ok == false);

    printf("Time ranking:\n");

    for (int i = 0; i < this->winners; ++i)
    {
        printf("%.2f h\n", this->results[i]);
    }

}

void Circuit::ShowWhoDidNotFinish()
{
    if (this->winners < this->nrOfParticipants)
    {
        printf("Cars who didn't finished the race:\n");
        for (int i = 0; i < this->nrOfParticipants; ++i)
        {
            if (!(this->cars[i]->canFinish(this->length)))
            {
                printf("%s\n", this->cars[i]->getName());
            }
        }
    }
    else
    {
        printf("Everyone finished the race\n");
    }
}

