#include "Matching.h"
#include "../Figures\CFigure.h"
#include "../Figures\CRectangle.h"
#include "../Figures/CSquare.h" 
#include "../Figures/CTriangle.h" 
#include "../Figures/CHexagon.h"
#include "../Figures/CCircle.h"
#include "../ApplicationManager.h"
#include "../GUI\Output.h"
#include "../GUI\Input.h"

Matching::Matching(ApplicationManager* pApp, int score) 
	:Action(pApp), pManager(pApp), score(0) {}

void Matching::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMessage("Matching Game: Click on the first figure.");
	fig1 = pManager->GetFigure(P1.x, P1.y); // Get the first click

	pOut->PrintMessage("Matching Game: Click on the second figure.");
	fig2 = pManager->GetFigure(P2.x, P2.y);// Get the second click

	pOut->ClearStatusBar();
}
void Matching::Execute() {

	ReadActionParameters();
	fig1 = pManager->GetFigure(P1.x, P1.y);
	fig2 = pManager->GetFigure(P2.x, P2.y);

	Output* pOut = pManager->GetOutput();

	compare(*fig1, *fig2);

}

void Matching::compare(CFigure& fig1, CFigure& fig2) {
	Output* pOut = new Output;
	bool match = false;
	if (fig1.getColor() == fig2.getColor() || fig1.getFigureType()==fig2.getFigureType()) {
		match = true;
	}
	if (match == true) {
		pOut->PrintMessage("Match found!");
		incScore();
	}
	else {
		pOut->PrintMessage("Match not found!");
		decScore();
	}
}

void Matching::Load(ofstream& Infile) {}

void Matching::incScore() {
	score++;
}
void Matching::decScore() {
	score--;
}
int Matching::getScore() {
	return score;
}
Matching::~Matching() {
}
