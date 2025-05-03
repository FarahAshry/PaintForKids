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
    ReadActionParameters();

    CFigure* selected;
    selected = pManager->GetSelected();
    Output* pOut = pManager->GetOutput();

    if (selected == nullptr)
    {
        pOut->PrintMessage("Error!! you can select only one figure to copy");
        return;
    }


    CFigure* copy = selected->Clone();


    pManager->SetClipboard(copy,false);

    pOut->PrintMessage("Figure copied :) ");
}
