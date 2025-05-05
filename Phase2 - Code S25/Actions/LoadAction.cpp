#include "LoadAction.h"
#include "ApplicationManager.h"
#include "Figures\CFigure.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Figures/CRectangle.h"
#include "Figures/CCircle.h"
#include "Figures/CTriangle.h"
#include "Figures/CSquare.h"
#include "Figures/CHexagon.h"
#include <iostream>
#include <fstream>
#include "GUI\UI_Info.h"
#include "DEFS.h"
using namespace std;

LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp) {}

void LoadAction::ReadActionParameters() {
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Load: Enter file name: ");
	FileName = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}

void LoadAction::Execute(bool readparameters ) {

	Output* pOut = pManager->GetOutput();
	
	ReadActionParameters();
	
	//Input* pIn = pManager->GetInput();
	
	LoadFile.open(FileName, ios::in);

	if (!LoadFile.is_open()) {
		cout << "Error opening file" << endl;
	}

	string drawColor, fillColor;
	LoadFile >> drawColor >> fillColor; //reading draw and fill colors

	color DrawColor = pManager->StringToColor(drawColor);
	pOut->setCrntDrawColor(DrawColor);

	if (fillColor == "No_Fill")
		pOut->setCrntFillColor(false);
	else
	{
		color FillColor = pManager->StringToColor(fillColor);
		pOut->setCrntFillColor(FillColor);
		pOut->setCrntFillColor(true);
	}
	string figureType;
	while (LoadFile >> figureType) //reading figure type
	{
		CFigure* pFig = nullptr;

		if (figureType == "RECT")
			pFig = new CRectangle();
		else if (figureType == "CIRC")
			pFig = new CCircle();
		else if (figureType == "SQR")
			pFig = new CSquare();
		else if (figureType == "TRI")
			pFig = new CTriangle();
		else if (figureType == "HEX")
			pFig = new CHexagon();

		if (pFig)
		{
			pFig->Load(LoadFile); 
			pManager->AddFigure(pFig); // Add to ApplicationManager
		}
	}

	
	LoadFile.close();
	pOut->PrintMessage("Graph loaded successfully!");
}
LoadAction::~LoadAction() {}
