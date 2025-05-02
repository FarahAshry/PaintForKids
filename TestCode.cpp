#include "GUI\Input.h"
#include "GUI\Output.h"
#include <iostream>

using namespace std;

//This is a test code to test the Input and Output classes

int main()
{
	string c;
	int x, y;
	double l, r;
	//Create Input and Output objects to test
	Output* pOut = new Output;

	Input* pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2, P3;

	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	
	gfxInfo.DrawClr = BLACK;
	gfxInfo.BorderWdth = 15;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);


	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.DrawClr = BLACK;
	gfxInfo.BorderWdth = 15;//any color for border
	gfxInfo.isFilled = true;//Figure is filled
	gfxInfo.FillClr = pIn->GetColour(pOut);
	pOut->DrawRect(P1, P2, gfxInfo, false);


	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->ClearDrawArea();

	/// 2.2- Square Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Square, normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///TODO: Add code to draw Square, Normal and Highlighted ////////// DONE

	pOut->PrintMessage("Drawing a square ==> non-filled,highlighted,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("Enter length");
	l = stod(pIn->GetSrting(pOut));

	while (l <= 0) {
		pOut->PrintMessage("Re-enter length, length must be positive.");
		l = stod(pIn->GetSrting(pOut));
	}


	gfxInfo.DrawClr = BLUE;
	gfxInfo.BorderWdth = 15;
	gfxInfo.isFilled = false;
	pOut->DrawSquare(P1, l, gfxInfo, true);
	pOut->PrintMessage("Drawing a Square Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->ClearDrawArea();


	/// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("Drawing a Triangle ==> non-filled,  Click three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);
	gfxInfo.isFilled = false;
	gfxInfo.DrawClr = RED;
	gfxInfo.BorderWdth = 15;
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);

	pOut->PrintMessage("Drawing a Triangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);

	pOut->PrintMessage("Drawing Triangle ==> filled, Click 3 points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);
	gfxInfo.isFilled = true;
	gfxInfo.FillClr = pIn->GetColour(pOut);
	gfxInfo.DrawClr = YELLOW;
	gfxInfo.BorderWdth = 15;
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);

	pOut->PrintMessage("Drawing a Triangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);



	///TODO: Add code to draw Triangle in all possible states ///////////// DONE 

	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->ClearDrawArea();


	/// 2.4- Hexagon Test ///
	/// =================== 

	pOut->PrintMessage("Drawing a Hexagon, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("Drawing a Hexagon, non-filled, click one point");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("Enter length");
	l = stod(pIn->GetSrting(pOut));

	while (l <= 0) {
		pOut->PrintMessage("Re-enter length, length must be positive.");
		l = stod(pIn->GetSrting(pOut));
	}

	gfxInfo.isFilled = false;
	gfxInfo.DrawClr = ORANGE;
	gfxInfo.BorderWdth = 25;
	pOut->DrawHexagon(P1, l, gfxInfo, false);

	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawHexagon(P1, l, gfxInfo, true);

	pOut->PrintMessage("Drawing a Hexagon, filled, click one point");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("Enter length");
	l = stod(pIn->GetSrting(pOut));

	while (l <= 0) {
		pOut->PrintMessage("Re-enter length, length must be positive.");
		l = stod(pIn->GetSrting(pOut));
	}

	gfxInfo.isFilled = true;
	gfxInfo.FillClr = pIn->GetColour(pOut);
	gfxInfo.DrawClr = GREEN;
	gfxInfo.BorderWdth = 15;
	pOut->DrawHexagon(P1, l, gfxInfo, false);

	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawHexagon(P1, l, gfxInfo, true);

	pOut->PrintMessage("Drawing a Hexagon Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	///TODO: Add code to draw Hexagon in all possible states /////// DONE






	/// 2.5- Circle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing an Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("Drawing a circle ===> non-filled, click one point");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("Enter radius");
	r = stod(pIn->GetSrting(pOut));

	while (r <= 0) {
		pOut->PrintMessage("Re-enter radius, Radius must be positive.");
		r = stod(pIn->GetSrting(pOut));
	}

	gfxInfo.isFilled = false;
	gfxInfo.DrawClr = GREEN;
	gfxInfo.BorderWdth = 15;
	pOut->DrawCircle(P1, r, gfxInfo, false);

	pOut->PrintMessage("Drawing a Circle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawCircle(P1, r, gfxInfo, true);

	pOut->PrintMessage("Drawing a circle ==> filled, click one point");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("Enter radius:");
	r = stod(pIn->GetSrting(pOut));

	while (r <= 0) {
		pOut->PrintMessage("Re-enter radius, Radius must be positive.");
		r = stod(pIn->GetSrting(pOut));
	}

	gfxInfo.FillClr = pIn->GetColour(pOut);
	gfxInfo.DrawClr = WHITE;
	gfxInfo.BorderWdth = 15;
	gfxInfo.isFilled = true;
	pOut->DrawCircle(P1, r, gfxInfo, false);

	pOut->PrintMessage("Drawing a Circle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawCircle(P1, r, gfxInfo, true);






	///TODO: Add code to draw Circle in all possible states /////DONE

	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("Testing Input ability to read strings");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar /////// DONE
	// 2- After reading the string clear the status bar ////// DONE
	// 3- print on the status bar "You Entered" then print the string ////// DONE

	string input = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	string out = "You Entered ";
	string conc = out + input;
	pOut->PrintMessage(conc);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions) /////// DONE
	//Add cases for the missing actions below /////// DONE
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case DRAW_RECT:
			pOut->PrintMessage("Action: Draw a Rectangle , Click anywhere");
			break;
		case DRAW_SQUARE:
			pOut->PrintMessage("Action: Draw a square, Click anywhere");
			break;
		case DRAW_TRI:
			pOut->PrintMessage("Action: Draw a triangle, Click anywhere");
			break;
		case DRAW_HEX:
			pOut->PrintMessage("Action: Draw a hexagon, Click anywhere");
			break;
		case DRAW_CIRCLE:
			pOut->PrintMessage("Action: Draw a circle, Click anywhere");
			break;
		case ADD_FIG:
			pOut->PrintMessage("Action: Adding a figure, Click anywhere");
			break;
		case SELECT:
			pOut->PrintMessage("Action:Selecting a figure, Click anywhere");
			break;
		case SWAP:
			pOut->PrintMessage("Action: Swapping figures, Click anywhere");
			break;
		case ROTATE_FIG:
			pOut->PrintMessage("Action: Rotating a figure, Click anywhere");
			break;
		case DELETE_FIG:
			pOut->PrintMessage("Action: Deleting a figure, Click anywhere");
			break;
		case CLEAR_ALL:
			pOut->PrintMessage("Action: Clear all figures, Click anywhere");
			break;
		case COPY_FIG:
			pOut->PrintMessage("Action: Copying a figure, Click anywhere");
			break;
		case CUT_FIG:
			pOut->PrintMessage("Action: Cutting a figure, Click anywhere");
			break;
		case PASTE_FIG:
			pOut->PrintMessage("Action: Pasting a figure, Click anywhere");
			break;
		case SAVE_GRAPH:
			pOut->PrintMessage("Action: Saving a figure, Click anywhere");
			break;
		case LOAD_GRAPH:
			pOut->PrintMessage("Action: Loading a figure, Click anywhere");
			break;


		case TO_PLAY:
			pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
			pOut->ClearToolBar();
			pOut->CreatePlayToolBar();
			break;

		case MATCHING_PAIRS:
			pOut->PrintMessage("Action: MATCHING PAIRS MODE :), Click anywhere");
			break;
		case MISSING_SHAPES:
			pOut->PrintMessage("Action: MISSING SHAPES MODE :), Click anywhere");
			break;

		case TO_DRAW:
			pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
			pOut->ClearToolBar();
			pOut->CreateDrawToolBar();
			break;



		case EXIT:
			break;


		case STATUS:
			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
			break;


		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;





			///TODO: Add more cases for the other action types /////DONE


	
		}
	} while (ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x, y);


	delete pIn;
	delete pOut;
	return 0;
}