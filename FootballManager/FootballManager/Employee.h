#pragma once
#include "Person.h"
#include <fstream>

class Employee : public Person
{
public:
	string profession;

	virtual void addPerson() override;

	virtual void showPerson() override;

	virtual void readPerson(fstream& file);

	virtual void writePerson(fstream& file) override;
};