// Done by TheTutor -- 06/06/01

/*  
	Check out "Point_Class.cpp" and "Point_Class.h" for explanation of what is going
	on -- Here I'm just going to use CPOINT, not get to heavy on the details of 
	what's going on 
*/

#include <iostream>
#include "Point_Class.h"

using namespace std;

int main()
{
	CPOINT point;

	// Let's set the point -- Exactly the same if we were using a struct in C-Land
	point.x = 52;
	point.y = 99;

	// Print out "point's" values
	cout << "X = " << point.x << " Y = " << point.y << endl << endl;

	point.Swap(); // That's it -- The values have been swapped
				  // Notice the we use the '.' to call point's method -- just like 
				  // we use the '.' to access point's variables --

	// Print out "point's" values
	cout << "X = " << point.x << " Y = " << point.y << endl << endl;

	// Okay the C-Land equivalent
	/*

	CPOINT point;

	point.x = 52;
	point.y = 99;

	printf("X = %d, and Y = %d\n",point.x,point.y);

	Swap(&point);

	printf("X = %d, and Y = %d\n",point.x,point.y);			
	
	*/

		return 0;
}


/*		ADDITIONAL INFO --

  Think of a class a blue-print -- It's spells out what data (variables) and what methods
  (functions) are going to manipulate the data -- 
  Then people create these objects and use them to do whatever their purpose is -- 
  If you've done the "Reading From A File" or "Writing To A File" C++ tutorials you've
  already used class(es) and their methods --

  Remember: ifstream fin;

  And then to open a file you did something like this:  fin.open("ATextFile.txt");

  What you did is create an "instance" (declared a variable) of the object ifstream. -- This
  object has methods associated with to open files, read from files, close files etc, etc.
  Then by using these methods, you were able to open a text file and read the contents of
  the text file.  The great part about objects is C++ provides us with a lot of them --
  We don't need to know how they're implemented, just how to use them.

  The object we made is quite simple it can only swap it's x and y values.  But don't
  worry we're going to add more methods to it in the next class tutorial and go over
  classes again -- Oh and I'll talk about the "public:" thing %)

*/

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/				  
