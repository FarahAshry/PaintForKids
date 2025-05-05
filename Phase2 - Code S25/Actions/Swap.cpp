
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
	if (countS < 2) {
		pOut->PrintMessage("Please select atleast 2 figures to swap");

		countS = 0;

	
		
	}
	else if (countS > 2)
	{
		pOut->PrintMessage("Select only 2 figures to swap");
	}
	else {
		pOut->PrintMessage("Selected 2 figures to swap");

	}
}
void Swap::Execute() {

}
