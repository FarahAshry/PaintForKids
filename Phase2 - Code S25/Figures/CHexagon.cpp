#include "CHexagon.h"
#include <fstream>
#include "../ApplicationManager.h"

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
CFigure* CHexagon::Clone()const
{
	return new CHexagon(*this);
}
void CHexagon::paste_clone(Point c)
{
	centre = c;
}

void CHexagon::save(ofstream& OutFile) const 
{
	OutFile << "HEX" << '\t'
     	       << ID << '\t'
               << centre.x << '\t' << centre.y << '\t'
               << length << '\t'
    	       << FigGfxInfo.DrawClr << '\t';
    
    if(FigGfxInfo.isFilled) OutFile << FigGfxInfo.FillClr;
    else OutFile << "NO_FILL";
	OutFile << '\n';
}
