#include "Person.h"
#include <iostream>
#include <fstream>

using namespace std;

void Person::addPerson()
{
	int raitingPom, rollPrice = 0, choice;
	unsigned seed = time(0);
	default_random_engine generator(seed);
	uniform_int_distribution<int> distribution1(1, 100), distribution2(100, 200), distribution3(200, 300),
		distribution4(300, 400), distribution5(400, 500), distribution6(500, 600), distribution7(600, 700),
		distribution8(700, 800), distribution9(800, 900), distribution10(900, 1000);
	do {
		cout << "What's the rating of the person?(1-10): "; cin >> raitingPom;
		switch (raitingPom)
		{
		case 1:
			rollPrice = distribution1(generator);
			break;
		case 2:
			rollPrice = distribution2(generator);
			break;
		case 3:
			rollPrice = distribution3(generator);
			break;
		case 4:
			rollPrice = distribution4(generator);
			break;
		case 5:
			rollPrice = distribution5(generator);
			break;
		case 6:
			rollPrice = distribution6(generator);
			break;
		case 7:
			rollPrice = distribution7(generator);
			break;
		case 8:
			rollPrice = distribution8(generator);
			break;
		case 9:
			rollPrice = distribution9(generator);
			break;
		case 10:
			rollPrice = distribution10(generator);
			break;
		default:
			cout << "Something wnet wrong :( Try again..." << endl;
		}
	} while (raitingPom < 1 || raitingPom>10);
	cout << "The price of person is: " << rollPrice << endl;
	this->ratingOfThePerson = raitingPom;
	this->price = rollPrice;
	cout << "What's the name?: "; cin >> this->name;
	cout << "What's the surrname?: "; cin >> this->surrname;
	cout << "Height?: "; cin >> this->height;
}

void Person:: showPerson()
{
	cout << "Price: " << this->price << endl;
	cout << "Name: " << this->name << endl;
	cout << "Surrname: " << this->surrname << endl;
	cout << "Height: " << this->height << endl;
	cout << "Rating: " << this->ratingOfThePerson << endl;
}

void Person::readPerson(fstream& file)
{
	file >> this->price;
	file >> this->name;
	file >> this->surrname;
	file >> this->height;
	file >> this->ratingOfThePerson;
}

void Person::writePerson(fstream& file)
{
	file << this->price << endl;
	file << this->name << endl;
	file << this->surrname << endl;
	file << this->height << endl;
	file << this->ratingOfThePerson << endl;
}