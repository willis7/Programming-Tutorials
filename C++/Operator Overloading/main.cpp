// Done by TheTutor -- 7/8/01

/*	Operator Overloading --

		This real isn't too difficult of a concept it's just the code looks a little 
		"funky" so it tends to intimidate people -- All operator overloading is trying
		to accomplish is that in our main() (or other .cpps) we want to be able treat
		user defined structs/classes as we would treat atomic data types (int, double, float, etc)

		So if I have float num1 = 3.4;
					 float num2 = 7.6666;

					float answer = 0.0;

					// You wouldn't even blink at the line of code
					answer = num1 + num2;
					
		Now we'll be able to make our own structs/classes and do that exact same type of thing
		Make sense??? Well you know where to go if you have questions :)
		(That's www.GameTutorials.com in case you forgot)

*/

				

#include "Vector.h"
#include <iostream>

using namespace std;

// We're just going to make a couple VECTORs and use 'em to illustrate operator overloading :)
int main()
{
	VECTOR vec1(5,5);
	VECTOR vec2(3,3);

	VECTOR answer;

	// Display the 3 VECTORs initial values
	cout << "vec1 = " << vec1 << endl;
	cout << "vec2 = " << vec2 << endl;
	cout << "answer = " << answer << endl;

	cout << endl << endl; // Blank lines

	// Display the 3 VECTORs values after adding vec1 to vec2 storing the result
	// in answer
	answer = vec1 + vec2;

	cout << "vec1 = " << vec1 << endl;
	cout << "vec2 = " << vec2 << endl;
	cout << "answer = " << answer << endl;

	cout << endl << endl; // Blank lines

	// Display the 3 VECTORs values after subtracting vec1 to vec2 storing the result
	// in answer
	answer = vec1 - vec2;

	cout << "vec1 = " << vec1 << endl;
	cout << "vec2 = " << vec2 << endl;
	cout << "answer = " << answer << endl;

	// Lastly set vec1 equal to vec2 and display the two
	vec1 = vec2;

	cout << endl << "Setting vec1 = vec2" << endl;
	cout << "vec1 = " << vec1 << endl;
	cout << "vec2 = " << vec2 << endl;
	
	return 0;
}

// Well I hope Operator Overloading is a tad more clear -- Don't sweat the "friend" concept
// too much -- If it doesn't make sense right now, it will later, I swear :)

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/