#include "ListOfTeams.h"

using namespace std;

Team ListOfTeams::addTeamToTheLeague()
{
	cout << "Club name: "; getline(cin >> ws, team.nameOfTeam);
	cout << "Stadium name: "; getline(cin >> ws, team.stadionName);
	cout << "Budget of the club: "; cin >> team.budget;
	cout << "Raiting of the club(1-100): "; cin >> team.ratingOfTheTeam;
	return team;
}

Team ListOfTeams::readTeamToTheLeague(fstream &file)
{
	getline(file, team.nameOfTeam);
	getline(file, team.stadionName);
	file >> team.budget;
	file >> team.pointsInTheLeague;
	file >> team.ratingOfTheTeam;
	return team;
}

