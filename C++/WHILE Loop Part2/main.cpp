// Done by TheTutor -- 10/26/01

/*	Here we're going to talk about "while loops" -- A while loop is a way for your program
	to do a set of tasks WHILE some condition is true.
	
	So this program has a very simple task to complete.  We simply want the 
	user to press the 'w' key (case sensitive) -- So our program is going to be like this:

	Prompt user to enter 'w' key -- While he HAS NOT entered the 'w' key, keep prompting him
	to enter the 'w' key.

	So with that, lets get coding :)

*/

// Here we include "iostream" -- This is a header file that allows access to functions
// to do input and output (input and output streams) -- The next line of code:
// "using namespace std;", simply says "we want to use the STANDARD (std) input and
// output streams provided by "iostream"

#include <iostream>   // So we can use "cout" AND "cin"
using namespace std;

// Here's our "main function" -- This is the core of all "console" programs (ie you have 
// to have a main()) -- Notice how we return an "int" from main.  The rule of thumb is as
// follows:  return '1' if an error occurs in main() -- If your program runs flawlessly,
// return '0' (so zero means NO errors)
int main()
{
	char letter = ' '; // Here we're making a char (character) variable and setting it
					  // equal to the space character (' ')
					 // We will use this to store the character we read in from the 
				    // keyboard

	/*  Okay here it is, the while loop in all it's glory!  Notice first the keyword
		"while" (you will use this keyword to implement ALL while loops).  Now the next
		thing we will look at is the stuff inside of the ()'s

		letter != 'w' -- This "condition statement" will evaluate to "true" if
						 letter DOES NOT equal 'w' -- So when we start this program
						 we know with absolute certainty that letter DOES NOT 
						 equal 'w' (because we set it to the space character)

						 This "condition statement" will evaluate to "false"
						 when letter DOES EQUAL 'w'

		So the way a while loop works is like this -- FIRST it evaluates the 
		"condition statement" between the ()'s (ie while(condition statement) )
		If the condition statement is TRUE it will execute ALL the code between the {}'s.
		Example:

		while(Some condition it true)
		{

			Execute EVERYTHING in here

		}

		Once we reach the "right bracket" (the '}'), we go back to the top of the while loop
		and again evaluate the "condition statement", if it's true we repeat the same process.
		If it's false, we go down to the next line of code underneath the while loop.

	*/

	// This says "while letter DOES NOT equal 'w'", keep looping, executing everything
	// in-between the two {}'s
	while(letter != 'w')
	{
		cout << "Enter the letter 'w' please: "; // Prompt the user (write out to the screen)
												// for them to enter the letter 'w'

		cin >> letter; // Read in from the keyboard a "letter" (read in WHATEVER key
					  // the user presses on the keyboard, it could be the 'g' key for example)
		
		cout << endl; // Move down to the next line (carriage return)
	}

	// The ONLY way we can get here is when the user types in a 'w' key (thus the 
	// condition in the while loop "letter != 'w'" will equal FALSE and the while loop
	// will terminate)

	cout << endl << "You pressed 'w' !!!" << endl; // Print out a "Good job" message :)
												  // *Remember* the "endl" simply equates
												 // to "go down to the next line".
												// It's like hitting "enter" on a 
											   // word processor

	return 0; // Program is over so we "return"
			 // Notice we return '0' to say "No problems encountered"

} // end of main()


// If you have more questions, feel free to post them at www.GameTutorials.com

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/


	
