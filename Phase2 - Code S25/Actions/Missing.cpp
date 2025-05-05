#include "Missing.h"
#include "../Figures\CFigure.h"
#include "../Figures\CRectangle.h"
#include "../ApplicationManager.h"
#include "../GUI\Output.h"
#include "../GUI\Input.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

Missing::Missing(ApplicationManager* pApp, int score) :Action(pApp), pManager(pApp), score(0), fig(nullptr) {
	this->pManager = pApp;
}

void Missing::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Missing Game: Click on a figure.");
	pIn->GetPointClicked(P1.x, P1.y); 
	
	pOut->ClearStatusBar();
}

void Missing::Execute() {
	ReadActionParameters();
	fig = pManager->GetFigure(P1.x, P1.y);
	Output* pOut = pManager->GetOutput();
	int c = 0;
	do {
		HideFigure(*fig, true);
		std::this_thread::sleep_for(std::chrono::seconds(5));

		ShowFigure(*fig, false);
		c++;
	} while (c<5);
}


void Missing::compare(CFigure& fig, CFigure& fig2) {
	Output* pOut = new Output;
	//

	/*if (fig == fig2) {
		pOut->PrintMessage("Match found!");
		incScore();
	}
	else {
		pOut->PrintMessage("Match not found!");
		decScore();
	}*/
}
void Missing::incScore() {
	score++;
}
void Missing::decScore() {
	score--;
}

int Missing::getScore() {
	return score;
}

void Missing::HideFigure(CFigure& fig, bool hide) {
	hidden = hide;
	Output* pOut = pManager->GetOutput();
	if (hidden) {
		fig.SetSelected(false);
		pOut->PrintMessage("Figure is hidden!");
	}
}
void Missing::ShowFigure(CFigure& fig, bool show) {
	hidden = show;
	Output* pOut = pManager->GetOutput();
	if (hidden) {
		fig.SetSelected(true);
		pOut->PrintMessage("Figure is shown!");
	}
}

bool Missing::isHidden() {
	return hidden;
}

Missing::~Missing() {}
