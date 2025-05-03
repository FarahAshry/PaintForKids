#pragma once
#include "D:\Uni\Semester 2\Programming Techniques\Project\PT Project Phase1 - Code S25\Phase2 - Code S25\Actions\Action.h"

class Matching: public Action
{
private:
	ApplicationManager* pManager;
	Point P1, p2;
	CFigure* fig1;
	CFigure* fig2;
	int score;


public:

	Matching(ApplicationManager* pApp, int score);

	
	void ReadActionParameters(); //Reads parameters required for action to execute
	void Execute(); //Execute action (code depends on action type)

	void compare(CFigure& fig1, CFigure& fig2);
	void incscore();
	int getScore() ;
	~Matching();

};

