#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddSqrAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\Select.h"
#include "Actions\COPY.h"
#include"Actions\CUT.h"
#include"Actions\PASTE.h"
#include "Actions\Matching.h"
#include "Actions\Missing.h"
#include "Actions/LoadAction.h"
#include"Actions\SwitchToPlay.h"
#include"Actions/SaveAction.h"
#include "Actions/Select.h"

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
	case DRAW_SQUARE:
		pAct = new AddSqrAction(this);
		break;
	case DRAW_TRI:
		pAct = new AddTriAction(this);
		break;
	case DRAW_HEX:
		pAct = new AddHexAction(this);
		break;
	case DRAW_CIRCLE:
		pAct = new AddCircAction(this);
		break;
	case SAVE_GRAPH:
		pAct = new SaveAction(this);
		break;
	case SELECT:
		pAct = new Select(this);
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
case TO_PLAY:
	pAct = new SwitchToPlay(this);
	break;
	case MISSING_SHAPES:
		pAct = new Missing(this, 0);
		break;

	case MATCHING_PAIRS:
		pAct = new Matching(this, 0);
		break;

	case TO_DRAW:
		
		break;

	case TO_PLAY:

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
	
	for (int i = FigCount-1; i >= 0; i--) {
        	if (FigList[i]->ContainsPoint(x, y)) return FigList[i];
	}

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

//LOAD all figures
void ApplicationManager::LoadAll(ifstream& Infile)
{
	int count;
	Infile >> count;
	for (int i = 0; i < count; i++)
	{
		FigList[i]->Load(Infile);
	}
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
void ApplicationManager::SetClipboard(CFigure* pFig, bool IsCut)
{
	IsClip_Cut = IsCut;
	
	if (Clipboard)
	{
		delete Clipboard;
		Clipboard = nullptr;
	}

	if (IsClip_Cut && CuttedFig)
	{
		Uncut();
	}
	if(IsCut)
	{
		CuttedFig = pFig;
		if (pFig->IsFilled())
		{
			IsHighlighted_Cut = true;
			IsFilled_Cut = true;
			DrawOg_Cut = pFig->GetDrawColor();
			FillOg_Cut = pFig->GetFillColor();
		}
		else
		{
			IsHighlighted_Cut = true;
			IsFilled_Cut = false;
		}
		
		pFig->ChngFillClr(GRAY);
		pFig->ChngDrawClr(GRAY);

	}
}

CFigure* ApplicationManager::GetClipboard() const
{
	return Clipboard;
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


bool ApplicationManager::GetIsCut()
{
	if (IsClip_Cut)
	{
		return true;
	}
	else
	{
		return false;
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

// Save all figures 
void ApplicationManager:: saveAll(ofstream & file) const
{
	file << FigCount<< endl;
	
	for (int i = 0; i < FigCount; i++)FigList[i]->save(file);
}


int ApplicationManager::GetSelectedCount() const 
{
    int count = 0;
    for (int i = 0; i < FigCount; i++)
        if (FigList[i]->IsSelected()) count++;
    return count;
}

int ApplicationManager::GetSelectedFigureCount(FigureType type) const {
	int count = 0;
    for (int i = 0; i < FigCount; i++)
        if (FigList[i]->IsSelected() && FigList[i]->getFigureType() == type) count++;
    return count;
}

CFigure* ApplicationManager::GetFigureList() const { return FigList; }

int ApplicationManager::GetFigureCount() const { return FigCount;}

