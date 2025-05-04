#include "Output.h"

const float pi = (22 / 7);

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.LineUnderTBWidth = 2;
	UI.MenuItemWidth = 80;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project - Spring 2025");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearToolBar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circle.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Menu_Hex.jpg";
	MenuItemImages[ITM_ADD_FIG] = "images\\MenuItems\\Menu_Add.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Arrow.png";
	MenuItemImages[ITM_SWAP] = "images\\MenuItems\\Menu_Swap.jpg";
	MenuItemImages[ITM_ROTATE_FIG] = "images\\MenuItems\\Menu_Rotate.jpg";
	MenuItemImages[ITM_DELETE_FIG] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_CLEAR_ALL] = "images\\MenuItems\\Menu_Clear.jpg";
	MenuItemImages[ITM_COPY_FIG] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[ITM_CUT_FIG] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuItemImages[ITM_PASTE_FIG] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[ITM_SAVE_GRAPH] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD_GRAPH] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_SWITCH_TO_PLAY] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++) {
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth / 1.25, 0, UI.MenuItemWidth / 1.25, UI.ToolBarHeight);
	}


	//TODO: Prepare images for each menu item and add it to the list




	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{

	UI.InterfaceMode = MODE_PLAY;


	string PlayMenuItem[PLAY_ITM_COUNT];
	PlayMenuItem[ITM_MATCHING_PAIRS] = "images\\MenuItems\\Menu_Matching.jpg";
	PlayMenuItem[ITM_MISSING_SHAPES] = "images\\MenuItems\\Menu_Missing.jpg";
	PlayMenuItem[ITM_SWITCH_TO_DRAW] = "images\\MenuItems\\Menu_Draw.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++) {
		pWind->DrawImage(PlayMenuItem[i], i * UI.MenuItemWidth / 1.25, 0, UI.MenuItemWidth / 1.25, UI.ToolBarHeight);
	}


	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::setCrntDrawColor(color DrawColor)	//set current drawing color
{
	UI.DrawColor = DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::setCrntFillColor(color FillColor)	//set current filling color
{
	UI.FillColor = FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawSquare(Point P1, double length, GfxInfo SqrGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SqrGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SqrGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqrGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, (P1.x + length), (P1.y + length), style);
}

void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawCircle(Point P1, double radius, GfxInfo CircGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, radius, style);
}

void Output::DrawHexagon(Point P1, double length, GfxInfo HexGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;

	double* xptrlist = new double[6];
	double* yptrlist = new double[6];

	xptrlist[0] = P1.x - length;
	xptrlist[1] = P1.x - length * 0.5;
	xptrlist[2] = P1.x + length * 0.5;
	xptrlist[3] = P1.x + length;
	xptrlist[4] = xptrlist[2];
	xptrlist[5] = xptrlist[1];

	yptrlist[0] = P1.y;
	yptrlist[1] = P1.y + length * cos(pi / 3);
	yptrlist[2] = yptrlist[1];
	yptrlist[3] = P1.y;
	yptrlist[4] = P1.y - length * cos(pi / 3);
	yptrlist[5] = yptrlist[4];

	//float angle = 0;
	//for (int i = 0; i < 6; i++)
	//{
	//	xptrlist[i] = P1.x + length * cos(angle);
	//	yptrlist[i] = P1.y + length * sin(angle);
	//	angle = angle + pi / 3.0;
	//}

	pWind->DrawPolygon(xptrlist, yptrlist, 6, style);
	delete[]xptrlist;
	delete[]yptrlist;
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

