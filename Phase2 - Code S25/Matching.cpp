#include "Matching.h"
#include "D:\Uni\Semester 2\Programming Techniques\Project\PT Project Phase1 - Code S25\Phase2 - Code S25\Figures\CFigure.h"
#include "D:\Uni\Semester 2\Programming Techniques\Project\PT Project Phase1 - Code S25\PT Project Phase1 - Code S25\Phase2 - Code S25\Figures\CRectangle.h"
#include "ApplicationManager.h"
#include "D:\Uni\Semester 2\Programming Techniques\Project\PT Project Phase1 - Code S25\Phase2 - Code S25\GUI\Output.h"
#include "D:\Uni\Semester 2\Programming Techniques\Project\PT Project Phase1 - Code S25\Phase2 - Code S25\GUI\Input.h"

Matching::Matching(ApplicationManager* pApp, int score) :Action(pApp), pManager(pApp), score(0), fig1(nullptr), fig2(nullptr) {
	this->pManager = pApp;
	CRectangle* rect = pManager->GetFigure(P1.x, P1.y);

}

void Matching::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Matching Game: Click on the first figure.");
	pIn->GetPointClicked(P1.x, P1.y); // Get the first click

	pOut->PrintMessage("Matching Game: Click on the second figure.");
	pIn->GetPointClicked(P2.x, P2.y); // Get the second click
	pOut->ClearStatusBar();
}
void Matching::Execute() {
	ReadActionParameters();
}

void Matching::compare(CFigure& fig1, CFigure& fig2) {
		Output* pOut = new Output;
	if (fig1.getColor() == fig2.getColor() ) {
		pOut->PrintMessage("Match found!");
		incscore();
	}
	else {
		pOut->PrintMessage("Match not found!");
	}
}
void Matching::incscore() {
	score++;
}
int Matching::getScore() {
	return score;
}
Matching::~Matching() {

}