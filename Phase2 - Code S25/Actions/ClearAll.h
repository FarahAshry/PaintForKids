#pragma once
#include "Action.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"

class ClearAll :public Action
{
public:
	ClearAll(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();

};
