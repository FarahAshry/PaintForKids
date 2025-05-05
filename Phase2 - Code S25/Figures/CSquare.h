#ifndef CSQU_H
#define CSQU_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point centre;
	double length;
public:
	CSquare(Point, double, GfxInfo FigureGfxInfo);
virtual void Draw(Output* pOut) const;
virtual void Load(ifstream& Infile);
virtual CFigure* Clone() const;
virtual void paste_clone(Point c);
virtual void printInfo()const;
virtual void save(ofstream& outputFile) const;
};

#endif
