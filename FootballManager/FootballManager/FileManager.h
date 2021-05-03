#pragma once
#include <iostream>
#include "ListOfLeagues.h"
#include "help.h"
#include <fstream>
#include <vector>

using namespace std;

class FileManager
{
private:
	ListOfLeagues listAssistant;
	
public:
	void readFromTheFile(ListOfLeagues& l);

	void saveToTheFile(ListOfLeagues& l);
};