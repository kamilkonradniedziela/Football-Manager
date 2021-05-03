#include "Gym.h"

void Gym::addFacility()
{
	SportFacility::addFacility();
	cout << "Does gym have air conditioner?(yes or no): "; cin >> this->airConditioner;
}

void Gym::showFacility()
{
	SportFacility::showFacility();
	cout << "Air conditioner: " << this->airConditioner << endl << endl;
}

void Gym::readSportFacility(fstream& file, int typeOfFacility)
{
	SportFacility::readSportFacility(file,typeOfFacility);
	file >> this->airConditioner;
}

void Gym::writeSportFacility(fstream& file)
{
	SportFacility::writeSportFacility(file);
	file << this->airConditioner;
}