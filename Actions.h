
#ifndef RATABS_PLAYER_AND_ENCOUNTER_ACTIONS_H
#define RATABS_PLAYER_AND_ENCOUNTER_ACTIONS_H


#include "Encounters.h"


// makes the player talk to an encounter
void talk();

// Makes the player attack an encounter
void attackEncounter(Encounters& encounter);

// notify the player on the amount of actions he can do before the end of his turn
void printActionsLeft(int actionsLeft);

// The following actions are for the encounters

// makes the encounter attack the player
void attackPlayer(Playerz& player);

#endif // !RATABS_PLAYER_AND_ENCOUNTER_ACTIONS_H