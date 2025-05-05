#include "AddCircAction.h"
#include "../Figures/CCircle.h"

#include "../ApplicationManager.h"

#include "../GUI/Output.h"
#include"../GUI/Input.h"

using namespace std;

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click on centre");

	//Read centre of circle and place in P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Enter radius");

	//Read radius of the circle
	radius = stod(pIn->GetSrting(pOut));

	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();

	pOut->PrintMessage("Choose drawing color (b=Black, y=Yellow, o=Orange, r=Red, g=Green, u=blue.)");
	CircGfxInfo.DrawClr = pIn->GetColour(pOut);

	//default is not filled
	CircGfxInfo.isFilled = false;
	// Ask if user wants filled shape
	pOut->PrintMessage("Fill shape? (y/n)");
	string fill = pIn->GetSrting(pOut);
	CircGfxInfo.isFilled = (tolower(fill[0]) == 'y');

	if (CircGfxInfo.isFilled) {
		pOut->PrintMessage("Choose fill color");
		CircGfxInfo.FillClr = pIn->GetColour(pOut);
	}
	else CircGfxInfo.FillClr = UI.FillColor; // Default no-fill color
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a circle with the parameters read from the user
	CCircle *C = new CCircle(P1, radius, CircGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(C);
}