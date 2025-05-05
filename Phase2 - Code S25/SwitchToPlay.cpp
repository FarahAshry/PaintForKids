#include "SwitchToPlay.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\Output.h"

SwitchToPlay::SwitchToPlay(ApplicationManager* pApp) : Action(pApp) {}

void SwitchToPlay::ReadActionParameters() {
}

void SwitchToPlay::Execute() {
    Output* pOut = pManager->GetOutput();
    pOut->CreatePlayToolBar();
    pOut->PrintMessage("Play Mode :)");
    
}