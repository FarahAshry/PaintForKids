#pragma once
#include "Action.h"

class CUT:public Action
{
public:
    CUT(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};