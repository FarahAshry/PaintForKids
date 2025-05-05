#include "Rotate.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include "../Figures/CFigure.h"
#include "../Actions/Action.h"

Rotate :: Rotate(ApplicationManager* pApp, CFigure* C) :Action(pApp) {
	
	Output* pOut;

	if (C->IsSelected()==1) {
		int ID = C->getID();

		if (ID == ITM_SQUARE || ID == ITM_HEX) {
			pOut->PrintMessage("No effect on figure");
			C->SetSelected(false);
		}
		else{	
		}
	}
	else {
		pOut->PrintMessage("No object selected");
	}
}
