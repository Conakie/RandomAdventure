
#include <iostream>
#include "Player Stats.h"
#include "Random.h"
#include "Encounters.h"
#include "Playerz.h"
#include "Input.h"
#include "Everywhere Used Func.h"
#include "Costants.h"
#include "AbilityScores.h"



namespace Creatures
{
	namespace Player
	{
		void Playerz::heal(double healing)
		{

			std::cout << name << " healed of " << healing << "hp.\n";
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
			std::cout << "You attack " << enc.getName() << ".\n";
			if (Random::get(0, 99) <= critRate)
			{
				std::cout << "\nYou did a critical hit!\n"
					<< enc.getName() << " took " << (atk * critDmg) << "dmg.\n";
				enc.takeDamage(atk * critDmg);

			}
			else
			{
				std::cout << enc.getName() << " took " << (atk) << "dmg.\n";
				enc.takeDamage(atk);

			}
		}

		void Playerz::attack(Encounter::Encounterz& enc)
		{
			std::cout << "You attack " << enc.getName() << ".\n";
			if (Random::get(0, 99) <= critRate)
			{
				std::cout << "\nYou did a critical hit!\n"
					<< enc.getName() << " took " << (atk * critDmg) << " dmg.\n";
				enc.takeDamage(atk * critDmg);

			}
			else
			{
				std::cout << enc.getName() << " took " << (atk) << " dmg.\n";
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
				<< "Defence: " << def << '\n'
				<< "Max defence: " << maxDef << '\n'
				<< "Xp: " << xp << "\n"
				<< "Xp to reach for level up: " << xpPerLvl << "\n"
				<< "Level: " << lvl << "\n"
				<< "Crit Rate: " << critRate << "\n"
				<< "Crit Damage: " << critDmg << "\n"
				<< "Stamina: " << stamina << "\n"
				<< "Weight: " << weight << "\n";
			stats.print();
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
			xpPerLvl = 22;
			lvl = 1;
			critRate = 10;
			critDmg = 2;
			stamina = 100;
			weight = 0;

			// reset stats
			stats.reset();

			//reset the inventory
			inventory.reset();
		}

		// under this line there are all the private member functions

		void Playerz::setStats()
		{
			stats.setStats();
			applyStatBonus();
		}

		void Playerz::setName(std::string newName)
		{
			name = newName;
			std::cout << "Necoto: \"From now on you shall be known as " << name << ".\"\n";
		}

		void Playerz::lvlUp()
		{

			// if the xp needed to lvl up is the same as the xp the player has increase stats
			if (xpPerLvl <= xp)
			{

				int hpIncrease{  };
				double atkIncrease{ static_cast<double>(Random::get(10, 60)) / 10.0 };
				++lvl;
				xpPerLvl += xpPerLvl * 50 / 100;
				xp = 0;
				maxAtk += atkIncrease + stats.getStrengthBonus();
				atk += atkIncrease + stats.getStrengthBonus();
				maxHp += hpIncrease + stats.getConstitutionBonus();
				hp += hpIncrease + stats.getConstitutionBonus();
				if (stats.getDexterityBonus() >= 0)
					critRate += stats.getDexterityBonus();
				else
					critRate += 1;
				std::cout << "Your stats increased.\n";

			}
			else// nothing happens
			{
				// IIOOOII-IIOOOII-IIOOOII-IIOOOII-IIOOOII-IOI-IIIOOII>
			}

		}

		void Playerz::applyStatBonus()
		{
			// add strenght bonus
			atk += stats.getStrengthBonus();
			maxAtk += stats.getStrengthBonus();
			hp += stats.getConstitutionBonus();
			maxHp += stats.getConstitutionBonus();
			critRate += stats.getDexterityBonus();
			// add dexterity bonus
			// add intelligence bonus
			// add wisdom bonus
			// add charisma bonus
		}
	};
};
