#pragma once
#include "Person.h"
#include "League.h"
#include "ListOfTeams.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ListOfLeagues
{
private:
	vector<League>leagues;
	League leagueObject;
	ListOfTeams listOfClubs;
	int numberOfTheLeague = 1;
	int numberOfTheClub = 1;

public:
	void addLeague(ListOfLeagues& l);

	void showAllLeagues(ListOfLeagues& l);

	void removeLeague(ListOfLeagues& l);

	void addClubsToTheLeague(ListOfLeagues& l);

	void showLeagueTeams(ListOfLeagues& l);

	void deleteLeagueTeam(ListOfLeagues& l);

	void buyWorkerToTheTeam(ListOfLeagues& l);

	void showWorkersOfTheTeam(ListOfLeagues& l);

	void sellWorkerOfTheTeam(ListOfLeagues& l);

	void buySportFacilityToTheClub(ListOfLeagues& l);

	void showSportFacilitiesOfTheClub(ListOfLeagues& l);

	void sellSportFacilityFromTheClub(ListOfLeagues& l);

	void simulateQueue(ListOfLeagues& l);

	void readLeagueFromTheFile(fstream& file, ListOfLeagues& l);

	void readClubFromTheLeague(fstream& file, int leagueCounter);

	void readPlayersToTheLeague(fstream& file, int leagueChoice, int teamChoice);

	void readEmployersToTheLeague(fstream& file, int leagueChoice, int teamChoice);

	void readSportFacilitiesToTheLeague(fstream& file, int leagueChoice, int teamChoice);
	
	void writeLeagueToTheFile(fstream& file, ListOfLeagues& l);

	void writeClubToTheLeague(fstream& file, int leagueCounter, int teamCounter);

	void writePlayersToTheLeague(fstream& file, int leagueChoice, int teamChoice);

	void writeEmployersToTheLeague(fstream& file, int leagueChoice, int teamChoice);

	void writeSportFacilitiesToTheLeague(fstream& file, int leagueChoice, int teamChoice);

	friend class FileManager;
	friend class ExceptionHandling;
	friend class MatchSimulation;
};
