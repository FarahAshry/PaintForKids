#include "CTriangle.h"

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

void CTriangle::Load(ofstream& Infile) {}

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

