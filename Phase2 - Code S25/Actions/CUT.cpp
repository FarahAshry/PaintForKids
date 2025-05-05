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
    CFigure* selected;
    selected = pManager->GetSelected();
    Output* pOut = pManager->GetOutput();
    if (selected == nullptr)
    {
        pOut->PrintMessage("You should select one figure to cut");
        return;
    }
    if (pManager->GetIsCut())
    {
        pManager->Uncut();
    }
    /*pManager->SetCutColors(selected->GetDrawClr(), selected->GetFillClr());*/
   /* selected->ChngDrawClr(GRAY);
    selected->ChngFillClr(GRAY);*/
    pManager->SetClipboard(selected,true);
    /*pManager->SetCuttedFig(selected);*/
    pOut->PrintMessage("Figure cut successfully.");
}
