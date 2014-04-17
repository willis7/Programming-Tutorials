//***********************************************************************//
//																		 //
//		- "Talk to me like I'm a 3 year old!" Programming Lessons -		 //
//                                                                       //
//		$Author:		Ben Humphrey	digiben@gametutorials.com		 //
//																		 //
//		$Program:		YourName										 //
//																		 //
//		$Description:	Asks and prints your name to the screen			 //
//																		 //
//		$Date:			5/17/00											 //
//																		 //
//***********************************************************************//

#include <stdio.h>

void main()									// The beginning of our program
{
	char szName[25];						// This means we are creating a "string"
											// Of CHAR-acters.  This is called a variable
											// A variable could be a "char", "int", "float", "double",
											// Or one we create ourselves.  An "int" is for numbers
											// A "float" is for floating point numbers like "1.2"
											// A "double" is for larger floating point numbers like 3.1462859
											// Anyway, we now have a variable with 25 characters. 
											// The number is arbitrary (can be however many needed)
											// In other words, we have space to put a word in that's at most 25
											// Characters long.  I chose the name "szName" because it is a string.
											// sz<The Name> is a standard for string variables.
											// You can type whatever you want as the variable name,
											// But if you are working with a lot of variables it's
											// Easier to decipher what type of variable it is this way

	printf("What is your name? ");			// Print to the screen "What is your name? "

	scanf("%s", szName);					// This function waits like a prompt.  The program
											// Won't go any further until you type something and hit ENTER or <return>
											// This function takes 2 paramters.  a "," seperates parameters
											// In this case, we passed in:  "%s" and szName
											// The "%s" means we want to get a string from the user.
											// If we wanted a integer (number) we would use "%d" .
											// The second parameter is our variable that we want to store what
											// Is typed in by the user.  In this case, the user's name.

	printf("Hello %s!\n", szName);			// Once the user types in their name and hit's return,
											// We will take our variable that holds the name typed in
											// And print it to the screen.  We use the "%s" again to say we
											// Want to print a string.  We use the "\n" (new line) character again
											// To skip a line.  After the end " there is the ","
											// To decipher between parameters.  The next parameter we pass in is
											// Our variable that stores the name.  What is in the variable will
											// Be printed to the screen where ever the "%s" is placed in the previous parameter.
											// We could also do "printf("Hi %s %s %s", szName, szName, szName);"
											// This would printf out, say the name is Ben .. "Hi Ben Ben Ben"
											// The function "printf()" knows how many parameters to read in by how
											// Many of "%s" <--- these you use.  So we used 3, so we need to pass in 3 other variables
}

// The output for this program should be:

// What is your name? <Say we typed in Ben as our name>
// Hello Ben!

// If any of this didn't make sense, refer to the "HelloWorld" tutorial.


// © 2000-2003 GameTutorials