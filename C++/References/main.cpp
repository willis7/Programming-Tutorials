// Done by TheTutor -- 06/05/01

/*  References are one of the great things you get with C++ but not with C.
	They act very similar to pointers, but in my opinion are easier to use.
	This tutorial is virtually the same as the "Pointers Part II" tutorial
	except here we're going to use references to achieve our goal.  First in C++ when
	you see the & in a function declaration	it means that function takes a reference to
	a variable, Now remember we wanted to pass in a pointer to a variable so that a 
	function could change it's value.  Well when you pass something as a reference it's
	the same concept, you are passing the address of that variable.  This means if you pass
	something by reference into	a function, that function can change it and when the
	function returns, that variable will remain changed.

	Is that wordy or what?  Anyway lets move on... */

#include <iostream>
using namespace std;

// We want to right a function that takes in two integers and swaps their values
// As you can see there is a right and a wrong way to go about accomplishing this

void swap_wrong(int num1, int num2); 
void swap_correct(int &num1, int &num2); // Passing in references to num1 and num2

// Prints the values of num1 and num2 to the screen on separate lines
void disp_numbers(int num1, int num2);

int main()
{
	int num1 = 52;
	int num2 = 44;

	cout << "Initial values of num1 and num2" << endl;
	disp_numbers(num1,num2);

// This doesn't actually swap the numbers 
	swap_wrong(num1,num2);
	cout << endl << "After calling swap_wrong() on num1 and num2..." << endl;
	disp_numbers(num1,num2);

// This correctly swaps the numbers
	swap_correct(num1,num2);	// Notice we're not doing anything special here --
							    // For the pointer example we had to pass them in like this:  swap_correct(&num1,&num2);
								// But since in our function declaration we specified we were
								// going to pass in the variables by reference, C++ knows to 
								// pass the address of these variables to the function

	cout << endl << "After calling swap_correct() on num1 and num2..." << endl;
	disp_numbers(num1,num2);

		return EXIT_SUCCESS; // Tells the OS that the program exited without any problems
}

void swap_wrong(int num1, int num2)
{
	// The intent of this function is to switch the values of num1 and num2
	// Therefore, first we'll make a temporary number to store num1
	int temp = num1;

	// Now we'll store the value of num2 into num1
	num1 = num2;

	// Finally we'll put num1's value (which is saved in temp) into num2
	num2 = temp;

	/* That should do it -- Except you see when this function returns the values have 
	   remained unchanged.  This is because of a very important aspect of functions.
	   Functions make local copies of the variables they are passed.  When num1 and num2
	   are created by the lines of code:

	   int num1 = 52;
	   int num2 = 44;

	   The program sets aside memory for these two variables.  When the function swap_wrong()
	   gets called a new and different chunk of memory is set aside for temporary copies
	   of num1 and num2.  You can change the values of num1 and num2 anyway you want.  When
	   the function looses scope (returns from the function) those temporary copies of num1
	   and num2 are destroyed.

	   But what if you wanted to change them?  This will be accomplished by swap_correct() */

} // end of swap_wrong(int num1, int num2)

void swap_correct(int &num1, int &num2)
{
	// Look closely -- This function looks IDENTICAL to the one above, except we're passing
	// by reference -- C++ knows that what was passed in was the addresses of these variables
	// and knows that if you assign anything to them, you don't want to change the address
	// of these variables, just the content at the addresses of these variables

	// Again wordy.  But does that make sense?  C++ is a lot smarter than C -- It just says
	// Okay if you pass a variable in by reference to a function and if that function changes
	// it, "save" those changes when the function returns.
	
	int temp = num1;

	// Now we'll store the value of num2 into num1
	num1 = num2;

	// Finally we'll put num1's value (which is saved in temp) into num2
	num2 = temp;

	// That will do it -- num1 and num2 will be swapped.

	// It also good to note that by passing in something by reference (as well as a pointer) 
	// the function DOES NOT make a local copy of the variable -- So if you had a huge
	// structure:

	/*	struct HUGE_STRUCT
		{
			int big_number1, big_number2, big_number3, .... big_number22222;
			
			  // Lots of other variables
		}

	*/

	// Every time you pass that into a function it makes a copy of EVERY member of the
	// structure -- That can eat a ton of CPU time -- But if you pass by reference it'll
	// just pass the address (4 bytes) AND you can treat it like you normally would
	// remembering that if you change a value inside the function, it will remained
	// changed outside of the function (when the function returns)
	// Example:

	/*  HUGE_STRUCT biggy;

		void some_function(HUGE_STRUCT &biggy)
		{
			biggy.big_number1 = 55 * 256 * biggy.big_number2;

			if(biggy.big_number1 > 1000000)
				biggy.big_number1 -= 12;

			// etc, etc, etc....
		}

	*/

	// Hope that makes the concept of references a little bit clearer --
	// I use them a lot so you'll see them again %)

}

// This is a function that prints out the values of num1 and num2 on separate lines
// I knew I'd be printing out the values of these numbers more than once, so instead
// of typing the two cout statements everywhere -- I can now just call this function
void disp_numbers(int num1, int num2)
{
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
}

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/
