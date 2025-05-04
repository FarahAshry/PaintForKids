#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point centre;
	double radius;
public:
	CCircle(Point, double, GfxInfo FigureGfxInfo);
virtual void Draw(Output* pOut) const;
virtual void Load(ofstream& Infile);
virtual CFigure* Clone() const;
virtual void paste_clone(Point c);
void save(ofstream& OutFile) const;
};

#endif
