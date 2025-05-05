#pragma once
#include "Action.h"

class PASTE:public Action
{
private:
Point p;
public:
	PASTE(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
