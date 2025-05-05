#include "Action.h"
#include "Delete.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
Delete::Delete(ApplicationManager* pApp) :Action(pApp) {
}
void Delete:: ReadActionParameters() {

 }
void Delete:: Execute() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Figure selected deleted");
	for (int i = 0; i < pManager->GetFigureCount(); i++) {
		if (pManager->GetFigureByIndex(i)->IsSelected()) {
			pManager->RemoveFig(pManager->GetFigureByIndex(i));
		}
	}
 }
