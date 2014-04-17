//***********************************************************************//
//																		 //
//		- "Talk to me like I'm a 3 year old!" Programming Lessons -		 //
//                                                                       //
//		$Author:		Ben Humphrey	digiben@gametutorials.com		 //
//																		 //
//		$Program:		Functions										 //
//																		 //
//		$Description:	Work with functions to create a menu.			 //
//																		 //
//		$Date:			6/5/00											 //
//																		 //
//***********************************************************************//

#include <iostream>							// This line of code is necessary to include all the C++ standard functions\classes definitions
using namespace std;						// Set our namespace to standard

void DrawMenu();							// This declares our function name and what it returns.
// This declaration would usually			// This let's the compiler know we have a function, and what parameters we need to pass in.
// Go in another file, say, functions.h		// This is like declaring a variable.  We initialize our variable at the beginning, 
											// Then usually assign it something later
											// In our case, our function doesn't need to return anything so we put a "void" , meaning nothing.
											// if you look down at "main()" you'll notice that we use "void" too.  We aren't returning anything in main usually.
											// The next tutorial will deal more with functions and returning things from them.
											// When declaring a function, we must put a semicolon after it.

void DrawMenu()								// This is the part where we assign the function to do something.
{											// We don't use a semicolon because we are not finished with the function, we are starting it with "{" and ending it with "}"
	cout << "\t\t ****************Game Menu**************** \n";
	cout << "\t\t *                                       * \n";	// This is our game menu, comprised of cout's :)
	cout << "\t\t *   1) New Game                         * \n";	// Beautiful isn't it?  hehe.
	cout << "\t\t *   2) Load Game                        * \n";	// You can obviously find more create ways to display a menu than this.
	cout << "\t\t *   3) Save Game                        * \n";	// Just somehow we have to let the user know their options
	cout << "\t\t *   4) Inventory                        * \n";	// You'll notice the "\t"  this is like "\n", but it means TAB.  It's just so you
	cout << "\t\t *   5) Options                          * \n";	// Don't have to press space bar 5 times... I am just expanding your C++ vocabulary :)
	cout << "\t\t *   6) Quit                             * \n";
	cout << "\t\t *                                       * \n";
	cout << "\t\t ***************************************** \n";	
}																	// This is the end of the function.
																	// If you remember the macro you did with PRINT_NUM(), this is very similar.

void main()
{
	bool bStillPlaying=true;				// Here we declare a type of "bool" which stands for boolean
	int choice=0;							// A boolean is usually a flag that holds a value, true, or false. (true is anything but 0, false is 0)
											// In this case, let's make a boolean and set it to true, meaning we
											// Are "bStillPlaying" the game.  When Quit is chosen, we will set it to false, ending the game loop.
											// Once again, we put the 'b' in front of "StillPlaying" to show that it's a boolean.  This provides good readable code

											// Let's create a while loop to continue until they Press '6' for quit.
	while(bStillPlaying)					// This says, do everything below until StillPlaying == FALSE.  Remember, a statement doesn't happen if 0 is the result from the expression.
	{
		DrawMenu();							// All we need to do is call our function, like so.
											// Since there are no parameters to pass in, we just close the parenthesis (); with a semicolon.															
											// Now comes the part where we need to be able to choose from the menu.
	
		cout << "Choose from the menu: ";	// Prompt the user

		cin >> choice;						// Get the users choice
												
											// This is called a "switch" statement.
											// What it does is take choice (or whatever is passed in), and do a bunch of if/else statements on it.
											// it's pretty much the same things as if/else, but looks cleaner.
		switch(choice)						// "case 1:"  is the same thing as saying, "if(choice == 1)"  You see?  A lot cleaner
		{
			case 1: cout << "You chose a New Game!\n";		// if (choice == 1)
					break;					// break - breaks out of the switch statement. 
			case 2: cout << "You chose to Load a Game!\n";	// if (choice == 2)
					break;									// Print the choice and break;
			case 3: cout << "You chose to Save a Game!\n";	// if (choice == 3)
					break;									// Print the choice and break;
			case 4: cout << "You chose your Inventory!\n";	// if (choice == 4)
					break;									// Print the choice and break;
			case 5: cout << "You chose Options!\n";			// if (choice == 5)
					break;									// Print the choice and break;
			case 6: bStillPlaying = false;					// if (choice == 6)
					cout << "Game Over Already?\n";			// bStillPlaying is set to false.  This means, when the code goes back up to the top, while(bStillPlaying) will NOT be true and fail.
					break;									// A weird thing about switch statements, you don't need brackets {} for more than one line.
		}													// You just need a break;
	}	// while (bStillPlaying)							// It's a good idea to label what the closing bracket is coming from.
															// When your code gets huge, it's kinda annoying to go back and match up all the brackets to find the statement.
															
}    	// void main()										// Once the user hits 6, the while loop quits and go end our program.
														
															// And that's it!  Here is a menu.  Sure it's the simplest menu ever, but it's a start :)
															// The more important thing here is the use of a function.


// © 2000-2003 GameTutorials
