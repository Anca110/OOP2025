#pragma once
#include "Car.h"

//clasa derivata din clasa de baza Car
class RangeRover : public Car //class, nume clasa : modificator_aces(daca nu e specificat se considera privat), clasa de baza
{
public:
    RangeRover();
    float GetSpeed(Weather w) const override;
    float GetFuelCapacity() const override;
    float GetFuelConsumption() const override;
    const char* GetName() const override;
};

