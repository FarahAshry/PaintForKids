#pragma once
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
	CFigure* Clone() const;
};

#endif
