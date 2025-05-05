#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <iostream>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	color FigColor;
	int incFig;
	string FigType; //to get the type of the figure

	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	//function for SaveAction
	virtual void save(ofstream& outputFile) const = 0;

	//function for ptinting
	virtual void printInfo() const = 0;

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	string getFigureType();	//returns the figure type for matching game check
	color getColor(); 	//returns the color of the figure for matching game check
	color GetFillColor() const;
	color GetDrawColor() const;
	bool IsFilled() const;
	void setID(int id);

	int getID();
	int incrementFig();
	virtual CFigure* Clone() const = 0;
	virtual void paste_clone(Point c)=0;


	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif
