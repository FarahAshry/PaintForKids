#include "Select.h"
#include "Figures/CFigure.h" 
#include "GUI/Input.h"     
#include "GUI/Output.h"

Select::Select(ApplicationManager* pApp) : Action(pApp) {}

void Select::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMessage("Click on a figure to select");
    pIn->GetPointClicked(P1.x, P1.y);
    pOut->ClearStatusBar();
}

void Select::ClearSelection()
{
    // Get figures and their count from ApplicationManager
    CFigure** figList = pManager->GetFigureList();
    int figCount = pManager->GetFigureCount();

    for (int i = 0; i < figCount; i++)
    {
        if (figList[i]->IsSelected())
        {
            figList[i]->SetSelected(false);
            figList[i]->ChngDrawClr(BLACK);
        }
    }
}

CFigure* Select::GetTopFigureAtPoint(int x, int y) const
{
    return pManager->GetFigure(x, y);
}

void Select::Execute(bool reading)
{
    if (reading) ReadActionParameters();

    Output* pOut = pManager->GetOutput();

    int count = pManager->GetSelectedCount();
    CFigure* clickedFigure = GetTopFigureAtPoint(P1.x, P1.y);

    if (count == 0) // No figures currently selected
    {
        if (clickedFigure != NULL)
        {
            // highlight the figure
            clickedFigure->SetSelected(true);
            clickedFigure->ChngDrawClr(MAGENTA);

            // Print figure ID
            pOut->PrintMessage(clickedFigure->GetInfoString());
        }
        else // Clicked on empty space
        {
            ClearSelection();
        }
    }
    else // Some figures already selected
    {
        if (clickedFigure == NULL)
        {
            // Clicked on empty space
            ClearSelection();
        }
        else if (clickedFigure->IsSelected())
        {
            // Clicked on selected figure - deselect it
            clickedFigure->SetSelected(false);
            clickedFigure->ChngDrawClr(BLACK); // Return to default color
        }
        else
        {
            // Clicked on new figure
            clickedFigure->SetSelected(true);
            clickedFigure->ChngDrawClr(MAGENTA);

            // Print count of selected figures by type
            int rectCount = pManager->GetSelectedFigureCount(ITM_RECT);
            int sqrCount = pManager->GetSelectedFigureCount(ITM_SQUARE);
            int triCount = pManager->GetSelectedFigureCount(ITM_TRI);
            int circCount = pManager->GetSelectedFigureCount(ITM_CIRCLE);
            int hexCount = pManager->GetSelectedFigureCount(ITM_HEX);

            pOut->PrintMessage("Selected: " + to_string(rectCount) + " Rectangle(s), " + 
                                              to_string(sqrCount) + " Square(s)" +
                                              to_string(triCount) + " Triangle(s)" +
                                              to_string(circCount) + " Circle(s)" +
                                              to_string(hexCount) + " Hexagon(s)");
        }
    }

    pManager->UpdateInterface();
}
