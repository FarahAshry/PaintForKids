#include "CSquare.h"
#include <ofstream>

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

CFigure* CSquare::Clone() const {
	return new CSquare(*this);
}
void CSquare::paste_clone(Point c)
{
	centre = c;
}
void CSquare::save(ofstream& OutFile) const 
{
    outputFile << "SQR" << '\t'
     	       << ID << '\t'
               << centre.x << '\t' << centre.y << '\t'
               << length << '\t'
    	       << FigGfxInfo.DrawClr << '\t';
    
    if(FigGfxInfo.isFilled) outputFile << FigGfxInfo.FillClr;
    else outputFile << "NO_FILL";
    outputFile << '\n';
}
