#include "Point_Class.h"


// Notice there is NO RETURN TYPE --
// Okay here's the lowdown on constructors --
/* 1) Constructors get called when you make an instance of a class.  Example: 

		int main()
		{
			CPOINT c;	-- This is called making a instance of a class
			
				return 0;
		}

  2)  What a constructor's purpose is, is to initialize the data (variables) of the class
*/  
CPOINT::CPOINT()
{
	x = 0;		// Here we set both values to zero
	y = 0;
}

// For this constructor we set x and y to the values passed in --

/*	IMPORTANT NOTE: -- If we only would of defined the constructor below, this code would
	not compile:

	int main()
	{
		CPOINT c;		// We made the constructor take two arguments
						// So now if want to make an instance of CPOINT we HAVE
						// to pass in two arguments

			return 0;
	}

	// This is why if you're going to define your own constructors -- you should always
	// define a default constructor (one that takes no arguments)
*/	
CPOINT::CPOINT(int X_value, int Y_value)
{
	x = X_value;
	y = Y_value;
}

// You know what swap does by now right??? -- Well I'll leave the comments in there just in case
void CPOINT::Swap()
{
	int temp = x; // Save off x -- Remember 'x' is contained within the "scope" of CPOINT
	             // So we don't have to pass it into Swap()

	x = y; // Set x to y -- Again 'y' is contained within the "scope" of CPOINT 
		  // CPOINT knows about "int x" and "int y" (see header file), so we don't need 
		 // to pass them in, they are "always known by CPOINT"

	y = temp; // Set y to x
}

// Here we just setting x and y to the values passed in

/* BUT HERE'S THE IMPORTANT PART -- The reason we make data private is so that as the implementer
of a class we decide how and if the data is going to be changed -- If we didn't want the
x value of our CPOINT to be greater than 100, we could do a check when setting x like this:

  if(new_x > 100)
	x = 100;
  else
	x = new_x;

If we were to do this NO CLIENT could set x to a value greater than 100 -- We could be
positive that x is ALWAYS going to be less than 100 (we'd have to do a similar check in
the constructor to be 100% sure it's never greater than 100, but you get the point) --
Then we can use that fact in other functions or methods

Is the whole reasoning (and madness) behind classes starting to make sense???
If not, you know what they say "Practice makes perfect" %)
*/
void CPOINT::setPoint(int new_x, int new_y)
{
	x = new_x;
	y = new_y;

}

// Here we're simply returning the value of x
int CPOINT::getX()
{
	return x;
}

// Yep, you guessed it, we're simply returning the value of y
int CPOINT::getY()
{
	return y;
}

