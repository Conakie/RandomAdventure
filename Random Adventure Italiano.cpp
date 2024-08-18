
#include <iostream>
#include <stdlib.h>
#include "Random Adventure English.h"
#include "Random Adventure Italiano.h"
#include "Actions.h"
#include "Everywhere Used Func.h"
#include "Player Stats.h"
#include "Encounter Stats.h"
#include "Place.h"



void gameIt()
{

	//setConsoleColor(0);

	//		player stats

	




	//The game starts here
	while (1)
	{

		
		//if player gained a new level upgrade all his statistics
		//checkForPlayerLvlUp();


		// It's the turn of the player
		playerTurn();

		// It's the turn of the encounter
		encounterTurn();

	}

	std::cout << "\n\n\n\nKelmod: \"You died.\"\n\n\n\n";

}
