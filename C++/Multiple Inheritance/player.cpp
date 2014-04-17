#include "player.h"

// PLAYER's default constructor
// Remember with this we can declare a PLAYER like this:
/*
	PLAYER player;

	Or like this:

	PLAYER player(1000);
*/
PLAYER::PLAYER(int max)
{
	cur_life = max;
	max_life = max;
}

// This method will "alter" (ie add or subtract to) the PLAYER's current life
void PLAYER::alterCurLife(int amount)
{
	cur_life += amount;
}

// This method will "alter" (ie add or subtract to) the PLAYER's max life
void PLAYER::alterMaxLife(int amount)
{
	max_life += amount;
}

// The method sets the PLAYER's name
void PLAYER::setName(string player_name)
{
	name = player_name;
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// Implementation of the SAGE /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

// The default constructor -- Notice how we EXPLICTLY call the PLAYER constructor
SAGE::SAGE(int max, int mp, int str):PLAYER(max)
{
	magic_selected = FIRE; // By default we're going to say the SAGE has "fire magic selected"

	// Set magic power and strength
	magic_power = mp;
	strength = str;

	name.assign("Merlin"); // Now notice this -- Here we assigning a default name for a SAGE
						   // We can DIRECTLY mess with "name" because it is a "protected"
						   // variable in PLAYER
}

// This sets the "magic type" (ie the spell the SAGE could cast)
void SAGE::setMagicType(int type)
{
	magic_selected = type;
}

// This is where we "figure out" the "magic level" (the strength of an attack)
int SAGE::getMagicLevel()
{
	// Here's the equation I came up with during a late hour coding binge

	return rand()%magic_power + strength;
}


//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// Implementation of the SWORDSMAN /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

// The default constructor -- Notice how we EXPLICTLY call the PLAYER constructor
SWORDSMAN::SWORDSMAN(int max, int str):PLAYER(max)
{
	strength = str;

	name.assign("Conan"); // Now notice this -- Here we assigning a default name for a SAGE
						  // We can DIRECTLY mess with "name" because it is a "protected"
						  // variable in PLAYER

}

// This returns the damage from a SWORDSMAN's attack
int SWORDSMAN::getSwordDamage()
{
	// Again just something I came up with

	return ((rand()%4 + 1) * -strength);

}
