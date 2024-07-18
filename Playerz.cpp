
#include <iostream>
#include "Player Stats.h"
#include "Random.h"
#include "Encounters.h"
#include "Playerz.h"
#include "Input.h"
#include "Everywhere Used Func.h"
#include "Costants.h"



void Playerz::heal(double healing)
{

	std::cout << name <<" healed of " << healing << "hp.\n";
	if (hp + healing >= maxHp)
	{

		hp = maxHp;

	}
	else
	{

		hp += healing;

	}
	std::cout << "Now you have " << hp << "hp.\n";

}

void Playerz::attack(Encounters& enc)
{
	std::cout << "\nYou attack the encounter.";
	if (Random::get(0, 99) <= critRate)
	{

		std::cout << "\nYou did a critical hit!\n";
		enc.takeDamage(atk * critDmg);

	}
	else
	{

		enc.takeDamage(atk);

	}
}

void Playerz::takeDamage(double damage)
{
	// add damageType to say what is the cause for the damage
	damage = damage - (damage * def / 100);
	hp -= damage;
	std::cout << "\n" << name << " took " << damage << "dmg.\n";

	if (hp <= 0.0)
		std::cout << "Kelmod: \"You died. Haha, loser!\"\n";
	else
		std::cout << "Now you have " << hp << "hp.\n";
}

void Playerz::increaseXpAndCheckForLvlUp(short value)
{

	xp += value;
	std::cout << "Xp increased of " << value;
	lvlUp();

}

void Playerz::printStats() const
{
	std::cout << "\n\nYour stats are:\n"
		<< "Health: " << hp << "\n"
		<< "Max Health: " << maxHp << "\n"
		<< "Attack: " << atk << "\n"
		<< "Max Attack: " << maxAtk << "\n"
		<< "Xp: " << xp << "\n"
		<< "Xp to reach for level up: " << lvlUpXp << "\n"
		<< "Level: " << lvl << "\n"
		<< "Crit Rate: " << critRate << "\n"
		<< "Crit Damage: " << critDmg << "\n"
		<< "Stamina: " << stamina << "\n"
		<< "Weight: " << weight << "\n"
		<< "Strenght: " << m_stats.strength << "\n"
		<< "Dexterity: " << m_stats.dexterity << "\n"
		<< "Constitution: " << m_stats.constitution << '\n'
		<< "Intelligence: " << m_stats.intelligence << "\n"
		<< "Wisdom: " << m_stats.wisdom << "\n"
		<< "Charisma: " << m_stats.charisma << "\n";
}

void Playerz::resetAllStats()
{
	// reset player character stats
	hp = 10;
	maxHp = 10;
	atk = 4;
	maxAtk = 4;
	def = 10;
	maxDef = 10;
	xp = 0;
	lvlUpXp = 22;
	lvl = 1;
	critRate = 10;
	critDmg = 2;
	stamina = 100;
	weight = 0;

	// reset stats
	m_stats.strength = 20;
	m_stats.dexterity = 20;
	m_stats.intelligence = 20;
	m_stats.wisdom = 20;
	m_stats.charisma = 20;

	//reset the inventory
	m_inventory.reset();
}

// under this line there are all the private member functions

void Playerz::setStats()
{
	short statsArr[k_statsAmount];
	bool repeat{ true };

	// set all the stats to -1 for later usage in assignStats()
	m_stats.strength	 = -1;
	m_stats.dexterity	 = -1;
	m_stats.constitution = -1;
	m_stats.intelligence = -1;
	m_stats.wisdom		 = -1;
	m_stats.charisma	 = -1;

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
	applyStatBonus();
}

void Playerz::lvlUp()
{

	// if the xp needed to lvl up is the same as the xp the player has increase stats
	if (lvlUpXp <= xp)
	{

		int hpIncrease{ Random::get(1, 10) };
		++lvl;
		lvlUpXp += lvlUpXp * 25 / 100;
		xp = 0;
		maxAtk += 1.5;
		atk += 1.5;
		maxHp += hpIncrease;
		hp += hpIncrease;

		std::cout << "Your stats increased.\n";

	}
	else// nothing happens
	{
		// IIOOOII-IIOOOII-IIOOOII-IIOOOII-IIOOOII-IOI-IIIOOII>
	}

}

void Playerz::rollStats(short arr[k_statsAmount]) const
{
	for (int i = 0; i < k_statsAmount; ++i)
	{
		arr[i] = Random::get(1, 20);
	}
}

bool Playerz::checkIfTmpStatsAreOk(short arr[k_statsAmount]) const
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

void Playerz::assignStats(short arr[k_statsAmount])
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
				if (m_stats.strength == -1)
				{
					m_stats.strength = arr[j];
					++j;
					std::cout << "Kelmod: \"Strength assigned!\n"
						<< "Strength: " << m_stats.strength << '\n';
				}
				else if (lastInput == '1')
				{
					arr[j - 1] = m_stats.strength;
					m_stats.strength = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Strength replaced!\n"
						<< "Strength: " << m_stats.strength << '\n';
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
				if (m_stats.dexterity == -1)
				{
					m_stats.dexterity = arr[j];
					++j;
					std::cout << "Kelmod: \"Dexterity assigned!\n"
						<< "Dexterity: " << m_stats.dexterity << '\n';
				}
				else if (lastInput == '2')
				{
					arr[j - 1] = m_stats.dexterity;
					m_stats.dexterity = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Dexterity replaced!\n"
						<< "Dexterity: " << m_stats.dexterity << '\n';
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
				if (m_stats.constitution == -1)
				{
					m_stats.constitution = arr[j];
					++j;
					std::cout << "Kelmod: \"Constitution assigned!\n"
						<< "Constitution: " << m_stats.constitution << '\n';
				}
				else if (lastInput == '3')
				{
					arr[j - 1] = m_stats.constitution;
					m_stats.constitution = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Constitution replaced!\n"
						<< "Constitution: " << m_stats.constitution << '\n';
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
				if (m_stats.intelligence == -1)
				{
					m_stats.intelligence = arr[j];
					++j;
					std::cout << "Kelmod: \"Intelligence assigned!\n"
						<< "Intelligence: " << m_stats.intelligence << '\n';
				}
				else if (lastInput == '4')
				{
					arr[j - 1] = m_stats.intelligence;
					m_stats.intelligence = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Intelligence replaced!\n"
						<< "Intelligence: " << m_stats.intelligence << '\n';
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
				if (m_stats.wisdom == -1)
				{
					m_stats.wisdom = arr[j];
					++j;
					std::cout << "Kelmod: \"Wisdom assigned!\n"
						<< "Wisdom: " << m_stats.wisdom << '\n';
				}
				else if (lastInput == '5')
				{
					arr[j - 1] = m_stats.wisdom;
					m_stats.wisdom = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Wisdom replaced!\n"
						<< "Wisdom: " << m_stats.wisdom << '\n';
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
				if (m_stats.charisma == -1)
				{
					m_stats.charisma = arr[j];
					++j;
					std::cout << "Kelmod: \"Charisma assigned!\n"
						<< "Charisma: " << m_stats.charisma << '\n';
				}
				else if (lastInput == '6')
				{
					arr[j - 1] = m_stats.charisma;
					m_stats.charisma = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = -1;
					std::cout << "Kelmod: \"Charisma replaced!\n"
						<< "Charisma: " << m_stats.charisma << '\n';
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
				short* stat = &m_stats.strength;
				for (int i{ j }; i < k_statsAmount; ++i)
				{
					if (m_stats.strength == -1)
						stat = &m_stats.strength;
					else if (m_stats.dexterity == -1)
						stat = &m_stats.dexterity;
					else if (m_stats.constitution == -1)
						stat = &m_stats.constitution;
					else if (m_stats.intelligence == -1)
						stat = &m_stats.intelligence;
					else if (m_stats.wisdom == -1)
						stat = &m_stats.wisdom;
					else if (m_stats.charisma == -1)
						stat = &m_stats.charisma;
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

void Playerz::applyStatBonus()
{
	// add strenght bonus
	atk += 0.5;
	maxAtk += 0.5;
	// add dexterity bonus
	// add intelligence bonus
	// add wisdom bonus
	// add charisma bonus
}
