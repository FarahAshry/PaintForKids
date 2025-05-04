#include "SaveAction.h"
#include "Figures\CFigure.h"
#include <fstream>
#include <string>
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"

SaveAction::SaveAction(ApplicationManager* pApplication) : Action(pApplication){}

void SaveAction::ReadActionParameters()
{
	//pointers for input and output 
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Save: Enter file name ");
	//user enters file name and placed into member variable name
	name = pIn->GetSrting(pOut);
	pOut->PrintMessage("File Saved ");
}

void SaveAction::Execute(bool readparameters)
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	ofstream file;
	file.open(name, ios::out);
	if (CFigure::IsFilled() == false)
	{
		file << (pOut->getCrntDrawColor()) << "  " << "No_Fill" << endl;
	}
	else
		file << (pOut->getCrntDrawColor()) << "  " << (pOut->getCrntFillColor()) << endl;

	for (int i = 0; i < /*figure count*/; i++)
	{
		FigList[i]->Save(file);
	}
	file.close();
}

SaveAction::~SaveAction(void){}
