// Done by TheTutor -- 12/23/01

/*	This tutorial is going to cover the "ternary operator" -- For starters it's called the
	"ternary operator" because it has three parts, but really what it is a conditional operator
	and works JUST LIKE an "if statement".

	So the first thing we'll do is look at an actual piece of code that uses the ternary
	operator:

	(x == 200)?(x = 0):(x++);

	Whoa that looks CRAZY right!  Well lets break it down into parts:

	(x == 200)?(x = 0):(x++);
	   |
	   |__ The (x == 200) part is just an expression for evaluating (it is also the first
		   part of the ternary operator)
		   It is has the same meaning as if this was the code:
		   
		   if(x == 200)		// Same thing as that
		     // Do stuff

    (x == 200)?(x = 0):(x++);
	          |
			  |__ The '?' is literally like a question mark here.  It's posing the question:
				  "Does the expression (x == 200) evaluate to TRUE or FALSE?"

	(x == 200)?(x = 0):(x++);
				  |
				  |__ The (x = 0) part is what will be executed if x == 200 (if x is equal to 200)
					  This is the second part of the ternary operator and it ALWAYS gets executed
					  if the first part (the expression part (x == 200)) is TRUE
					  It NEVER gets executed if the expression part is FALSE

	(x == 200)?(x = 0):(x++);
					  |
					  |__ The ':' (colon) is the basically saying "otherwise"
						  So what we saying so far is this:
						  If (x == 200) is true then set (x = 0) OTHERWISE...

	(x == 200)?(x = 0):(x++);
					     |
						 |__ The 3rd part of the ternary operator, this will ALWAYS gets 
							 executed if the first part (x == 200 in this example) is FALSE
							 It NEVER gets executed if the first part (again (x == 200) in this 
							 example) is true.


	Okay that's it -- Pretty simple I hope.

	So why would you use this instead of an if statement?  Well the answer is most times you
	want if for the simple fact that "if/else statements" are a lot more clearer to read.  Plus
	if you want to do multiple things, for instance:
		
		  if(x == 200)
		  {
			   x++;
			   cout << x << endl;
		  }

	You should ALWAYS use the "if/else statements"

	So back to when you should use the ternary operator -- The two MAIN (notice I didn't say only)
	times you should use ternary operators is if you are declaring a variable and depending on
	a certain state in the program you want	to set that variable's initial value to one thing
	or another -- The other time is when defining macros

*/

#include <iostream>
using namespace std;

int main()
{
	int level; // This will hold the level of difficulty for our pretend game

	cout << "Enter difficulty level (0 - 9): ";
	cin >> level; // Read in the "level of difficulty"

	// Error check to make sure they typed in a number between (and including) 0-9
	if(level < 0 || level > 9)
	{
		cout << "You didn't follow directions did you?!?" << endl;
		return 0; // Quit the program
	}

	cout << endl << endl; // Print a couple of blank lines

	// Okay here where we going to use the ternary operator
	int AI_str = (level < 5)?(10):(level * 5); // So what we saying is this
											  // Create the variable "AI_str" -- If "level"
											 // is less than 5, set AI_str to equal 10
										    // Otherwise, set AI_str to equal (level * 5);

	// Again same thing -- Hopefully you see how this ternary operator works now :)
	int AI_hp = (level < 8)?(level * 10 + 10):(level * 25);

	// We'll print them to the screen -- Be sure you know why those values are what they are
	cout << "AI Strengh = " << AI_str << endl;
	cout << "AI Hits Point = " << AI_hp << endl;

		return 0; // And we're done
}

// As always, if you have any questions be sure to post 'em at www.GameTutorials.com

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/


									


					  

