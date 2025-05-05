#include "COPY.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\Output.h"

COPY::COPY(ApplicationManager* pApp) : Action(pApp) {}

void COPY::ReadActionParameters()
{
}

void COPY::Execute()
{
    CFigure* selected;
    selected = pManager->GetSelected();
    Output* pOut = pManager->GetOutput();

    if (selected == nullptr)
    {
        pOut->PrintMessage("You should select one figure to copy");
        return;
    }

    if (pManager->GetIsCut()) 
    {
        pManager->Uncut();
    }

    CFigure* copy = selected->Clone();
    pManager->SetClipboard(copy,false);
    pOut->PrintMessage("Figure copied :) ");
}
