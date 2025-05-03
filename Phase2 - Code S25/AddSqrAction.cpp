#include "AddSqrAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

using namespace std;

AddSqrAction::AddSqrAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddSqrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click on centre");

	//Read centre and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Square: Enter length");

	//Read length using stod() function
	//unsure of how to get length
	Length = stod(pIn->GetSrting(pOut));

	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqrGfxInfo.FillClr = pOut->getCrntFillColor();


	pOut->ClearStatusBar();

}

//Execute the action
void AddSqrAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a square with the parameters read from the user
	CSquare* S = new CSquare(P1, Length, SqrGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(S);
}
