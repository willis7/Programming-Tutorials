#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

/*	I'm going to keep these classes as SIMPLE as possible -- All we want to do is see
    how virtual functions work */


/* Now as you'll recall I said if a class contains virtual function(s) it contains a vtable
   this is a "graphical" representation of what the vtable looks like for the SHAPE class:

	**********
	* 0	** | *
	*******|**
		   |--> points to the draw method's implementation


	The first entry in a vtable is ALWAYS zero -- every entry after that will correspond
	to a virtual function.  The order goes from the first (top most) virtual function in your
	class definition on down.

*/

class SHAPE
{
	public:

	// Here you see the key word "virtual" -- This is what says "This is a virtual function"
	// Notice it goes BEFORE the return type
	virtual void draw();

	// Now this function draw isn't going to do ANYTHING -- That's right it's just going to
	// return
};

// Pretty simple SHAPE class -- Now where going to make two classes that INHERIT from the 
// SHAPE class publicly

// This class will "draw" a ASCII representation of a triangle
class TRIANGLE : public SHAPE
{
	public:

	// Again were just going to make a "draw" function
	void draw();

	/*	Now if a derived class (from a class containing virtual functions) DOESN'T specifically
		contain a virtual function from the base class, (if there are virtual functions in the 
		base class that ARE NOT functions in the derived class) the derived classes vtable
		WILL point to the base class "slot" for that function
	
		For the TRIANGLE class, THIS IS NOT THE CASE (because we defined a "local" definition
		of "draw")
	*/
};

// Again this class's ONLY method is "draw" which will 
// draw an ASCII representation of a square
class SQUARE : public SHAPE	
{
	public:

	// Again were just going to make a "draw" function
	void draw();

	/* To paraphrase what's happening slightly differently -- Here's what 
	   SQUARE's vtable looks like:

		**********
		* 0	** | *
		*******|**
			   |--> points to SQUARE's draw method implementation

	*/
};

#endif