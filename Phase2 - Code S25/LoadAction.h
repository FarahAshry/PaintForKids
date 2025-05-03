#pragma once
#include <fstream>
#include "D:\Uni\Semester 2\Programming Techniques\Project\PT Project Phase1 - Code S25\Phase2 - Code S25\Actions\Action.h"

class LoadAction :public Action
{
private:
	std::ofstream LoadFile; //File to load from


	Point P1; //Point to load from
public:
	LoadAction(ApplicationManager* pApp, int incFig); //Constructor
	void ReadActionParameters(); //Reads parameters required for action to execute
	void Execute(); //Execute action (code depends on action type)
	~LoadAction(); //Destructor
};

