#include "ExceptionHandling.h"

void ExceptionHandling::leagueException(int choice, ListOfLeagues& l, bool addingOrRemovingTeam)		
{
	if (static_cast<size_t>(choice - 1) >= l.leagues.size() || choice - 1 < 0)
	{
		throw out_of_range("There is no league with that number :( you're going to the menu...");
	}
	if (l.leagues[choice - 1].Team.empty() == true && addingOrRemovingTeam == false)	
	{
		throw out_of_range("The list of this league teams is empty! You are going to menu...");
	}
}

bool ExceptionHandling::handleLeagueException(int choice, ListOfLeagues& l, bool addingOrRemovingTeam)
{
	try
	{
		leagueException(choice, l, addingOrRemovingTeam);
	}
	catch (out_of_range& error)
	{
		cout << "Error: " << error.what() << endl << endl;;
		return true;
	}
	return false;
}

void ExceptionHandling::teamException(int leagueChoice, int teamChoice, ListOfLeagues& l)
{
	if (static_cast<size_t>(teamChoice - 1) >= l.leagues[leagueChoice - 1].Team.size() || teamChoice - 1 < 0)
	{
		throw out_of_range("There is no club with that number :( You're going to the menu...");
	}
}

bool ExceptionHandling::handleTeamException(int leagueChoice, int teamChoice, ListOfLeagues& l)
{
	try
	{
		teamException(leagueChoice, teamChoice, l);
	}
	catch (out_of_range& error)
	{
		cout << "Error: " << error.what() << endl << endl;;
		return true;
	}
	return false;
}