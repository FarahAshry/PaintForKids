#pragma once
#include"Action.h"
class COPY :public Action
{
public:
	COPY(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};