#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "help.h"
#include "Person.h"
#include "ListOfLeagues.h"
#include "League.h"
#include "ListOfTeams.h"
#include "Team.h"
#include "SportFacility.h"
#include "ProgrammManagement.h"
#include "FileManager.h"
#include "ExceptionHandling.h"

using namespace std;

int main()
{
	string name, surrname;
	int choice;
	ProgrammManagement mainList;
	ListOfLeagues mainObject;
	mainList.fm.readFromTheFile(mainObject);
	cout << "What's your name: "; cin >> name;
	cout << "What's your surrname: "; cin >> surrname; cout << endl;
	do
	{
		help(name, surrname);
		cout << "Choice: "; cin >> choice;
		switch (choice)
		{
		case 1:
			mainList.mList.addLeague(mainObject);
			break;
		case 2:
			mainList.mList.showAllLeagues(mainObject);
			break;
		case 3:		
			mainList.mList.removeLeague(mainObject);
			break;
		case 4:		
			mainList.mList.addClubsToTheLeague(mainObject);
			break;
		case 5:		
			mainList.mList.showLeagueTeams(mainObject);
			break;
		case 6:		
			mainList.mList.deleteLeagueTeam(mainObject);
			break;
		case 7:
			mainList.mList.buyWorkerToTheTeam(mainObject);
			break;
		case 8:
			mainList.mList.showWorkersOfTheTeam(mainObject);
			break;
		case 9:
			mainList.mList.sellWorkerOfTheTeam(mainObject);
			break;
		case 10:
			mainList.mList.buySportFacilityToTheClub(mainObject);
			break;
		case 11:
			mainList.mList.showSportFacilitiesOfTheClub(mainObject);
			break;
		case 12:
			mainList.mList.sellSportFacilityFromTheClub(mainObject);
			break;
		case 13:
			mainList.mList.simulateQueue(mainObject);
			break;
		case 14:
			cout << "See you soon!...." << endl;
			break;
		default:
			cout << "Bad choice. Try again...." << endl << endl;
			break;
		}
	} while (choice != 14);
	mainList.fm.saveToTheFile(mainObject);
}