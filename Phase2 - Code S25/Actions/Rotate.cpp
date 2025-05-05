#include "Rotate.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "GUI/Input.cpp"
#include "GUI/Output.cpp"
#include "ApplicationManager.h"
#include "Figures/CFigure.h"
#include "Actions/Action.h"

Rotate :: Rotate(ApplicationManager* pApp){
	Output* pOut;

	if (IsSelected()==1) {
		if (ID == ITM_SQUARE || ID == ITM_HEX) {
			pOut->PrintMessage("No effect on figure");
			SetSelected(0);
		else{	
			switch(ID)
				case :



			SetSelected(0);
		}
	}
	else {
		pOut->PrintMessage("No object selected");
	}
}
