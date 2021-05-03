#include "FootballPitch.h"

void FootballPitch:: addFacility()
{
	SportFacility::addFacility();
	cout << "Does the footbal pitch is illuminated?(yes or no): "; cin >> this->illumination;
}

void FootballPitch::showFacility()
{
	SportFacility::showFacility();
	cout << "Is footbal pitch illuminated?: " << this->illumination << endl << endl;
}

void FootballPitch::readSportFacility(fstream& file, int typeOfFacility)
{
	SportFacility::readSportFacility(file,typeOfFacility);
	file >> this->illumination;
}

void FootballPitch::writeSportFacility(fstream& file)
{
	SportFacility::writeSportFacility(file);
	file << this->illumination;
}