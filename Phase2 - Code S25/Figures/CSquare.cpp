#include "CSquare.h"
#include <fstream>

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

void CSquare::printInfo() const
{
	cout << "SQR" << '\t'
    	     << ID << '\t'
             << centre.x << '\t' << centre.y << '\t'
             << length << '\t'
	     << colouString(FigGfxInfo.DrawClr0 << '\t';
}

void CSquare::save(ofstream& outputFile) const 
{
	outputFile << "SQR" << '\t'
    	     	<< ID << '\t'
            	<< centre.x << '\t' << centre.y << '\t'
             	<< length << '\t'
		<< colouString(FigGfxInfo.DrawClr << '\t';
   
	if (FigGfxInfo.isFilled)outputFile << colourString(FigGfxInfo.FillClr);
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
