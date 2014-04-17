// Done by TheTutor -- 12/11/01

/*  This tutorial is going to use the STL (Standard Template Library) "List" to do some simple
	things.  The STL provides quite a few useful well-tested templates to use in your programs.
	Now because these are templates, there is a speed hit.  So if you ever feel the need to 
	micro optimize one of your programs, replacing STL components with your components will speed
	things up a tad.

	**WARNING** This is an advanced tutorial so if you don't feel comfortable with the 
				concepts of a "list" in general, you probably shouldn't be reading this yet

	So with that, lets get going...
*/

#include <list> // This is what you include to use the STL List

#include <iostream> // For cout naturally :)
using namespace std;

#define BLANK_LINES() cout << endl << endl; // Here we make a little macro to print out 
											// two blank lines -- I seem to do this a lot in 
											// the tutorial :)

// Now this main doesn't do anything revolutionary -- We're simply going to create a list
// and call some very common methods, we'll also use and talk about "itertors"
int main()
{
	list<int> numList; // This is our list (for holding a bunch of integers)

	// The first method we'll cover is empty() -- Nothing fancy here, if your list is 
	// empty (has nothing in it) empty() returns true, otherwise (if your list has at least one
	// element) empty() returns false
	if(numList.empty())
		cout << "List is empty, all is good" << endl; // This should get print to the screen
													 // since our list is empty

	// First lets put some numbers in the list
	// Here we're adding the numbers 0 - 9
	// NOTE** every time you push a number on the front of the list it becomes the new 
	// "head" -- So when it's all said and done, numList will look like this:
	// 9 8 7 6 5 4 3 2 1 0
	for(int i = 0; i < 10; i++)
		numList.push_front(i);

	// Now we're going to walk the list -- To do that we're going to use iterators
	// You can think of an iterator as a pointer or reference to an element in your list
	// So just as you would in your own implementation of a list, we're going to get an
	// iterator (pointer) to the first element and walk the list until we reach the last
	// element -- Here's how each line in the for loop breaks down:
	// list<int>::iterator walker = numList.begin(); -- list<int>::iterator walker just
	//													declares an iterator (of type list<int>)
	//													begin() is a "list" method
	//													that returns an iterator to the 
	//													beginning (head) of the list
	// walker != numList.end(); -- This just says "while the walker doesn't equal the end 
	//							   of the list, keep going".  end() is a "list" method that
	//							   returns "one element PAST the end of the list" (so you
	//							   can think of this as the NULL node in a "normal" list 
	//							   implementation)
	// walker++ -- This just increments the walker (it moves it to the next element in 
	//			   the list)
	for(list<int>::iterator walker = numList.begin(); walker != numList.end(); walker++)
		cout << *walker << " "; // The * here is dereferencing the iterator (remember I said
							   // you can think of the iterator as a pointer) so it can be
							  // displayed

	// Okay now you are an iterator guru --
	// If not, don't worry we'll use them again in this tutorial :)

	// Now lets clear out our list
	numList.clear(); // The clear() method makes a list empty

	BLANK_LINES()

	// Now we'll fill it again -- Notice how we're making it FIVE elements larger this time
	for(i = 0; i < 15; i++)
		numList.push_back(i); // push_back() method adds an element to the list at the BACK
							 // of the list -- So our list will look like this:
							// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14

	cout << "Size of list = " << numList.size(); // The size() method just tells you 
												// how many elements are on the list

	BLANK_LINES()

	// Now we'll print out each element of the list AND increment the value of each element
	// in the list just so you see that you can change an element of a list by changing 
	// it's corresponding iterator
	for(walker = numList.begin(); walker != numList.end(); walker++)
		cout << (*walker)++ << " "; // Just like last time we're dereferencing (getting the 
								   // value stored at walker) and printing it to the screen THEN
								  // we're adding one to the value stored at walker

	BLANK_LINES()

	// When we print the list this time, it should go from 1 - 15
	for(walker = numList.begin(); walker != numList.end(); walker++)
		cout << *walker << " ";

	BLANK_LINES()

	// This gives you the front (head) element on the list
	cout << "Front of list = " << numList.front() << endl;
	
	// This gives you the back (tail) element on the list
	cout << "Back of list = " << numList.back(); 

	numList.clear(); // Again totally wipe out the list

	BLANK_LINES()

	// I'm going to cover one more method (that's pretty self-explanatory) but what the heck
	// First we need to create a "random list"
	for(i = 0; i < 10; i++)
		numList.push_front(rand()%1000); // Push on some random numbers

	numList.sort(); // This handy method sorts your list -- So if we had a list
					// of say FRACTION's (that you created) you'd HAVE to overload the
					// '<' operator (less than operator) in the FRACTION class for this to work

	// The list will be ordered from smallest to largest
	for(walker = numList.begin(); walker != numList.end(); walker++)
		cout << *walker << " ";

	BLANK_LINES()

	return 0; // And we're out :)
}

/* Grocery list

  There are MORE methods for the STL list class -- I simply went over the ones I tend to 
  use the most.  Hopefully iterators aren't as intimidating as they might have been

  Also you can make a CONST iterator (so this way you CAN'T change the value in the list through
  the iterator) -- The syntax for making a const iterator (for a list of ints) is:
  list<int>::const_iterator variable_name;

  If you have any questions, feel free to post them at www.GameTutorials.com

*/

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/

