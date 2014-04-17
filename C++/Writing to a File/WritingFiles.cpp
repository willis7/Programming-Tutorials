//**********************************************************************************//
//																					//
//		- "Talk to me like I'm a 3 year old!" Programming Lessons -					//
//																					//
//		$Author:		Ben Humphrey	digiben@gametutorials.com					//
//																					//
//		$Program:		WritingFiles											    //
//																					//
//		$Description:	This shows you how to write to a file					    //
//																					//
//		$Date:			6/22/00														//
//																					//
//**********************************************************************************//

#include <iostream>										// Include our standard header
#include <string>										// Include this to use strings
#include <fstream>										// Include this to use file streams
using namespace std;									// set our namespace to standard;

void main()												// A standard and plain main (hey! that rhymed!) :)
{														// Start of our program
	ofstream fout;										// Here we create an ofstream and we will call it "fout", like "cout".
														// ofstream stands for output file stream.  That means we are sending data to a file.
	string szLine ="";									// Lets create a string to hold a line of text from the file.
	string szWord = "";									// This will hold a word of text.
	string szName = "Adol";								// This holds the players name.
	int health=100, gold = 75;							// We holds the players health and gold.
														
	fout.open("Stats.txt");								// We call a function from our ofstream object called open().
														// We just tell open() the file name we want to open or create.
														// If the file doesn't exist, it will create it for us once we start writing to it.																									
														
														// Below, we use fout just like cout.  Instead of writing to the screen though, it writes to out open file.
	fout << "Player: " << szName << endl;				// This prints "Player: Adol" to our file
	fout << "Health: " << health << endl;				// This prints "Health: 100" to our file
	fout << "Gold: "   << gold   << endl;				// This prints "Gold: 75" to our file

														// close() closes the file for us. (very important)
	fout.close();										// We must always close the file after we are done with it.  It frees memory and make's it so we can access it again.

}														// End of our program


//////////////////////////// Quick notes //////////////////////////
//
//	So, now that you know how to write things to a file,
//  Do you think that you could write a save and load game function?
//  
//  Of course, you would not want to hard code your data.  You would
//  most likely have the player enter in their name in the beginning,
//  then you save that off, and start with a default health and gold.
//  You should be able to take this and apply it to a simple save game
//  function.  Now that you know how to read in data and save data, you
//  can make a save game file, maybe called <playerName>.sav (IE. Adol.sav).
//  Once you save the data, it's simple to read in.  
//
//	As you can see, this is really simple.  If you know cout, you know ofstream.
//  I call my variable fout (file Output) because it is so much like cout (console Output).
//
//  © 2000-2003 GameTutorials 

