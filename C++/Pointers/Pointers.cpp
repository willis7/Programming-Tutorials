//**********************************************************************************//
//																					//
//		- "Talk to me like I'm a 3 year old!" Programming Lessons -					//
//																					//
//		$Author:		Ben Humphrey	digiben@gametutorials.com					//
//																					//
//		$Program:		Pointers												    //
//																					//
//		$Description:	Understanding pointers the simplest way					    //
//																					//
//		$Date:			6/20/00														//
//																					//
//**********************************************************************************//

#include <iostream>										// We do this so we can use "cout"
using namespace std;

void IncreaseNumber(int Number);						// These should probably go in a .h file, 
void IncreaseNumber2(int *Number);						// But I don't want to create a new file for 2 declarations.

void IncreaseNumber(int Number)							// Here is a function that just increases "Number" by 5.
{														// "Number" is a local variable created and assigned the value of the number passed into the function.
	Number += 5;										// Increase the Number by 5.
}														// This didn't touch the number passed in.

														// If we want to change the actual number passed in, we need to give the function the memory address. with a "*"

void IncreaseNumber2(int *Number)						// Here is a function that increases the actual number passed in
{														// Now "Number" is called a "pointer".
	*Number += 5;										// Because "Number" is a memory address, the value of equals something like:
}														// "0x00fffec2"   If we don't put the "*" in front of "Number" it will assign
														// "Number"'s memory address to "0x00000005"  ... Which will SCREW our program up.
														// By putting the "*" in front of "Number" get the actual VALUE held AT the memory address,
														// Which happens to be 0.  Let me show you:
														// "Number += 5"  == "0x00fffec2 += 5"  :  Which equals SCREWED! :)
														// "*Number += 5" == "0 += 5"           :  Which equals 5.
														// (Side Note:  0x00fffec2 is a hexadecimal number which is an offset into memory)
														// (Number doesn't actually equal that number, I just made it up, but that is what an memory address's look like).
														// A little hint on HEX, a = 10, b = 11, c = 12, d = 13, e = 14, f = 15.
														// Letters are used instead of numbers after 9 because 10 and up are 2 digits.  Each slot in HEX means something...
														// 0x10 does not mean 10.  0xa = 10.  Not really important right now, but neat to know when you see HEX :)


void main()												// Start of our program
{														
	int num = 0;										// Declare a integer and set it to 0;

	IncreaseNumber(num);								// Pass num into our first function.

	cout << "Num now equals: " << num << endl << endl;	// Print out the value of num.  You'll notice when the program run's it prints out 0.
														// Num doesn't change at all.

	IncreaseNumber2(&num);								// Now we pass in num to our second function that requires a memory address.
														// We put a "&" in front of "num" to give the function "num"'s memory address.
															
	cout << "Num now equals: " << num << endl << endl;	// Now we print out the value of "num".  It's 5!  See the difference? :)
}


// © 2000-2003 GameTutorials  