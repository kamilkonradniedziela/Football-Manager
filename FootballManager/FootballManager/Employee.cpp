#include "Employee.h"

void Employee::addPerson()
{
	Person::addPerson();
	int choice = 0;
	do
	{
		cout << "What's the proffesion of the employee?(1.Coach 2.Doctor 3.Cleaner): " << endl;		cin >> choice;
		switch (choice)
		{
		case 1:
			this->profession = "Coach";
			break;
		case 2:
			this->profession = "Doctor";
			break;
		case 3:
			this->profession = "Cleaner";
			break;
		default:
			cout << "There is no position. Try again" << endl;
			break;
		}
	} while (choice != 1 && choice != 2 && choice != 3);
}

void Employee::showPerson()
{
	Person::showPerson();
	cout << "Profession: "; cout << this->profession << endl << endl;
}

void Employee::readPerson(fstream& file)
{
	Person::readPerson(file);
	file >> this->profession;	
}

void Employee::writePerson(fstream& file)
{
	Person::writePerson(file);
	file << this->profession;
}