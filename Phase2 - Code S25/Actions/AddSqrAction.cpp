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

	//Read centre of square and place in P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Square: Enter length");

	//Read length of the square
	Length = stod(pIn->GetSrting(pOut));

	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();

	pOut->PrintMessage("Choose drawing color (b=Black, y=Yellow, o=Orange, r=Red, g=Green, u=blue.)");
	SqrGfxInfo.DrawClr = pIn->GetColour(pOut);

	//default is not filled
	SqrGfxInfo.isFilled = false;
	// Ask if user wants filled shape
	pOut->PrintMessage("Fill shape? (y/n)");
	string fill = pIn->GetSrting(pOut);
	SqrGfxInfo.isFilled = (tolower(fill[0]) == 'y');

	if (SqrGfxInfo.isFilled) {
		pOut->PrintMessage("Choose fill color");
		SqrGfxInfo.FillClr = pIn->GetColour(pOut);
	}
	else SqrGfxInfo.FillClr = UI.FillColor; // Default no-fill color

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
