#include "Point_Class.h"

// All right here we get to what appears to be tricky syntax (it's not)
// The :: is called the scope resolution operator (Holy Tabernacle that's a mouthful)
// Anyway what is happening is this:
/*
	When we created class CPOINT
					{ // FLLED IN CLASS
					};
	
	We created an "object" named CPOINT -- Using the :: we can get to either variables or 
										   methods that are contained within that "object's"
										   scope (which basically means contained between
										   the {}'s )
*/
void CPOINT::Swap()
{
	int temp = x; // Save off x -- Remember 'x' is contained within the "scope" of CPOINT
	             // So we don't have to pass it into Swap()

	x = y; // Set x to y -- Again 'y' is contained within the "scope" of CPOINT 
		  // CPOINT knows about "int x" and "int y" (see header file), so we don't need 
		 // to pass them in, they are "always known by CPOINT"

	y = temp; // Set y to x
}

// Now C-Land's Implementation:

/*
void Swap(CPOINT *point)
{
	int temp = point->x; // Save off x

	point->x = point->y; // Set x to y
	point->y = temp;	 // Set y to x

}
*/