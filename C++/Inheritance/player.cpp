#include "player.h"

// Our constructors ---

// Our default constructor will set the player name to NULL
// It will set life to 100 units and intellect and strength to 20 units
// Since we a creating a player, it's obviously alive
PLAYER::PLAYER():life(100),intellect(20),strength(20),alive(true)
{
	// Clear the name to NULL
	memset(name,0,MAX_PLAYER_NAME);
}

// An overloaded constructor will set the name, life, strength and intellect of the 
// player to values passed in
PLAYER::PLAYER(char *player_name, int L, int I, int S):life(L),intellect(I),strength(S),alive(true)
{
	// Clear the name to NULL
	memset(name,0,MAX_PLAYER_NAME);
	
	if(player_name)
	{
		int len = strlen(player_name); // Get the length of the player name passed in

		// If it's greater than the space we are allotting for player names
		// cut it off
		if(len >= MAX_PLAYER_NAME)
		{
			for(int i = 0; i < MAX_PLAYER_NAME; i++)
				name[i] = player_name[i];

			name[MAX_PLAYER_NAME - 1] = NULL;
		}
		else
			strcpy(name,player_name); // Just copy over the player name
	}

} // end of PLAYER::PLAYER(char *player_name, int L, int S, int I)


// Our WIZARD class default constructor -- This set the spellPower to a value of 10
// Everything else (like "life" for example) will get set by the default PLAYER constructor
// that WILL be called
WIZARD::WIZARD():spellPower(10) { /* do nothing */ }

// Now this is our constructor that takes parameters --
// To set the PLAYER variables (such as life), we HAVE to EXPLICTILY call the PLAYER's constructor
// Otherwise the default constructor for the PLAYER will get called and these variables WILL NOT get set
WIZARD::WIZARD(char *player_name, int L, int I, int S, int SP):PLAYER(player_name,L,I,S),spellPower(SP)
{ 
	/* do nothing */
}


/* **NOTE** WHAT IF WE WANTED TO HAVE A METHOD LIKE THIS:

void WIZARD::decrementLife()
{
	life--;
}

  Well if we attempted to program this, it wouldn't compile -- Remember life is a PRIVATE member
  of PLAYER -- ONLY PLAYER methods can directly access "life" -- If there was a public function
  in PLAYER that let us modify the "life" variable, then we could modify it inside the implementation
  of WIZARD methods

*/
