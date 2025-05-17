#include "LoadAction.h"
#include "../ApplicationManager.h"
#include "../Figures\CFigure.h"
#include "../GUI\Output.h"
#include "../GUI\Input.h"
#include <iostream>
#include "../Figures\CRectangle.h"
#include "../Figures/CSquare.h" 
#include "../Figures/CTriangle.h" 
#include "../Figures/CHexagon.h"
#include "../Figures/CCircle.h"
#include <fstream>
#include "../GUI\UI_Info.h"
#include "../DEFS.h"
using namespace std;


LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{
}

void LoadAction::ReadActionParameters() {
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Load Figures: Enter file name ro load");
	FileName = pIn->GetSrting(pOut);

	if (!LoadFile.is_open()) {
		pOut->PrintMessage("Error opening file. Please check the file name");
	}
	else {
		pOut->PrintMessage("File opened successfully");
	}

	pOut->PrintMessage("Click anywhere to continue");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}

void LoadAction::Execute(bool readparameters) {
	Output* pOut = pManager->GetOutput();
	CFigure* pFig;
	ReadActionParameters();
	LoadFile.open(FileName, ios::in);

	if (LoadFile.is_open()) {
		pManager->LoadAll(LoadFile);
		LoadFile.close();
		pOut->PrintMessage("Graph loaded successfully!");
	}
	string drawColor, fillColor;
	LoadFile >> drawColor >> fillColor; //reading draw and fill colors

	color DrawColor = pFig->StringToColor(drawColor);
	pOut->setCrntDrawColor(DrawColor);

	if (fillColor == "No_Fill")
		pOut->setCrntFillColor(false);
	else
	{
		color FillColor = pFig->StringToColor(fillColor);
		pOut->setCrntFillColor(FillColor);
		pOut->setCrntFillColor(true);
	}


}

LoadAction::~LoadAction() {
	// Close the file if it is open
	if (LoadFile.is_open())
	LoadFile.close();
	
	
	delete this;
}
