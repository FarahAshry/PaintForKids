#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddSqrAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\Select.h"
#include "Actions\COPY.h"
#include "Actions\COPY.h"
#include"Actions\CUT.h"
#include"Actions\PASTE.h"

#include <iostream>
#include <fstream>




//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	Clipboard = nullptr;
	CuttedFig = nullptr;

IsClip_Cut = false;
IsFilled_Cut = false;
	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case EXIT:
		///create ExitAction here

		break;

	case STATUS:	//a click on the status bar ==> no action
		return;

	case COPY_FIG:
		pAct = new COPY(this);
		break;
	case CUT_FIG:
	        pAct = new CUT(this);
	        break;

        case PASTE_FIG:
	      pAct = new PASTE(this);
	      break;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	
	// NADA TODO

	/*for (int i = FigCount-1; i >= 0; i--) {
        	if (FigList[i]->ContainsPoint(x, y)) return FigList[i];
    	}*/

    	return nullptr;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
CFigure* ApplicationManager::RemoveAction(Action* pAct)
{
	return nullptr;
}
void ApplicationManager::LoadAll()
{
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::RemoveFig(CFigure* pFig)
{
	for (int i = 0; i < FigCount; ++i)
	{
		if (FigList[i] == pFig)
		{
			delete FigList[i];

			for (int j = i; j < FigCount - 1; ++j)
			{
				FigList[j] = FigList[j + 1];
			}
			FigList[--FigCount] = nullptr;
			break;
		}
	}
}

CFigure* ApplicationManager::GetFigureList()
{
	return nullptr;
}

int ApplicationManager::GetFigureCount()
{
	return 0;
}

int ApplicationManager::GetSelectedCount()
{
	return 0;
}

int ApplicationManager::GetSelectedFigureCount(DrawMenuItem item)
{
	return 0;
}

CFigure* ApplicationManager::GetSelected() const {
	CFigure* selected = nullptr;
	int c = 0;
	for (int i = 0; i < FigCount; ++i) {
		if (FigList[i]->IsSelected()) {
			c++;
			selected = FigList[i];
		}
	}
	if (c == 1)
	{
		return selected;
	}
	else
	{
		return nullptr;
	}
}
void ApplicationManager::Uncut()
{
	if (IsClip_Cut && CuttedFig)
	{
		CuttedFig->ChngFillClr(FillOg_Cut);
		CuttedFig->ChngDrawClr(DrawOg_Cut);

		CuttedFig = nullptr;
		IsClip_Cut = false;
		Clipboard = nullptr;
	}
}

void ApplicationManager::SetClipboard(CFigure* pFig,bool IsCut)
{
	Uncut();
	if (Clipboard && !IsClip_Cut)
	{
		delete Clipboard;
	}
	Clipboard = pFig;
	IsClip_Cut = IsCut;
	
	if (IsCut)
	{
		CuttedFig = pFig;

		FillOg_Cut = pFig->GetFillColor();
		DrawOg_Cut = pFig->GetDrawColor();

		pFig->ChngFillClr(GRAY);
		pFig->ChngDrawClr(GRAY);

	}
	else
		CuttedFig = nullptr;

}
void ApplicationManager::Clear_Clip()
{
	
	if (IsClip_Cut)
	{
		if (CuttedFig)
		{
			CuttedFig->ChngFillClr(UI.FillColor);
			CuttedFig->ChngDrawClr(UI.DrawColor);
		}
	}

	else if (Clipboard)
	{
		delete Clipboard;
	}

	Clipboard = nullptr;
	CuttedFig = nullptr;
	IsClip_Cut = false;


}
CFigure* ApplicationManager::GetClipboard() const
{
	return Clipboard;
}

// Save all figures 
void ApplicationManager:: saveAll(ofstream & file) const
{
	file << FigCount<< endl;

	// NADA TODO
	//for (int i = 0; i < FigCount; i++)FigList[i]->Save(file);
}



//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}

