#pragma once
#include "SportFacility.h"
#include <iostream>
#include <fstream>

using namespace std;

class Gym : public SportFacility
{
public:
	string airConditioner;

	virtual void addFacility() override;

	virtual void showFacility() override;

	virtual void readSportFacility(fstream& file, int typeOfFacility) override;

	virtual void writeSportFacility(fstream& file) override;
};