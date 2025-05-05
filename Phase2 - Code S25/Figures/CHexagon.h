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
	virtual CFigure* Clone() const;
	virtual void paste_clone(Point c);
	virtual void save(ofstream& OutFile) const;
	virtual void Load(ifstream& Infile);
	virtual color StringToColor(string color);
};

#endif
