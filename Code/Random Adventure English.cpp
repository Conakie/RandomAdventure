
#include <iostream>
#include <stdlib.h>
#include "Random Adventure English.h"
#include "Actions.h"
#include "Everywhere Used Func.h"
#include "Player Stats.h"
#include "Encounter Stats.h"
#include "Set Encounters.h"
#include "Stats.h"
#include "Mage.h"
#include "PlayerActions.h"
#include "GameSession.h"



void gameEn()
{
	// reset stats
	player().resetAllStats();
	encounter().resetAllStats();

	GameSession game{ };
	game.startSession();
	game.play();


	std::cout << "\n\n\n\nKelmod: \"Game over.\"\n\n\n\n";

}
