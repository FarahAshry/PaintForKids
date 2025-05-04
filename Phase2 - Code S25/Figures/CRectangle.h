#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	FigureType getFigureType() const;
	virtual void Load(ifstream& Infile);
	virtual CFigure* Clone() const;
	virtual void paste_clone(Point c);
	virtual void save(ofstream& OutFile) const;
};
#endif
