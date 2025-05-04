#pragma once
#include "Actions/Action.h"        
#include "ApplicationManager.h" 
#include "GUI/Output.h"

class Select : public Action
{
private:
    Point P1; // Click position
    void ClearSelection();
public:
    Select(ApplicationManager* pApp); // Constructor
    virtual void ReadActionParameters();
    virtual void Execute(bool reading = false);
    CFigure* GetTopFigureAtPoint(int x, int y) const;
};
