#include"CUT.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\Output.h"
CUT::CUT(ApplicationManager* pApp):Action(pApp)
{
}

void CUT::ReadActionParameters()
{
}

void CUT::Execute()
{
    ReadActionParameters();

    CFigure* selected;
    selected = pManager->GetSelected();
    Output* pOut = pManager->GetOutput();

    if (selected == nullptr)
    {
        pOut->PrintMessage("Error!! you can only select one figure to cut");
        return;
    }

    ;
    pManager->SetClipboard(selected,true);

    pManager->RemoveFig(selected);

    pOut->PrintMessage("Figure cut successfully.");
}
