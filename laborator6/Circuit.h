#pragma once
#include <vector>
#include "Car.h"
#include "Weather.h"

class Circuit
{
private:
    int length;
    Weather weather;
    Car* cars[10];//vector de pointeri la masini
    float time[10];//timpul fiecarei masini
    int nr_masini;//nr masini adaugate

public:

    Circuit();//constructor default
    ~Circuit();// destructor default

    void SetLength(int l);
    void SetWeather(Weather w);
    void AddCar(Car* c);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};

