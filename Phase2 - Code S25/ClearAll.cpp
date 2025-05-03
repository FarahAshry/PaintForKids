#include "ClearAll.h"
#pragma once
#include "Actions/Action.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "GUI/Input.cpp"
#include "GUI/Output.cpp"
#include "ApplicationManager.h"


ClearAll::ClearAll(ApplicationManager* pApp) {
	Output* pOut;
	pOut->PrintMessage("Clearing all menus");
	void ClearStatusBar();	
	void ClearToolBar();
	void ClearDrawArea();
}