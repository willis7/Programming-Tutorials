#ifndef POINT_CLASS_H
#define POINT_CLASS_H

/*	This is our simple little class we're going to use to talk about the "this" pointer.
	You see the keyword "this" used in the implementation part of CPOINT.
	I also briefly redefine what "public" and "private" mean in the context of a class.
*/

class CPOINT // It holds a Cartesian Point
{
	public: // Public stuff can be accessed by a "client" -- If I declare a CPOINT in 
			// "main.cpp" I can call Swap()
		
		void Swap(); // Looks a lot like a function (and really it is) but "functions" that
				     // are inside of classes are referred to as "methods" -- This will swap
					 // the x and y values of a CPOINT

		void setPoint(int x_val, int y_val); // This sets a CPOINT's x and y to the
											// x_val (x value) and y_val (y value) passed in

		// Data access functions -- Remember x an y are PRIVATE we CANNOT access them directly
		// so if want to print out x, we need a way to get to it -- These data access functions
		// will work nicely
		int getX() { return x; }
		int getY() { return y; }

	
	private: // Private stuff can ONLY be accessed (directly) in the implementation of
			 // CPOINT -- In main.cpp this would be illegal code:

			 /*  CPOINT cpoint;
					
				 cpoint.x = 5; // This is illegal -- Will NOT compile
			 */

		int x;
		int y;
};


#endif