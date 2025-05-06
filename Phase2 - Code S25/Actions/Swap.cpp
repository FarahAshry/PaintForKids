#include "Swap.h"
#include "Action.h"        
#include "../ApplicationManager.h" 
#include "../GUI/Output.h"
#include "../Figures/CFigure.h"


Swap::Swap(ApplicationManager* pApp) :Action(pApp) {
	SuccessfulyS = 0;
}
void Swap::ReadActionParameters() {
	
	Output* pOut = pManager->GetOutput();
	int countS = (pManager->GetSelectedCount());
	if (countS !=2) {
		if (countS<2)
			pOut->PrintMessage("Please select atleast 2 figures to swap");
		else
			pOut->PrintMessage("Select only 2 figures to swap");

		CFigure** figList = pManager->GetFigureList();
		int figCount = pManager->GetFigureCount();

		for (int i = 0; i < figCount; i++)
		{
			if (figList[i]->IsSelected())
			{
				figList[i]->SetSelected(false);
				figList[i]->ChngDrawClr(BLACK);
			
			}
		}
		countS = 0;
		SuccessfulyS = 0;
		return;

	}
	else {
		pOut->PrintMessage("Selected 2 figures to swap");
		SuccessfulyS = 1;
	}
}
void Swap::Execute() {
	Output* pOut = pManager->GetOutput();
	CFigure** figList = pManager->GetFigureList();
	int figCount = pManager->GetFigureCount();

	CFigure* selected[2];
	int j = 0;

	// Get 2 figures 
	for (int i = 0; i < pManager->GetFigureCount(); i++) {

		if (figList[i]->IsSelected()) {
			selected[j++] = figList[i];
		}
		if (j == 2) 
			break;
	}

	// take centers
	Point c1 = selected[0]->getCentre();
	Point c2 = selected[1]->getCentre();
	//move each shape from its center to new center
	selected[0]->setCentre(c2); 
	selected[1]->setCentre(c1);  

	pManager->deselect();
	pManager->UpdateInterface(); 
}


