#pragma once
#include "Team.h"
#include <string>
#include <fstream>

class ListOfTeams
{
private:
	Team team;

public:
	Team addTeamToTheLeague();
	Team readTeamToTheLeague(fstream& file);

	friend class FileManager;
	friend class ExceptionHandling;
};