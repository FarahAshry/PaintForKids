#include "CSquare.h"

CSquare::CSquare(Point P1, double L, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	centre = P1;
	lenght = L;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pOut->DrawSquare(centre, length, FigGfxInfo, Selected);
}

void CSquare::Load(ifstream& Infile) {}

CFigure* CSquare::Clone() const {
	return new CSquare(*this);
}