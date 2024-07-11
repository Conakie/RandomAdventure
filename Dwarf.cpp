
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Random.h"



void dwarf()
{

	char answer{ 0 };


	bool answerAgain{ false };


	std::cout << "Dwarf: \"Hey you. Why are you looking at me like this? Have you ever seen a "
		<< "dwarf?\"\n"
		<< "y: I have seen many dwarves in my life\n"
		<< "n: Nope. Never.\n"
		<< "s: How does a dwarf looks like?\n";

	do
	{
		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes

			std::cout << "Dwarf: \"Finally a good answer. Wanna go to the nearest tavern?\n"
				<< "I want some beer. After an hour of mining I want a good old beer.\n"
				<< "Wanna join me?\"\n"
				<< "y: Oh yeah!\n"
				<< "n: No, I don't want to drink beer.\n"
				<< "s: I'm not so sure I want one right now...\n";
			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "Dwarf: \"Good, good now come with me.\"\n";
					// heal like he drank a beer
					player().heal(3.3 * player().getLvl());
					answerAgain = false;

					break;

				case 'n'://no

					std::cout << "Dwarf: \"Wait you don't drink beer? How can you survive without beer?\n"
						<< "Now I need two or three more beers after what you said. Bye.\"\n";
					answerAgain = false;

					break;

				case 's'://Skip

					std::cout << "Dwarf: \"Come on join me, you won't regret it. Trust me.\"\n";
					// heal like he drank many beers
					player().heal(Random::get(8, 38) * player().getLvl());
					answerAgain = false;

					break;

				default:

					printNotPossible();
					answerAgain = true;

					break;
				}

			} while (answerAgain == true);

			answerAgain = false;

			break;

		case 'n'://no

			std::cout << "Dwarf: \"You're a lost cause. I'll go and get a good beer with "
				<< "my friends and leave someone like you here.\n";
			answerAgain = false;

			break;

		case 's'://Skip

			std::cout << "Dwarf: \"Maybe you should go in a library and study a little bit.\n"
				<< "It doesn't hurt ya know?\"\n"
				<< "(The dwarf leave you there and goes away)\n";
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain == true);


	encounter().setIsGone(true);
	encounter().setCanTalk(false);

}



void nano()
{

	char answer{ 0 };


	bool answerAgain{ false };


	std::cout << "Nano: \"Hey tu. Perche' mi stai guardando cosi'? Mai visto un nano?\"\n";

	do
	{
		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes

			std::cout << "Nano: \"Finalmente una buona risposta. Vuoi andare alla taverna piu' vicina?\n"
				<< "Voglio della birra. Dopo un'ora di miniera voglio una buona vecchia birra.\n"
				<< "Vuoi unirti a me?\"\n";

			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "Nano: \"Bene, bene ora vieni con me.\"\n"
						<< "(Mentre stai seguendo il nano lo vedi sparire)\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'n'://no

					std::cout << "Nano: \"Aspetta tu non bevi birra? Come fai a sopravvivere senza?\n"
						<< "Ora ne ho bisogno di due o tre birre in piu' dopo questo. Ciao.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'w'://Skip

					std::cout << "Nano: \"Dai unisciti a me, non te ne pentirai. Fidati.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				default:

					std::cout << "(Non possibile)\n";
					answerAgain = true;

					break;
				}

			} while (answerAgain == true);

			answerAgain = false;

			break;

		case 'n'://no

			std::cout << "Nano: \"Sei una causa persa. Me ne vado a prender una birra con "
				<< "i miei amici e lascio uno come te qua.\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case 'w'://Skip

			std::cout << "Nano: \"Magari dovresti andare un po' in una libreria e studiare un po'.\n"
				<< "Non fa male sai?\"\n"
				<< "(Il nano se ne va via)\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		default:

			std::cout << "(Non possibile)\n";
			answerAgain = true;

			break;
		}

	} while (answerAgain == true);


	encounter().setCanTalk(false);

}