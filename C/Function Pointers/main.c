// Done by TheTutor -- 10/8/01

/*  Okay this "lesson" is all about function pointers -- This assumes you know what a 
	pointer is and "generally how they work"

	So what is a function pointer? -- Well like the name suggests a function pointer is
	a pointer to a function -- So we're going to write a function "printName" that is going
	to take a function pointer.  This will give us the capability of having "printName" be
	able to print out a name any way we want.

	Additionally, we're going to write two functions:
	horzPrint() -- This prints out a name horizontally
	vertPrint() -- This prints out a name vertically.

	Okay sounds pretty easy right?  Well if you're a little confused, do not fret, all 
	will be revealed :)

*/


#include <stdio.h>

// This function takes the char* passed in and prints it our horizontally (ie like
// you would normally read text)
void horzPrint(char*);

void vertPrint(char*); // This function takes the char* passed in and prints it out 
					   // vertically -- So if I passed in "game" it would print like this:
					   // g
					   // a
					   // m
					   // e

// Now here's where all the magic is happening
// Well the first parameter (the char*) will be the name to be printed
// Now what the heck is this mess -- void (*print)(char*) ???
// This is where we're saying this function takes a function pointer
// the "void" is the return type of the function pointer (notice horzPrint() and vertPrint()
// both return void)
// (*print) is the "name" of the function pointer.  What's important here is the '*' before
// the "print" -- The '*' says this is a function pointer, we could name the function 
// "spitOutToScreen" if we wanted (ie replace "print" with "spitOutToScreen")
// Last but not least the "char*" is what our "function" takes as parameter(s)
// This works very much the same way as it would for a "normal" function declaration
// Again note that horzPrint() and vertPrint() take a char* AND only a char* as their input
// parameters
void printName(char*, void (*print)(char*));

int main()
{
	char name[] = "TheTutor"; // This is the name -- Cool name if you ask me :)

	// First lets print it out vertically
	printName(name,vertPrint);

	// Now we'll print it out horizontally
	printName(name,horzPrint);

		return 0; // Okay -- I feel good about this program ending

}

// This function takes "name" and prints it horizontally (ie simply prints it to the screen)
void horzPrint(char *name)
{
	// Error check -- Make sure we received a valid pointer
	if(!name)
		return;

	printf("%s",name); // Simply print out the name

}

// This function takes "name" and prints it vertically to the screen 
// (ie prints out each letter with a carriage return after it)
void vertPrint(char *name)
{
	int index = 0; // This will be the index of the letter in "name" to print out

	// Error check -- Make sure we received a valid pointer
	if(!name)
		return;

	// While we HAVE NOT reached the end of "name"
	while(name[index] != '\0')
	{
		printf("%c",name[index++]); // Print out the "current letter" of the name
							       // and increment the index AFTER the letter has
								  // been printed out
		printf("\n"); // Print out a blank line (carriage return)
	}

}

// This function takes a name to print "name" and a function pointer which points to a 
// function that implements how "name" should be print to the screen -- Wordy enough :)
void printName(char *name, void (*print)(char*))
{
	print(name); // Print the name (it will be print in whatever style the function pointer
				 // implements)

	printf("\n"); // Then we're going to print a "carriage return"
}

/*

  Okay lets review:

  I hope it is obvious that a function pointer syntax is VERY SIMILAR to a "normal functions
  declaration" -- Lets break down the function one more time:

  void printName(char*, void (*print)(char*));
	|
	|__ The return type for the function printName() (ie no return type)


  void printName(char*, void (*print)(char*));
			|
			|__ The name of a function (just like any other function you declare, you pick this)


  void printName(char*, void (*print)(char*));
				  |
				  |__ First "input parameter" to the function, it takes a char* (char array)


  void printName(char*, void (*print)(char*));
								|
								|__ This whole mess "void (*print)(char*)" is defining
									the second input parameter to printName() which happens
									to be a function pointer


  /////////////////// Now we'll break down the function pointer

  void (*print)(char*)
    |
	|__ The return type of the function pointer (ie no return type)


  void (*print)(char*)
		  |
		  |__ The name of the function pointer.  The '*' is what is important here.  The '*'
			  tells the compiler that "this is a function pointer" -- The name "print"
			  is just like any other "function", we pick it

  void (*print)(char*)
				  |
				  |__ This is the first (and only) parameter passed to the function pointer
					  it happens to be a char* (char array)


  Well I hope that clears up the tricky syntax programmers like to call "function pointers".
  As always any questions can be directed to:  www.GameTutorials.com

*/

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/
									
				





