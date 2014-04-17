// Done by TheTutor -- 10/31/01

/*	Templates are one of the wonderful advantages C++ has over C (Can you tell I
    like C++ better?)  In C land lets say we wanted to write a function that took the average
	of two int's -- The function prototype would probably look something like this:
	
	  double average(int num1, int num2);	// Returns the average of num1 and num2

	Now lets say we wanted to do the average of two doubles.  We'd have to come up with a
	completely new name

	double average_double(double num1, double nun2); // Returns the average of num1 and num2

	//////////////////// Well in C++ Land, we can "templatize" functions (in our example
						 the average function) so it will take "any data type" we pass in

	template<class item>
	float average(item num1, item num2);  // With this templatized function we can take the
										 // average of ANY data type (even classes and structs
										// as long as their copy constructors are correct and 
									   // their '+' and '/' operators are overloaded)

	So lets break down the syntax:

	template<class item>
	   |
	   |__ This is the keyword "template", you use this to signify the start of a 
		   templatized function

    template<class item>
			      |
				  |__ The "class" keyword is very different in this context, it simply says 
					  "the next term (in this case "item") is going to refer to a generic
					  data type that can take on "any data type" (if you understand the concept
					  of void pointers, this is very similar).  So we could of written our
					  templatized function declaration like this:

					  template<class arbVar> float average<arbVar num1, arbVar num2);

					  First off all, the function declaration can be on one line (or two, 
					  your choice) and as you can see "item" is just a name we select.
					  Once we've selected our "data type" (ie "item" from the first example)
					  We simply declare any input parameter (or return parameter) of the
					  function with that "data type" that we want to be generic (ie able to
					  be any valid data type)

	Whoa!  Hope that wasn't too confusing.  It's real easy.  After taking a look at this
	simple program hopefully templates will make perfect sense :)

*/

#include <iostream>
using namespace std;

// Here we're making a template average function -- It will return a "double" and take
// two variables of type "item" (where a variable of type "item" means ANY VARIABLE TYPE)

template<class item>
double average(item num1, item num2);

int main()
{

	double answer = 0.0; // Variable for holding the answers from the average functions

	// Two "float" variable types to pass into our templatized average function
	// When declaring a type "float" you put the 'f' after it, otherwise the compiler (VC++)
	// assumes it is of type "double" (you'll probably get a warning)
	float x = 3.5f; 
	float y = 7.9f; 

	// Print out the average of two "ints"
	answer = average(43, 24);
	cout << "The average of the integers 43 and 24 = " << answer << endl << endl;

	// Print out the average of two "doubles"
	answer = average(23.2, 62.33);
	cout << "The average of the doubles 23.2 and 62.33 = " << answer << endl << endl;

	// Print out the average of two "floats"
	answer = average(x, y);
	cout << "The average of the floats " << x << " and " << y << " = " 
		 << answer << endl << endl;

		return EXIT_SUCCESS; // EXIT_SUCCESS is just #defined to be 0 so you could
							// replace EXIT_SUCCESS with zero if you wanted

}

// Returns the average of two "items" (Again "item" can be any valid data type)
template<class item>
double average(item num1, item num2)
{
	return (num1 + num2) / 2.0; // We divide by 2.0 because we want to insure that
							   // "double division" takes place as opposed to "int division"
}

// Well that's templates -- Any questions, be sure to post 'em at www.GameTutorials.com

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/