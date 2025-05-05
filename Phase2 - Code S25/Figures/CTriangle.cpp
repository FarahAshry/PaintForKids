#include "CTriangle.h"
#include <fstream>
#include "../ApplicationManager.h"
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

void CTriangle::Load(ifstream& Infile) {
	 // Read the triangle's data from the file
	 Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
	
	 // Read the figure's graphics info (e.g., colors, pen width)
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
	if(FigGfxInfo.isFilled) cout << colourString(FigGfxInfo.FillClr);
    	else cout << "NO_FILL";
}

void CTriangle::save(ofstream& outputFile) const 
{
	outputFile << "TRI" << '\t'
     	       << ID << '\t'
               << Corner1.x << '\t' << Corner1.y << '\t'
               << Corner2.x << '\t' << Corner2.y << '\t'
	       << Corner3.x << '\t' << Corner3.y << '\t'
    	       << colourString(FigGfxInfo.DrawClr) << '\t';
    
    if(FigGfxInfo.isFilled) outputFile << colourString(FigGfxInfo.FillClr);
    else outputFile << "NO_FILL";
    outputFile << '\n';
}
