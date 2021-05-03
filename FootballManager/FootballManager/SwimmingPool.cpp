#include "SwimmingPool.h"

void SwimmingPool :: addFacility()
{
	SportFacility::addFacility();
	cout << "What's the depth of the swimming pool?: "; cin >> this->depth;
}

void SwimmingPool:: showFacility()
{
	SportFacility::showFacility();
	cout << "What's the depth of the swimming pool?: " << this->depth << endl << endl;
}

void SwimmingPool::readSportFacility(fstream& file, int typeOfFacility)
{
	SportFacility::readSportFacility(file,typeOfFacility);
	file >> this->depth;
}

void SwimmingPool::writeSportFacility(fstream& file)
{
	SportFacility::writeSportFacility(file);
	file << this->depth;
}