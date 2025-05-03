#pragma once
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "GUI/Input.cpp"
#include "GUI/Output.cpp"
#include "ApplicationManager.h"
#include "Figures/CFigure.h"
#include "Actions/Action.h"
class Rotate : public CFigure, public Action
{
	Rotate(ApplicationManager* pApp);
};

