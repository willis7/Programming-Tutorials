//**********************************************************************************//
//																					//
//		- "Talk to me like I'm a 3 year old!" Programming Lessons -					//
//																					//
//		$Author:		Ben Humphrey	digiben@gametutorials.com					//
//																					//
//		$Program:		WritingFiles											    //
//																					//
//		$Description:	This gives several ways to write to a file				    //
//																					//
//		$Date:			6/22/00														//
//																					//
//**********************************************************************************//

#include <stdio.h>										// We need to include this for printf() and fgetc().
#include <string.h>										// This is needed for strlen()

void main()												// A standard and plain main (hey! that rhymed!) :)
{														// Start of our program
	FILE *fp;											// This variable will be used for writing to a file.  Once again, 'fp' stands for filepointer.													
	char szLine[50] = {0};								// This is used to hold the text that will be written to the file.  remember to use {0} to initialize arrays.
	char szName[] = "Adol";								// Here we initialize our player name in the beginning.  This char array is 4 characters long.
														// If you don't stick a number in the [], then it is allocated to how many characters are in the string you initialize it to.
	int health=100, gold = 75;							// I created 2 integers which we will use for writing the gold and health of the player to the file.
	int length = 0;										// This will be used to store the string length of our output.
	int i = 0;											// A simple counter variables.
														
	fp = fopen("Stats.txt", "w");						// Here we recieve the address of where the file resides in memory.  "fopen()" returns the address.
														// Once again, fopen() needs a file name for the first parameter, and a letter.
														// This time, since we want to write to a file, we use "w", where if we want to read from file, we use "r".												
														// If there happens to be a file already called, "stats.txt" , it will erase the contents first before writing.
														// If you want to append to a file, use "a".  Then it will just add to the file, not erase it.

														
	if(fp == 0)											// Now we should have valid file pointer, but we need to make sure.
	{													// If fp equals 0 it means fopen() couldn't create the file.  This could be because we don't have any memory or space left.
		printf("ERROR: Could not create Stats.txt!\n");	// Print out an error message.  This is very important, especially when getting into huge projects.
														// There is so many times where I have spent wasted time trying to find out why my program was crashing.
		return;											// Return is like a 'break' but it's for functions, not loops.  Just because we have a "void main()" , doesn't mean we can return in it.
	}													// We just can't return something to it.  Return will quit from the current funciton, in this case it's main.  So the program is now ended.
	
	////////////////////// FPUTC() //////////////////////////

	sprintf(szLine, "Player: %s", szName);				// Sprintf() works almost exactly like printf(), except you aren't putting it to the screen.
														// Instead of display the data to the screen, you store it in a buffer, or string.
														// In this case, we store the players name in a string that looks like this: "Player: Adol".
														// The parameters are: (the string to save it to, the string to be saved, ... the data to insert into the string)
														// Just like printf(), you can have multiple paramters for the data, like sprintf(szLine, "%d %d %d", num1, num2, num3);

	length = strlen(szLine);							// Here we use the string length function to get the length of characters in our new string.

	for(i = 0; i < length; i++)							// Here we want to loop and write each character out to the file.  We want to go until i is less than the length (array indices start at zero)
	{
		fputc(szLine[i], fp);							// Like fgetc(), fputc() "puts", or writes a character to a file.
														// So, after this for loop finished, our final should have "Player: Adol" in it.  Check and see!
	}

	fputc('\n', fp);									// This will set the file pointer to the next line of the text file.

	sprintf(szLine, "Health: %d", health);				// This will create a string that looks like this: "Health: 100".  We can then save this to the file.

	length = strlen(szLine);							// Here we use the string length function to get the length of characters in our new string.

	for(i = 0; i < length; i++)							// Here we want to loop and write each character out to the file.  We want to go until i is less than the length (array indices start at zero)
	{
		fputc(szLine[i], fp);							// Now, print out the line "Health: 100" to the file.  After this loop finishes, we should have 2 lines in our file.
	}

	fputc('\n', fp);									// This will set the file pointer to the next line of the text file.

	sprintf(szLine, "Gold: %d", gold);					// This will create a string that looks like this: "Gold: 75".  We can then save this to the file.

	length = strlen(szLine);							// Here we use the string length function to get the length of characters in our new string.

	for(i = 0; i < length; i++)							// Here we want to loop and write each character out to the file.  We want to go until i is less than the length (array indices start at zero)
	{
		fputc(szLine[i], fp);							// Now, print out the line "Gold: 75" to the file.  After this loop finishes, we should have the 3 lines in our file.
	}

																								
	////////////////////// FPUTS() //////////////////////////

	fputc('\n', fp);									// This will set the file pointer to the next line of the text file.
	fputc('\n', fp);									// This will set the file pointer to the next line of the text file.

	sprintf(szLine, "Player: %s", szName);				// This will create a string that looks like this: "Player: Adol".  We can then save this to the file.

	fputs(szLine, fp);									// Like fgets(), this can take a whole string, not just a character.
														// This will save a whole string to a file.  You just need to pass in (a string, and a file pointer).

	fputc('\n', fp);									// This will set the file pointer to the next line of the text file.

	sprintf(szLine, "Health: %d", health);				// This will create a string that looks like this: "Health: 100".  We can then save this to the file.

	fputs(szLine, fp);									// Save "Health: 100" to the file.

	fputc('\n', fp);									// This will set the file pointer to the next line of the text file.

	sprintf(szLine, "Gold: %d", gold);					// This will create a string that looks like this: "Gold: 75".  We can then save this to the file.

	fputs(szLine, fp);									// Save "Gold: 75" to the file.
	
	////////////////////// FPRINTF() ////////////////////////
	
														// Like printf(), fprintf() works exactly the same.  Instead of printing to the screen,
														// It prints it to a file.  You need to give it a file pointer as the first parameter.
	fprintf(fp, "\n\n");								// This will move the file pointer down 2 lines in the text file.
														
	fprintf(fp, "Player: %s\n", szName);				// Here we save the Name of the player to the file.
	fprintf(fp, "Health: %d\n", health);				// Here we save the "health" of the player to the file.  
	fprintf(fp, "Gold: %d\n",   gold);					// Here we save the "gold" of the player to the file.
														// fclose() passes in the file pointer and closes the file for us. (very important)
	fclose(fp);											// We must always close the file after we are done with it.  It frees memory and make's it so we can access it again.

}														// End of our program

//////////////////////////// Quick notes //////////////////////////
//
//	So, now that you know how to write things to a file,
//  which one looks like the easiest way to do it?  Most likely
//  you would want to use, fprintf().  Though I would never use
//  the first 2, I thought it necessary to give different examples.
//  fprintf() is a lot less code, and more easily understood.  If you 
//  know printf(), you know fprintf().  
//
//  Of course, you would not want to hard code your data.  You would
//  most likely have the player enter in their name in the beginning,
//  then you save that off, and start with a default health and gold.
//  You should be able to take this and apply it to a simple save game
//  function.  Now that you know how to read in data and save data, you
//  can make a save game file, maybe called <playerName>.sav (IE. Adol.sav).
//  Once you save the data, it's simple to read in.  I recommend using 
//  fprintf() to save the data and fscanf() to load the data.
//
// © 2000-2003 GameTutorials