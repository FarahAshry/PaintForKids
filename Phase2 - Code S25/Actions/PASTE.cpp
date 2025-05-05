#include "PASTE.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

PASTE::PASTE(ApplicationManager* pApp) :Action(pApp)
{
}

void PASTE::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	int x;
	int y;
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please click on the place you want to paste at");
	pIn->GetPointClicked(x, y);
	
}

void PASTE::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	CFigure* Clipboard = pManager->GetClipboard();
	if (!Clipboard)
	{
		pOut->PrintMessage("Copy or Cut to be able to use clipboard");
		return;

}
	pOut->PrintMessage("Click anywhere to paste ");
	int x;
	int y;
	pIn->GetPointClicked(x, y);
	Point c= { x, y };
	CFigure* paste = Clipboard->Clone();
	paste->paste_clone(c);
	paste->SetSelected(false);
	pManager->AddFigure(paste);
	pManager->Uncut();
	pOut->PrintMessage("Pasted :)");
}
