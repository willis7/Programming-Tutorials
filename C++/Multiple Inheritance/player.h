#ifndef PLAYER_H
#define PLAYER_H

#include "damage.h" // Include our "damage class"

#include <string>
using namespace std;

// Okay here is our PLAYER class that will have all the "base functionality" of all
// "players"
class PLAYER
{
	public:

		// Our default constructor.  Because we are giving a default value for ALL the 
		// parameters passed into the constructor (ie the only one passed in) this will
		// work as a default constructor.
		PLAYER(int max = 500);

		void alterCurLife(int amount); // Alters current life by "amount"
		void alterMaxLife(int amount); // Alters max life by "amount"

		void setName(string player_name); // Set's the PLAYER's name to "player_name"

		// *** Data Access

		string getName() { return name; }
		int getCurLife() { return cur_life; }
		int getMaxLife() { return max_life; }

		// End of Data Access ***


	/*  This is the "protected" key word -- It works much the same way as the
	    "private" key word -- Just like when you use "private", client .cpp files
		(such as main.cpp) CAN NOT access protected variables/methods.  Their difference
		is that derived classes CAN access protected variables/methods (they can't access
		private)
	*/
	protected:

		string name; // The PLAYER's name

		int cur_life; // The PLAYER's current life
		int max_life; // The PLAYER's max life

};


// This is our "Sage" player
class SAGE : public PLAYER			// The single colon ':' signifies we are inheriting -- 
{									// The "public" means that everything that is public to
									// the PLAYER class will be public to the SAGE class
	
	public:

		// Here will make our default constructor, again we'll provide default arguments so
		// if the client chooses, they don't have to pass in anything when creating a SAGE
		// The SAGE takes "max" (the max life), "mp" (magic power) and "str" strength
		SAGE(int max = 100, int mp = 50, int str = 10);

		void setMagicType(int type); // Set "magic_selected" to whatever magic the SAGE is
								// currently using

		int getMagicLevel(); // This returns the "level" of the current magic attack

		// *** Data Access

		int getMagicType() { return magic_selected; }
		
		// End of Data Access ***

	private:

		int magic_selected; // Which magic is the SAGE currently "using" (have selected to use)

		int magic_power; // How much magic power SAGE has
		int strength; // How much strength SAGE has

};


// Okay last but not least our "Swordsman" player -- It will be derived from the
// PLAYER and MAG_DAMAGE classes, hence "multiple inheritance" will occur --

class SWORDSMAN : public PLAYER, public MAG_DAMAGE	// So here we saying we're publicly deriving
{											       // from PLAYER and MAG_DAMAGE -- You use
												  // a comma to separate the classes you're 
												 // deriving from

	public:

		// Our default constructor:
		// "max" is the max life for the SWORDSMAN, "str" is the SWORDSMAN's strength
		SWORDSMAN(int max = 800, int str = 40);

		int getSwordDamage(); // This returns the amount of damage a SWORDSMAN's attack
							  // causes

	private:

		int strength; // How much strength the SWORDSMAN has

};


#endif