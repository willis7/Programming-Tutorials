// Done by TheTutor -- 8/12/01

/*	Polymorphism -- Is the ability for determining which function/method to process 
	at run-time.

	Normally when you compile a program the functions/methods have a STATIC memory location
	they will be called from -- For example:

	void print_name(char*);

	So basically what is happening when you compile your program is that the compiler replaces
	"print_name" with some address in memory that points to the address in memory where the 
	functions code is -- Make sense? -- This address DOES NOT change for the entire
	life of the program

	This is where polymorphism differs.  First off, when your thinking about polymorphism, you
	should think virtual functions -- By using virtual functions we can achieve polymorphism

	A virtual function lets us decide, while the program is executing which "address" we're 
	going to use to process a particular function/method -- Making more sense???

	Some rules for virtual functions:

	1)	They must be class methods
	2)	They CAN NOT be stand alone functions
	3)	They CAN NOT be class data
	4)	They CAN NOT be static methods
	5)	When a class has virtual function(s) -- That class will get a vtable -- This vtable
		exists for the class (That means only ONE copy, not a new copy every time you declare
		a variable of that class type)

	Polymorphism is a complex subject so don't get frustrated if doesn't click all at once :)
	This program is going to make three classes:  SHAPE class, TRIANGLE class, SQUARE class
	Using virtual functions we'll be able to write a function that takes a SHAPE and draws
	out the appropriate shape (ie a triangle or square)

	So let's get moving -- There plenty more green stuff to read through in Shape.h :)

*/

#include "Shape.h"

// Okay we have our three SIMPLE classes and what we want to do is create a function
// that will draw ANY shape passed in.
void Draw(SHAPE *shape);

int main()
{
	// Here we make an instance of our "specific shape classes"
	TRIANGLE triangle;
	SQUARE square;

	// **Note -- Every time we make an instance of any of the classes we created,
	// the object we create (example "triangle") will have a hidden member variable
	// called a vtable pointer (vptr) -- This member variable will point to the classes
	// vtable the object was created from

	// Notice this function takes a SHAPE* -- but remember TRIANGLE was derived from
	// SHAPE so it is a "SHAPE" -- Also notice WE DO NOT have to typecast
	Draw(&triangle); // This should draw a triangle to the screen

	Draw(&square); // This should draw a square to the screen

	// Again this should draw a triangle to the screen
	triangle.draw();

	return EXIT_SUCCESS; // I feel good about this program ending :)

}


// Because we are using polymorphism (we derive all our "specific shape classes" (such as 
// TRIANGLE) from the SHAPE class) -- The correct "draw" method will get called at run time
void Draw(SHAPE *shape)
{
	shape->draw();
}


/* You will notice that we take a pointer to a SHAPE in the draw function -- Why not just a
   SHAPE?  If we just passed in a SHAPE this program would print out NOTHING -- The reason is
   because of the "copy constructor"
*/


// If you have any more questions about polymorphism, please post at www.GameTutorials.com
// and the GameTutorials community will do it's best to answer 'em :)

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/

