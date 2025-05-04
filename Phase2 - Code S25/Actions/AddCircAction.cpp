#include "AddCircAction.h"
#include "Figures/CCircle.h"

#include "ApplicationManager.h"

#include "GUI/Output.h"
#include"GUI/Input.h"

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

	CircGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a circle with the parameters read from the user
	CCircle C = new CCircle(P1, radius, CircGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(C);
}

