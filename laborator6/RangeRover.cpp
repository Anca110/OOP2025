#include "RangeRover.h"
#include "Weather.h"


RangeRover::RangeRover() 
{
    name = "RangeRover";
    fuelCapacity = 80;
    fuelConsumption = 15;
    speed[0] = 75;
    speed[1] = 110;
    speed[2] = 70;
}

float RangeRover::GetSpeed(Weather w) const 
{
    if (w == Weather::Rain)
        return speed[0];
    else
        if (w == Weather::Sunny)
            return speed[1];
        else
            return speed[2];
}
float RangeRover::GetFuelCapacity() const 
{
    return fuelCapacity;
}
float RangeRover::GetFuelConsumption() const
{
    return fuelConsumption; 
}
const char* RangeRover::GetName() const
{
    return name;
}