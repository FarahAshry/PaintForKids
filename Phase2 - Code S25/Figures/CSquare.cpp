#include "CSquare.h"
#include <fstream>
#include <iostream>
#include "..\ApplicationManager.h"
CSquare::CSquare(Point P1, double L, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	centre = P1;
	length = L;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pOut->DrawSquare(centre, length, FigGfxInfo, Selected);
}

CFigure* CSquare::Clone() const {
	return new CSquare(*this);
}
void CSquare::paste_clone(Point c)
{
	centre = c;
}

void CSquare::printInfo()const
{
	cout << "SQR" << '\t'
		<< ID << '\t'
		<< centre.x << '\t' << centre.y << '\t'
		<< length << '\t'
		<< colourString(FigGfxInfo.DrawClr) << '\t';
	if (FigGfxInfo.isFilled) cout << colourString(FigGfxInfo.FillClr);
	else cout << "NO_FILL";
	cout << '\n';
}

void CSquare::save(ofstream& outputFile) const
{
	outputFile << "SQR" << '\t'
		<< ID << '\t'
		<< centre.x << '\t' << centre.y << '\t'
		<< length << '\t'
		<< colourString(FigGfxInfo.DrawClr) << '\t';

	if (FigGfxInfo.isFilled) outputFile << colourString(FigGfxInfo.FillClr);
	else outputFile << "NO_FILL";
	outputFile << '\n';
}

void CSquare::Load(ifstream& Infile) {
	// read the square's data from the file
	Infile >> centre.x >> centre.y >> length;
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

FigureType CSquare::getFigureType() const
{
	return SQUARE;
}

FigureID CSquare::getFigureID() const
{
	return Square_ID;
}

Point CSquare :: getCentre() const {
	return centre;
}
void CSquare::setCentre(Point c)
{
	centre = c;
}

