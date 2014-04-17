#include "Queue.h"

// The fun part -- Implementing our wonderful creation the QUEUE!

// This will initialzie the queue
bool InitQueue(QUEUE *queue, int size)
{
	// Can't create a QUEUE of negative or zero size
	if(size <= 0)
		return false;
	
	// Create an array of integers as big as the "size" passed in
	queue->array = (int*)malloc(size * sizeof(int));

		// Error Check -- malloc returns NULL if it can not allocate
		//				  the memory we requested
		if(queue->array == NULL)
			return false;

	// Otherwise everything was created successfully so set our two other variables
	// and return true
	queue->max_elements = size;
	queue->index = 0; // Nothing is on the queue

		return true;

} // end of InitQueue(QUEUE *queue, int size)

// This will insert an element on to the BACK of the queue
bool Insert(QUEUE *queue, int num)
{
	// If the queue is full -- We CAN NOT put any more elements in the queue
	if(queue->index == queue->max_elements)
		return false;

	// Fill the queue with "num" that was passed in
	queue->array[queue->index] = num;

	// Move to next OPEN slot in the queue
	queue->index++;

		return true;
}

// Return the FRONT element of the queue (and actually remove it from the queue)
// AND slide the elements on the queue down (so that we have a new FRONT element)
int Remove(QUEUE *queue)
{
	int front = 0; // This is going to hold the front of the queue
	int i = 0; // A counter variable

	// If the queue is empty -- We can't remove anything from it so return the 
	// "default front"
	if(!queue->index)
		return front;

	// Otherwise we want to return the front element of the queue (this is always
	// queue->array[0])
	front = queue->array[0]; // Save off front element

	queue->index--; // Decrease the index, since we're removing an element
				   // the next open slot on the queue will be one less than what it was

	// Now slide everthing down
	for(; i < queue->index; i++)
		queue->array[i] = queue->array[i + 1];

	return front;  // Return the FRONT of the queue

}

// Last but not least, since we're good programmers, we'll free all the memory
// (Assuming of course the client calls our function)
void FreeQueue(QUEUE *queue)
{
	// Incase the client passes in a "bogus queue"
	if(!queue)
		return;

	// If the "array" portion of the queue doesn't have any memory associated
	// with it, we can't free it
	if(!queue->array)
		return;

	free(queue->array);
	memset(queue,0,sizeof(QUEUE)); // Zero out the QUEUE struct
		
}

	 



