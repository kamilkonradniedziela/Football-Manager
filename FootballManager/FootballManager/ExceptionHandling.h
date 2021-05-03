#pragma once
#include "ListOfLeagues.h"
#include <iostream>

using namespace std;

class ExceptionHandling
{
public:
	static void leagueException(int choice, ListOfLeagues& l, bool addingOrRemovingTeam);

	static bool handleLeagueException(int choice, ListOfLeagues& l, bool addingOrRemovingTeam);

	static void teamException(int leagueChoice, int teamChoice, ListOfLeagues& l);

	static bool handleTeamException(int leagueChoice, int teamChoice, ListOfLeagues& l);
};