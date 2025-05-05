#pragma once
#include <fstream>
#include "Actions\Action.h"

class LoadAction :public Action
{
private:
	std::ifstream LoadFile; //File to load from
	string FileName;

public:
	LoadAction(ApplicationManager* pApp); //Constructor
	void ReadActionParameters(); //Reads parameters required for action to execute
	void Execute(bool readparameters = true); //Execute action (code depends on action type)
	~LoadAction(); //Destructor
};

