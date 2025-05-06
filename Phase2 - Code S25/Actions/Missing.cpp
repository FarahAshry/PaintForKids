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
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ActionType ActType;

	do {

		pOut->PrintMessage("Missing Game: Click on a point to start.");
		pIn->GetPointClicked(P1.x, P1.y);
		
		if (fig == nullptr) {
			pOut->PrintMessage("No figure found at the clicked point.");
			return;
		}
		else {

			HideFigure(fig, true);
			pOut->PrintMessage("A shape is now hidden, hit one of the following keys to determine its type: rectangle (r), circle (c), square (s), hexagon (h), triangle (t)");
			std::this_thread::sleep_for(std::chrono::seconds(5));
			in = pIn->GetSrting(pOut);
			char key = tolower(in[0]);

			ShowFigure(*fig, false);
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		compare(*fig, in);
	} while (ActType != EXIT);
}

void Missing::compare(CFigure& fig, string in) {
	Output* pOut = new Output;
	bool guess = false;

	if (fig.getFigureType() == RECTANGLE && in == "r") {
		pOut->PrintMessage("Correct guess!");
		incScore();
	}
	else if (fig.getFigureType() == CIRCLE && in == "c") {
			pOut->PrintMessage("Correct guess!");
			incScore();
	}
	else if (fig.getFigureType() == SQUARE && in == "s") {
		pOut->PrintMessage("Correct guess!");
		incScore();
	}
	else if (fig.getFigureType() == HEXAGON && in == "h") {
		pOut->PrintMessage("Correct guess!");
		incScore();
	}
	else if (fig.getFigureType() == TRI && in == "t") {
		pOut->PrintMessage("Correct guess!");
		incScore();
	}
	else if (in != "r" || in != "c" || in != "s" || in != "h" || in != "t") {
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
