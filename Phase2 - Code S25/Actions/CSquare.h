#pragma once
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
	CFigure* Clone() const;
};

#endif

