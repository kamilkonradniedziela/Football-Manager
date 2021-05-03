#include "MatchSimulation.h"

void MatchSimulation::simulateQueue(ListOfLeagues& l, int choiceOfLeague)
{
	unsigned seed = time(0);
	default_random_engine generator(seed);
	uniform_int_distribution<int> distribution(1, 100);
	cout << "Football week number: " << ++l.leagues[choiceOfLeague].matchdayCounter << endl;
	for (int i = 0; i < l.leagues[choiceOfLeague].Team.size(); i++)
	{
		if (l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam > 0 && l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam <= 30)
		{
			int roll = distribution(generator);
			if (roll <= 10)				//zwyciestwo
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 3;
			}
			else if (roll > 10 && roll <= 50)				//remis
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 1;
			}
			else				//porazka
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 0;
			}
		}
		else if (l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam > 30 && l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam <= 60)
		{
			int roll = distribution(generator);
			if (roll <= 10)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 3;
			}
			else if (roll > 10 && roll <= 80)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 1;
			}
			else
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 0;
			}
		}
		else if (l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam > 60 && l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam <= 90)
		{
			int roll = distribution(generator);
			if (roll <= 20)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 3;
			}
			else if (roll > 20 && roll <= 60)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 1;
			}
			else
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 0;
			}
		}
		else if (l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam > 90 && l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam <= 120)
		{
			int roll = distribution(generator);
			if (roll <= 20)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 3;
			}
			else if (roll > 20 && roll <= 80)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 1;
			}
			else
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 0;
			}
		}
		else if (l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam > 120 && l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam <= 150)
		{
			int roll = distribution(generator);
			if (roll <= 30)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 3;
			}
			else if (roll > 30 && roll <= 50)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 1;
			}
			else
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 0;
			}
		}
		else if (l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam > 150 && l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam <= 180)
		{
			int roll = distribution(generator);
			if (roll <= 30)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 3;
			}
			else if (roll > 30 && roll <= 80)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 1;
			}
			else
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 0;
			}
		}
		else if (l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam > 180 && l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam <= 210)
		{
			int roll = distribution(generator);
			if (roll <= 40)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 3;
			}
			else if (roll > 40 && roll <= 70)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 1;
			}
			else
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 0;
			}
		}
		else if (l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam > 210 && l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam <= 240)
		{
			int roll = distribution(generator);
			if (roll <= 50)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 3;
			}
			else if (roll > 50 && roll <= 80)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 1;
			}
			else
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 0;
			}
		}
		else if (l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam > 240 && l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam <= 270)
		{
			int roll = distribution(generator);
			if (roll <= 60)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 3;
			}
			else if (roll > 60 && roll <= 80)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 1;
			}
			else
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 0;
			}
		}
		else if (l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam > 270 && l.leagues[choiceOfLeague].Team[i].ratingOfTheTeam <= 300)
		{
			int roll = distribution(generator);
			if (roll <= 70)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 3;
			}
			else if (roll > 70 && roll <= 90)
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 1;
			}
			else
			{
				l.leagues[choiceOfLeague].Team[i].pointsInTheLeague += 0;
			}
		}
	}
	cout << "Simulated Queue!" << endl << endl;
	if (l.leagues[choiceOfLeague].matchdayCounter == 5)
	{
		string champion = l.leagues[choiceOfLeague].Team[0].nameOfTeam;
		int maxPoints = l.leagues[choiceOfLeague].Team[0].pointsInTheLeague;
		int indexWithTeamOfMaxPoints = 0;
		for (int i = 0; i < l.leagues[choiceOfLeague].Team.size(); i++)
		{
			if (l.leagues[choiceOfLeague].Team[i].pointsInTheLeague > maxPoints)
			{
				maxPoints = l.leagues[choiceOfLeague].Team[i].pointsInTheLeague;
				indexWithTeamOfMaxPoints = i;
			}
		}
		champion = l.leagues[choiceOfLeague].Team[indexWithTeamOfMaxPoints].nameOfTeam;
		cout << "That's the end of the club competition" << endl;
		cout << "The Champion is: " << champion << " !!!" << endl;
		cout << "Congratulations: " << champion << " !!!" << endl << endl;
		for (int i = 0; i < l.leagues[choiceOfLeague].Team.size(); i++)
		{
			l.leagues[choiceOfLeague].Team[i].pointsInTheLeague = 0;
		}
		l.leagues[choiceOfLeague].matchdayCounter = 0;
	}
}