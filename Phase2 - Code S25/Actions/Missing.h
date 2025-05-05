#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"

class Missing : public Action
{
private:
	ApplicationManager* pManager;
	Point P1; 
	CFigure* fig;
	CFigure *fig2;
	int score; 
	bool hidden;

public:
	Missing(ApplicationManager* pApp, int score);
	void ReadActionParameters();
	void Execute();
	void incScore();
	void decScore();
	int getScore();
	void compare(CFigure& fig, CFigure& fig2);
	void HideFigure(CFigure& fig, bool hide);
	void ShowFigure(CFigure& fig, bool show);
	bool isHidden();
	~Missing();
};

