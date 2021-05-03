#pragma once
#include "SportFacility.h"
#include <fstream>

class SwimmingPool : public SportFacility
{
public:
	int depth = 0;

	virtual void addFacility() override;

	virtual void showFacility() override;

	virtual void readSportFacility(fstream& file, int typeOfFacility) override;

	virtual void writeSportFacility(fstream& file) override;
};