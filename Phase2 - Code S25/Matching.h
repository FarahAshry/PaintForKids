#pragma once
#include "Actions\Action.h"

class Matching: public Action
{
private:
	ApplicationManager* pManager;
	Point P1, P2;
	CFigure* fig1;
	CFigure* fig2;
	int score;


public:

	Matching(ApplicationManager* pApp, int score);

	
	void ReadActionParameters(); 
	void compare(CFigure& fig1, CFigure& fig2);
	void incScore();
	void decScore();
	int getScore() ;
	void Execute(); 

	~Matching();

};
