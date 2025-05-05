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
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please click anywhere to paste");
	pIn->GetPointClicked(p.x, p.y);
	
}

void PASTE::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Click anywhere to paste ");
	bool c = pManager->GetIsCut();
	CFigure* Clipboard = pManager->GetClipboard(); 
	if (!Clipboard)
	{
		pOut->PrintMessage("Copy or Cut to be able to use clipboard in pasting");
		return;
	}
	else
	{
		if (c)
		{
			Clipboard->paste_clone(p);
			Clipboard->SetSelected(false);
			/*pManager->AddFigure(Clipboard);*/
			pManager->Uncut();
		}
		else
		{
			CFigure* copied = Clipboard->Clone();
			copied->paste_clone(p);
			copied->SetSelected(false);
			pManager->AddFigure(copied);
		}
		pOut->PrintMessage("Pasted :)");
	}
}
