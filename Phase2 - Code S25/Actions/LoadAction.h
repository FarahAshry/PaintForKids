#pragma once
#include <fstream>
#include "Action.h"

class LoadAction :public Action
{
private:
	std::ifstream LoadFile; //File to load from
	string FileName;
	Point P1; //Point to load from
	int incFig;
public:
	LoadAction(ApplicationManager* pApp); //Constructor
	void ReadActionParameters(); //Reads parameters required for action to execute
	void Execute(bool readparameters = true); //Execute action (code depends on action type)
	~LoadAction(); //Destructor
};

