#pragma once
#include "Actions/Action.h"
#include<fstream>

class SaveAction : public Action
{
private:
	string name;
	ofstream file;
public:
	//default constractor
	SaveAction(ApplicationManager* pApplication);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters = true);

	~SaveAction(void);
};
