
#pragma once
#include "Swap.h"
#include "Action.h"        
#include "../ApplicationManager.h" 
#include "../GUI/Output.h"


Swap::Swap(ApplicationManager* pApp) :Action(pApp) {
}
void Swap::ReadActionParameters() {
	
	Output* pOut = pManager->GetOutput();
	int countS = 0;
	countS = (pManager->GetSelectedCount());
	if (countS !=2) {
		if (countS<2)
			pOut->PrintMessage("Please select atleast 2 figures to swap");
		if (countS > 2)
			pOut->PrintMessage("Select only 2 figures to swap");

		CFigure* figList = pManager->GetFigureList();
		int figCount = pManager->GetFigureCount();

			for (int i = 0; i < figCount; i++)
			{
				if (figList[i].IsSelected())
				{
					figList[i].SetSelected(false);
					figList[i].ChngDrawClr(BLACK);
					pManager->GetSelectedCount()--;
				}
			}
		countS = 0;

	}
	else {
		pOut->PrintMessage("Selected 2 figures to swap");
		SuccessfulyS = 1;
	}
}
void Swap::Execute() {
	if (SuccessfulyS) {

	}
}
