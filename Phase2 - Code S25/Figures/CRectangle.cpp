#include "CRectangle.h"
#include <fstream>
#include <iostream>
#include "..\ApplicationManager.h"

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

void CRectangle::printInfo() const
{
	cout << "RECT" << '\t'
		<< ID << '\t'
		<< Corner1.x << '\t' << Corner1.y << '\t'
		<< Corner2.x << '\t' << Corner2.y << '\t'
		<< colourString(FigGfxInfo.DrawClr) << '\t';
	if (FigGfxInfo.isFilled)cout << colourString(FigGfxInfo.FillClr);
	else cout << "NO_FILL";
	cout << '\n';
}

void CRectangle::save(ofstream& outputFile) const
{
	outputFile << "RECT" << '\t'
		<< ID << '\t'
		<< Corner1.x << '\t' << Corner1.y << '\t'
		<< Corner2.x << '\t' << Corner2.y << '\t'
		<< colourString(FigGfxInfo.DrawClr) << '\t';
	if (FigGfxInfo.isFilled)cout << colourString(FigGfxInfo.FillClr);
	else outputFile << "NO_FILL";
	outputFile << '\n';
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

FigureType CRectangle::getFigureType() const
{
	return RECTANGLE;
}

FigureID CRectangle::getFigureID() const
{
	return Rect_ID;
}

Point CRectangle::getCentre() const
{
	Point center;
	center.x = (Corner1.x + Corner2.x) / 2;
	center.y = (Corner1.y + Corner2.y) / 2;
	return center;
}
void CRectangle::setCentre(Point c)
{
		// Calculate width and height
		int w = (Corner2.x - Corner1.x);
		int h = (Corner2.y - Corner1.y);
		//check height and width are pos
		if (w < 0)
			w = -w;
		if (h < 0)
			h = -h;
		// Calculate new corner
		Corner1.x = c.x - w / 2;
		Corner1.y = c.y - h / 2;

		Corner2.x = c.x + w / 2;
		Corner2.y = c.y + h / 2;
	
}
