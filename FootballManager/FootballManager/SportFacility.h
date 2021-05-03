#pragma once
#include <iostream>

using namespace std;

class SportFacility
{
public:
	int price;
	int surface;
	int typeOfSportFacility;

	virtual void addFacility();

	virtual void showFacility();

	virtual void readSportFacility(fstream& file, int typeOfFacility);

	virtual void writeSportFacility(fstream& file);
};
