#include "CCircle.h"

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

void CCircle::Load(ofstream& Infile) {

}
CFigure* CCircle::Clone() const {
	return new CCircle(*this);
}
void CCircle::paste_clone(Point c)
{
	centre = c;
}
}
