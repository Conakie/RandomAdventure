
#include <iostream>
#include "AbilityScores.h"
#include "Everywhere Used Func.h"
#include "Input.h"
#include "Random.h"



void Creatures::Player::AbilityScores::reset()
{
	strength = -1;
	dexterity = -1;
	constitution = -1;
	intelligence = -1;
	wisdom = -1;
	charisma = -1;
}

void Creatures::Player::AbilityScores::setStats()
{
	short statsArr[k_statsAmount];
	bool repeat{ true };


	// set all the stats to -1 for later usage in assignStats()
	reset();

	// roll the stats, ask the player if they like them and assign them to where they belong
	// if the player does not like the stats, repeat from the start
	// also applies the stat bonus/malus at the end
	while (repeat)
	{
		rollStats(statsArr);
		if (checkIfTmpStatsAreOk(statsArr))
		{
			assignStats(statsArr);
			repeat = false;
		}
	}
}

void Creatures::Player::AbilityScores::print() const
{
	std::cout << "Strength: " << strength << '\n'
		<< "Dexterity: " << dexterity << '\n'
		<< "Constiutution: " << constitution << '\n'
		<< "Intelligence: " << intelligence << '\n'
		<< "Wisdom: " << wisdom << '\n'
		<< "Charisma: " << charisma << '\n';
}

double Creatures::Player::AbilityScores::getStrengthBonus() const
{
	if (strength <= 5 && strength >= 0)
		return -0.5;
	else if (strength <= 10 && strength >= 5)
		return 1;
	else if (strength <= 15 && strength >= 10)
		return 1.5;
	else if (strength <= 20 && strength >= 15)
		return 2;
	else
		return 0;
	return 0;
}

int Creatures::Player::AbilityScores::getDexterityBonus() const
{
	if (dexterity <= 5 && dexterity >= 0)
		return -1;
	else if (dexterity <= 10 && dexterity >= 5)
		return 1;
	else if (dexterity <= 15 && dexterity >= 10)
		return 1;
	else if (dexterity <= 20 && dexterity >= 15)
		return 2;
	else
		return 0;
	return 0;
}

double Creatures::Player::AbilityScores::getConstitutionBonus() const
{
	if (constitution <= 5 && constitution >= 0)
		return -1;
	else if (constitution <= 10 && constitution >= 5)
		return 1;
	else if (constitution <= 15 && constitution >= 10)
		return 2;
	else if (constitution <= 20 && constitution >= 15)
		return 3;
	else
		return 0;
	return 0;
}

double Creatures::Player::AbilityScores::getIntelligenceBonus() const
{
	if (intelligence <= 5 && intelligence >= 0)
		return -0.5;
	else if (intelligence <= 10 && intelligence >= 5)
		return 1;
	else if (intelligence <= 15 && intelligence >= 10)
		return 1.5;
	else if (intelligence <= 20 && intelligence >= 15)
		return 2;
	else
		return 0;
	return 0;
}

double Creatures::Player::AbilityScores::getWisdomBonus() const
{
	if (wisdom <= 5 && wisdom >= 0)
		return -0.5;
	else if (wisdom <= 10 && wisdom >= 5)
		return 1;
	else if (wisdom <= 15 && wisdom >= 10)
		return 1.5;
	else if (wisdom <= 20 && wisdom >= 15)
		return 2;
	else
		return 0;
	return 0;
}

double Creatures::Player::AbilityScores::getCharismaBonus() const
{
	if (charisma <= 5 && charisma >= 0)
		return -0.5;
	else if (charisma <= 10 && charisma >= 5)
		return 1;
	else if (charisma <= 15 && charisma >= 10)
		return 1.5;
	else if (charisma <= 20 && charisma >= 15)
		return 2;
	else
		return 0;
	return 0;
}

void Creatures::Player::AbilityScores::rollStats(short arr[k_statsAmount]) const
{
	for (int i = 0; i < k_statsAmount; ++i)
	{
		arr[i] = Random::get(1, 20);
	}
}

bool Creatures::Player::AbilityScores::checkIfTmpStatsAreOk(short arr[k_statsAmount]) const
{
	bool answerAgain{ false };
	int amountOfLowValueStats{ 0 };

	std::cout << "\nKelmod: \"Those are the stats for your character.\"\n";
	for (int i = 0; i < (k_statsAmount - 1); ++i)
		std::cout << arr[i] << ", ";
	std::cout << arr[(k_statsAmount - 1)] << ".\n";
	std::cout << "Kelmod: \"Do you want to keep 'em?\"\n"
		<< "y: Yes, I like them.\n"
		<< "n: Nope. Reroll them please.\n"
		<< "s: Do what you want.\n";
	do
	{

		switch (Input::character())
		{
		case 'y':// yes: Yes, I like them.

			std::cout << "Kelmod: \"Time go to step three.\"\n";
			return true;

			break;

		case 'n':// no: Nope. Reroll them please.

			std::cout << "Kelmod: \"Seriously? Why would I...\"\n"
				<< "Nanre: \"Rerolling.\"";
			return false;

			break;

		case 's':// skip: Do what you want.

			std::cout << "Kelmod: \"You said it. Lemme see the stats again...\"\n";
			for (int i = 0; i < k_statsAmount; ++i)
			{
				if (arr[i] < 10)
				{
					++amountOfLowValueStats;
				}
			}
			if (amountOfLowValueStats >= 4)
			{
				std::cout << "Kelmod: \"I have decided what to do. I'm keeping 'em.\"\n";
				return true;
			}
			else
			{
				std::cout << "Kelmod: \"Nah, I don't like these too much. I'm rerolling 'em.\"\n";
				return false;
			}
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);

	return false;
}

void Creatures::Player::AbilityScores::assignStats(short arr[k_statsAmount])
{
	bool answerAgain{ false };
	char lastInput{ '0' };
	int j{ 0 };

	std::cout << "Kelmod: \"Now you can assign the number to its stat.\"\n";

	while (j < k_statsAmount)
	{
		std::cout << "Kelmod: \"These are the values you can use: ";
		for (int i{ j }; i < (k_statsAmount - 1); ++i)
			std::cout << arr[i] << ", ";
		std::cout << arr[(k_statsAmount - 1)] << ".\n"
			<< "Where do you want to put " << arr[j] << "?\"\n"
			<< "1: Strength.\n"
			<< "2: Dexterity.\n"
			<< "3: Intelligence.\n"
			<< "4: Wisdom.\n"
			<< "5: Charisma.\n"
			<< "d: Place automatically what's left.\n";

		do
		{
			switch (Input::character())
			{
			case '1':// option 1: strength.
				if (strength == -1)
				{
					strength = arr[j];
					++j;
					std::cout << "Kelmod: \"Strength assigned!\n"
						<< "Strength: " << strength << '\n';
				}
				else if (lastInput == '1')
				{
					arr[j - 1] = strength;
					strength = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Strength replaced!\n"
						<< "Strength: " << strength << '\n';
					lastInput = '0';
				}
				else
				{
					std::cout << "Kelmod: \"You have already placed something here.\n"
						<< "Enter '1' again to replace the current value.\"\n";
					lastInput = '1';
				}
				answerAgain = false;
				break;

			case '2':// option 2: dexterity.
				if (dexterity == -1)
				{
					dexterity = arr[j];
					++j;
					std::cout << "Kelmod: \"Dexterity assigned!\n"
						<< "Dexterity: " << dexterity << '\n';
				}
				else if (lastInput == '2')
				{
					arr[j - 1] = dexterity;
					dexterity = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Dexterity replaced!\n"
						<< "Dexterity: " << dexterity << '\n';
					lastInput = '0';
				}
				else
				{
					std::cout << "Kelmod: \"You have already placed something here.\n"
						<< "Enter '2' again to replace the current value.\"\n";
					lastInput = '2';
				}
				answerAgain = false;
				break;

			case '3':// option 3: constitution.
				if (constitution == -1)
				{
					constitution = arr[j];
					++j;
					std::cout << "Kelmod: \"Constitution assigned!\n"
						<< "Constitution: " << constitution << '\n';
				}
				else if (lastInput == '3')
				{
					arr[j - 1] = constitution;
					constitution = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Constitution replaced!\n"
						<< "Constitution: " << constitution << '\n';
					lastInput = '0';
				}
				else
				{
					std::cout << "Kelmod: \"You have already placed something here.\n"
						<< "Enter '3' again to replace the current value.\"\n";
					lastInput = '3';
				}
				answerAgain = false;
				break;

			case '4':// option 4: intelligence.
				if (intelligence == -1)
				{
					intelligence = arr[j];
					++j;
					std::cout << "Kelmod: \"Intelligence assigned!\n"
						<< "Intelligence: " << intelligence << '\n';
				}
				else if (lastInput == '4')
				{
					arr[j - 1] = intelligence;
					intelligence = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Intelligence replaced!\n"
						<< "Intelligence: " << intelligence << '\n';
					lastInput = '0';
				}
				else
				{
					std::cout << "Kelmod: \"You have already placed something here.\n"
						<< "Enter '4' again to replace the current value.\"\n";
					lastInput = '4';
				}
				answerAgain = false;
				break;

			case '5':// option 3: wisdom.
				if (wisdom == -1)
				{
					wisdom = arr[j];
					++j;
					std::cout << "Kelmod: \"Wisdom assigned!\n"
						<< "Wisdom: " << wisdom << '\n';
				}
				else if (lastInput == '5')
				{
					arr[j - 1] = wisdom;
					wisdom = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Wisdom replaced!\n"
						<< "Wisdom: " << wisdom << '\n';
					lastInput = '0';
				}
				else
				{
					std::cout << "Kelmod: \"You have already placed something here.\n"
						<< "Enter '5' again to replace the current value.\"\n";
					lastInput = '5';
				}
				answerAgain = false;
				break;

			case '6':// option 3: charisma.
				if (charisma == -1)
				{
					charisma = arr[j];
					++j;
					std::cout << "Kelmod: \"Charisma assigned!\n"
						<< "Charisma: " << charisma << '\n';
				}
				else if (lastInput == '6')
				{
					arr[j - 1] = charisma;
					charisma = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Charisma replaced!\n"
						<< "Charisma: " << charisma << '\n';
					lastInput = '0';
				}
				else
				{
					std::cout << "Kelmod: \"You have already placed something here.\n"
						<< "Enter '6' again to replace the current value.\"\n";
					lastInput = '6';
				}
				answerAgain = false;
				break;

			case 'd':// option d: Place automatically what's left.
			{
				short* stat = &strength;
				for (int i{ j }; i < k_statsAmount; ++i)
				{
					if (strength == -1)
						stat = &strength;
					else if (dexterity == -1)
						stat = &dexterity;
					else if (constitution == -1)
						stat = &constitution;
					else if (intelligence == -1)
						stat = &intelligence;
					else if (wisdom == -1)
						stat = &wisdom;
					else if (charisma == -1)
						stat = &charisma;
					else
						i = 4;
					*stat = arr[i];
				}
				j = k_statsAmount;
				break;
			}
			default:
				printNotPossible();
				answerAgain = true;
				break;
			}
		} while (answerAgain);
	}
}

std::ostream& Creatures::Player::operator<<(std::ostream out, AbilityScores& stats)
{
	std::cout << "Strength: " << stats.strength << '\n'
		<< "Dexterity: " << stats.dexterity << '\n'
		<< "Constiutution: " << stats.constitution << '\n'
		<< "Intelligence: " << stats.intelligence << '\n'
		<< "Wisdom: " << stats.wisdom << '\n'
		<< "Charisma: " << stats.charisma << '\n';
	return out;
}