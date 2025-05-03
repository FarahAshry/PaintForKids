#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}


color Input::GetColour(Output* pO) const
{

	while (1)
	{
		pO->PrintMessage("Enter Colour: b->Black, y->Yellow, o->Orange, r->Red, g->Green, u->Blue ");
		string in = GetSrting(pO);
		char key = tolower(in[0]);

		switch (key)
		{
		case 'b': return BLACK;
			break;
		case 'y': return YELLOW;
			break;
		case 'o': return ORANGE;
			break;
		case 'r': return RED;
			break;
		case 'g': return GREEN;
			break;
		case 'u': return BLUE;
			break;
		default:
			pO->PrintMessage("colour not found :(");



		}
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / (UI.MenuItemWidth / 1.25));
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE:return DRAW_SQUARE;
			case ITM_TRI:return DRAW_TRI;
			case ITM_HEX:return DRAW_HEX;
			case ITM_CIRCLE:return DRAW_CIRCLE;


			case ITM_ADD_FIG:return ADD_FIG;
			case ITM_SELECT:return SELECT;
			case ITM_SWAP: return SWAP;
			case ITM_ROTATE_FIG:return ROTATE_FIG;
			case ITM_DELETE_FIG:return DELETE_FIG;
			case ITM_CLEAR_ALL:return CLEAR_ALL;
			case ITM_COPY_FIG:return COPY_FIG;
			case ITM_CUT_FIG:return CUT_FIG;
			case ITM_PASTE_FIG:return PASTE_FIG;
			case ITM_SAVE_GRAPH: return SAVE_GRAPH;
			case ITM_LOAD_GRAPH:return LOAD_GRAPH;
			case ITM_SWITCH_TO_PLAY:return TO_PLAY;

			case ITM_EXIT: return EXIT;



			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		// return TO_PLAY;	just for now. This should be updated
		if (y >= 0 && y < UI.ToolBarHeight)
		{

			int ClickedItemOrder = (x / (UI.MenuItemWidth / 1.25));


			switch (ClickedItemOrder)
			{

			case ITM_MATCHING_PAIRS:return MATCHING_PAIRS;
			case ITM_MISSING_SHAPES:return MISSING_SHAPES;
			case ITM_SWITCH_TO_DRAW:return TO_DRAW;
			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}


		return STATUS;


	}

}
/////////////////////////////////

Input::~Input()
{
}
