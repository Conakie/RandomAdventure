
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Actions.h"
#include "Input.h"
#include "Stats.h"
#include "Random.h"
#include "Cleric.h"



void cleric()
{

	char answer{ 0 };


	bool answerAgain{ false };



	std::cout << "Cleric: \"Hi little guy, I see you need healing. Leave it to me.\"\n"
		<< "y: Thanks.\n"
		<< "n: No thanks. I don't need help.\n"
		<< "s: -... --- --- -... ...\n"
		<< "a: Wanna fight?\n"
		<< "h: (Heal)\n"
		<< "e: (Heal to full health)\n";

	do
	{

		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes
			std::cout << "Cleric: \"Always have a cleric like me to help you in your group.\n"
				<< "You'll never know when you'll need to be healed.\n"
				<< "See you again in the future.\"\n";
			answerAgain = false;

			break;

		case 'n'://no

			std::cout << "Cleric: \"Why don't you want my healing? Well then see you in"
				<< " the future.\"\n";
			answerAgain = false;

			break;

		case 's'://Skip

			std::cout << "Cleric: \"Why don't I give you this map. It's more useful to you then "
				<< "to me.\"\n(He gives you a map of the place and heals you)\n"
				<< "(After he finishes healing he goes away)\n";

			player().heal(2 * encounter().getLvl());
			answerAgain = false;

			break;

		case 'a'://attack

			std::cout << "Cleric: \"I won't attack you. I'll go away.\"\n";
			answerAgain = false;

			break;

		case 'h'://use healing potion

			std::cout << "Cleric: \"Why do you want to use these instead of MY help?\n"
				<< "If I'll ever see you again i won't help you. Even if your dying.\"\n";
			answerAgain = false;

			break;

		case 'e'://heal to max hp

			std::cout << "Cleric: \"How can you heal like this? Please teach me how to heal like so.\n"
				<< "Oh right I went away to learn and help. Thank you for remembering me this.\"\n";
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

void clerico()
{

	char answer{ 0 };


	bool answerAgain{ false };



	std::cout << "Chierico: \"Ciao piccoletto, vedo che hai bisogno di cure. Lascialo a me.\"\n";

	do
	{

		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes
			std::cout << "Chierico: \"Devi sempre avere un chierico come me nel tuo gruppo.\n"
				<< "Non saprai mai quando avrai bisogno di essere curato.\n"
				<< "Ci vediaamo nel futuro.\"\n";
			answerAgain = false;

			break;

		case 'n'://no

			std::cout << "Chierico: \"Perche' non vuoi la mia cura? Bene, quindi ci vediamo nel futuro.\"\n";
			answerAgain = false;

			break;

		case 'w'://Skip

			std::cout << "Chierico: \"Perche' non ti do' questa mappa. E' piu' utile a te che a me.\""
				<< "\n(Ti da' una mappa del posto e ti cura)\n"
				<< "(Dopo che ha finito se ne va)\n";
			player().heal(0.01);
			answerAgain = false;

			break;

		case 'a'://attack

			std::cout << "Chierico: \"Non ti attacchero'. Me ne vvado.\"\n";
			answerAgain = false;

			break;

		case '3'://use healing potion

			std::cout << "Chierico: \"Perche' vuoi usare quelle al posto del MIO aiuto?\n"
				<< "Se ti vedo di nuovo non ti aiutero'. Anche se stai morendo.\"\n";
			answerAgain = false;

			break;

		case 'e'://heal to max hp

			std::cout << "Chierico: \"Come puoi curare cosi'? Per favore insegnami come fare.\n"
				<< "Oh giusto, me ne sono andato per aiutare e imparare. Grazie per avermelo ricordato.\"\n";
			answerAgain = false;

			break;

		default:

			std::cout << "(Non possibile)\n";
			answerAgain = true;

			break;
		}

	} while (answerAgain == true);


	encounter().setIsGone(true);
	encounter().setCanTalk(false);

}



/// above this point there are the dialogues for the cleric encounter
// not related to the cleric
void Cleric::attack(Encounters& enc)
{
}

void Cleric::printStats() const
{
}

void Cleric::resetAllStats()
{
}

int Cleric::useSpell()
{
	return 0;
}

int Cleric::useBlessing()
{
	int healing{ 0 };
	int spiritualEnergyUsed{ 0 };
	bool answerAgain{ false };


	std::cout << "Which blessing do you want to cast?\n"
		<< "1: Small Healing.(1 spiritual energy)\n"
		<< "2: Restoration.(5 spiritual energy)\n"
		<< "3: Complete restoration.(10 spiritual energy)\n";

	do
	{
		switch (Input::character())
		{
		case '1':// option 1: Small Healing.
			spiritualEnergyUsed = 1;
			healing = hp / 3;
			answerAgain = false;
			break;

		case '2':// option 2: Restoration.
			spiritualEnergyUsed = 5;
			healing = hp / 2;
			answerAgain = false;
			break;

		case '3':// option 3: Complete restoration.
			spiritualEnergyUsed = 10;
			healing = hp;
			answerAgain = false;
			break;

		default:
			printNotPossible();
			answerAgain = true;
			break;
		}
	} while (answerAgain);

	return 0;
}

int Cleric::useCurse()
{
	return 0;
}
