#include "Fiat.h"
#include "Weather.h"


Fiat::Fiat() 
{
    name = "Fiat";
    fuelCapacity = 45;
    fuelConsumption = 9;
    speed[0] = 65;
    speed[1] = 95;
    speed[2] = 55;
}

float Fiat::GetSpeed(Weather w) const
{
   // return speed[(int)(w)]; POT SI ASA
    if (w == Weather::Rain)
        return speed[0];
    else
        if (w == Weather::Sunny)
            return speed[1];
        else
            return speed[2];
}
float Fiat::GetFuelCapacity() const
{
    return fuelCapacity; 
}
float Fiat::GetFuelConsumption() const 
{
    return fuelConsumption; 
}
const char* Fiat::GetName() const
{
    return name;
}
