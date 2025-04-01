#include "Circuit.h"
#include <iostream>
#include <algorithm>
using namespace std;

//CONSTRUCTOR, DESTRUCTOR
Circuit::Circuit()//imi seteaza obiectul initial tot la 0
{
    //creez obiect Circuit c;  Car* pointer la un obiect de tip derivat; cum e Car* car1
    length = 0;
    weather = Weather::Sunny;
    nr_masini = 0;

    for (int i = 0; i < 10; ++i)//trec prin vectorul de pointeri la masini
    {
        cars[i] = nullptr;
        time[i] = 0;
    }
}

Circuit::~Circuit()
{
    for (int i = 0; i < nr_masini; ++i)
    {
        delete cars[i];
    }
}


//METODE
void Circuit::SetLength(int l) 
{
    length = l;
}

void Circuit::SetWeather(Weather w)
{
    weather = w;
}

void Circuit::AddCar(Car* c)
{
    if (nr_masini < 10)
    {
       // Car* e un pointer la o masina; c e obiectul masina
        cars[nr_masini++] = c;
    }
    else
    {
        cout << "Prea multe ma?ini!"<<endl;
    }
}

void Circuit::Race()
{
    //Pentru fiecare ma?inã adãugatã în circuit, verificã dacã are combustibil sã termine cursa ?i, dacã da, îi calculeazã timpul. Dacã nu — marcheazã cã nu a terminat.
    for (int i = 0; i < nr_masini; ++i)//parcurgi masinile adaugate in circuit
    {
        //car[i] de tip Car*- un pointer la un obiect de tip derivat
        float speed = cars[i]->GetSpeed(weather);//obtii viteza masinii in functie de vremea curenta        // viteza în func?ie de vreme
        float consumption = cars[i]->GetFuelConsumption();
        float capacity = cars[i]->GetFuelCapacity(); 

        float maxDistance = (capacity / consumption) * 100;//cat poate merge cu combustibilul

        if (maxDistance >= length)//daca poate parcurge tot circuitul
        {
            time[i] = length / speed;  // timpul necesar
        }
        else
        {
            time[i] = -1;// marcheaza ca masina n a terminat cursa
        }
    }
}

void Circuit::ShowFinalRanks() 
{
    // Afi?eazã ma?inile care AU TERMINAT cursa in fct de timp crescator
    for (int i = 0; i < nr_masini - 1; ++i) 
    {
        for (int j = i + 1; j < nr_masini; ++j)
        {
            if (time[i] >= 0 && time[j] >= 0 && time[i] > time[j]) 
            {
                float aux_time = time[i];
                time[i] = time[j];
                time[j] = aux_time;

                Car* aux_car = cars[i];
                cars[i] = cars[j];
                cars[j] = aux_car;

            }
        }
    }
    cout << "masini care au terminat cursa:" << endl;
    for (int i = 0; i < nr_masini; ++i) 
    {
        if (time[i] >= 0) 
        {
            cout << cars[i]->GetName() << " cu timpul: " << time[i] <<endl;
        }
    }
}

void Circuit::ShowWhoDidNotFinish() 
{
    cout << "masinile care NU au terminat cursa:" << endl;
    for (int i = 0; i < nr_masini; ++i) 
    {
        if (time[i] < 0) 
        {
            cout << cars[i]->GetName() <<endl;
        }
    }
}

