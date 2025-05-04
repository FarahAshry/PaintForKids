#ifndef CHEX_H
#define CHEX_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point centre;
	double length;
public:
	CHexagon(Point, double, GfxInfo FigureGfxInfo);
virtual void Draw(Output* pOut) const;
virtual void Load(ofstream& Infile);
virtual CFigure* Clone() const;
virtual void paste_clone(Point c);
void save(ofstream& OutFile) const;
};

#endif
