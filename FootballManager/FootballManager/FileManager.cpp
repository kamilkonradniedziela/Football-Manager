#include "FileManager.h"

void FileManager::readFromTheFile(ListOfLeagues& l)
{
	fstream fileWithLeagues;
	int numberOfTheLeague = 0;
	fileWithLeagues.open("fileWithLeagues.txt", ios::in);
	if (fileWithLeagues.good() == true)
	{
		while (!fileWithLeagues.eof())
		{
			listAssistant.readLeagueFromTheFile(fileWithLeagues, l);
			numberOfTheLeague++;
		}
	}
	fileWithLeagues.close();

	for (int leagueCounter = 0; leagueCounter < numberOfTheLeague; leagueCounter++)
	{
		fstream league, club, clubPlayers, clubEmployers, sportFacilities;
		int teamCounter = 0;
		league.open(l.leagues[leagueCounter].nameOfLeague + ".txt", ios::in);
		while (!league.eof())
		{
			string line;
			getline(league, line);
			if (line == "")
			{
				break;
			}
			club.open(line + ".txt", ios::in);
			while (!club.eof())
			{
				l.readClubFromTheLeague(club, leagueCounter);

				clubPlayers.open(line + "Players.txt");
				if (clubPlayers.good() == true)
				{
					if (!(clubPlayers.peek() == ifstream::traits_type::eof()))			//file isn't empty
					{
						while (!clubPlayers.eof())
						{
							l.readPlayersToTheLeague(clubPlayers, leagueCounter, teamCounter);
						}
					}
					clubPlayers.close();
				}

				clubEmployers.open(line + "Employers.txt");
				if (clubEmployers.good() == true)
				{
					if (!(clubEmployers.peek() == ifstream::traits_type::eof()))
					{
						while (!clubEmployers.eof())
						{
							l.readEmployersToTheLeague(clubEmployers, leagueCounter, teamCounter);
						}
					}
					clubEmployers.close();
				}

				sportFacilities.open(line + "SportFacilities.txt");	
				if (sportFacilities.good() == true)
				{
					if (!(sportFacilities.peek() == ifstream::traits_type::eof()))
					{
						while (!sportFacilities.eof())
						{
							l.readSportFacilitiesToTheLeague(sportFacilities, leagueCounter, teamCounter);
						}
					}
					sportFacilities.close();
				}

				teamCounter++;
			}
			club.close();
		}
		league.close();
	}
}

void FileManager::saveToTheFile(ListOfLeagues& l)
{
	fstream fileWithLeagues;
	int numberOfTheLeague = 0;
	fileWithLeagues.open("fileWithLeagues.txt", ios::out);
	if (fileWithLeagues.good() == true)
	{
		listAssistant.writeLeagueToTheFile(fileWithLeagues, l);
		numberOfTheLeague = l.leagues.size();
	}
	fileWithLeagues.close();

	for (int leagueCounter = 0; leagueCounter < numberOfTheLeague; leagueCounter++)
	{
		fstream league, club, clubPlayers, clubEmployers, sportFacilities;
		league.open(l.leagues[leagueCounter].nameOfLeague + ".txt", ios::out);
		for (int teamCounter = 0; teamCounter < l.leagues[leagueCounter].Team.size(); teamCounter++)
		{
			league << l.leagues[leagueCounter].Team[teamCounter].nameOfTeam << endl;
			club.open(l.leagues[leagueCounter].Team[teamCounter].nameOfTeam + ".txt", ios::out);
			l.writeClubToTheLeague(club, leagueCounter, teamCounter);
			clubPlayers.open(l.leagues[leagueCounter].Team[teamCounter].nameOfTeam + "Players.txt", ios::out);
			l.writePlayersToTheLeague(clubPlayers, leagueCounter, teamCounter);
			clubEmployers.open(l.leagues[leagueCounter].Team[teamCounter].nameOfTeam + "Employers.txt", ios::out);
			l.writeEmployersToTheLeague(clubEmployers, leagueCounter, teamCounter);
			sportFacilities.open(l.leagues[leagueCounter].Team[teamCounter].nameOfTeam + "SportFacilities.txt", ios::out);
			l.writeSportFacilitiesToTheLeague(sportFacilities, leagueCounter, teamCounter);

			club.close();
			clubPlayers.close();
			clubEmployers.close();
			sportFacilities.close();
		}
		league.close();
	}
}