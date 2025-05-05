#include "CHexagon.h"
#include <fstream>
#include <iostream>
#include "..\ApplicationManager.h"
using namespace std;

CHexagon::CHexagon(Point P1, double L, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	centre = P1;
	length = L;
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon to draw a hexagon on the screen	
	pOut->DrawHexagon(centre, length, FigGfxInfo, Selected);
}

CFigure* CHexagon::Clone()const
{
	return new CHexagon(*this);
}

void CHexagon::paste_clone(Point c)
{
	centre = c;
}

void CHexagon::printInfo()const
{
    cout << "HEX" << '\t'
        << ID << '\t'
        << centre.x << '\t' << centre.y << '\t'
        << length << '\t'
        << colourString(FigGfxInfo.DrawClr) << '\t';
    if (FigGfxInfo.isFilled) cout << colourString(FigGfxInfo.FillClr);
    else cout << "NO_FILL";
    cout << '\n';
}

void CHexagon::save(ofstream& outputFile) const
{
    outputFile << "HEX" << '\t'
        << ID << '\t'
        << centre.x << '\t' << centre.y << '\t'
        << length << '\t'
        << colourString(FigGfxInfo.DrawClr) << '\t';

    if (FigGfxInfo.isFilled) outputFile << colourString(FigGfxInfo.FillClr);
    else outputFile << "NO_FILL";
    outputFile << '\n';
}

void CHexagon::Load(ifstream& Infile)
{
	// Load the hexagon's data from the file
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

FigureType CHexagon::getFigureType() const {
    return HEXAGON;
}

FigureID CHexagon::getFigureID() const {
    return Hexagon_ID;
}

Point CHexagon::getCentre() const {
	return centre;
}
void CHexagon::setCentre(Point c) {
	centre = c;
}