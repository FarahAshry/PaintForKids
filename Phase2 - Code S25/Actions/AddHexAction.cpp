#include "AddHexAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

using namespace std;

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click on centre");

	//Read centre of hexagon and place in P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Hexagon: Enter length");

	//Read length of the hexagon
	Length = stod(pIn->GetSrting(pOut));

	HexGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(P1, Length, HexGfxInfo);

	//Add the hexagon to the list of figures
	pManager->AddFigure(H);
}
