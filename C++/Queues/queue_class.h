#ifndef QUEUE_CLASS_H
#define QUEUE_CLASS_H

/*	Okay for starters what the heck is a queue?  Well a queue is nothing more than
	a FIFO structure.  FIFO stands for First In First Out --

	So a queue can be thought of as the line at a grocery store. Example:

	Check Out <>	Customer1	Customer2	Customer3	Customer4	Customer5

	In the above queue, Customer1 was first in line (they got their first) so Customer1 
	will be the fist customer to get checked out.  Customer1 would be referred to as the
	front of the queue while Customer5 would be referred to as the back of the queue.

	See, simple.  We're going to implement our own queue class.  Internally (our implementation
	of the queue) we're going to do little to no error checking.  We'll leave that to the client.

*/
					

class QUEUE
{

	public:

		// The constructors -- We're going to overload our constructor so that we can 
		// give the queue any size we want

		QUEUE();	// Default constructor -- This makes our queue of size 10
		QUEUE(int size); // The queue created will be whatever size we pass in

		// The Copy Constructor -- We have dynamic data so we want to make sure it gets
		// handled correctly
		QUEUE(const QUEUE&);

		// Overloading the assignment operator -- Again we have dynamic data so if we set
		// two QUEUES equal to one another WE are responsible for making sure everything gets
		// set correctly
		QUEUE& operator =(const QUEUE&);

		// Returns the integer at the front of the queue -- DOES NOT remove it from the queue
		int front();
		
		int back();	// Returns the integer at the back of the queue -- DOES NOT remove it from the queue

		void insert(int element); // Puts "element" into the queue (in the back of the queue)
		void remove(); // Removes the first element of the queue

		bool isEmpty(); // This will return true when the QUEUE is empty, false otherwise
		bool isFull(); // This will return true when the QUEUE is full, false otherwise

		~QUEUE(); // The deconstructor -- Frees memory associated with QUEUE

	private:

		int *data; // An array to store all the integers in the queue

		int index; // This index will ALWAYS correspond to the next available slot in the queue

		int max_size; // This is the maximum amount of elements that the queue can hold

};


#endif