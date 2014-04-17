// Done by TheTutor -- 8/10/01

/*	Inheritance -- 

	This occurs when a class is "derived" from another class -- It "inherits" the other 
	classes attributes.

	To demonstrate this concept, we're going to create two classes:

	A player class -- This class will encompass all the basic functionality of ALL players

	A wizard class -- This class will be a specific type of player

	All the "hardcore code" is in player.cpp

*/

#include <iostream>
#include "player.h"

using namespace std;

/* 
	For the main we're going to create a WIZARD and print out it's name, life, and spell power
    that's it :)
*/

int main()
{

	// Instantiate our wizard
	WIZARD wizard("Merlin",50,40,30,70);
		
	char *wizard_name = wizard.getName(); // Get the name
	int life = wizard.getLife(); // Get the life
	int spellPower = wizard.getSpellPower(); // Get the spell power

	// Print it
	cout << wizard_name << "'s life = " << life << "." << endl;
	cout << wizard_name << "'s spell power = " << spellPower << "." << endl << endl;
		return 0;
}

//	Inherit this...

/*	
	Obviously these two classes are very limited (and not too useful in their current state)
	but nevertheless, the WIZARD class uses inheritance --

	Inheritance is VERY powerful -- Used correctly it can limit the amount of code you have to
	write AND make it reusable.  I can think of TONS of instances when inheritance would be 
	extremely useful -- For example, if you were making a RTS game that was comprised of many 
	different vehicles you could make a "base vehicle" (this would correspond to PLAYER).
	From that you could derive tanks, planes, boats, skateboards, whatever --

	The thing you want to remember if you going to use inheritance is to keep the BASE class
	(this refers to the thing other classes derive from) as GENERAL as possible -- Don't put 
	things in your base class that can't be used by all classes that derive from it

	As usual post your questions at www.GameTutoirals.com message board

*/

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/