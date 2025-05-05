#pragma once
#include "Action.h"        
#include "../ApplicationManager.h" 
#include "../GUI/Output.h"

class Swap : public Action
{
	Swap(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};

