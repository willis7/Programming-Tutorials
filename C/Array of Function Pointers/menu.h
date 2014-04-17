#ifndef MENU_H
#define MENU_H

#include <stdio.h> // So we can use printf()

/* Here we're creating a "set of functions" that display various "menus" in our
   imaginary game.  Now it is important to note that these functions take the SAME
   parameters AND have the SAME return value (void)
*/

#define MAX_NAME 64

// This is our player struct -- Not much there eh?
typedef struct _PLAYER
{
	char name[MAX_NAME];
	int level;

} *pPlayer;

// This displays the "save game menu"
void SaveMenu(pPlayer);

// This displays the "load game menu"
void LoadMenu(pPlayer);

// This displays the "options menu"
void OptionsMenu(pPlayer);


#endif