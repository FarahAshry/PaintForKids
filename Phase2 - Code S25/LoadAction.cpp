#include "LoadAction.h"
#include "ApplicationManager.h"
#include "D:\Uni\Semester 2\Programming Techniques\Project\PT Project Phase1 - Code S25\Phase2 - Code S25\Figures\CFigure.h"
#include "D:\Uni\Semester 2\Programming Techniques\Project\PT Project Phase1 - Code S25\Phase2 - Code S25\GUI\Output.h"
#include "D:\Uni\Semester 2\Programming Techniques\Project\PT Project Phase1 - Code S25\Phase2 - Code S25\GUI\Input.h"
#include <iostream>
#include "D:\Uni\Semester 2\Programming Techniques\Project\PT Project Phase1 - Code S25\Phase2 - Code S25\Figures\CRectangle.h"
#include <fstream>
using namespace std;

LoadAction::LoadAction(ApplicationManager* pApp, int incFig) :Action(pApp) {
	this->pManager = pApp;
	LoadFile.open("Figures.txt", ios::out);
	if (!LoadFile.is_open()) {
	    cout << "Error opening file" << endl;
	}
	else {
		cout << "File opened successfully" << endl;
		LoadFile << incFig << endl;
		for (int i = 0; i < incFig; i++) {
			CFigure* pFig = pManager->GetFigure(P1.x,P1.y);
			if (pFig != nullptr) {
				pFig->Load(LoadFile);
			}
		}
	}
}
void LoadAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Load Figures: Click to load");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}
void LoadAction::Execute() {
	//This action needs to read some parameters first
	ReadActionParameters();
	
}
LoadAction::~LoadAction() {
	LoadFile.close();
	//Destructor
	pManager->RemoveAction(this);
	pManager->UpdateInterface();
	pManager->GetOutput()->ClearStatusBar();
	pManager->GetInput()->GetPointClicked(P1.x, P1.y);
	pManager->GetOutput()->ClearStatusBar();
	
	delete this;
}