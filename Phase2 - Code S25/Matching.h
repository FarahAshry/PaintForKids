#pragma once
#include "D:\Uni\Semester 2\Programming Techniques\Project\PT Project Phase1 - Code S25\Phase2 - Code S25\Actions\Action.h"

class Matching: public Action
{
private:
	ApplicationManager* pManager;
	Point P1;
	Point P2;
	/*CFigure fig1;
	CFigure fig2;*/
	int score;


public:

	Matching(ApplicationManager* pApp, int score);
	void compare(CFigure& fig1, CFigure& fig2);
	int incscore();
	int getScore() ;
	~Matching();

};

