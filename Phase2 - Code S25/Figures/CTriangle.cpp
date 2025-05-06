#include "CTriangle.h"
#include <fstream>
#include <iostream>
#include "..\ApplicationManager.h"
using namespace std;

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

CFigure* CTriangle::Clone() const {
	return new CTriangle(*this);
}
void CTriangle::paste_clone(Point c)
{
	int N_X = ((Corner1.x + Corner2.x+ Corner3.x) / 3);
	int N_Y = ((Corner1.y + Corner2.y+ Corner3.y) / 3);
	int P_X = c.x - N_X;
	int P_Y = c.y - N_Y;

	Corner1.x = Corner1.x + P_X;
	Corner2.x = Corner2.x + P_X;
	Corner3.x = Corner3.x + P_X;

	Corner1.y = Corner1.x + P_Y;
	Corner2.y = Corner2.x + P_Y;
	Corner3.y = Corner3.y + P_X;

}

void CTriangle::printInfo()const
{
	cout << "TRI" << '\t'
		<< ID << '\t'
		<< Corner1.x << '\t' << Corner1.y << '\t'
		<< Corner2.x << '\t' << Corner2.y << '\t'
		<< Corner3.x << '\t' << Corner3.y << '\t'
		<< colourString(FigGfxInfo.DrawClr) << '\t';
	if (FigGfxInfo.isFilled) cout << colourString(FigGfxInfo.FillClr);
	else cout << "NO_FILL";
	cout << '\n';
}

void CTriangle::save(ofstream& outputFile) const
{
	outputFile << "TRI" << '\t'
		<< ID << '\t'
		<< Corner1.x << '\t' << Corner1.y << '\t'
		<< Corner2.x << '\t' << Corner2.y << '\t'
		<< Corner3.x << '\t' << Corner3.y << '\t'
		<< colourString(FigGfxInfo.DrawClr) << '\t';

	if (FigGfxInfo.isFilled) outputFile << colourString(FigGfxInfo.FillClr);
	else outputFile << "NO_FILL";
	outputFile << '\n';
}

void CTriangle::Load(ifstream& Infile) {
	// Read the triangle's data from the file
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;

	// Read the figure's graphics info (e.g., colors, pen width)
	string drawColor, fillColor;
	Infile >> drawColor >> fillColor;

	FigGfxInfo.DrawClr = CFigure::StringToColor(drawColor);
	if (fillColor == "No_Fill")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = CFigure::StringToColor(fillColor);
	}
}
FigureType CTriangle::getFigureType() const
{
	return TRI;
}

FigureID CTriangle::getFigureID() const
{
	return Tri_ID;
}

Point CTriangle::getCentre() const {
	int N_X = ((Corner1.x + Corner2.x + Corner3.x) / 3);
	int N_Y = ((Corner1.y + Corner2.y + Corner3.y) / 3);
	Point center;
	center.x = N_X;
	center.y = N_Y;
	return center;
 }
void CTriangle::setCentre(Point c) {
	Point OldC= getCentre();
// calculaing difference in x and y from centre
	int ChangeX = c.x - OldC.x;
	int ChangeY = c.y - OldC.y;
// updating new corners
	Corner1.x = Corner1.x + ChangeX;
	Corner2.x = Corner2.x + ChangeX;
	Corner3.x = Corner3.x + ChangeX;
	Corner1.y = Corner1.y + ChangeY;
	Corner2.y = Corner2.y + ChangeY;
	Corner3.y = Corner3.y + ChangeY;

}

