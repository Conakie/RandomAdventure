
#include <iostream>
#include <stdlib.h>
#include "Random Adventure English.h"
#include "Actions.h"
#include "Everywhere Used Func.h"
#include "Player Stats.h"
#include "Encounter Stats.h"
#include "Random.h"
#include "Items.h"
#include "Object UID.h"
#include "Stats.h"



void encounterTurn()
{

	// if the encounter is alive do something, else increase player xp and print drops
	if (encounter().getHealth() >= 0.01 && !(encounter().getIsGone()))
	{

		// if the encounter is under attack, attack the player, else it waits or it is the cleric
		if (encounter().getIsUnderAttack() && encounter().getUid() != EncounterUid::cleric)
		{

			player().takeDamage(encounter().getAttack());

		}
		else if (encounter().getUid() == EncounterUid::cleric)// if the encounter is the cleric, heal the player
		{

			// if the cleric is not uner attack, heal the player, else he goes away
			if (encounter().getIsUnderAttack())
			{

				std::cout << "Cleric: \"You aren't worthy of Miiro help.\"\n";

			}
			else
			{

				std::cout << "Cleric: \"Goodmorning. Here, let me heal you.\"\n";
				player().heal(Random::get(1, 6) * player().getLvl());

			}
			encounter().setIsGone(true);

		}
		else// the encounter waits
		{
			std::cout << "\nThe encounter waits for your decision.\n";
		}
		

	}
	else if(encounter().getIsGone())
	{

		std::cout << "\nThe Encounter is gone.\n";
		// increase xp
		increaseXP();
		// drop items
		encounter().dropItems();

	}
	else
	{

		std::cout << "\nThe encounter is dead\n";
		// increase xp
		increaseXP();
		// drop items
		encounter().dropItems();

	}

}