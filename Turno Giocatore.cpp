
#include <iostream>
#include <stdlib.h>
#include "Random Adventure English.h"
#include "Azioni.h"
#include "Everywhere Used Func.h"
#include "Player Stats.h"
#include "Encounter Stats.h"
#include "Input.h"



void turnoGiocatorre()
{

	// used to know how many actions the player can do in his turn
	short actionsLeft{ 2 };




	std::cout << "Cosa vuoi fare?\n";

	while (actionsLeft > 0)
	{

		// ask for input and the choose the corresponding actions
		switch (Input::character())
		{
		case 'y':// yes

			std::cout << "\nOltre all'incontro che si sta chiedendo perche' hai detto \"Si!\", "
				<< "nulla accade.\n";
			--actionsLeft;

			break;

		case 'n':// no

			std::cout << "\nOltre all'incontro che si sta chiedendo perche' hai detto \"No!\", "
				<< "nulla accade.\n";
			--actionsLeft;

			break;

		case 'w':// skip

			actionsLeft = 0;

			break;

		case '5'://check character statistic

			printPlayerStats();

			break;

		case 'a':// attack

			attaccaIncontro();
			actionsLeft = 0;

			break;

		case 'h':// use healing potion

			cura(3.00);
			--actionsLeft;

			break;

		case 'e':// heal to max hp

			cura(9999.99);
			actionsLeft = 0;
			break;

		case 't':// talk

			parla();
			actionsLeft = 0;

			break;

		default:// no action possible

			std::cout << "Errore: azione non trovata o non possibile.\n\n";

			break;
		}

		stampAzioniRimanenti(actionsLeft);

	}

}