#ifndef PLAYER_H
#define PLAYER_H

#define MAX_PLAYER_NAME 25 // The maximum number of characters in a player's name

#include <stdlib.h>
#include <string.h>

// This will encompass attributes (variables, characteristics) that ALL players have
// for this tutorial
class PLAYER
{
	public:

		// Our constructors
		PLAYER();
		PLAYER(char *player_name, int L, int I, int S); // L == life
														// I == intellect
														// S == strength

		/** Data Access Functions **/

		char* getName() { return name; }
		
		int getLife() { return life; }
		
		/** End of Data Access Functions **/


	private:

		char name[MAX_PLAYER_NAME]; // The name of the player

		int life; // The amount of "life" the player has -- Range is 0 - 1000
		int intellect; // How "smart the player is -- Range is 0 - 100
		int strength; // How "strong" the player is -- Range is 0 - 100

		bool alive; // Is the player alive or dead

};



/* 
	Okay here is where the power of inheritance (deriving from classes is)
	We are going to inherit the WIZARD class from the PLAYER class meaning "certain aspects
	of the PLAYER class will exist in the WIZARD class as if the code was cut 'n paste
	directly into the WIZARD class" -- Notice I said "certain aspects", depending on how we
	inherit, differnt aspects (member variables, methods) will be accessible to us in
	the WIZARD class	

*/

// The single colon ':' signifies we are inheriting -- The "public" means that everything that
// is public to the PLAYER class will be public to the WIZARD class
class WIZARD : public PLAYER
{
	public:

		// Constructors
		WIZARD();
		WIZARD(char *player_name, int L, int I, int S, int SP); // L == life
														       // I == intellect
														      // S == strength
															 // SP == spellPower

		/** Data Access Functions **/

		int getSpellPower() { return spellPower; }
		
		/** End of Data Access Functions **/

	private:

		int spellPower; // The power of the wizard's spell -- Range 0 - 100

};

#endif