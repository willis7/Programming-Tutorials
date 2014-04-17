#ifndef POINT_CLASS_H
#define POINT_CLASS_H

/* Okay now we're going to expand our knowledge of classes a bit.

  First lets name the four methods you ALWAYS get when making a class

  Constructor
  Copy Constructor
  Assignment_Operator
  Deconstructor

     In the "Class" tutorial we defined one method Swap() -- But these four methods we're
	 also given to us "behind the scenes" -- However, we can decide how each of these
	 methods is going to operate (if we want) -- For this tutorial we're going to define
	 and implement the Constructor, We'll leave the rest for yet another class tutorial.
	 For now the default Copy Constructor, Assignment Operator and Deconstructor work fine
	 anyway.
*/

class CPOINT // Cartesian Point
{
	// I said I'd explain the public thing so here goes -- Anything that is public
	// is accessible by a client (a client being main.cpp or any other .cpp file you have
	//							  in your project)
	// So that means I can call any method or set any variable that is defined publicly
	// Read the private explanation, and hopefully this whole public/private thing will become clear
	public: 
		
		// This is a constructor -- 
		// IT IS ALWAYS NAMED LIKE THIS (the method name is the same as your class name)
		// A constructor that takes no arguments is called THE DEFAULT CONSTRUCTOR
		CPOINT();

		// Constructor's can be overloaded and take arguements (just like functions in C++)
		CPOINT(int X_value, int Y_value);

		void Swap(); // Looks a lot like a function (and really it is) but "functions" that
				     // are inside of classes are referred to as "methods"

		// After reading the description of what "private:" is -- You know we CANNOT change
		// x and y directly (as we did in the "Class Tutorial" -- So we going to create a 
		// public method, so that we CAN change these variables
		void setPoint(int new_x, int new_y);
		
		/*  Again we can't get at x or y from main.cpp -- So how are we going to get
		    their values???  Simple, we'll make data access functions -- 
			getX() will return the current value of x --
			getY() will return the current value of y */
		int getX();
		int getY();


	/* Okay if a method or variable is private it CAN ONLY BE ACCESED BY THE CLASS
	   This means when we are writing the code that implements this classes methods,
	   we can change these variables (or call private methods if we had any)
	   From main.cpp WE CANNOT change these variables directly (I have a commented out
	   piece of code in main.cpp that tries -- When you remove the comments you get a
	   compiler error)
	*/
	private:

		int x;
		int y;
};


#endif