// Done by TheTutor -- 5/6/02

// Say for instance you wanted to create a POINT class (which is what we do 
// by the way).  Now sometimes you want the (x,y,z) of the POINT class to be of type int.
// Other times you want the (x,y,z) of the POINT class to be of type float, and even 
// some other times of type double.  Wouldn't it be handy if you could just write ONE
// class that handled all of your needs???
//
// Well with C++ template classes you can do just that.  This tutorial is all about C++
// templated classes -- What we are going to do is write a SIMPLE templated class
// named "POINT".  But before we get to the code, here's a list of some templated class
// facts:

// 1)	Will start with the syntax.  Every templated class prototype/implementation
//		starts off looking something like this:
//
//		template <class T>
//		
//		So lets break this down:
//	
//		template <class T>
//		  |
//		  |
//		  --- This is the keyword "template".  This says, "Hey whatever follows is going
//			  to be a template."
//
//		template <class T>
//				   |
//				   |
//				   --- This is the keyword "class".  THIS DOES NOT MEAN THE USUAL C++ CLASS
//					   Every time you create a templatized "something", (whether it's just
//					   one single function, or a class) you use this keyword "class".
//					   This simply signifies that the next "variable" is going to 
//					   be the user defined name of the "templated variable".  Wordy yes, but
//					   just roll with me :)
//
//		template <class T>
//					    |
//						|
//						--- Last but not least this is the user defined "templatized data type"
//							'T' is the industry standard (well at least that's what the Standard
//							Template Library uses).  All this really is, is a name for the 
//							"new templatized/generic data type" that will be used by
//							the class.  This "new templatized/generic data type" can be ANYTHING
//							(examples:  int, float, double, *some class/struct you make*, etc)
//							You say what generic data type you want to use when you declare 
//							a variable of your templated class
//
//		And yes the <>'s are part of the syntax and must be there.

// 2)	Templates MUST be implemented in the header file.  Now if you want to get crazy technical
//		this statement isn't 100% true, but for the sake of simplicity we're gonna say
//		that templated classes MUST be implemented in the header file they are 
//		defined in.

// 3)	If a templated class has a function that is NEVER used, it will NOT be 
//		compiled.  So when you are writing your own templated classes it's imperative
//		that you also write a test app, and test out ALL of your classes functions.

// Lost yet?  It's pretty wordy stuff, because templated classes are so general so don't 
// sweat it if you are.  A good long look at the implementation and all should become 
// clear %)

#include "point_tem.h"
#include <iostream>
using namespace std;


// Remember if you DO NOT call a function inside of your templated class it WILL NOT
// be compiled.  Thus main() calls all the functions just to make sure they work.
int main()
{
	// Notice the syntax when you declare a instance of type POINT
	// First comes the class name POINT
	// Second, in-between the angled brackets, comes the variable type you
	// wish to have the POINT class take on
	// Third comes the user defined variable name
	// So you can think of it like this:  When you declare a templated class, whatever
	// you put between the <>'s will get substituted in your class everywhere "item" (or
	// whatever you might happen to name it) shows up.
	// Thus for this declaration:  POINT<int> p1;
    // the x, y, and z of p1 will all be of type int.

	POINT<int> p1; // Use the default constructor
	POINT<int> p2(2,3,4); // Use the overloaded constructor

	// Use the "set" function
	p1.set(5,5,5);

	POINT<int> p3 = p1 + p2; // Use the overloaded + operator

	// For fun print out the result
	cout << p3.x << " " << p3.y << " " << p3.z << endl;
		return 0;
}

// Some quick facts summed up in a nice easy to read template:

/*
	1)  In general you the first line for declaring a templated class and all the functions in
		in the templated class are like so:

		template<class YOUR_VARIABLE_NAME>

		YOUR_VARIABLE_NAME could equal pretty much anything.  
		Some examples are: item, T (this is pretty standard), genVar, cookieMonster, etc

	2)	Templated classes MUST be implemented in the same .h file in which they are defined

	3)	If you DO NOT call a function in your program, that is in your templated 
		class, it WILL NOT be compiled

	4)  When returning a variable from a function, that is of the templated class type
		you use this syntax:

		CLASS_NAME<templateVarName> // Return type

		When passing in a variable into a templated class function OR
		declaring a variable inside a templated class function that is of the
		templated class type you use "normal" syntax:

		CLASS_NAME yourVariable // Parameter to function OR variable declaration
							    // inside of templated class

*/

// Hopefully you learned a good deal about templates.  As always
// post your questions and comments at www.GameTutorials.com

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/



