// Car.h
#pragma once
#include "Weather.h"
using namespace std;

class Car //clasa ABSTRACT- pt ca are cel putin o metoda virtuala pura
{
protected://pun la protected fiind clasa de baza(vreau clasele derivate sa le poata acesa direct)
    //( nu vreu ca alte clase din AFARA IERARHIEI sa le aceseze=> nu pui public)
    float fuelCapacity;   
    float fuelConsumption; 
    float speed[3];// viteze în func?ie de vreme
    const char* name;//pointer catre un sir pe care NU L POT MODIFICA

public:
    virtual ~Car() = default; // destructor virtual — important pentru polimorfism!

    virtual float GetSpeed(Weather w) const = 0;//pt ca le fac virtuale(sa le pot accesa diferit pt fiecare obiect din clase derivate de la Car)
    virtual float GetFuelCapacity() const = 0;//virtual pt a putea pune in celelalte clase functii cu acelasi numa; si cand apelez sa mi apeleze pentru aia din clasa derivata unu pentru asta din clasa de baza
    virtual float GetFuelConsumption() const = 0;
    virtual const char* GetName() const = 0;// metoda virtuala PURA (pura adc are =0)=> clasa derivata e obligata sa o implementeze
};
//clasa de baza NU E ABSTRACTA=> in cele derivate poti suprascrie metodele daca vrei, nu e obligatoriu
//clasa abstracta=> nu pot crea obiecte direct din ea c.



//!!!!char name[100], ai fi alocat fix 100, mereu. Dar cu char* po?i aloca cât vrei, dinamic.
