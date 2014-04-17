// Done by TheTutor -- 9/23/01

/*	Okay lets talk about Abstract Base Classes (commonly referred to as ABC's)

	Abstract Base Classes basically just serve as a "template" for creating polymorphic classes
	You would use an ABC to mandate/design an interface for an object.  That's where the 
	"base class" part comes from.  An ABC should hold the "base functionality" for whatever 
	object you're trying to create.  Then you would derive objects (classes) from the ABC.
	These derived classes would be forced to follow the layout of your ABC.  In this example
	we're going to make a SHAPE ABC, then derive to classes from it a TRIANGLE, and SQUARE.
	The TRIANGLE and SQUARE class will have to follow the conventions laid out by the SHAPE
	ABC (or we won't be able to create a TRIANGLE or SQUARE variable)

	Here's some basic rules of ABC's

	1)  You CAN NOT declare an instance of an ABC.  So for our example SHAPE is an ABC  
	    (Abstract Base Class), I COULD NOT do the following:

		int main()
		{
			SHAPE shape; // I could not do this, won't compile

			return 0;
		}

	2)  You can have pointers to ABC's.  So for our example this would be legal code:

		int main()
		{
			SHAPE *s = new TRIANGLE;

			// rest of code goes here

		}

	3)  You can also have references to ABC's.  Again for our example this is legal:

		int main()
		{
			TRIANGLE tri;

			SHAPE &s = tri;

			// rest of code goes here

		}

	4) Classes CAN derive from ABC's (hence this is where they are useful) but if a derived
	   class DOES NOT implement ALL of the ABC's pure virtual functions (more on these in
	   the header file) the derived class itself becomes an ABC.



*/

#include "Shape.h"

// Okay we have our one ABC and two derived classes.  What we want to do is create a function
// that will draw ANY shape passed in.
void Draw(SHAPE &shape);

int main()
{
	// Here we make an instances of our "specific shape classes"
	TRIANGLE triangle;
	SQUARE square;

	// **Note -- Every time we make an instance of any of TRIANGLE or SQUARE,
	// that instance will have a hidden member variable called a vtable pointer (vptr)
	// This member variable will point to the classes' vtable the object was created from

	// Notice this function takes a SHAPE& -- but remember TRIANGLE was derived from
	// SHAPE so it is a "SHAPE" -- Also notice WE DO NOT have to typecast
	Draw(triangle); // This should draw a triangle to the screen

	Draw(square); // This should draw a square to the screen

	// Again this should draw a triangle to the screen
	triangle.draw();

	return EXIT_SUCCESS; // I feel good about this program ending :)

}


// Because we are using polymorphism, we derived all our "specific shape classes" (such as 
// TRIANGLE) from the SHAPE class -- The correct "draw" method will get called at run time
void Draw(SHAPE &shape)
{
	shape.draw();
}


/* You will notice that we take a reference to a SHAPE in the draw function -- Why not just a
   SHAPE?  Well remember SHAPE is an ABC, YOU CAN NOT create an instance of SHAPE (which would
   be done by the copy constructor if you had a function which took a SHAPE) -- Thus
   we pass a reference to a SHAPE (we could also pass a pointer to SHAPE)
*/


// If you have any more questions about ABC's, feel free to post 'em
// at www.GameTutorials.com

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/
