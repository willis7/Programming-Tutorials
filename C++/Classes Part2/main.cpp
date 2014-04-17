// Done by TheTutor -- 06/08/01

#include <iostream>
#include "Point_Class.h"

using namespace std;

/* 
	Basically I'm just going to create two instances of CPOINT and call their methods
	printing out the results after each method call --
	
	All the hard core explaining is in Point_Class.cpp and Point_Class.h
*/


// Prints out the X and Y value for "point1" and "point2"
void print_values(CPOINT pt1, CPOINT pt2); 
   
int main()
{
	CPOINT point1; // DEFAULT CONSTRUCTOR gets called
	
	CPOINT point2(50,50);

	/* Uncomment this code -- You'll see that it WON'T compile
	   this is because you can't access private data members */
	//point1.x = 12;


	// Initial values of the points
	print_values(point1,point2);

	point1.setPoint(40,22); // Set's point1's x and y

	// We've now set the X and Y value in point1
	print_values(point1,point2);

	int temp = point1.getX(); // Get point1 x

	point1.setPoint(30,temp); // Set point1's x and y		
	point1.Swap(); // Sway point1's x and y				

	// We've again set the X and Y value in point1 and then swapped them
	print_values(point1,point2);

	// The "behind the scene" Assignment Operator is being
	// called below -- We'd did not implement our own so the
	// default one is being called -- The default Assignment Operator
	// does a "member-wise copy".  After running the code it should
	// become crystal clear what a "member-wise copy" is.  But if not,
	// I'll go over it again, in the next class tutorial %)
	
	point2 = point1; // Set point2 equal to point1

	print_values(point1,point2);


	/* We set point1 equal to point2.  If we call setPoint() on point2, will the values
	   in point1 change???  Good!  I'm glad you answered NO!  */

	point2.setPoint(110,22); // Set point2's x and y

	print_values(point1,point2);

		return EXIT_SUCCESS;
}

// In case this wasn't evident -- You can pass classes as arguments to functions
void print_values(CPOINT pt1, CPOINT pt2)
{
	cout << "point1's X value = " << pt1.getX() << ", point1's Y value = " << pt1.getY()
		 << endl;

	cout << "point2's X value = " << pt2.getX() << ", point2's Y value = " << pt2.getY()
		 << endl << endl;

	// **Note** remember the getX() and getY() method return an int, so these methods will
	// get evaluated FIRST then printed to the screen

}

/* EXTRA CHATTER --

  Like always, if this whole class thing doesn't seem "clearer" to you -- drop us an
  email at thetutor@gametutorials.com || digiben@gametutorials.com

  I'd also suggest looking at the first class tutorial to see if that will help %)
*/

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/