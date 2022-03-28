#include "Dacia.h"

Dacia::~Dacia()
{
    delete this->name;
}

// bool Dacia::canFinish(int length)
// {
//     double fuelNeeded = double(length / this -> fuelConsumption); 
//     if(fuelNeeded > this -> fuelCapacity)
//     {
//         return false;
//     }
//     return true;
// }

// double Dacia::timeNeeded(int length, Weather weather) 
// {
//     if(canFinish(length))
//     {
//         switch(weather)
//         {
//             case Rain: 
//                 return double(length / this -> averageSpeedOnRain);
//             break;

//             case Sunny: 
//                 return double(length / this -> averageSpeedOnSunny);
//             break;

//             case Snow: 
//                 return double(length / this -> averageSpeedOnSnow);
//             break;
//         }
//     }
// }