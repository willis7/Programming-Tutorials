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

// *Note*    Using "//" allows us to type anything we want and the compiler ignores it - called "Comments"

#include <iostream>				// This line of code is necessary to include all the C++ standard functions\classes definitions
using namespace std;			// This confusing line isn't important right now.  
								// Just know that "std" is an abbreviation for standard and that
								// if we are using <iostream> verses <iostream.h> we need to use "namespaces"
								// In a nutshell namespaces for cases when you have millions of lines of
								// code and you might want to use the same name for 2 different functions
								// After a while, you might run out of names to call your functions, and this solves that.
								// It is something very new, but not anything someone new to programming needs to do.
								// You can create your own namespaces, but we are just going to use the standard one, "std"												

void main()						// This creates a function called "main".  Every program must have a "main()"
{								// The "{" signifies the start of the function
								// The next line displays "HelloWorld" to the screen, then skips down a line
	cout << "HelloWorld!" << endl;
								// cout is a standard "class" that stands for (console output).
								// We are inserting a string of characters, "HelloWorld", and a (endl) command into the class "cout"
								// (endl) stands for (end of line) which drops the cursor down to the next line in the console.
								// cout uses "<<" as syntax between each insertion.  You could say:
								//		cout << "Hello" << "World!" << endl;
								// And it would print out the same thing.  You can go on forever.  You could
								// Also do this:  cout << "HelloWorld!" << endl << endl << endl;
								// This would print "HelloWorld!" then skip down 3 new lines in the console window upon execution of the program.
								// Notice the semicolon at the end of "endl;".. This tells the compiler we are done processing that statement.
								// It allows us to be able to type crazy things like this:
								//	cout <<
								//			"Hello" << "World!"
								//								<< endl;
								// Though it's ugly and unnecessary, we can put those on separate lines because it takes the whole
								// statement starting at the "cout" and goes to the ";".  This comes in handy some times.  Some compilers are line based with no ";"
}								// The "}" signifies the end of the function , and the end of the program.

// To run this with Visual Studio C++ , Hit Control-F5
// If you don't already have a project open, it will prompt you
// You should see: 

// HelloWorld!
// press any key to continue			<-- Windows puts this at the end to show the program is finished

// So, all this program does is just display text in a window.  A good start.
// Experiment with printing other words and sentences out, uses more "<<" to get the idea.

// Let me explain more about the #include <iostream>
// #include is a "preprocessor" command that happens FIRST before anything else.
// What is does, is basically cut and paste the file called "iostream" into the code
// Before the compiler compiles the code into a program.  
// You can open the file "iostream" in the include\ folder in your Visual Studio directory.
// Take a look at it if you like.  It just holds a bunch of definitions to tell the compiler.
// When we call "cout" it knows what cout is by the file <iostream>.  The "<" ">" syntax
// Means that the file is located in the include\ directory, where double quotes ("iostream")
// would mean that you have the file in your root directory (where your HelloWorld.cpp file is located).
// We will later create our own files.  These are called header files.  

// If any of this is confusing, it should be.  It's strange :)
// As we go along mostly everything will be explained and understood.
// BUT!  You can fully understand anything until you do it yourself.
// I suggest taking each tutorial and messing around with the code:
// Deleting things, adding things... seeing what it does, that way you
// will understand what each part of the code does.  A lot of the times
// You will get errors from deleting things, just put it back and try something else.

// *LAST NOTE*

// Everything below you must have to run a program that uses console output:

// #include <iostream>
// using namespace std;

// void main()
// {
// }

// That is the "SHELL" you could say of a program, you must have all of that
// Or else the program won't run.  If you ran a "SHELL" it will open a window
// and say:  "press any key to continue..."

// Before you start programming, it's a good idea to make sure your program runs first.
// Then start adding code line "cout" etc..

// A big part of programming you won't understand in the beginning, but you will later.
// Some things are too complex to explain in the beginning and you need to just take them
// For face value and say, "Ok, I don't know what this does right now, but I know I need it.."

// © 2000-2003 GameTutorials