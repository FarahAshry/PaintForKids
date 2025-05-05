#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();

	pOut->PrintMessage("Choose drawing color (b=Black, y=Yellow, o=Orange, r=Red, g=Green, u=blue.)");
	RectGfxInfo.DrawClr = pIn->GetColour(pOut);

	// Ask if user wants filled shape
	pOut->PrintMessage("Fill shape? (y/n)");
	string fill = pIn->GetSrting(pOut);
	RectGfxInfo.isFilled = (tolower(fill[0]) == 'y');

	if (RectGfxInfo.isFilled) {
		pOut->PrintMessage("Choose fill color");
		RectGfxInfo.FillClr = pIn->GetColour(pOut);
	}
	else RectGfxInfo.FillClr = UI.FillColor; // Default no-fill color

	pOut->ClearStatusBar();
}

//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}