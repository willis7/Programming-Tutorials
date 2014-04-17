//**********************************************************************************//
//																					//
//		- "Talk to me like I'm a 3 year old!" Programming Lessons -					//
//																					//
//		$Author:		Ben Humphrey	digiben@gametutorials.com					//
//																					//
//		$Program:		ReadingFiles											    //
//																					//
//		$Description:	This gives several ways to read from a file				    //
//																					//
//		$Date:			6/20/00														//
//																					//
//**********************************************************************************//

#include <iostream>										// Include our standard header
#include <string>										// Include this to use strings
#include <fstream>										// Include this to use file streams
using namespace std;									// set our namespace to standard;

void main()												// A standard and plain main (hey! that rhymed!) :)
{														// Start of our program
	ifstream fin;										// Here we create an fstream and we will call it "fin", like "cin".
	string szLine = "";									// Lets create a string to hold a line of text from the file.
	string szWord = "";									// This will hold a word of text.
	string szName = "";									// This will hold the players name.
	int health=0, gold = 0;								// We will read in the players health and gold from a file
														
	fin.open("Stats.txt");								// We call a function from our ifstream object called open().
														// We just tell open() the file name we want to open.  It must be
														// In the same directory as the program if not specified (ie, "c:\stats.txt")
														// The "." after fin allows us to access some functions within an object/class
														// Later you will see how to create classes yourself.
													
														
	if(fin.fail())										// But before we start reading .. we need to check IF there is even a file there....
	{													// We do that by calling a function from "fin" called fail().  It tells us if the file was opened or not.
		cout << "ERROR: Could not find Stats.txt!\n";	// Now, Print out an error message.  This is very important, especially when getting into huge projects.
														// There is so many times where I have spent wasted time trying to find out why my program was crashing.
		return;											// Return is like a 'break' but it's for functions, not loops.  Just because we have a "void main()" , doesn't mean we can return in it.
	}													// We just can't return something to it.  Return will quit from the current function, in this case it's main.  So the program is now ended.
														
	cout << endl;										// Just to space things out when we go down one line

														// Here we just do a while loop to get every word in the file.
	while(fin >> szWord)								// It works just like "cin", it will read every word of the file.
		cout << szWord;									// Here we print out the word it just read in.  This results in printing the whole document to the screen (but not very neat...)
														// After it reads each word, it moves the file cursor/pointer to the next word until it gets to the end (EOF - End of File)

														// At the end of every file the computer puts a symbol to show it's the end of the file.
														// EOF is #defie'd to be -1 -- But what is really important is that when you see EOF
														// you think End-Of-File.

	cout << endl;										// Just to space things out when we go to the next line
														
														// Once the input file stream reaches the end of the file, it set's a flag, EOF to TRUE.
	fin.clear();										// We clear the flag inside of "fin" that holds EOF.  If we don't, a boolean will tell us that we are still at the EOF.
	fin.seekg(NULL, ios::beg);							// We use this to go to the beginning of the file.  We could just close and open the file again though...
	
														
														// This is another way to read from a file.  getline() gets a whole line of text at a time
	while(getline(fin, szLine))							// This gets a line of the text file at a time and stores it in the string "szLine"
		cout << szLine << endl;							// getline needs to pass in (the input file stream, and the string to store what it gets)
														// Next we print out line by line as we get the line in the file.
	
	cout << endl;										// Just to space things out when we go to the next line

	fin.clear();										// We clear the flag inside of "fin" that holds EOF.  If we don't, a boolean will tell us that we are still at the EOF.
	fin.seekg(NULL, ios::beg);							// We use this to go to the beginning of the file.  We could just close and open the file again though...
														// This is a tricky thing below..
														// Remember up above how we read in a word at a time and it move the file pointer to the next word??
														// Well, below we are doing just that.  We read PAST the first word, then read in the next word.
	fin >> szWord >> szName;							// Here we read past the word "Player: ", then we read in the players name and it stores it in "szName"
	fin >> szWord >> health;							// Here we read past the word "Health: ", then we read in the players health and it stores it in "health"
	fin >> szWord >> gold;								// Here we read past the word "Gold: ", then we read in the players gold and it stores it in "gold"			

	cout << "The Player's name is:   " << szName << endl;	// Here we print out the Player's name that we retrieved from the file.
	cout << "The Player's health is: " << health << endl;	// Now we print out the Health of the player that we got from the "Health: 50" part of the file.
	cout << "The Player's gold is:   " << gold << endl;		// Then we print out the amount of gold the player has, which we retrieved from the line "Gold: 20" in the file "stats.txt".

														// close() closes the file for us. (very important)
	fin.close();										// We must always close the file after we are done with it.  It frees memory and make's it so we can access it again.

}														// End of our program


// © 2000-2003 GameTutorials