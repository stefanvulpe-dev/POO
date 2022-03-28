#include <cstdio> 
#include <cstdlib>
#include <cstring>

#include "Circuit.h"
#include "Weather.h"
#include "D:\Facultate\Sem 2\OOP\Lab_6\includes\Cars\Car.h"

#define _CRT_SECURE_NO_WARNINGS

Circuit::Circuit(int length, int nrOfParticipants, Weather weather)
{
    this -> length = length; 
    this -> nrOfParticipants = nrOfParticipants;
    this -> weather = weather; 

    if(this -> cars == nullptr)
    {
        this -> cars = (Car**)(malloc(MAX_NR_OF_PARTICIPANTS * sizeof(Car*)));
    }
}

Circuit::~Circuit()
{
    if(this -> cars != nullptr)
    {
        free(this -> cars);
    }
}

void Circuit::SetLength(int length)
{
    this -> length = length;
}

void Circuit::SetWeather(Weather weather)
{
    this -> weather = weather;
}

void Circuit::AddCar(Car* car)
{
    if(this -> nrOfParticipants < MAX_NR_OF_PARTICIPANTS && this -> cars != nullptr)
    {
        int cnt = this -> nrOfParticipants ++;
        this -> cars[cnt] = car;
    }
}

void Circuit::ShowFinalRanks()
{   

}

