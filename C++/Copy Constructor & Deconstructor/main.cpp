// Done by TheTutor -- 06/10/01

/* Copy constructors and deconstructors -- Like usual all the intense explanation lies hidden
   deep within "name.h" and "name.cpp"

	This main() is going to be kept simple -- I'm going to create a function that prints
	out the name of a PLAYER -- I call this function PrintName() -- I'll call it once
	and we're done!

*/

#include "name.h"	// <iostream> was defined in "name.h"

// You guessed it, this function prints out the "player_name" of the PLAYER it's passed
void PrintName(PLAYER player);


int main()
{

	PLAYER Slim_Tim;	// Okay our player is going to be Slim_Tim (he doesn't eat)

	// We better set his name appropriately
	Slim_Tim.setName("Slim Tim");

	// Now we'll set his race
	Slim_Tim.setRace("NonEater"); // 

	// Okay lets call our function
	PrintName(Slim_Tim);
	
		return EXIT_SUCCESS;	// We're done -- I hope copy constructors and deconstructors
								// are infinitely clearer to you :)

} // Deconstructor gets called here



void PrintName(PLAYER player)	// Copy constructor gets called here (Every time function is called)
{
	cout << "Player's name is: " << player.getName() << endl;

}	// Deconstructor gets called here (Every time function is called)


/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/