#include "SwitchToDraw.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\Output.h"

SwitchToDraw :: SwitchToDraw(ApplicationManager* pApp)  : Action(pApp){
}
 void SwitchToDraw:: ReadActionParameters() {

}
 void SwitchToDraw:: Execute() {
    Output* pOut = pManager->GetOutput();
    pOut->PrintMessage("Switch to draw mode");
    UI.InterfaceMode = MODE_DRAW;
    pOut->CreateDrawToolBar();
    pOut->PrintMessage("Draw Mode :)");
    pOut->ClearDrawArea();
}

