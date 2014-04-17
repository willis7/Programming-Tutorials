// Done by TheTutor -- 12/9/01

/*  This tutorial is going to use the STL (Standard Template Library) "Stack" to do some simple
	things.  The STL provides quite a few useful well-tested templates to use in your programs.
	Now because these are templates, there is a speed hit.  So if you ever feel the need to 
	micro optimize one of your programs, replacing STL components with your components will speed
	things up a tad.

	So with that, lets get going...

*/

#include <stack> // This is the header file you use to include the "stack" class found 
				// in the STL

#include <iostream>
using namespace std;

// Okay, in main() we're just going to call methods in the STL's stack implementation
// so you can get a feel of how to use the thing :)
int main()
{
	stack<int> sss; // The stack<int> says "We are making a variable of type stack that will
				   // hold in it integers (int)" -- And of course the highly intuitive name of
				  // of our stack is "sss" :)

	// First we'll check the empty() method -- The empty() method works like this, if the 
	// stack has no elements in it (ie it's empty) empty() returns true, if the stack has 
	// ANY elements in it (ie it's not empty) empty() returns false
	if(sss.empty())
		cout << "Stack is empty, this is correct" << endl;
	else
		cout << "Ahhhh, we have a problem here..." << endl;

	// Now we should really put something on our stack, so we're going to "push" the numbers
	// 0 - 9 onto the stack
	for(int i = 0; i < 10; i++)
		sss.push(i); // Again the push() method works just like you'd expect, it simply
					// pushes 'i' onto the stack

	// Okay we put 10 elements on to the stack, so we'll use the size() method to double
	// check that -- The size() method simply returns the count of elements on the stack
	cout << "The number of elements on the stack are: " << sss.size() << endl;

	// Now lets go ahead and pop everything off of our stack, displaying them as we go
	for(i = 0; i < 10; i++)
	{
		cout << sss.top() << " "; // The top() method displays the "element" (the int in our
								 // case) which is at the top of our stack -- It DOES NOT remove 
							    // this element from the stack -- Pretty straight forward eh?

		sss.pop(); // The method pop() simply removes the element located at the top of the
				  // stack from the stack
	}

	cout << endl << endl; // Some blank lines for fun

	return 0;
}

/*	As you can see the stack is a very straightforward, easy STL template to use.

	So to recap, some benefits of using a STL object are:

	1)  You don't have to worry about the implementation
	2)  You don't have to worry about allocating/freeing memory
	3)  You can use ANY data type with the object

	And again the only "draw back" is that for using all this flexibility and functionality 
	you will pay a slight speed hit (but chances are unless you're doing something very CPU
	intensive you'll never notice).
*/

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/




	
