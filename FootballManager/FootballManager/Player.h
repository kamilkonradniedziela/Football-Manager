#pragma once
#include "Person.h"
#include <fstream>

class Player : public Person
{
public:
	string position;

	virtual void addPerson() override;

	virtual void showPerson() override;

	virtual void readPerson(fstream& file) override;

	virtual void writePerson(fstream& file) override;
};