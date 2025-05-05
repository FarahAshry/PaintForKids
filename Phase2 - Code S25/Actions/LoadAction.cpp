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

LoadAction::LoadAction(ApplicationManager* pApp, int incFig) :Action(pApp) { this->incFig = incFig; }

void LoadAction::ReadActionParameters() {
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Load Figures: Click to load");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}

void LoadAction::Execute() {

	string FigColor;


	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string tempColor;

	LoadFile.open("Figures.txt", ios::out);
	if (!LoadFile.is_open()) {
		cout << "Error opening file" << endl;
	}
	else {
		
		cout << "File opened successfully" << endl;
		LoadFile << incFig << endl;
		for (int i = 0; i < 200; i++) {
			CFigure* pFig = pManager->GetFigure(P1.x, P1.y);
			
			if (pFig != nullptr) {
				if (pFig->getColor() == RED) {
					tempColor = "Red";
				}
				else if (pFig->getColor() == BLUE) {
					tempColor = "Blue";
				}
				else if (pFig->getColor() == YELLOW) {
					tempColor = "Yellow";
				}
				else if (pFig->getColor() == BLACK) {
					tempColor = "Black";
				}
				else if (pFig->getColor() == ORANGE) {
					tempColor = "Orange";
				}
				else if (pFig->getColor() == GREEN) {
					tempColor = "Green";
				}

				pFig->Load(LoadFile);
				pFig->setID(i);
				LoadFile << pFig->getFigureType()<< "\t" << pFig->getID() << endl;

			}

		}
	}
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
