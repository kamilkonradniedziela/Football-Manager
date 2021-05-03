#include "Team.h"

void Team::showTeam()	
{
	cout << "Club name: "; cout << this->nameOfTeam << endl;
	cout << "Stadium name: "; cout << this->stadionName << endl;
	cout << "Budget of the club: "; cout << this->budget << endl;
	cout << "Points in the league: "; cout << this->pointsInTheLeague << endl;
	cout << "Rating of the team: "; cout << this->ratingOfTheTeam << endl << endl;
}

void Team::addToTheTeam()
{
	int choice;
	do 
	{
		cout << "Who would you like to add?(1.Player 2.Employee): "; cin >> choice;
		switch (choice)
		{
		case 1:
			player.addPerson();
			budget -= player.price;
			ratingOfTheTeam += player.ratingOfThePerson;
			players.push_back(player);
			break;
		case 2:
			employee.addPerson();
			budget -= employee.price;
			ratingOfTheTeam += employee.ratingOfThePerson;
			employers.push_back(employee);
			break;
		default:
			cout << "Bad choice. Try again...." << endl;
			break;
		}
	} while (choice != 1 && choice != 2);
}

void Team::readPlayerToTheTeam(fstream& file)
{
	player.readPerson(file);
	players.push_back(player);
}

void Team::readEmployerToTheTeam(fstream& file)
{
	employee.readPerson(file);
	employers.push_back(employee);
}

void Team::readSportFacilityToTheTeam(fstream& file)
{
	this->readSportFacilityPointer(file);
}

void Team::readSportFacilityPointer(fstream& file)
{
	shared_ptr<SportFacility> sportFacility(new SportFacility);
	int typeOfSportFacility;
	file >> typeOfSportFacility;
	switch (typeOfSportFacility)
	{
	case 1:
		sportFacility.reset(new FootballPitch);
		break;
	case 2:
		sportFacility.reset(new SwimmingPool);
		break;
	case 3:
		sportFacility.reset(new Gym);
		break;
	}
	sportFacility->readSportFacility(file, typeOfSportFacility);
	sportFacilities.push_back(sportFacility);
}

void Team::showTeamWorkers()
{
	int choice;
	cout << "Who would you like to see?(1.Players 2.Employees): "; cin >> choice;
	switch (choice)
	{
	case 1:
		if (players.empty() == true)
		{
			cout << "There is no player in the team! You're going to menu..." << endl << endl;
			return;
		}
		for (auto it = players.begin(); it < players.end(); it++)
		{
			cout << "Number of the player: " << numberOfPlayer++ << endl;
			(*it).showPerson();
		}
		numberOfPlayer = 1;
		break;
	case 2:
		if (employers.empty() == true)
		{
			cout << "There is no employee in the team! You're going to menu..." << endl << endl;
			return;
		}
		for (auto it = employers.begin(); it < employers.end(); it++)
		{
			cout << "Number of the employee: " << numberOfEmployee++ << endl;
			(*it).showPerson();
		}
		numberOfEmployee = 1;
		break;
	default:
		cout << "Bad choice. You're going to menu..." << endl;
		return;
	}
}

void Team::sellFromTheTeam()
{
	int choice, choiceOfWorker;
	do 
	{
		cout << "What worker would you like to sell?(1.Player 2.Employee): "; cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "What player would you like to sell?(Give a number): "; cin >> choiceOfWorker;
			if (static_cast<size_t>(choiceOfWorker - 1) >= players.size() || choiceOfWorker - 1 < 0)
			{
				cout << "There is no player with that number :( you're going to the menu..." << endl << endl;
				return;
			}
			players.erase(players.begin() + (choiceOfWorker - 1));
			budget += player.price;
			ratingOfTheTeam -= player.ratingOfThePerson;
			break;
		case 2:
			cout << "What employee would you like to sell?(Give a number): "; cin >> choiceOfWorker;
			if (static_cast<size_t>(choiceOfWorker - 1) >= employers.size() || choiceOfWorker - 1 < 0)
			{
				cout << "There is no employee with that number :( you're going to the menu..." << endl << endl;
				return;
			}
			employers.erase(employers.begin() + (choiceOfWorker - 1));
			budget += employee.price;
			ratingOfTheTeam -= employee.ratingOfThePerson;
			break;
		default:
			cout << "There is no option. Try again..." << endl;
			break;
		}
	} while (choice != 1 && choice != 2);
	cout << "Successfuly selled!" << endl << endl;
}

void Team::buySportFacilityToTheTeam()
{
	int choice;
	shared_ptr<SportFacility>wsk;
	do 
	{
		cout << "What kind of object would you like to buy(1.Gym 2.Football pitch 3.Swimming pool)?: "; cin >> choice;
		if (choice == 1)
		{
			wsk.reset(new Gym);
		}
		else if (choice == 2)
		{
			wsk.reset(new FootballPitch);
		}
		else if (choice == 3)
		{
			wsk.reset(new SwimmingPool);
		}
		else
		{
			cout << "There is no option. Try again..." << endl;
		}
	} while (choice != 1 && choice != 2 && choice != 3);
	wsk->addFacility();
	budget -= wsk->price;
	sportFacilities.push_back(wsk);
}

void Team::showSportFacilitiesOfTheTeam()
{
	if (sportFacilities.empty() == true)
	{
		cout << "There is no sport facility in the team! You're going to menu..." << endl << endl;
		return;
	}
	else
	{
		for (auto it = sportFacilities.begin(); it < sportFacilities.end(); it++)
		{
			cout << "Number of the sport facility: " << numberOfTheSportFacility++ << endl;
			(*it)->showFacility();
		}
		numberOfTheSportFacility = 1;
	}
}

void Team::sellSportFacilityFromTheTeam()
{
	int choiceOfFacility;
	cout << "What facility would you like to sell?(Give the number): "; cin >> choiceOfFacility;
	if (sportFacilities.empty() == true)
	{
		cout << "There is no sport facility in the team! You're going to menu..." << endl << endl;
		return;
	}
	else
	{
		if (static_cast<size_t>(choiceOfFacility - 1) >= sportFacilities.size() || choiceOfFacility - 1 < 0)
		{
			cout << "There is no facility with that number :( you're going to the menu..." << endl << endl;
			return;
		}
		budget += sportFacilities[choiceOfFacility - 1]->price;
		sportFacilities.erase(sportFacilities.begin() + (choiceOfFacility - 1));		
		cout << "Successfuly selled facility!" << endl << endl;
	}
}

void Team::writeTeamToTheLeague(fstream& file)
{
	file << this->nameOfTeam << endl;
	file << this->stadionName << endl;
	file << this->budget << endl;
	file << this->pointsInTheLeague << endl;
	file << this->ratingOfTheTeam;
}

void Team::writePlayerToTheTeam(fstream& file)
{
	for (int i = 0; i < players.size(); i++)
	{
		players[i].writePerson(file);
		if (i == players.size() - 1) return;
		file << endl;
	}
}

void Team::writeEmployerToTheTeam(fstream& file)
{
	for (int i = 0; i < employers.size(); i++)
	{
		employers[i].writePerson(file);
		if (i == employers.size() - 1) return;
		file << endl;
	}
}

void Team::writeSportFacilityToTheTeam(fstream& file)
{
	for (int i = 0; i < sportFacilities.size(); i++)
	{
		file << sportFacilities[i]->typeOfSportFacility << endl;
		sportFacilities[i]->writeSportFacility(file);
		if (i == sportFacilities.size() - 1) return;
		file << endl;
	}
}