#pragma once
#include "Car.h"

class BMW : public Car //din clasa de baza Car
{
    //daca am declarat variabilele in clasa de baza protected nu mai e necesar sa le scriu si aici; doar metodele

public:

    BMW();//constructor care seteaza valorile!!

    //toate metodele VIRTUALE PURE(care s si in clasa de baza) trebuie implememntate in .cpp
    float GetSpeed(Weather w) const override;
    float GetFuelCapacity() const override;
    float GetFuelConsumption() const override;//CONST- metoda nu modifica valorile membrilor obiectului
    const char* GetName() const override;//OVERRIDE - aceasta metoda suprascrie o metoda din clasa de baza
};
//pe langa metodele obligatorii poti adauga si altele care n au treaba cu clasa de baza

