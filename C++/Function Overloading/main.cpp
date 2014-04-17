// Done by TheTutor -- 06/10/01

#include <iostream>

using namespace std;

/*	Function overloading is one of the wonderful advantages C++ has over C (Can you tell I
    like C++ better?)  In C land lets say we wanted to write a function that took the average
	of two int's -- The function prototype would probably look something like this:
	
	  float average(int num1, int num2);	// Returns the average of num1 and num2

	Now lets say we wanted to do the average of two doubles.  We'd have to come up with a
	whole new name

	float average_double(double num1, double nun2); // Returns the average of num1 and num2

	//////////////////// Well in C++ Land, function overloading is supported so that means

	double average(int num1, int num2);
	double average(double nun1, double num2);

	Equate to DIFFERENT functions -- You can have as many functions as you want named "average"
	so long as the variable types (int, double, etc) are different or there is a different
	number of variables passed in.

	So 

	double average(int num1, int num2);				is known to be different than
	double average(int num1, int num2, int num3);

	That's it -- It's really quite simple -- Here we'll overload the "average" function just
	to show that I'm not lying!

	*/

double average(int num1, int num2);	// Returns the average of two integers

double average(double num1, double num2); // Returns the average of two doubles

double average(int num1, int num2, int num3); // Returns the average of three integers

int main()
{

	double answer = 0.0; // Variable for holding the answers from the average functions

	// Print out the average of two integers
	answer = average(43, 24);
	cout << "The average of the integers 43 and 24 = " << answer << endl << endl;

	// Print out the average of two doubles
	answer = average(23.2, 62.33);
	cout << "The average of the doubles 23.2 and 62.33 = " << answer << endl << endl;

	// Print out the average of three integers
	answer = average(2, 22, 222);
	cout << "The average of the integers 2, 22, 222 = " << answer << endl << endl;

		return EXIT_SUCCESS;

}

// Returns the average of two integers
double average(int num1, int num2)
{
	return (num1 + num2) / 2;
}

// Returns the average of two doubles
double average(double num1, double num2)
{
	return (num1 + num2) / 2;
}

// Returns the average of three integers
double average(int num1, int num2, int num3)
{
	return (num1 + num2 + num3) / 3;
}

/*	Add On +++++++++++++++

  Here is an example of function overloading that WILL NOT WORK!!!!

  double ave(int num1, int num2);
  int ave(int num1, int num2);

  Functions that are overloaded CAN NOT only differ by RETURN TYPE!

  Well I think that's it -- Soon we'll talk about templatized functions -- These puppies are
  really powerful and handy --

*/


/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/