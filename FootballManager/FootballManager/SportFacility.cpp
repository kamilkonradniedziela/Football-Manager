#include "SportFacility.h"
#include <fstream>

void SportFacility::addFacility()
{
	cout << "What's the price of the facility?: "; cin >> this->price;
	cout << "What's the surface of the facility?(in square meters): "; cin >> this->surface;
}

void SportFacility::showFacility()
{
	cout << "Type of the sport facility: ";
	switch (this->typeOfSportFacility)
	{
	case 1:
		cout << "Football Pitch" << endl;
		break;
	case 2:
		cout << "Swimming Pool" << endl;
		break;
	case 3:
		cout << "Gym" << endl;
		break;
	}
	cout << "Price of the facility " << this->price << endl;
	cout << "Surface of the facility: " << this->surface << " m^2" << endl;
}

void SportFacility::readSportFacility(fstream& file, int typeOfFacility)
{
	this->typeOfSportFacility = typeOfFacility;
	file >> this->price;
	file >> this->surface;
}

void SportFacility::writeSportFacility(fstream& file)
{
	file << this->price << endl;
	file << this->surface << endl;
}