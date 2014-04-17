#include "stack_class.h"

// Our default constructor -- We'll make a default stack have 10 elements in it
STACK::STACK()
{
	max_size = 10; // Max # of elements
	index = 0; // Zero is the first "open slot" in the stack

	array = new int[max_size];

		// Error Check
		if(array == NULL)	// We couldn't dynamically allocate memory
			error_flag = true;
	
	// Let's initialize the array to '0'
	for(int i = 0; i < max_size; i++)
		array[i] = 0;

	error_flag = false; // We we're successful!
}

// This constructor allows a user of our stack to pass in a size for the stack
STACK::STACK(int size)
{
	max_size = size;	// Max # of elements on our stack
	index = 0;	// Zero is first "open slot" in the stack

	array = new int[max_size];

		// Error Check
		if(array == NULL)		// We couldn't dynamically allocate memory
			error_flag = true;
		else
			error_flag = false;	// Yeah buddy!  We we're successful

}

// Copy Constructor 
STACK::STACK(const STACK &stack)
{
	// Copy "max_size" and "index" from "stack"
	max_size = stack.max_size;
	index = stack.index;
	
	array = new int[max_size];

		// Error Check
		if(array == NULL)	// No dynamic memory for us -- ERROR
		{
			error_flag = true;
			return;
		}
		else				// Set error_flag to "stack's" error flag
			error_flag = stack.error_flag;

	// Copy the array of integers in "stack"
	for(int i = 0; i < max_size; i++)
		array[i] = stack.array[i];

}

// Push places "element" on the TOP of the stack
void STACK::Push(int element)
{
	// If the stack is already full, we can't push an new element onto it
	// Set the error flag and return
	if(index == max_size)
	{
		error_flag = true;
		return;
	}

	array[index] = element;	// Fill the "open slot" in the stack with element

	index++; // Now element is pointing to the next open slot
}

// Pop removes the integer (element) at the TOP of the stack
void STACK::Pop()
{
	// The stack is already empty if index equals zero, so set the error flag
	// and return
	if(!index)
	{
		error_flag = true;
		return;
	}

	index--;	// Simply move the index back one, effectively "removing" the TOP
				// of the stack -- If a Push() is called immediately after a Pop()
				// whatever integer that was at the TOP of the stack will be written over
}


// Returns the top element of the stack
// This does NOT remove the from the stack
int STACK::Top()
{
	// The stack is empty if index equals zero, so there IS NOT a top element
	// Set the error flag and return -1
	if(!index)
	{
		error_flag = true;
		return -1;
	}

	
	// Remember "index" equals the next OPEN (not-filled) slot so 
	// we want (index - 1) for the "last filled slot" (top of stack)
	return array[index - 1]; 

}

// If the "error_flag" has been set -- Return true and set it back to false
// Otherwise the "error_flag" still equals false, so return false
bool STACK::Error()
{
	if(error_flag == true)
	{
		error_flag = false;
		return true;
	}

	return false;
}

// The Deconstructor -- Free the memory associated with STACK
STACK::~STACK()
{
	delete[] array;
	array = NULL;
}




