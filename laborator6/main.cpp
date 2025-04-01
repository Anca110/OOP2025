#include "Circuit.h"
#include "Volvo.h"
#include "BMW.h"
#include "Fiat.h"
#include "Seat.h"
#include "RangeRover.h"
#include<iostream>
#include "Weather.h"
using namespace std;

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Rain);
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;

	//creez obiecte 
	/*Car* car2 = new Volvo();
	Car* car1 = new BMW();*/
	//!!!!!!!!!!!!!!!!!!!!!!!!
	/*Clasa Car este abstractã, deci nu po?i face Car car;
	Dar po?i face un pointer cãtre ea : Car *
    ?i po?i stoca în acel pointer un obiect dintr - o clasã derivatã, cum ar fi BMW, Fiat etc.*/

	//new aloca memorie si apeleaza constructorul BMW
	//new BMW() se creaza un obiect dar nu il poti acesa=>il  pui in variabila Car1

	/*cout << "Car1: " << car1->GetName() << endl;
	cout << "Car1:" << car1->GetSpeed(Weather::Rain) << endl;
	cout << "Car1:" << car1->GetFuelCapacity() << endl;*/

	//car1- pointer la clasa de baza Car, care pointeaza catre un obiect de tip BMW
	//car1->GetName() apeleaza metoda din clasa derivata(cea suprascrisa din clasa de baza)
	//daca metoda n ar fi virtuala in Car=> ar fi apelata versiunea din Car


}
