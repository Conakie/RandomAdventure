
#include <iostream>
#include <stdlib.h>
#include "Random Adventure English.h"
#include "Actions.h"
#include "Everywhere Used Func.h"
#include "Player Stats.h"
#include "Encounter Stats.h"
#include "Set Encounters.h"
#include "Stats.h"



void gameEn()
{
	// reset stats
	player().resetAllStats();
	encounter().resetAllStats();
	player().setStats();


	//The game starts here
	while (player().getHealth() > 0.00)
	{
		
		// Check if Hp is 0. If it's 0 prepare a new encounter
		encounter().setEncounter();

		// It's the turn of the player
		playerTurn();

		// It's the turn of the encounter
		encounterTurn();

	}

	std::cout << "\n\n\n\nKelmod: \"You died.\"\n\n\n\n";

}