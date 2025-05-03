#include "CRectangle.h"

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

void CRectangle::Load(ifstream& Infile) {
	
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
