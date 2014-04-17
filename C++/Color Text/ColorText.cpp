//***********************************************************************//
//																		 //
//		- "Talk to me like I'm a 3 year old!" Programming Lessons -		 //
//                                                                       //
//		$Author:		Ben Humphrey	digiben@gametutorials.com		 //
//																		 //
//		$Program:		ColorText										 //
//																		 //
//		$Description:	Displays Color Text in a Console Window.		 //
//																		 //
//		$Date:			6/22/00											 //
//																		 //
//***********************************************************************//

#include <iostream>										// Include the standard
#include <windows.h>									// We need to include this for "console" functions.
#include <string>										// Allows us to use the "string" type
using namespace std;									// Use the standard namespace (blah blah, not important to understand right now)

														// Here is our function that draw's a color string in a DOS window.
														// We just pass in the string, the X and Y position, then the color we desire.
														// The color can be a background color AND a foreground color.  Here are some color examples:
														// FOREGROUND_GREEN; FOREGROUND_RED; FOREGROUND_BLUE; - BACKGROUND_RED; BACKGROUND_BLUE; BACKGROUND_GREEN;
														// You can mix and match these to create other colors.  Look in "Main()" to see how.
void DrawColorString(string szText, int X, int Y, WORD color)
{	
	HANDLE OutputH;										// This will be used for our handle to the output (basically, holds permission to change the output settings)
	COORD position = {X, Y};							// Create a COORD and set it's x and y to the X and Y passed in.

	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);			// Get a OUTPUT handle to our screen.

	SetConsoleTextAttribute(OutputH, color);			// Set the text attribute to what ever color that was passed in.
														// The function SetConsoleTextAttribute takes (the handle to the output, and the color);
	SetConsoleCursorPosition(OutputH, position);		// Set the cursor position to the desire position passed in.

	cout << szText;										// Now print out what we wanted to at the position that was passed in.

}

void main()												// Here is our main().
{
	DrawColorString("Red",  0, 0, FOREGROUND_RED);		// Draw "Red" in the color RED.  Draw "White" in the color WHITE.  If we OR ("|") the colors together, it becomes white.
	DrawColorString("White",10, 1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	DrawColorString("Blue", 20, 2, FOREGROUND_BLUE);	// Draw "Blue" in the color BLUE.

	DrawColorString("Red",  0, 4, BACKGROUND_RED);		// Draw "Red" with a background of RED.  Draw "White" with a background of WHITE.
	DrawColorString("White",10, 5, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	DrawColorString("Blue", 20, 6, BACKGROUND_BLUE);	// Draw "Blue" with a background of BLUE.
														// Draw a Red text color with a green background.
	DrawColorString("Color Text!", 0, 8, FOREGROUND_RED | BACKGROUND_GREEN);
														// This puts the "Press any key to continue..." on the next line.
	DrawColorString("", 0, 9, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}														// End of the program

// *Quick Note*
//
// The "|" is a binary OR.  I won't explain what that really does, except that it
// allows you to "mix" colors.  Just like in paint.  If you mix 2 colors, it
// Changes to another color.  Also, you can OR background and foreground colors together.
// There is another thing, you can OR a FOREGROUND_INTENSITY and/or a BACKGROUND_INTENSITY
// together.  Those just make the colors brighter.  Like:
// (FOREGROUND_RED | FOREGROUND_INTENSITY) will make a brighter red.

// There's color for ya.  The next tutorial will focus on a "screen buffer".
// This will allow use to draw things to the screen in one swoop, rather than character by character.
// If any of this is unclear, email me at digiben@gametutorials.com.
// I will be more than happy to write a program to explain it if needs be.

// © 2000-2003 GameTutorials