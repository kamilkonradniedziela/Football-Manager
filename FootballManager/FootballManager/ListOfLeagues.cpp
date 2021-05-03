#include "ListOfLeagues.h"
#include "ExceptionHandling.h"
#include "MatchSimulation.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void ListOfLeagues :: addLeague(ListOfLeagues& l)
{
	cout << "League name: "; getline(cin >> ws, l.leagueObject.nameOfLeague);
	l.leagues.push_back(l.leagueObject);
	cout << "Successfuly added league!" << endl << endl;
}

void ListOfLeagues :: showAllLeagues(ListOfLeagues& l)
{
	if (l.leagues.empty() == true)
	{
		cout << "The list of leagues is empty! You are going to menu..." << endl << endl;
		return;
	}
	cout << "Available leagues:" << endl;
	for (int i = 0; i < static_cast<int>(l.leagues.size()); i++)
	{
		cout << l.numberOfTheLeague++ << ". " << l.leagues[i].nameOfLeague << endl;
	}
	cout << endl;
	l.numberOfTheLeague = 1;
}

void ListOfLeagues::removeLeague(ListOfLeagues& l)
{
	int choice;
	cout << "Give the number of the league that you want to remove: "; cin >> choice;
	if(ExceptionHandling::handleLeagueException(choice,l, true) == true) return;
	l.leagues.erase(l.leagues.begin() + (choice - 1));
	cout << "Successfuly removed league!" << endl << endl;
}

void ListOfLeagues::addClubsToTheLeague(ListOfLeagues& l)
{
	int choice;
	cout << "Where would you like to put the team?(Give the number of the league): ";	cin >> choice;
	if (ExceptionHandling::handleLeagueException(choice,l, true) == true) return;
	auto it = l.listOfClubs.addTeamToTheLeague();
	l.leagues[choice - 1].Team.push_back(it);
	cout << "Successfuly added team!" << endl << endl;
}

void ListOfLeagues::showLeagueTeams(ListOfLeagues& l)
{
	int choice;
	cout << "What league clubs would you like to see?(Give a number): "; cin >> choice;
	if (ExceptionHandling::handleLeagueException(choice,l, false) == true) return;
	for (vector<Team>::iterator it = l.leagues[choice - 1].Team.begin(); it != l.leagues[choice - 1].Team.end(); it++)
	{
		cout << "Club number: " << l.numberOfTheClub++ << endl;
		(*it).showTeam();
	}
	l.numberOfTheClub = 1;
}

void ListOfLeagues::deleteLeagueTeam(ListOfLeagues& l)
{
	int choice, choice2;
	cout << "Which league would you like to reduce?(Give the number of the league): ";	cin >> choice;
	if (ExceptionHandling::handleLeagueException(choice,l, false) == true) return;
	cout << "What club would you like to remove? (give the number): "; cin >> choice2;
	if (ExceptionHandling::handleTeamException(choice, choice2, l) == true) return;
	l.leagues[choice - 1].Team.erase(l.leagues[choice - 1].Team.begin() + (choice2 - 1));
	cout << "Successfuly removed team!" << endl;
}

void ListOfLeagues::buyWorkerToTheTeam(ListOfLeagues& l)
{
	int choice, choice2;
	cout << "Which league would you like to buy worker?(Give the number of the league): ";	cin >> choice;
	if (ExceptionHandling::handleLeagueException(choice,l, false) == true) return;
	cout << "Which club would you like to buy worker? (give the number): "; cin >> choice2;
	if (ExceptionHandling::handleTeamException(choice, choice2, l) == true) return;
	l.leagues[choice - 1].Team[choice2 - 1].addToTheTeam();			
	cout << "Successfuly buyed worker to the team!" << endl << endl;
}

void ListOfLeagues::showWorkersOfTheTeam(ListOfLeagues& l)
{
	int choice, choice2;
	cout << "Which league would you like to see workers?(Give the number of the league): ";	cin >> choice;
	if (ExceptionHandling::handleLeagueException(choice,l, false) == true) return;
	cout << "Which club would you like to see workers? (give the number): "; cin >> choice2;
	if (ExceptionHandling::handleTeamException(choice, choice2, l) == true) return;
	l.leagues[choice - 1].Team[choice2 - 1].showTeamWorkers();
	cout << endl;
}

void ListOfLeagues::sellWorkerOfTheTeam(ListOfLeagues& l)
{
	int choice, choice2;
	cout << "Which league would you like to sell worker(Give the number of the league): "; cin >> choice;
	if (ExceptionHandling::handleLeagueException(choice,l, false) == true) return;
	cout << "Which club would you like to put worker? (give the number): "; cin >> choice2;
	if (ExceptionHandling::handleTeamException(choice, choice2, l) == true) return;
	l.leagues[choice - 1].Team[choice2 - 1].sellFromTheTeam();
	cout << "Succesfully selled worker from the team!" << endl << endl;
}

void ListOfLeagues::buySportFacilityToTheClub(ListOfLeagues& l)
{
	int choice, choice2;
	cout << "Which league would you like to buy sport facility?(Give the number of the league): ";	cin >> choice;
	if (ExceptionHandling::handleLeagueException(choice,l, false) == true) return;
	cout << "Which club would you like to buy sport facility? (give the number): "; cin >> choice2;
	if (ExceptionHandling::handleTeamException(choice, choice2, l) == true) return;
	l.leagues[choice - 1].Team[choice2 - 1].buySportFacilityToTheTeam();
	cout << "Successfuly buyed sport facility to the team!" << endl << endl;
}

void ListOfLeagues::showSportFacilitiesOfTheClub(ListOfLeagues& l)
{
	int choice, choice2;
	cout << "Which league would you like to see sport facilietes?(Give the number of the league): ";	cin >> choice;
	if (ExceptionHandling::handleLeagueException(choice,l, false) == true) return;
	cout << "Which club would you like to see sport facilietes?(give the number): "; cin >> choice2;
	if (ExceptionHandling::handleTeamException(choice, choice2, l) == true) return;
	l.leagues[choice - 1].Team[choice2 - 1].showSportFacilitiesOfTheTeam();
	cout << endl;
}

void ListOfLeagues::sellSportFacilityFromTheClub(ListOfLeagues& l)
{
	int choice, choice2;
	cout << "Which league would you like to sell sport facility(Give the number of the league): "; cin >> choice;
	if (ExceptionHandling::handleLeagueException(choice,l, false) == true) return;
	cout << "Which club would you like to sell sport facility? (give the number): "; cin >> choice2;
	if (ExceptionHandling::handleTeamException(choice, choice2, l) == true) return;
	l.leagues[choice - 1].Team[choice2 - 1].sellSportFacilityFromTheTeam();
}

void ListOfLeagues::simulateQueue(ListOfLeagues& l)			
{
	int choice;
	cout << "Which league would you like to simulate queue?(Give the number): "; cin >> choice;
	if (ExceptionHandling::handleLeagueException(choice,l, false) == true) return;
	MatchSimulation::simulateQueue(l, choice - 1);
}

void ListOfLeagues::readLeagueFromTheFile(fstream& file, ListOfLeagues& l)
{
	getline(file, leagueObject.nameOfLeague);
	l.leagues.push_back(leagueObject);
}

void ListOfLeagues::readClubFromTheLeague(fstream& file, int leagueCounter)
{
	auto it = listOfClubs.readTeamToTheLeague(file);
	leagues[leagueCounter].Team.push_back(it);
}

void ListOfLeagues::readPlayersToTheLeague(fstream& file,int leagueChoice,int teamChoice)
{
	leagues[leagueChoice].Team[teamChoice].readPlayerToTheTeam(file);
}

void ListOfLeagues::readEmployersToTheLeague(fstream& file, int leagueChoice, int teamChoice)
{
	leagues[leagueChoice].Team[teamChoice].readEmployerToTheTeam(file);
}

void ListOfLeagues::readSportFacilitiesToTheLeague(fstream& file, int leagueChoice, int teamChoice)
{
	leagues[leagueChoice].Team[teamChoice].readSportFacilityToTheTeam(file);
}

void ListOfLeagues::writeLeagueToTheFile(fstream& file, ListOfLeagues& l)
{
	for (int i = 0; i < static_cast<int>(l.leagues.size()); i++)
	{
		file << l.leagues[i].nameOfLeague;
		if (i == l.leagues.size() - 1) return;
		file << endl;
	}
}

void ListOfLeagues::writeClubToTheLeague(fstream& file, int leagueCounter, int teamCounter)
{
	leagues[leagueCounter].Team[teamCounter].writeTeamToTheLeague(file);
}

void ListOfLeagues::writePlayersToTheLeague(fstream& file, int leagueChoice, int teamChoice)
{
	leagues[leagueChoice].Team[teamChoice].writePlayerToTheTeam(file);	
}

void ListOfLeagues::writeEmployersToTheLeague(fstream& file, int leagueChoice, int teamChoice)
{
	leagues[leagueChoice].Team[teamChoice].writeEmployerToTheTeam(file);
}

void ListOfLeagues::writeSportFacilitiesToTheLeague(fstream& file, int leagueChoice, int teamChoice)
{
	leagues[leagueChoice].Team[teamChoice].writeSportFacilityToTheTeam(file);
}