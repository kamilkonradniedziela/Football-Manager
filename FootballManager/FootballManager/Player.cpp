#include "Player.h"

void Player::addPerson()
{
	Person::addPerson();
	int choice = 0;
	do
	{
		cout << "What's the position of the player?(1.Goalkeeper 2.Defender 3.Midfielder 4.Forward): " << endl;		cin >> choice;
		switch (choice)
		{
		case 1:
			this->position = "Goalkeeper";
			break;
		case 2:
			this->position = "Defender";
			break;
		case 3:
			this->position = "Midfielder";
			break;
		case 4:
			this->position = "Forward";
			break;
		default:
			cout << "There is no position. Try again" << endl;
			break;
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
}

void Player::showPerson()
{
	Person::showPerson();
	cout << "Position: " << this->position << endl << endl;
}

void Player::readPerson(fstream& file)
{
	Person::readPerson(file);
	file >> this->position;	
}

void Player::writePerson(fstream& file)
{
	Person::writePerson(file);
	file << this->position;
}