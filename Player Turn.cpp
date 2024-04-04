
#include <iostream>
#include <stdlib.h>
#include "Random Adventure English.h"
#include "Actions.h"
#include "Everywhere Used Func.h"
#include "Player Stats.h"
#include "Encounter Stats.h"
#include "Items.h"
#include "Input.h"
#include "Stats.h"
#include "Print Errors.h"



void playerTurn()
{

	// used to know how many actions the player can do in his turn
	short actionsLeft{ 2 };




	std::cout << "Your turn. Choose wisely.\n";
	// repeat until the player finishes his actions
	while(actionsLeft > 0)
	{

		// ask for input and the choose the corresponding actions
		switch (Input::character())
		{
		case 'y':// yes

			std::cout << "\nOther than the encounter wondering why you said \"Yes!\", nothing "
				<< "happens.\n";
			--actionsLeft;

			break;

		case 'n':// no

			std::cout << "\nOther than the encounter wondering why you said \"No!\", nothing "
				<< "happens.\n";
			--actionsLeft;

			break;

		case 's':// skip

			actionsLeft = 0;

			break;

		case '5'://check character statistic
			
			player().printStats();

			break;

		case 'a':// attack

			attackEncounter(encounter());
			actionsLeft = 0;

			break;

		case 'h':// use healing potion

			player().heal(3.00);
			--actionsLeft;

			break;

		case 'e':// heal to max hp

			player().heal((player().getMaxHealth() - player().getHealth()));
			actionsLeft = 0;

			break;

		case 't':// talk

			talk();
			actionsLeft = 0;

			break;

		case 'i':// use an item of the inventory
		{
			ObjectUid itemToUse{ ObjectUid::none };
			int amount{ 1 };

			// before asking the user everything, print the inventory
			player().setInventory().print();
			// ask the user to enter the item and amount to use
			std::cout << "Choose the object to use.";
			// the user is going to use print as reference
			// itemToUse is input - 1 since the print function
			// starts from 1 instead of 0
			itemToUse = static_cast<ObjectUid> (Input::integer() - 1);
			std::cout << "Please, enter the amount to use.";
			amount = Input::integer();
			
			// try to use an item. if the item isn't used because of some errors
			// the action the player can do won't change
			if (!player().setInventory().useItem(itemToUse, amount))
			{
				--actionsLeft;
			}
			else
			{
				std::cout << "Not enough items / wrong item!\n";
			}

			break;
		}
		case 'p':// print inventory

			player().setInventory().print();

			break;

		case '/':// commands

			std::cout << "\n/\\Commands are not ready!/\\\n";

			break;

		default:// no action possible

			PrintError::actionNotFound();

			break;
		}

		printActionsLeft(actionsLeft);

	}

}