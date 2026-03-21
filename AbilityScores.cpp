
#include <iostream>
#include "AbilityScores.h"
#include "Random.h"
#include "Input.h"
#include "Costants.h"



std::ostream& Creatures::Player::operator<<(const AbilityScores& stats, std::ostream& out)
{
	std::cout << "Strength: " << stats.m_strength << ";\n"
		<< "Dexterity: " << stats.m_dexterity << ";\n"
		<< "Constitution: " << stats.m_constitution << ";\n"
		<< "Intelligence: " << stats.m_intelligence << ";\n"
		<< "Wisdom: " << stats.m_wisdom << ";\n"
		<< "Charisma: " << stats.m_charisma << ";\n";
	return out;
}

void Creatures::Player::AbilityScores::setStats()
{
	short statsArr[k_statsAmount];
	bool repeata{ true };
    bool answerAgain{ false };


	// set all the stats to -1 for later usage in assignStats()
	reset();
	// roll the stats, ask the player if they like them and assign them to where they belong
	// if the player does not like the stats, repeat from the start
	// also applies the stat bonus/malus at the end
	while (repeata)
	{
        rollStats(statsArr);
		if (checkIfTempStatsAreOk(statsArr))
		{
			do
			{
				assignStats(statsArr);
				std::cout << "kelmod: \"This is your situation with the stats.\"\n";
				printStats();
				answerAgain = isPlayerSure("Kelmod: \"Do you want to keep these?\" (y/n)");
				putStatsBackInTheArray(statsArr, !answerAgain);
			} while (!answerAgain);
			repeata = false;
			std::cout << "aaa";
		}
		else;
		std::cout << repeata;
	}
}

void Creatures::Player::AbilityScores::silentSetStats()
{
    m_strength = Random::get(1, 20);
	m_dexterity = Random::get(1, 20);
	m_constitution = Random::get(1, 20);
	m_intelligence = Random::get(1, 20);
	m_wisdom = Random::get(1, 20);
	m_charisma = Random::get(1, 20);
}

void Creatures::Player::AbilityScores::reset()
{
	m_strength = -1;
	m_dexterity = -1;
	m_constitution = -1;
	m_intelligence = -1;
	m_wisdom = -1;
    m_charisma = -1;
}

void Creatures::Player::AbilityScores::rollStats(short arr[k_statsAmount]) const
{
	for (int i = 0; i < k_statsAmount; ++i)
	{
		arr[i] = Random::get(1, 20);
	}
}

bool Creatures::Player::AbilityScores::checkIfTempStatsAreOk(short arr[k_statsAmount])
{
	bool answerAgain{ false };
	int amountOfLowValueStats{ 0 };

	std::cout << "\nKelmod: \"These are the stats for your character.\"\n";
	for (int i = 0; i < (k_statsAmount - 1); ++i)
		std::cout << arr[i] << ", ";
	std::cout << arr[(k_statsAmount - 1)] << ".\n";
	std::cout << "Kelmod: \"Do you want to keep 'em?\"\n"
		<< "y: Yes, I like them.\n"
		<< "n: Nope. Reroll them please.\n"
		<< "s: Do whatever you want.\n";
	do
	{

		switch (Input::character())
		{
		case 'y':// yes: Yes, I like them.

			std::cout << "Kelmod: \"Time go to step three then.\"\n";
			return true;

		case 'n':// no: Nope. Reroll them please.

			std::cout << "Kelmod: \"Seriously? Why would I...\"\n"
				<< "Nanre: \"Rerolling. Understood Kelmod?\"\n"
				<< "Kelmod: \"y-yes, I will reroll them...\"";
			return false;

		case 's':// skip: Do what you want.

			std::cout << "kelmod: \"You said it! Woohoo! Let me see...\"\n";
			for (int i = 0; i < k_statsAmount; ++i)
			{
				if (arr[i] < 10)
				{
					++amountOfLowValueStats;
				}
			}
			if (amountOfLowValueStats >= 4)
			{
				std::cout << "Kelmod: \"I see... I'm keeping them. They are low enough.\n"
					<< "wait! I meant they are perferìct for you. Totally perfect!\"\n";
				return true;
			}
			else
			{
				std::cout << "Kelmod: \"Let's see... Nah, they aren't good enough to me.\n"
					<< "I think we should reroll them and see if the next ones are wo-"
					<< "I mean, better.\"\n";
				return false;
			}
			answerAgain = false;
			break;

		default:
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

	std::cout << "Kelmod: \"Ready or not, we are assigning the numbers.\"\n";
	while (j < k_statsAmount)
	{
		std::cout << "Kelmod: \"These are the values you can use: ";
		for (int i{ j }; i < (k_statsAmount - 1); ++i)
			std::cout << arr[i] << ", ";
		std::cout << arr[(k_statsAmount - 1)] << ".\n"
			<< "Where do you want to put " << arr[j] << "?\"\n"
			<< "1: Strength.\n"
			<< "2: Dexterity.\n"
			<< "3: Constitution.\n"
			<< "4: Intelligence.\n"
			<< "5: Wisdom.\n"
			<< "6: Charisma.\n"
			<< "d: Place automatically what's left.\n";

		do
		{
			switch (Input::character())
			{
			case '1':// option 1: strength.
				if (m_strength == -1)
				{
					m_strength = arr[j];
					++j;
					std::cout << "Kelmod: \"Strength assigned!\n"
						<< "Strength: " << m_strength << '\n';
				}
				else if (lastInput == '1')
				{
					arr[j - 1] = m_strength;
					m_strength = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Strength replaced!\n"
						<< "Strength: " << m_strength << '\n';
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
				if (m_dexterity == -1)
				{
					m_dexterity = arr[j];
					++j;
					std::cout << "Kelmod: \"Dexterity assigned!\n"
						<< "Dexterity: " << m_dexterity << '\n';
				}
				else if (lastInput == '2')
				{
					arr[j - 1] = m_dexterity;
					m_dexterity = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Dexterity replaced!\n"
						<< "Dexterity: " << m_dexterity << '\n';
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
				if (m_constitution == -1)
				{
					m_constitution = arr[j];
					++j;
					std::cout << "Kelmod: \"Constitution assigned!\n"
						<< "Constitution: " << m_constitution << '\n';
				}
				else if (lastInput == '3')
				{
					arr[j - 1] = m_constitution;
					m_constitution = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Constitution replaced!\n"
						<< "Constitution: " << m_constitution << '\n';
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
				if (m_intelligence == -1)
				{
					m_intelligence = arr[j];
					++j;
					std::cout << "Kelmod: \"Intelligence assigned!\n"
						<< "Intelligence: " << m_intelligence << '\n';
				}
				else if (lastInput == '4')
				{
					arr[j - 1] = m_intelligence;
					m_intelligence = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Intelligence replaced!\n"
						<< "Intelligence: " << m_intelligence << '\n';
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
				if (m_wisdom == -1)
				{
					m_wisdom = arr[j];
					++j;
					std::cout << "Kelmod: \"Wisdom assigned!\n"
						<< "Wisdom: " << m_wisdom << '\n';
				}
				else if (lastInput == '5')
				{
					arr[j - 1] = m_wisdom;
					m_wisdom = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Wisdom replaced!\n"
						<< "Wisdom: " << m_wisdom << '\n';
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
				if (m_charisma == -1)
				{
					m_charisma = arr[j];
					++j;
					std::cout << "Kelmod: \"Charisma assigned!\n"
						<< "Charisma: " << m_charisma << '\n';
				}
				else if (lastInput == '6')
				{
					arr[j - 1] = m_charisma;
					m_charisma = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Charisma replaced!\n"
						<< "Charisma: " << m_charisma << '\n';
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
				short* stat = &m_strength;
				for (int i{ j }; i < k_statsAmount; ++i)
				{
					if (m_strength == -1)
						stat = &m_strength;
					else if (m_dexterity == -1)
						stat = &m_dexterity;
					else if (m_constitution == -1)
						stat = &m_constitution;
					else if (m_intelligence == -1)
						stat = &m_intelligence;
					else if (m_wisdom == -1)
						stat = &m_wisdom;
					else if (m_charisma == -1)
						stat = &m_charisma;
					else
						i = 4;
					*stat = arr[i];
				}
				j = k_statsAmount;
				break;
			}
			default:
				//printNotPossible();
				answerAgain = true;
				break;
			}
		} while (answerAgain);
	}
}

void Creatures::Player::AbilityScores::printStats() const
{
	std::cout << "Strength: " << m_strength << ";\n"
		<< "Dexterity: " << m_dexterity << ";\n"
		<< "Constitution: " << m_constitution << ";\n"
		<< "Intelligence: " << m_intelligence << ";\n"
		<< "Wisdom: " << m_wisdom << ";\n"
		<< "Charisma: " << m_charisma << ";\n";
}

void Creatures::Player::AbilityScores::putStatsBackInTheArray(short arr[k_statsAmount], bool ignore)
{
	if (ignore)
		return;
	arr[0] = m_strength;
    arr[1] = m_dexterity;
	arr[2] = m_constitution;
	arr[3] = m_intelligence;
	arr[4] = m_wisdom;
    arr[5] = m_charisma;
	reset();
}
