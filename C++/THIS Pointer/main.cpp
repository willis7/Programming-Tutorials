// Done by TheTutor -- 08/26/01

/*  This tutorial is going to show you what the "this" pointer is -- Basically it's just
	an "invisible pointer" in all classes that points to that classes member variables and 
	member functions -- We'll implement this class by referring to the "this" pointer a 
	couple different ways just so you can see how to access it.

*/
#include <iostream>
#include "Point_Class.h"

using namespace std;

int main()
{
	CPOINT point;

	// Let's set the point
	point.setPoint(45,22);

	// Print out "point's" values
	cout << "X = " << point.getX() << " Y = " << point.getY() << endl << endl;

	// Swap the values
	point.Swap(); 
	
	// Print out "point's" values
	cout << "X = " << point.getX() << " Y = " << point.getY() << endl << endl;
		return 0;
}


/*	
	For more on the "this" pointer -- Check out the Operator Overloading tutorial
	In it, I use the "this" pointer to implement the overloading of the assignment (=)
	operator

	Of course if you have more questions, feel free to post 'em at www.GameTutorials.com
*/

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/

									  
