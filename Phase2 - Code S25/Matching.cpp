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
	if (fig1.getColor() == fig2.getColor() ) {
		Output* pOut = new Output;
		pOut->PrintMessage("Match found!");
	}
}
int Matching::incscore(int score) {
	return score++;
}
int Matching::getScore() {
	return score;
}
Matching::~Matching() {

}