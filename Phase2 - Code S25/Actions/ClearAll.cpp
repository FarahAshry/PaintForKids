#include "ClearAll.h"
#pragma once
#include "Action.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"


ClearAll::ClearAll(ApplicationManager* pApp) {
	Output* pOut;
	pOut->PrintMessage("Clearing all menus");
	void ClearStatusBar();	
	void ClearToolBar();
	void ClearDrawArea();
}