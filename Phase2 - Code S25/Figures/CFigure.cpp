#include "CFigure.h"

#include <iostream>
#include <fstream>

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
//Farah added these 4 functions
string CFigure::getFigureType() {
	cout << this->FigType << endl;
	return this->FigType;	
}
 
//to get the color of the figure
color CFigure::getColor() {
	if (FigGfxInfo.isFilled == true) {
		FigColor = FigGfxInfo.FillClr;
		if (FigColor == RED) {
			FigColor = Red_ID;
		}
		else if (FigColor == BLUE) {
			FigColor = Blue_ID;
		}
		else if (FigColor == YELLOW) {
			FigColor = Yellow_ID;
		}
		else if (FigColor == BLACK) {
			FigColor = Black_ID;
		}
		else if (FigColor == ORANGE) {
			FigColor = Orange_ID;
		}
		else if (FigColor == GREEN) {
			FigColor = Green_ID;
		}
		else {
			FigColor = No_Fill_ID;
		}
	}
	return FigColor;
}
void CFigure::setID(int id)
{
	ID = id;
}

int CFigure::getID() {
	return ID;
}

int CFigure::incrementFig()
{
	return incFig++;
}
string CFigure::GetInfoString()
{
	return string();
}
color CFigure::GetFillColor() const
{
	return FigGfxInfo.FillClr; 
}


color CFigure::GetDrawColor()const
{
	return FigGfxInfo.DrawClr; 
}

bool CFigure::IsFilled()const
{
	return FigGfxInfo.isFilled; 
}
