#ifndef VECTOR_H
#define VECTOR_H

/* Operator Overloading -- 

	Well operator overloading is pretty much just like it sounds.  It's a concept that 
	allows you to take established operators (+ for example) and have these operators work
	normally on user defined objects (classes/structs)

	So what we going to do is make a class called VECTOR -- This class will embody a vector
	just as it would be found in math.  If you don't know what a vector is ask 
	your math teacher :)

	Then we're going to overload the assignment '=', the addition '+' and
	the subtraction '-' operators so that if we had

	VECTOR aaa AND VECTOR bbb -- The following code would work:

	VECTOR ccc = aaa - bbb;

	We're also going to overload the "cout" operator though it's a little different then you
	may expect -- But if I have VECTOR vec1;
	I want to be able to write:
	cout << vec1 << endl;
	and have it print the value of "vec1" -- So we're going to overload the '<<' (yes I know
	just a few lines above I said "cout" but this how we'll get cout << vec1 << endl; to work)

	I find operator overloading is quite useful (and it's essential that you overload the 
	assignment operator if you class contains dynamic data)

*/

#include <fstream>
using namespace std;

// Our vector class
class VECTOR
{
	public:
		
		// Our constructor -- It just initializes our vector to zero
		VECTOR():x(0),y(0) { /* do nothing */ }

		// An overloaded constructor -- This sets our vector to the x_val and y_val passed in
		VECTOR(int x_val, int y_val):x(x_val),y(y_val) { /* do nothing */ }

		// This is our assignment operator -- For this example we could actually not
		// define one and we'd still be able to set to VECTORs equal to one another
		// (Remember you ALWAYS get an overloaded assignment operator when defining a class)
		// But we're going to define it ourselves for practice :)
		VECTOR& operator =(const VECTOR&);

		// This is our overloaded addition operator -- This will allow us to add two vectors
		// the same way we would add two ints in code
		// example:
		// int a = 5; int b = 6;   ----- You'll now be able to also say VECTOR a(2,2);
		// int c = a + b;												VECTOR b(3,3);
		//																VECTOR c = a + b;
		VECTOR operator +(const VECTOR&);
		
		// This is our overloaded subtraction operator -- This will allow us to subtract two vectors
		// the same way we would subtract two ints in code
		// example:
		// int a = 5; int b = 6;   ----- You'll now be able to also say VECTOR a(2,2);
		// int c = a - b;												VECTOR b(3,3);
		//																VECTOR c = a - b;
		VECTOR operator -(const VECTOR&);

		// Holly Tabernacle does that look ugly -- But trust me it's not that bad
		// Okay I opened a whole can of worms by introducing the keyword "friend"
		// but for now I'm going to skate by not defining "friend" to intensely and simply
		// saying friend functions (which is what we are defining) can access a classes'
		// private variables -- As for the return value "ostream&" -- Well an ostream is 
		// simply an "output stream" -- cout is an example of an output stream
		// So what basically is going to happen is this:  The output stream "cout" will get passed
		// into the function when we write "cout << vec1 < endl;"
		// What will return is an output stream filled with the text of what we want
		// I know it's wordy but hopefully the actual code will clear it up more :)
		friend ostream& operator <<(ostream&, const VECTOR&);

	private:

		int x; // X component of our vector
		int y; // Y component of our vector

};



#endif