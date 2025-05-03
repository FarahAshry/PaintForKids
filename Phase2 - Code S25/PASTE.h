#pragma once
#include "Action.h"

class PASTE:public Action
{
public:
	PASTE(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};