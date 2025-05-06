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
	virtual CFigure* Clone() const;
	virtual void paste_clone(Point c);
	virtual void printInfo()const;
	virtual void save(ofstream& outputFile) const;
	virtual void Load(ifstream& Infile);
	virtual FigureType getFigureType() const override;
	virtual FigureID getFigureID() const override;
	virtual Point getCentre() const override;
	virtual void setCentre(Point)  override;
};
#endif
