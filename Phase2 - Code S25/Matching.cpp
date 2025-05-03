#include "Matching.h"
#include "D:\Uni\Semester 2\Programming Techniques\Project\PT Project Phase1 - Code S25\Phase2 - Code S25\Figures\CFigure.h"
#include "D:\Uni\Semester 2\Programming Techniques\Project\PT Project Phase1 - Code S25\PT Project Phase1 - Code S25\Phase2 - Code S25\Figures\CRectangle.h"
#include "ApplicationManager.h"
#include "D:\Uni\Semester 2\Programming Techniques\Project\PT Project Phase1 - Code S25\Phase2 - Code S25\GUI\Output.h"
#include "D:\Uni\Semester 2\Programming Techniques\Project\PT Project Phase1 - Code S25\Phase2 - Code S25\GUI\Input.h"

Matching::Matching(ApplicationManager* pApp, int score) :Action(pApp), pManager(pApp), score(0) {
	this->pManager = pApp;
	CRectangle* rect = pManager->GetFigure(P1.x, P1.y);

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
int Matching::incscore() {
	return score++;
}
int Matching::getScore() {
	return score;
}
Matching::~Matching() {

}