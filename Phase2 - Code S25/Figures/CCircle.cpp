#include "CCircle.h"
#include <fstream>
#include <iostream>
#include "..\ApplicationManager.h"
using namespace std;

CCircle::CCircle(Point P1, double R, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	centre = P1;
	radius = R;
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a circle on the screen	
	pOut->DrawCircle(centre, radius, FigGfxInfo, Selected);
}

CFigure* CCircle::Clone() const {
	return new CCircle(*this);
}

void CCircle::paste_clone(Point c)
{
	centre = c;
}

void CCircle::printInfo() const
{
	cout << "CIRC" << '\t'
		 << ID << '\t'
		 << centre.x << '\t' << centre.y << '\t'
		 << radius << '\t'
		 << colourString(FigGfxInfo.DrawClr) << '\t';
	if (FigGfxInfo.isFilled) cout << colourString(FigGfxInfo.FillClr);
	else cout << "NO_FILL";
	cout << '\n';
}

void CCircle::save(ofstream& outputFile) const
{
	outputFile << "CIRC" << '\t'
		<< ID << '\t'
		<< centre.x << '\t' << centre.y << '\t'
		<< radius << '\t'
		<< colourString(FigGfxInfo.DrawClr) << '\t';

	if (FigGfxInfo.isFilled)outputFile << colourString(FigGfxInfo.FillClr);
	else outputFile << "NO_FILL";
	outputFile << '\n';
}

void CCircle::Load(ifstream& Infile) {
	// Read the circle's data from the file
	Infile >> centre.x >> centre.y >> radius;

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
FigureType CCircle::getFigureType() const
{
	return CIRCLE;
}

FigureID CCircle::getFigureID() const
{
	return Circle_ID;
}

 Point CCircle::getCentre() const  {
	 return centre;
}
 void CCircle::setCentre(Point c) {
	 centre = c;
 }
