#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	CFigure* Clipboard;  //Pointer to copied/cut figure
	CFigure* CuttedFig;

	color DrawOg_Cut;
	color FillOg_Cut;

	bool IsClip_Cut;
	bool IsFilled_Cut;
        bool IsHighlighted_Cut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	
	Output *GetOutput() const; //Return pointer to the output
	
	void UpdateInterface() const;	//Redraws all the drawing window	
	
	CFigure* RemoveAction(Action* pAct);
	
	void LoadAll();
	
	void RemoveFig(CFigure* pFig);

	CFigure* GetFigureList();
	
	int GetFigureCount();
	
	int GetSelectedCount();
	
	int GetSelectedFigureCount(DrawMenuItem item);

	CFigure* GetSelected() const;

	void SetClipboard(CFigure* pFig,bool IsCut);
	
	CFigure* GetClipboard() const;

	void Clear_Clip();
	
	void Uncut();

	void saveAll(ofstream& file) const;
bool GetIsCut();

	/*color StringToColor(string color);*/ //Convert string to color
};

#endif

