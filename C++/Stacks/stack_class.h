#ifndef STACK_CLASS_H
#define STACK_CLASS_H

#include <iostream>

using namespace std;

/* First off, what is a stack?  Well a stack is a LIFO based "container".  Yeah,
okay but what is that?

  LIFO stands for Last In First Out -- So a stack is nothing more than "something" that has
  this property --

  A perfect example is a stack of dishes.

  plate5		-- Here plate5 was added LAST to the STACK of dishes
  plate4		   Yet, when it comes time to wash them, plate5 will be
  plate3		   the FIRST to be washed (removed).  Once plate5 is removed, plate4 will
  plate2		   have the status of "being the last plate added to the stack", so it will
  plate1		   be the next dish to be washed (removed).  Etc, etc, etc...

  // Make sense?  Now when related back to programming, a stack is a LIFO based arrangement
  of data (variables)

  // There are multiple ways you can represent a stack but we're going to
     use an array to do it --

*/

class STACK
{
	public:

		// The constructors -- We're going to overload the constructor so we can specify
		// a size -- Otherwise we'll give our stack the default size of 10 elements
		STACK();
		STACK(int size);

		// The copy constructor -- Since we're using dynamic data, we have to make sure 
		// we copy the stack correctly when passing it into a function.
		STACK(const STACK&);

		// Push an element (an integer) onto the top of the stack
		// If an error is occurred, the "error_flag" is set to true
		void Push(int element);

		void Pop(); // Removes the top element.  We can now put a new element in it's place.
					// If an error is occurred, the "error_flag" is set to true

		/* Okay what we are doing here is returning the value of the integer
		   located at the top of the stack.
		   So if our stack looked this:		16
											22
											33
		   By calling Top(), the method would return 16
		   If the stack is empty, Top() returns -1 and "error_flag" is set to true */
		int Top();

		bool Error(); // This function will return true if the "error_flag" has been set to true
					  // false if the "error_flag" is set to false -- Calling Error() sets the 
					  // "error_flag" to false -- 

		~STACK();	// The Deconstructor

	private:

		int *array; // This is the pointer that will hold our stack of integers

		int max_size; // This is the max size (maximum number of elements) that can be 
					  // on our stack

		int index; /* "index" is an index into "array" at the next OPEN slot in the stack
					  so if our stack looked like this:

						32 // value of int ------ [2] // array index 
						16 // value of int ------ [1] // array index
						21 // value of int -------[0] // array index

					  index would equal 3 (next open spot in array)		*/

		bool error_flag; // This is the flag that, if an error occurs, will be set
						// to true, otherwise will equal false

};

#endif



			   