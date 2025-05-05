#pragma once
#include "Action.h"        
#include "../ApplicationManager.h" 
#include "../GUI/Output.h"

class Swap : public Action
{
private:
	bool SuccessfulyS = 0;
public:

	Swap(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};

