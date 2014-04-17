// Done by the TheTutor -- 6/20/01

/*

	Okay -- Queues yet another mechanism for orderly storing data --

	As usual all the good stuff is in "queue_class.cpp" and "queue_class.h"
	Here we going to make a QUEUE, insert some elements into it, remove some elements from it,
	and call it a day :)

*/

#include "queue_class.h"
#include <iostream>

using namespace std;

int main()
{
	QUEUE queue(50); // We'll make our queue 50 elements large

	// Let's put the numbers 1 through 10 onto the queue
	for(int i = 0; i <= 10; i++)
		queue.insert(i);

	// Now let's print out the value at the front of the queue and the back of the queue
	cout << "Front of queue = " << queue.front() << endl;
	cout << "Back of queue = " << queue.back() << endl << endl;

	// Remove TWO elements
	queue.remove();
	queue.remove();

	// Now let's print out the value at the front of the queue and the back of the queue
	cout << "Front of queue = " << queue.front() << endl;
	cout << "Back of queue = " << queue.back() << endl << endl;

	// Let's add the numbers 20 - 30 to the queue
	for(i = 20; i <= 30; i++)
		queue.insert(i);

	// Again, let's print out the value at the front of the queue and the back of the queue
	cout << "Front of queue = " << queue.front() << endl;
	cout << "Back of queue = " << queue.back() << endl << endl;

	// Lastly for a sanity check these two statements should print to the screen

	if(queue.isFull() == false)
		cout << "The queue is not full" << endl;

	if(queue.isEmpty() == false)
		cout << "The queue is not empty" << endl;

	// Okay now if implemented correctly we should be able set two QUEUE equal to one another
	// and they'd both have their own dynamic associated with them with ALL the same values
	// Let's try it

	QUEUE second_queue; // Notice the default constructor will make "second_queue" be of max size 10

	second_queue = queue;	// They're equal now

	// Let's print them out to be sure
	while(queue.isEmpty() == false)
	{
		cout << queue.front() << " ";

		queue.remove();
	}

	// Skip a line
	cout << endl << endl;

	// Now print out the second queue
	while(second_queue.isEmpty() == false)
	{
		cout << second_queue.front() << " ";

		second_queue.remove();
	}

	// Skip some more lines for fun
	cout << endl << endl;

		return EXIT_SUCCESS;

} // end of main()

/* Add-On

	Okay a quick example of when a "Queue" might be used in a game.

		Your character gets so far in a cave.  There is a sealed door at the end of the cave
		creatures keep attacking you, one by one, by dropping from the ceiling (they are stored in a queue) --
		When the creatures are defeated (when the queue is empty) the sealed door opens!

*/
	

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/
