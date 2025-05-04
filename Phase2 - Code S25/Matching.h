#pragma once
#include "Actions\Action.h"
#include "Figures\CFigure.h"
#include "Figures\CRectangle.h"
#include "Figures/CSquare.h"
#include "Figures/CTriangle.h"
#include "Figures/CHexagon.h"
#include "Figures/CCircle.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "DEFS.h"

class Matching : public Action
{
private:
	ApplicationManager* pManager;
	Point P1;
	Point P2;
	CFigure* fig1;
	CFigure* fig2;
	int score;


public:

	Matching(ApplicationManager* pApp, int score);


	void ReadActionParameters(); //Reads parameters required for action to execute
	void Execute(); //Execute action (code depends on action type)
	virtual void Load(ofstream& Infile);
	void compare(CFigure& fig1, CFigure& fig2);
	void incScore();
	void decScore();
	int getScore();
	~Matching();

};

