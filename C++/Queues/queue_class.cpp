#include "queue_class.h"

// Default Constructor
QUEUE::QUEUE()
{
	index = 0; // No elements in queue
	max_size = 10; // Default size of our queue

	data = new int[max_size];

	// Set the entire queue to equal zero
	for(int i = 0; i < max_size; i++)
		data[i] = 0;
	
}

// Constructor -- This will set the size of the queue to whatever is passed in
QUEUE::QUEUE(int size)
{
	index = 0; // No elements in queue
	max_size = size; // The maximum size of our queue

	data = new int[max_size];

	// Set the entire queue to equal zero
	for(int i = 0; i < max_size; i++)
		data[i] = 0;

}

// The Copy Constructor
// We have dynamic data so we must be sure it gets copied correctly
QUEUE::QUEUE(const QUEUE &qqq)
{
	index = qqq.index; // Set the index to be the same
	max_size = qqq.max_size; // Set the max_size to be the same

	data = new int[max_size]; // Create the memory needed to store the integers in the queue

	// Now copy over each entry in the queue
	for(int i = 0; i < max_size; i++)
		data[i] = qqq.data[i];
}


// We have dynamic data so when we set two QUEUES equal to one another we want to make sure
// sure each QUEUE has a copy of the dynamic data (similar to the copy constructor)
QUEUE& QUEUE::operator =(const QUEUE &qqq)
{
	delete[] data; // First delete any data associated with the QUEUE
	
	data = new int[qqq.max_size]; // Create the new memory

	// Set "index" and "max_size" to qqq's index and max_size
	index = qqq.index;
	max_size = qqq.max_size;

	// Copy over the data
	for(int i = 0; i < max_size; i++)
		data[i] = qqq.data[i];
	
		return *this;	// If you're not familiar with the "this pointer" you can overlook
						// the "this pointer" tutorial :)
}

// Returns the front of the queue which we'll always be data[0]
int QUEUE::front() { return data[0]; }

// Returns the back of the queue -- 
// Remember that index ALWAYS will point to the next open spot in the queue so
// the back of the queue is always index - 1
int QUEUE::back() { return data[index - 1]; }

// We want to insert an element in to the queue --
// Insertion is always done at the back (don't even go there :] )
void QUEUE::insert(int element)
{
	data[index] = element; // index points to the NEXT open slot so we'll fill it with "element"

	index++; // Move "index" to the next open slot

}

// This takes the element at the front and removes it -- 
// By removing it, we must move everything else down
void QUEUE::remove()
{
	int size = max_size - 1; // We need one less than "max_size"

	// Since we terminating the for loop by the condition "i < size" we won't overrun the array "data"
	for(int i = 0; i < size; i++)
		data[i] = data[i + 1];

	/* Here's what we're doing

	data[0]'s value will be gone

	data[0] will now equal data[1]
	data[1] will now equal data[2]
	data[2] will now equal data[3]
	etc, etc...

	*/

	index--; // The next open spot is now one less than what it used to be

}

// This returns true if the QUEUE is empty -- otherwise false
bool QUEUE::isEmpty() { return !index; }	// Does this make sense?  If index equals 0 the queue is empty
											//						  !0 equals true -- Otherwise index will be a
											//						  positive number (say 4) and !4 equals false

bool QUEUE::isFull() { return (index == max_size); } // Again if this conditional statment is true,
													 // the return value will be true -- if this
													 // conditional statement is false, the return value will be false

// The Deconstructor -- Frees memory
QUEUE::~QUEUE() { delete[] data; }


