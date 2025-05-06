#include "SwitchToPlay.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\Output.h"

SwitchToPlay::SwitchToPlay(ApplicationManager* pApp) : Action(pApp) {}

void SwitchToPlay::ReadActionParameters() {
}

void SwitchToPlay::Execute() {
    Output* pOut = pManager->GetOutput();
    pOut->PrintMessage("Switch to play mode");
    pOut->ClearToolBar();
    UI.InterfaceMode = MODE_PLAY;
    pOut->CreatePlayToolBar();
    pOut->PrintMessage("Play Mode :)");
	pOut->ClearDrawArea();
}