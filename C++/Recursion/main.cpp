// Done by TheTutor -- 8/26/01

/*	Okay so what the heck is recursion -- Well it's NOT a C/C++ thing.  Recursion can be
	implemented in "any language" -- Recursion is more of a logical process, that when
	used at the correct times, can help accomplish a task faster and/or with less code.

	Recursion is simply defined as having a function that calls itself inside of the function.
	Did I lose you?  Okay VERY QUICK example of recursion (that happens to go on forever and
	would eventually crash your computer)

	void badRecursion()
	{
		cout << "This will eventually crash" << endl;

		badRecursion();
	}

	As you can hopefully more clearly see now, recursion is nothing more than a function
	that calls itself inside of "the function's" implementation.

	So for a GOOD example of recursion -- We're going to implement a factorial function
	Let's do a quick mathematical example (so we're all on the same page)
	
	First things, the ! symbol (in the math world) means "factorial".  So 3! is read
	"three factorial" -- When you take the factorial of a number you take all the whole numbers
	that precede it (starting at one) and multiply them together.  So...
	
	3! = 1 * 2 * 3 = 6

	Okay lets make our factorial function using recursion.

*/

// Standard include to use cout -- alternative (though older) would be this:
// #include <iostream.h> -- Then you'd have to remove the using namespace std; line
#include <iostream>
using namespace std;

typedef unsigned int uint; // We're lazy so instead of typing unsigned int, we'll just
						  // type uint

// Our killer factorial function
uint factorial(uint num);

// Our main is pretty weak -- It should print out the number 6 and then be done with
// it's bad self
int main()
{
	cout << factorial(3) << endl;

	return 0;
}


// All right this is it -- 
// Let's think about the "definition" of factorial for a second.
// We said 3! = 1 * 2 * 3 -- which is equivalent to 3 * 2! -- We know 1! = 1, so by using
// those simple facts we design our "factorial function" to mimic these properties
uint factorial(uint num)
{
	// Factorial of one is one -- Thus we'll return one
	if(num == 1)
		return 1;

	else
		return num * factorial(num - 1); // Otherwise it's num * the factorial of (num - 1)
}

/*	So lets go through step by step what happens when factorial(3) gets called:

	factorial(3)

	// "num" doesn't equal 1 so we return num * factorial(2) but before 
	// we can return, factorial(2) must return

		factorial(2)

		// "num" doesn't equal 1 so we return num * factorial(1) but before 
		// we can return, factorial(1) must return

			factorial(1)

			// Here num DOES EQUAL 1 so we return 1

		// Now we're back in "factorial(2)" and we're at the line of code
		// "return num * factorial(1)" -- Now remember in factorial(2) "num" EQUALS 2
		// So what we have is num equals 2 and factorial(1) has returned 1 so 
		// the call to factorial(2), returns 2 (The result of 2 * 1)

	// Now we're back in "factorial(3)" and we're at the line of code 
	// "return num * factorial(2)" -- Now remember in factorial(3) "num" EQUALS 3
	// So what we have is num equals 3 and factorial(2) has returned 2 so 
	// we return 6 (The result of 3 * 2)

	// **Remember** every time you call a function you get LOCAL COPIES of the 
	// variable(s) passed in -- That means these "local copies" ARE ONLY KNOWN to that
	// specific function call
*/

// As always, any concerns, comments, criticisms, and tasty chemical concoction recipes can
// be posted at www.GameTutorials.com

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/

	