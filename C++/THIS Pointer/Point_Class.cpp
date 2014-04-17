#include "Point_Class.h"

// Okay we simply want to switch the x and y values of CPOINT 
void CPOINT::Swap()
{
	int temp = this->x; // Save off x -- 'x' is contained in the scope of CPOINT thus CPOINT's 
				       // "this" pointer, points to x -- So ONE way to access "x" is "this->x"
					  // If you are using VC++6.0 and you type in this->, intellisense should
					 // come up and show you all the methods/variables contained in CPOINT


	// Set x equal to y
	this->x = this->y;

	// Set y to x
	y = temp;			// Notice here WERE NOT USING THE THIS POINTER -- Remember the
					   // "this" pointer is SUPPOSED to be invisible so
					  // "y" and "this->y" are identical (they both "point" to the
					 // integer variable y)
}

// Set the x and y values
void CPOINT::setPoint(int x_val, int y_val)
{
	// You can also access the "this" pointer another way
	// by dereferencing it -- This is particular useful if you want 
	// to return an instance of the class (example: if you overload the assignment (=)
	// operator)

	// So this is also legal
	(*this).x = x_val;
	(*this).y = y_val;

	// Another option (that does the exact same thing) would have been:
	// x = x_val;
	// y = y_val;

}
	