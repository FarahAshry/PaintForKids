#pragma once
#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H

#include "Action.h"

//Add Hexagon Action class
class AddHexAction : public Action
{
private:
	Point P1; //hexagon centre
	double Length; //Length of hexagon sides
	GfxInfo HexGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads hexagon parameters
	virtual void ReadActionParameters();

	//Add hexagon to the ApplicationManager
	virtual void Execute();
};

#endif
