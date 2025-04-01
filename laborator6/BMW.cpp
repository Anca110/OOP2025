#include "BMW.h"
#include "Weather.h"


//BMW mosteneste clasa ABSTRACTA Car=> trebuie sa implementeze toate metodele virtuale pure

BMW::BMW() //constructor DEFAULT- pt ca n are parametrii
{
    //pot exista si mai multi constructori cu sau fara parametrii si ii folosesti pe care trebuie(senumeste OVERLOADING- cand am mai multi)
    name = "BMW";
    fuelCapacity = 55;
    fuelConsumption = 10;
    speed[0] = 80;
    speed[1] = 120;
    speed[2] = 65;
}

//METODE
float BMW::GetSpeed(Weather w) const //returneaza speed dar in functie de tip weather
{
    //folosind if=> n am nevoie de conversie
    //daca luam direct return speed[(int)w];  // <- aici e conversia

    if (w == Weather::Rain)
        return speed[0];
    else
        if (w == Weather::Snow)
            return speed[2];
        else
            return speed[1];
}
float BMW::GetFuelCapacity() const 
{ 
    return fuelCapacity;
}
float BMW::GetFuelConsumption() const 
{
    return fuelConsumption;
}
const char* BMW::GetName() const 
{ 
    return name; 
}
