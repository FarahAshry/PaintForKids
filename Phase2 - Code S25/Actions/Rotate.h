#pragma once
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include "../Figures/CFigure.h"
#include "Action.h"
class Rotate : public Action
{
	Rotate(ApplicationManager* pApp, CFigure* C);
};

