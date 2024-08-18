
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
// not related to the player controlled cleric
namespace Creatures
{
	namespace Player
	{
		void Cleric::heal(double healing)
		{
			Playerz::heal(healing);
			if (spiritualEnergy + 10 < maxSpiritualEnergy)
				spiritualEnergy += 10;
			else
				spiritualEnergy = maxSpiritualEnergy;
		}

		void Cleric::attack(Encounters& enc)
		{
			bool answerAgain{ false };
			// can be damage or healing based on the player choice
			double value{ 0.0 };

			do
			{
				std::cout << "What do you want to use:\n"
					<< "1: Morningstar.\n"
					<< "2: Blessing.\n"
					<< "3: Curse.\n";

				switch (Input::character())
				{
				case '1':// option 1: Morningsatr.
					Playerz::attack(enc);
					answerAgain = false;
					break;

				case '2':// option 2: Blessing.
					value = useBlessing();
					if (value > 0)
					{
						std::cout << "No party members. Healing yourself...\n";
						heal(value);
					}
					else
					{
						std::cout << "You do not have enough spiritual energy.\n"
							<< "Choose another action or blessing.\n";
					}

					answerAgain = false;
					break;

				case '3':// option 3: Curse.
					value = useCurse();
					if (value > 0)
					{
						std::cout << enc.getName() << " took " << value << " dmg.\n";
						enc.takeDamage(value);
					}
					else
					{
						std::cout << "You do not have enough spiritual energy.\n"
							<< "Choose another curse or action.\n";
					}
					answerAgain = false;
					break;

				default:
					printNotPossible();
					answerAgain = true;
					break;
				}
			} while (answerAgain);

		}

		void Cleric::attack(Creatures::Encounter::Encounterz& enc)
		{
			bool answerAgain{ false };
			// can be damage or healing based on the player choice
			double value{ 0.0 };

			do
			{
				std::cout << "What do you want to use:\n"
					<< "1: Morningstar.\n"
					<< "2: Blessing.\n"
					<< "3: Curse.\n";

				switch (Input::character())
				{
				case '1':// option 1: Morningsatr.
					Playerz::attack(enc);
					answerAgain = false;
					break;

				case '2':// option 2: Blessing.
					value = useBlessing();
					if (value > 0)
					{
						std::cout << "No party members. Healing yourself...\n";
						heal(value);
					}
					else
					{
						std::cout << "You do not have enough spiritual energy.\n"
							<< "Choose another action or blessing.\n";
					}

					answerAgain = false;
					break;

				case '3':// option 3: Curse.
					value = useCurse();
					if (value > 0)
					{
						std::cout << enc.getName() << " took " << value << " dmg.\n";
						enc.takeDamage(value);
					}
					else
					{
						std::cout << "You do not have enough spiritual energy.\n"
							<< "Choose another curse or action.\n";
					}
					answerAgain = false;
					break;

				default:
					printNotPossible();
					answerAgain = true;
					break;
				}
			} while (answerAgain);
		}

		void Cleric::printStats() const
		{
			std::cout << "\n\nYour stats are:\n"
				<< "Health: " << hp << "\n"
				<< "Max Health: " << maxHp << "\n"
				<< "Attack: " << atk << "\n"
				<< "Max Attack: " << maxAtk << "\n"
				<< "Spiritual energy: " << spiritualEnergy << '\n'
				<< "Max spiritual energy: " << maxSpiritualEnergy << '\n'
				<< "Xp: " << xp << "\n"
				<< "Xp to reach for level up: " << xpPerLvl << "\n"
				<< "Level: " << lvl << "\n"
				<< "Crit Rate: " << critRate << "\n"
				<< "Crit Damage: " << critDmg << "\n"
				<< "Stamina: " << stamina << "\n"
				<< "Weight: " << weight << "\n";
			stats.print();
		}

		void Cleric::resetAllStats()
		{
			// reset player character stats
			hp = 10;
			maxHp = 10;
			atk = 3.5;
			maxAtk = 3.5;
			def = 2;
			maxDef = 2;
			xp = 0;
			xpPerLvl = 22;
			lvl = 1;
			critRate = 5;
			critDmg = 2;
			stamina = 85;
			weight = 0;
			spiritualEnergy = 60;
			maxSpiritualEnergy = 60;

			// reset stats
			stats.reset();

			//reset the inventory
			inventory.reset();
		}

		double Cleric::useBlessing()
		{
			double healing{ 0 };
			int spiritualEnergyUsed{ 0 };
			bool answerAgain{ false };


			std::cout << "Which blessing do you want to cast? (" << spiritualEnergy << " spiritual energy)\n"
				<< "1: Small Healing.(1 spiritual energy)\n"
				<< "2: Restoration.(5 spiritual energy)\n"
				<< "3: Complete restoration.(10 spiritual energy)\n";

			do
			{
				switch (Input::character())
				{
				case '1':// option 1: Small Healing.
					spiritualEnergyUsed = 1;
					healing = maxHp / 3;
					answerAgain = false;
					break;

				case '2':// option 2: Restoration.
					spiritualEnergyUsed = 5;
					healing = maxHp / 2;
					answerAgain = false;
					break;

				case '3':// option 3: Complete restoration.
					spiritualEnergyUsed = 10;
					healing = maxHp;
					answerAgain = false;
					break;

				default:
					printNotPossible();
					answerAgain = true;
					break;
				}
			} while (answerAgain);

			if (spiritualEnergyUsed > spiritualEnergy)
				return -1;
			else
				spiritualEnergy -= spiritualEnergyUsed;

			return healing;
		}

		double Cleric::useCurse()
		{
			double dmg{ 0 };
			int spiritualEnergyUsed{ 0 };
			bool answerAgain{ false };


			std::cout << "Which blessing do you want to cast? (" << spiritualEnergy << " spiritual energy)\n"
				<< "1: Breaking.(1 spiritual energy)\n"
				<< "2: Mental degeneration.(5 spiritual energy)\n"
				<< "3: Body collapse.(10 spiritual energy)\n";

			do
			{
				switch (Input::character())
				{
				case '1':// option 1: Breaking.
					spiritualEnergyUsed = 1;
					dmg = 3 * lvl;
					answerAgain = false;
					break;

				case '2':// option 2: Mental degenaration.
					spiritualEnergyUsed = 5;
					dmg = 5 * lvl;
					answerAgain = false;
					break;

				case '3':// option 3: Body collapse.
					spiritualEnergyUsed = 10;
					dmg = 6 * lvl;
					answerAgain = false;
					break;

				default:
					printNotPossible();
					answerAgain = true;
					break;
				}
			} while (answerAgain);

			if (spiritualEnergyUsed > spiritualEnergy)
				return -1;
			else
				spiritualEnergy -= spiritualEnergyUsed;

			return dmg;
		}
	};
};
