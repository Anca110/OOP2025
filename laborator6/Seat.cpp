#include "Seat.h"
#include "Weather.h"


Seat::Seat()
{
    name = "Seat";
    fuelCapacity = 50;
    fuelConsumption = 7;
    speed[0] = 60;
    speed[1] = 90;
    speed[2] = 50;
}

float Seat::GetSpeed(Weather w) const 
{
    if (w == Weather::Rain)
        return speed[0];
    else
        if (w == Weather::Sunny)
            return speed[1];
        else
            return speed[2];
}
float Seat::GetFuelCapacity() const 
{
    return fuelCapacity; 
}
float Seat::GetFuelConsumption() const 
{
    return fuelConsumption; 
}
const char* Seat::GetName() const 
{
    return name; 
}