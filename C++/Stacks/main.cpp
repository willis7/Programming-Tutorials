// Done by TheTutor -- 06/10/01

// Lets not stack this opening with too much fluff!
// Explanation for what is going on lies in "stack_class.h" and "stack_class.cpp"
// Below we'll use the stack class to make sure it indeed does what we intended

#include "stack_class.h"

/* Remember we #include <iostream> in "stack_class.h" so we DON'T have to re-include it here */

int main()
{
	STACK stack; // Default constructor is called -- Our stack will be "10 elements big"

		// Something VERY, VERY bad happened
		if(stack.Error())
			return EXIT_FAILURE;

	// Let's push some integers (0 - 4) on the stack
	for(int i = 0; i < 5; i++)
		stack.Push(i);

	// Okay let's push one more element on the stack
	stack.Push(22);

	// If you uncomment the two lines of code of below, will that statement be printed?
	// Ponder that question, come to an answer and see if you are correct!  Then
	// try changing the '5' in the for loop a few lines above to '500'.  Will it print then?
	//if(stack.Error())
	//	cout << "Hey buddy!  You've pushed your limit!" << endl << endl;

	// Let's print out the top element of the stack ------
	cout << "The top element is: " << stack.Top() << endl << endl;
	
	// All right you should be able to uncomment the code below and know what is
	// going to be printed out -- I'll throw you off and say it's not going to be
	// as straight forward as you think :) -- 
	/*for(i = 0; i < 5; i++)
	{
		cout << "The top element is: " << stack.Top() << endl;
	
		stack.Pop();
	}*/

		return EXIT_SUCCESS;

} // end of main()

/* EXPANSION PACK ---------

  Okay the way we did "Error Checking" in our stack class is just ONE possible way to do it
  You really need to see what is going to work best for your project --

  Another very common technique is to NOT DO error checking inside of STACK -- We'd let
  the client (user's of our stack) error check for themselves.  If we were to use this
  method we could do away with the Error() method and all the checks inside of Push(), Pop()
  and Top() -- But we'd have to supply the client a way to do error checking -- This would
  be accomplished by supplying two additional methods isEmpty() and isFull() (or whatever you
  want to name them).

  isEmpty() would return true if the stack was empty, false otherwise.
  isFull() would return true if the stack was full, false otherwise

*/

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/

