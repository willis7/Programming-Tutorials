//***********************************************************************//
//																		 //
//		- "Talk to me like I'm a 3 year old!" Programming Lessons -		 //
//                                                                       //
//		$Author:		Ben Humphrey	digiben@gametutorials.com		 //
//																		 //
//		$Program:		HellowWorld										 //
//																		 //
//		$Description:	Print "HelloWorld" to the screen				 //
//																		 //
//		$Date:			5/17/00											 //
//																		 //
//***********************************************************************//

// *Note*    Using "//" allows us to type anything we want and the compiler ignores it

#include <stdio.h>				// This includes a header file called "stdio.h"
								// If we did not include this file we would not be able to call
								// The function "printf" down below.

								// The line below means we are calling a function that returns
								// Nothing, aka, "void".  We MUST have a function called "main()"
								// In order to run a program.  This basically lets the compiler
								// Know we are ready to begin our program.

void main()
{								// The "{" signifies the start of the function

	printf("HelloWorld\n");		// We called another function called "printf()"  This prints
								// The message in quotes out to the screen.
								// One of first functions anyone uses when beginning to program.
								// The "(" ")" after the function name signify a begin and end
								// To passing in parameters.  The parameter we passed in was a string
								// Filled with "HelloWorld".  You'll notice the "\n" right before
								// The last quote.  This tells the cursor to goto the next line on the screen.
								// So if we have "HellowWorld\n\n" , this would go down 2 lines
								// The ";" at the end of the "printf()" function let's the compiler
								// Know we are done with that line of code.
}								// The "}" signifies the end of the function


// Ahhh.... I feel good about this... :)
// To run this with Visual Studio C++ , Hit Control-F5
// If you don't already have a project open, it will prompt you
// You should see 

// HelloWorld
// Press any key to continue			<-- Windows puts this at the end to show the program is finished

// © 2000-2003 GameTutorials