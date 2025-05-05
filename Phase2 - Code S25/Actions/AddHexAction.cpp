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

	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();

	pOut->PrintMessage("Choose drawing color (b=Black, y=Yellow, o=Orange, r=Red, g=Green, u=blue.)");
	HexGfxInfo.DrawClr = pIn->GetColour(pOut);

	//default is not filled
	HexGfxInfo.isFilled = false;
	// Ask if user wants filled shape
	pOut->PrintMessage("Fill shape? (y/n)");
	string fill = pIn->GetSrting(pOut);
	HexGfxInfo.isFilled = (tolower(fill[0]) == 'y');

	if (HexGfxInfo.isFilled) {
		pOut->PrintMessage("Choose fill color");
		HexGfxInfo.FillClr = pIn->GetColour(pOut);
	}
	else HexGfxInfo.FillClr = UI.FillColor; // Default no-fill color
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();
	pOut->ClearStatusBar();

}

void AddHexAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(P1, Length, HexGfxInfo);

	//Add the hexagon to the list of figures
	pManager->AddFigure(H);
}