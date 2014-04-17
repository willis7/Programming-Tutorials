#ifndef NAME_H
#define NAME_H

#include <iostream>

using namespace std;

/*	Okay here we're going to cover two of the four methods you always get with a class

	Remember the four methods you ALWAYS get with a class are

	Constructor
	Copy Constructor
	Assignment Operator
	Deconstructor

	The Copy Constructor is the method that gets called when you pass a class as an
	argument to a function -- As you'll recall, functions make local copies of variables
	they are passed -- A Copy Constructor also gets called when you make an instance of
	a class and set it equal to another class -- Example:

	POINT point = diff_point;	// Your declaring a type POINT "point" and setting it equal
								// to "diff_point" -- This calls the Copy Constructor

	/////////////////////////////////////////////////////////////////////////////////////////

	The Deconstructor gets called when your class loses scope (is destroyed)

	So for example when you pass a class to a function, that function makes a local copy
	of that class (via the Copy Constructor) -- When that function returns, the
	Deconstructor is called freeing all the memory associated with that class

	IT'S IMPORTANT THAT YOU DEFINE YOUR OWN COPY CONSTRUCTOR AND DECONSTRUCTOR
	IF YOUR CLASS CONTAINS DYNAMIC DATA -- If your class doesn't have dynamic data, you more
	than likely don't have to (or would want to) define your own copy constructor and 
	deconstructor


*/


// Here we're going to define a PLAYER class that has VERY little functionality --
// All our player class is going to allow us to do is define a player's name of any size
// and the player's race (ie warlock, ninja, mage, etc) of a predetermined size

#define RACE_SIZE 30 // This is going to be the max # of characters that can
					 // be used in naming a PLAYER's race

class PLAYER
{

	public:
	
		PLAYER(); // Default constructor

		// When defining a copy constructor you should always pass in the argument as seen
		// here (a const reference to the class) -- This is not technically the only way
		// a copy constructor can be prototyped -- but I suggest ONLY doing it this way
		PLAYER(const PLAYER &player);
		
		void setName(char name[]); // Sets the name of the player
		void setRace(char name[]); // Sets the race of the player

		// Notice how we defined the function and implemented the function right here
		// in the header file -- this is totally legal, there is only one slight difference
		// when we define it here, the function is automatically inlined 
		// Don't worry if you don't know what "inlining" a function means -- It will be
		// discussed later, it's not important right now
		char* getName() { return player_name; }
		char* getRace() { return player_race; }


		~PLAYER(); // The Deconstructor -- This frees all memory that gets allocated
				   // in PLAYER, notice how it starts with a '~' -- All deconstructors
				   // begin with the '~'

	private:

		char *player_name;	// pointer to hold the PLAYER's name

		char player_race[RACE_SIZE]; // an array to hold the PLAYER's race

};




#endif