// Done by TheTutor	10/11/01

/*	Multiple inheritance -- Well for starters what is it?  Multiple inheritance is 
	just having a class that is derived from more than one class.  So if you understand
	"inheritance" you'll understand multiple inheritance just fine.

	If you don't understand "inheritance" and think that's something you get when your 
	great grandpa kicks the bucket, this tutorial isn't for you at the present time :)

	So to illustrate multiple inheritance we're going to created 4 classes.

	One will be a player class -- This will represent all generic players.

	Next will create a "magic damage" class that will be responsible for dolling out
	damage based on magical spells.

	Lastly will create two "specific player" classes the Sage and the Swordsman.  The
	Sage will ONLY be derived from the "player" class.  The Swordsman will be derived from
	the "player" class and the "magic damage" class.

*/

#include "player.h"

#include <iostream>
using namespace std;


/* Okay this main doesn't do anything spectacular -- It just creates all three of the 
   classes (PLAYER, SAGE, SWORDSMAN) and calls some of their methods printing out the
   results
*/

int main()
{
	// Create a PLAYER, SAGE, SWORDSMAN
	PLAYER player;
	SAGE sage;
	SWORDSMAN swordsman;

	player.setName("Player"); // Set the player's name

	// Print out the player's, sage's and swordsman's name
	cout << player.getName() << endl;
	cout << sage.getName() << endl;
	cout << swordsman.getName() << endl;

	cout << endl; // A blank line

	// Have the sage execute a FIRE attack on the swordsman

	cout << "Swordsman current life = " << swordsman.getCurLife() << endl; // First print out
																		  // current life

	// Now here we going to combine a few function calls :)
	// Does this monstrosity make sense???
	// We're passing into alterCurLife() the result of calcDamage(), calcDamage() takes 
	// the attackers (in this case the SAGE) magic type (retrieved through getMagicType())
	// and the attackers magic level (retrieved through getMagicLevel())
	swordsman.alterCurLife(swordsman.calcDamage(sage.getMagicType(),sage.getMagicLevel()));

	cout << "Swordsman current life = " << swordsman.getCurLife() << endl; // Reprint out the
																		  // current life


	return 0; // Okay we're out of here
}

/*

	Okay it is important to note that these classes ARE IN NO WAY ROBUST -- The tutorial is 
	meant to accomplish two things:

	1)  To show how to "syntactically achieve" multiple inheritance

	2)  Explain the "protected" key word

	When making your own programs you'll be responsible for coming up with a 
	programming schematic that solves your problems elegantly and efficiently :)

	As always, post your questions at www.GameTutorials.com

*/

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/