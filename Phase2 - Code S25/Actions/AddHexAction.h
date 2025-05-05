#pragma once
#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H

#include "Action.h"

//Add Hexagon Action class
class AddHexAction : public Action
{
private:
	//hexagon centre
	Point P1; 

	//Length of hexagon sides
	double Length; 

	GfxInfo HexGfxInfo;

public:
	AddHexAction(ApplicationManager* pApp);

	//Reads hexagon parameters
	virtual void ReadActionParameters();

	//Add hexagon to the ApplicationManager
	virtual void Execute();
};

#endif
