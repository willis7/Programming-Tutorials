#include "name.h"

// The default constructor
PLAYER::PLAYER():player_name(NULL)
{
	// Set the "player_race" initially to NULL
	for(int i = 0; i < RACE_SIZE; i++)
		player_race[i] = NULL;


	/* Okay what's with the funky syntax PLAYER::PLAYER():player_name(NULL)

		Well the "player_name(NULL)" part is the same as if we would of done 
		this inside of the {}'s

		player_name = NULL;

		There's no difference, notice the single ':' after the ')' of the constructor
		this must be there if you want to initialize variables in this manner.  You can
		initialize multiple member variables this way as well.  All you have to do is
		separate them by commas.

		This style of initialization can ONLY be done with constructors!

  */

}

// The Copy Constructor -- The copy constructor gets called when a NEW instance of the 
// class is be instantiated -- So the copy constructor is responsible for copying ALL the 
// data contained within a class correctly
PLAYER::PLAYER(const PLAYER &Johnny)		/* I choose the variable name "Johnny" just 
											   so it's a little easier to see what's going
											   on (I hope)	-- Remember you can switch
											   "Johnny" to whatever makes you breathe heavy,
											   (with a few exceptions) it's just a variable
											   name */
{
	// First off we're going to copy the "player_race" over
	for(int i = 0; i < RACE_SIZE; i++)
		player_race[i] = Johnny.player_race[i];		/* Remember we're inside of class PLAYER
													   (inside the scope of PLAYER) so we can
													   mess directly with the private member
													   variables -- */

	// The next we have to do is create memory for the player name
	// But first we need to know how much to create
	int name_len = strlen(Johnny.player_name);  // This returns the # of characters
												// in "player_name" (not including the NULL
												// terminator)

	// Now let's make that memory
	player_name = new char[name_len + 1];	// "player_name" is now big enough to 
											// hold "Johnny.player_name"
											// The "+1" is for the NULL terminator

	// Copy over the "player_name"
	for(i = 0; i <= name_len; i++)
		player_name[i] = Johnny.player_name[i];

}

// Sets the name of PLAYER
void PLAYER::setName(char name[])
{
	// If the player name HASN'T been set yet, we need to allocate space for it
	if(player_name == NULL)
		player_name = new char[strlen(name) + 1];	// If this doesn't make sense,
													// look at the explanation
													// given in the copy constructor

	// Fill "player_name"
	for(unsigned int i = 0; i <= strlen(name); i++)
		player_name[i] = name[i];


	/* 
		Notice we ARE NOT doing any error checking -- If the first "name" they pass in
		is 5 characters long, then they call setName() again with a larger "name"
		(say 10 charaters), there will be some memory overwritten -- THAT WOULD BE BAD!
	*/

}

// Sets the race of PLAYER
void PLAYER::setRace(char name[])
{
	for(unsigned int i = 0; i <= strlen(name); i++)
		player_race[i] = name[i];


	/* 
		Again notice we ARE NOT doing any error checking -- If the "name" that gets passed in
		is longer than 30 characters (RACE_SIZE) -- there will be some memory overwritten -- 
		OVERWRITING MEMORY IS VERY BAD!
	*/

}

// The Deconstructor -----
PLAYER::~PLAYER()
{
	if(player_name)
		delete[] player_name;


	/* Okay first thing about deconstructors, they DO NOT take arguments
	   Next thing is they DO NOT have a return type (just like constructors)
	   Lastly, know that every time a class loses scope, that classes' deconstructor will
	   be called

		What we're doing here is checking to see if "player_name" has had allocated memory
		associated with it (it won't equal NULL if it does)
		If it has "been allocated" we free it -- simple as that :)

  */

}

