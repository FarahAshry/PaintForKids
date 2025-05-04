#include "CHexagon.h"

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

void CHexagon::Load(ofstream& Infile)
{

}
CFigure* CHexagon::Clone()const
{
	return new CHexagon(*this);
}
void CHexagon::paste_clone(Point c)
{
	centre = c;
}
}
