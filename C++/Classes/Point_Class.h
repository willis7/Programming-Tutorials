#ifndef POINT_CLASS_H
#define POINT_CLASS_H

/* Welcome to the wonder world of classes and encapsulation.  What makes C++ different
(and better) is the ability to encapsulate data.  When programming in C the general flow of
a program is this:
-- Make structures/variables, write functions to do stuff with them

But in C++ land the general program flow is this:
-- Create functional objects that can interact to do stuff

So all encapsulation is, is grouping data and the functions that manipulate the data
in one "object"

An object can be thought of as a struct in C world -- But, you have the ability to call
functions from the struct

Yeah I know as I'm reading this I'm like, "This doesn't make any sense" so what I'm going to do
is a program that defines a Cartesian Point (X,Y) and has one operation "Swap" which changes
the X and Y -- So if had a point (X1,Y1) after calling "Swap" on it the point would equal (Y1,X1)

Also for every step of the program I'm going to put the "equivalent" (what we would HAVE to do in C land)
below each major code section

*/

class CPOINT // Cartesian Point
{
	public: // For the time being don't worry about this -- JUST KNOW (for this example) 
			// it HAS to be there
		
		int x;
		int y;

		void Swap(); // Looks a lot like a function (and really it is) but "functions" that
				     // are inside of classes are referred to as "methods"
};

/* In C world we'd need first a struct -- Then a function to do the swapping

typedef struct _CPOINT
{
	int x;
	int y;

} CPOINT;

void Swap(CPOINT *point);	// Since we want to swap x and y we HAVE to pass in a pointer
							// to the function Swap() to accomplish this	*/


// Well let's move onto the coding portion...

#endif