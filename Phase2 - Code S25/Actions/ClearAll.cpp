#include "ClearAll.h"
#pragma once
#include "Action.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"

ClearAll::ClearAll(ApplicationManager* pApp) :Action(pApp) {
}
void ClearAll::ReadActionParameters() {}
void ClearAll::Execute() {
	Output* pOut;
	pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pOut->ClearDrawArea();
	pOut->PrintMessage("Cleared Everything");
}