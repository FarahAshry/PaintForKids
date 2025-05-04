#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
virtual void Draw(Output* pOut) const;
virtual void Load(ifstream& Infile);
virtual CFigure* Clone() const;
virtual void paste_clone(Point c);
virtual void save(ofstream& OutFile) const;
};

#endif
