#include "CRectangle.h"
#include <fstream>
#include "../ApplicationManager.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

FigureType CRectangle::getFigureType() const {
	return Rect_ID; // Return the correct enum value
}

void CRectangle::Load(ifstream& Infile) {
	// Read the rectangle's data from the file
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	
	// Read the figure's graphics info (e.g., colors, pen width)
	string drawColor, fillColor;
	Infile >> drawColor >> fillColor;
	
	FigGfxInfo.DrawClr = StringToColor(drawColor);
	if (fillColor == "No_Fill")
	    FigGfxInfo.isFilled = false;
	else
	{
	    FigGfxInfo.isFilled = true;
	    FigGfxInfo.FillClr = StringToColor(fillColor);
	}
}
 CFigure* CRectangle::Clone() const {
	return new CRectangle(*this);
}
void CRectangle::paste_clone(Point c)
{
 int N_X = ((Corner1.x + Corner2.x) / 2);
 int N_Y = ((Corner1.y + Corner2.y) / 2);
 int P_X = c.x - N_X;
 int P_Y = c.y - N_Y;

 Corner1.x = Corner1.x + P_X;
 Corner2.x = Corner2.x + P_X;
 Corner1.y = Corner1.x + P_Y;
 Corner2.y = Corner2.x + P_Y;
}

void CRectangle::printInfo()
{
	cout << "RECT" << '\t'
     	       << ID << '\t'
               << Corner1.x << '\t' << Corner1.y << '\t'
               << Corner2.x << '\t' << Corner2.y << '\t'
    	       << colourString(FigGfxInfo.DrawClr) << '\t';
}
void CRectangle::save(ofstream& OutFile) const 
{
    OutFile << "RECT" << '\t'
     	       << ID << '\t'
               << Corner1.x << '\t' << Corner1.y << '\t'
               << Corner2.x << '\t' << Corner2.y << '\t'
    	       << colourString(FigGfxInfo.DrawClr) << '\t';
    
    if(FigGfxInfo.isFilled) OutFile << colourString(FigGfxInfo.FillClr);
    else OutFile << "NO_FILL";
	OutFile << '\n';
}

