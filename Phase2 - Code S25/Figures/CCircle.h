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
	virtual CFigure* Clone() const;
	virtual void paste_clone(Point c);
	virtual void printInfo() const;
	virtual void save(ofstream& outputFile) const;
	virtual void Load(ifstream& Infile);
	virtual color StringToColor(string color);
};

#endif
