#pragma once
#include"Team.h"

using namespace std;

class League
{
private:
	string nameOfLeague;
	vector<Team>Team;
	int matchdayCounter = 0;

	friend class ListOfLeagues;
	friend class FileManager;
	friend class ExceptionHandling;
	friend class MatchSimulation;
};