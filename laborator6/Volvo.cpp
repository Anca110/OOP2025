// Volvo.cpp
#include "Volvo.h"
#include "Weather.h"


Volvo::Volvo() {
    name = "Volvo";
    fuelCapacity = 60;
    fuelConsumption = 8;
    speed[0] = 70;  // Rain
    speed[1] = 100; // Sunny
    speed[2] = 60;  // Snow
}

float Volvo::GetSpeed(Weather w) const 
{
    if (w == Weather::Rain)
        return speed[0];
    else
        if (w == Weather::Sunny)
            return speed[1];
        else
            return speed[2];
}

float Volvo::GetFuelCapacity() const 
{
    return fuelCapacity; 
}
float Volvo::GetFuelConsumption() const 
{
    return fuelConsumption; 
}
const char* Volvo::GetName() const 
{
    return name; 
}

