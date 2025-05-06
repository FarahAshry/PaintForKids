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

void Missing::Execute(ActionType ActType) {
	ReadActionParameters();
	fig = pManager->GetFigure(P1.x, P1.y);
	Output* pOut = pManager->GetOutput();
	Input* pIn;
	
	do {
		HideFigure(fig, true);
		pOut->PrintMessage("A shape is now hidden, hit one of the following keys to determine its type: rectangle (r), circle (c), square (s), hexagon (h), triangle (t)");
		std::this_thread::sleep_for(std::chrono::seconds(5));
		pIn->GetSrting(pOut);

		ShowFigure(*fig, false);
		std::this_thread::sleep_for(std::chrono::seconds(1));


	} while (ActType != EXIT);
}

void Missing::Execute()
{
}


void Missing::compare(CFigure& fig, CFigure& fig2) {
	Output* pOut = new Output;
	

	if (fig.getFigureType() == fig2.getFigureType()) {
		pOut->PrintMessage("Correct guess!");
		incScore();
	}
	else {
		pOut->PrintMessage("Incorrect guess!");
		decScore();
	}
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

void Missing::HideFigure(CFigure* fig, bool hide) {
	hidden = hide;
	hidden = true;

	Output* pOut = pManager->GetOutput();
	pManager->RemoveFig(fig);	
	pOut->PrintMessage("Figure is hidden!");

}
void Missing::ShowFigure(CFigure& fig, bool show) {
	hidden = show;
	show = true;
	Output* pOut = pManager->GetOutput();
	
	fig.Draw(pOut);

	pOut->PrintMessage("Figure is shown!");
	
}

Missing::~Missing() {}
