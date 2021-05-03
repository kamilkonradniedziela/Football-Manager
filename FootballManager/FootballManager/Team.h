#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Person.h"
#include "Player.h"
#include "Employee.h"
#include "Gym.h"
#include "FootballPitch.h"
#include "SwimmingPool.h"
#include "SportFacility.h"

using namespace std;

class Team
{
public:
	string nameOfTeam;
	string stadionName;
	int budget = 0;
	int pointsInTheLeague = 0;
	int ratingOfTheTeam = 0;

	vector <Player> players;
	Player player;
	int numberOfPlayer = 1;

	vector<Employee> employers;
	Employee employee;
	int numberOfEmployee = 1;

	vector<shared_ptr< SportFacility>>sportFacilities;
	int numberOfTheSportFacility = 1;

	void showTeam();

	void addToTheTeam();

	void showTeamWorkers();

	void sellFromTheTeam();

	void buySportFacilityToTheTeam();

	void showSportFacilitiesOfTheTeam();

	void sellSportFacilityFromTheTeam();

	void readPlayerToTheTeam(fstream& file);

	void readEmployerToTheTeam(fstream& file);

	void readSportFacilityToTheTeam(fstream& file);
	
	void readSportFacilityPointer(fstream& file);

	void writeTeamToTheLeague(fstream& file);

	void writePlayerToTheTeam(fstream& file);

	void writeEmployerToTheTeam(fstream& file);

	void writeSportFacilityToTheTeam(fstream& file);
};