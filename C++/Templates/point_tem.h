#ifndef POINT_TEM_H
#define POINT_TEM_H

// Here is our templated class -- As you can see it's REALLY SIMPLE (the operator+ is the 
// only thing that looks a little menacing :)
// Lets go over this syntax once again

// Okay you see the keyword "template" -- This says we're doing a templated class (or function)
// Directly after "template" you see <class item> -- This says, "The name of our generic
// data type, that can become ANY data type is "item".  So when you want variables to 
// be of this generic data type we will declare them as type "item".
template <class item>
class POINT
{
	public:

		POINT(); // Default constructor

		// Copy constructor
		// Notice how we define the variables being passed in
		// as type "item" -- This really is no different than if 
		// we were defining them as type "int" for example
		POINT(item x_val, item y_val, item z_val);

		// Same thing here, everywhere we want a "generic, can be anything variable"
		// we use the keyword "item" (which is what we defined at the top of the class)
		void set(item x_val, item y_val, item z_val);

		// Now here's slightly different syntax -- You'll notice that for
		// the RETURN variable we HAVE to put the class name and our 
		// templated variable name in angled brackets -- But for the input parameter(s)
		// to the function, we ONLY use POINT (just like normal)
		// **NOTE** For those who are not completely fluent with the overloading of operators
		//			All this does is allow us to write code like this:
		//			ccc = aaa + bbb;
		//			Where aaa, bbb, and ccc are all of type POINT<item>
		POINT<item> operator +(const POINT&);
	
		// This is our data
		item x;
		item y;
		item z;
};


// And now the implementation part ---

// First we'll do the good old default constructor
// For EVERY method you implement you will HAVE to start with the 
// EXACT same syntax you declared your class with
template <class item> // See it's the same as above the class declaration
POINT<item>::POINT()
{
	// Now if this WAS NOT a templated class, the syntax would look like this:
	//
	// POINT::POINT()
	//
	// So you see how you HAVE to add the <item> BEFORE the scope resolution operator
	// **NOTE** the scope resolution operator equals :: (double colon's)

	// Lets default to zero
	x = 0;
	y = 0;
	z = 0;
}

// Okay now it's the overloaded constructor
// Again we HAVE to start out with the "template syntax"
template <class item>
POINT<item>::POINT(item x_val, item y_val, item z_val)
{
	// As you can syntax looks similar to the default constructor

	x = x_val;
	y = y_val;
	z = z_val;
}

// Okay next, we'll implement the set function.  Guess what syntax goes first?
template <class item>
void POINT<item>::set(item x_val, item y_val, item z_val)
{
	// Notice here that first (like usual) is the return type of the function
	// After that the "pattern" remains the same:
	// void POINT<item>::set(item x_val, item y_val, item z_val)
	//	|	 |     |      |
	//	|	 |     |	  |__ Name of function
	//	|	 |	   |
	//	|	 |	   |__ Name of templated data type we declared
	//	|	 |
	//	|	 |__ Name of class
	//  |
	//  |__ Return type

	x = x_val;
	y = y_val;
	z = z_val;
}

// Last but not least, we'll implement the overloaded + operator
template <class item>
POINT<item> POINT<item>::operator +(const POINT &point)
{

	// Notice there's slightly different syntax:
	// 
	// POINT<item> POINT<item>::operator +(const POINT&)
	//	|			|     |       |				  |
	//	|			|	  |		  |				  |__ Input parameter DOES NOT include
	//	|			|     |		  |					  templatized variable type
	//	|			|	  |		  |
	//	|			|	  |		  |__ Name of the function (yes "operator +" can be
	//	|			|	  |			  thought of as the name of a function)
	//	|			|	  |			 
	//	|			|	  |__ Name of templated data type we declared
	//	|			|
	//	|			|
	//	|			|__ Name of class
	//  |
	//	|
	//  |__ Return type.  MUST include templatized variable type
	//
	
	// Now here's the next (and last) piece of syntax knowledge
	// When you declare a temporary variable of your templated class
	// inside of a function in your templated class (like we are doing here)
	// you DO NOT use the angled brackets/templated variable name (the <item> in our case)
	POINT answer;

	// Calculate our answer
	answer.x = x + point.x;
	answer.y = y + point.y;
	answer.z = z + point.z;
		return answer;
}

#endif