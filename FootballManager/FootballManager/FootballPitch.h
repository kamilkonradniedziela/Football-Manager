#pragma once
#include "SportFacility.h"
#include <iostream>
#include <fstream>

using namespace std;

class FootballPitch : public SportFacility
{
public:
	string illumination;

	virtual void addFacility() override;

	virtual void showFacility() override;

	virtual void readSportFacility(fstream& file, int typeOfFacility) override;
	
	virtual void writeSportFacility(fstream& file) override;
};