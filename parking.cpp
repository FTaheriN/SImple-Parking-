#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;


void Parking::set_to_empty(int parking_space)
{
	CarOwner[parking_space] = '*';
}
int Parking::getCurrentCarsCount()
{
	cout << "Number of cars currently parked in the parking is:" << CurrentCarsCount << endl;
}
void Parking::freeCar(int park_id)
{
	set_to_empty(park_id);
	CarModel[park_id] = '*';
	cout << "Car parked in the " << park_id + 1 << "place will now leave the parking." << endl;
	CurrentCarsCount--;
	cout << getCurrentCarsCount() << endl;
}
void Parking::addCar(string car_owner, string car_model)
{
	int search1;
	for (search1 = 0;search1 < 100;search1++)
	{
		if (CarOwner[search1] == '*')
		{
			CarOwner[search1] = car_owner;
			CarModel[search1] = car_model;
			break;
		}
	}
	if (search1 == 100)
		cout << "No empty carpark availabe" << endl;
}
string Parking::getCarOwner(int park_id)
{
	cout << "Car owner of the parking number you have entered is: " << CarOwner[park_id + 1] << endl;
}
string Parking::getCarModel(int park_id)
{
	cout << "Car model of the parking number you have entered is: " << CarModel[park_id + 1] << endl;
}

int main()
{
	Parking p;
	int counter;
	for (counter = 0;counter < 100;counter++)
	{
		p.set_to_empty(counter);
	}
	char choice1;//enter or exit the parking
	char choice2;//what user wants to do(get info)
	string car_owner, car_model;
	int park_id;
	cout << "enter 'i' for entering a car and 'o' for exiting a car(max 20)" << endl << "peress the EOF key to stop." << endl;
	while ((choice1 = cin.get()) != EOF)
	{
		switch (choice1)
		{
		case'i':
			cout << "Enter name and model of the car" << endl;
			cin >> car_owner >> car_model;
			p.addCar(car_owner, car_model);
			p.getCurrentCarsCount();
			break;
		case 'o':
			cout << "Enter park_id to exit parking." << endl;
			cin >> park_id;
			p.freeCar(park_id);
			p.getCurrentCarsCount();
			break;
		}

	}
	while ((choice2 = cin.get()) != EOF)
	{
		switch (choice2)
		{
		case'o':
			cout << "Enter the park id" << endl;
			cin >> park_id;
			cout << p.getCarOwner(park_id) << endl;
			break;
		case'm':
			cout << "Enter park id" << endl;
			cin >> park_id;
			cout << p.getCarModel(park_id) << endl;
			break;
		}
	}

	return 0;
}

