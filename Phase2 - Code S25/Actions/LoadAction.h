#pragma once
#include <fstream>
#include "Action.h"

class LoadAction :public Action
{
private:
	std::ofstream LoadFile; //File to load from
	Point P1; //Point to load from
	int incFig;
public:
	LoadAction(ApplicationManager* pApp, int incFig); //Constructor
	void ReadActionParameters(); //Reads parameters required for action to execute
	void Execute(); //Execute action (code depends on action type)
	void Load(ofstream &Infile);
	~LoadAction(); //Destructor
};

