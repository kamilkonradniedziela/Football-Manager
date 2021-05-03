#pragma once
#include <iostream>

using namespace std;

template <class T>
void help(T name, T surrname)
{
	cout << "Welcome to Football Manager!" << endl;
	cout << "Manager: " << name << " " << surrname << endl << endl;
	puts("Choose one option: \n"
		"1.Add football league\n"
		"2.Show all football leagues\n"
		"3.Remove football league\n"
		"4.Add club to the league\n"
		"5.Show all league's clubs\n"
		"6.Remove club from the league\n"
		"7.Buy footballer or employee to the club\n"
		"8.Show workers of the team\n"
		"9.Sell footballer or employee from the club\n"
		"10.Buy sport facility to the club\n"
		"11.Show sport facilities of the club\n"
		"12.Sell sport facility from the club\n"
		"13.Simulate a queue\n"
		"14.Quit\n");
}