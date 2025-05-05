#pragma once
#include "Action.h"

class Delete :public Action
{
private:
public:
	Delete(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
