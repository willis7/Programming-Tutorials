#include "stack.h"

// The fun part -- Implementing our wonderful creation the STACK!

bool InitStack(STACK *stack, int size)
{
	// Can't create a STACK of negative or zero size
	if(size <= 0)
		return false;
	
	// Create an array of integers as big as the "size" passed in
	stack->array = (int*)malloc(size * sizeof(int));

		// Error Check -- malloc returns NULL if it can not allocate
		//				  the memory we requested
		if(stack->array == NULL)
			return false;

	// Otherwise everything was created successfully so set our two other variables
	// and return true
	stack->max_elements = size;
	stack->index = 0; // Nothing is on the stack

		return true;

} // end of InitStack(STACK *stack, int size)

bool Push(STACK *stack, int num)
{
	// If the stack is full -- We CAN NOT push anything on to it
	if(stack->index == stack->max_elements)
		return false;

	// Fill the stack with "num" that was passed in
	stack->array[stack->index] = num;

	// Move to next OPEN slot in the stack
	stack->index++;

		return true;
}

// Return the top element of the stack and remove it from the stack
int Pop(STACK *stack)
{
	// If the stack is empty -- We can't pop anything of it so by default we're going
	// to return zero
	if(!stack->index)
		return 0;

	// Otherwise we want to return the top element of the stack and remove it from
	// the stack

	stack->index--; // Move to the top element, also index will now correctly correspond
					// to the next OPEN slot in the stack

	return stack->array[stack->index];  // The TOP of the stack

}

// Last but not least, since we're good programmers, we'll free all the memory
// (Assuming of course the client calls our function)
bool FreeStack(STACK *stack)
{
	// CAN NOT free a "stack" that doesn't point to anything (has no memory associated with it)
	if(!stack)
		return false;

	// Same idea -- If the "array" portion of the stack doesn't have any memory associated
	// with it, we can't free it
	if(!stack->array)
		return false;

	free(stack->array);
	memset(stack,0,sizeof(STACK)); // Zero out the stack
		
		return true; // We freed the memory!
}

	 



