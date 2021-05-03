#pragma once
#include <iostream>
#include <random>

using namespace std;

class Person
{
public:
	int price = 0;
	string name;
	string surrname;
	int height = 0;
	int ratingOfThePerson = 0;

	virtual void addPerson();

	virtual void showPerson();

	virtual void readPerson(fstream& file);

	virtual void writePerson(fstream& file);
};
