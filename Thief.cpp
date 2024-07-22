
#include "Thief.h"
#include "Random.h"



namespace Creatures
{
	namespace Player
	{
		void Thief::attack(Encounters& enc)
		{
			bool isACritHit{ false };


			std::cout << "You chose violence.\n";
			if (Random::get(0, 99) < critRate)
				isACritHit = true;

			if (Random::get(0, 99) < stealthHitChance)
			{
				std::cout << "You attacked " << enc.getName() << " from behind.\n";
				if (isACritHit)
				{
					std::cout << "You did a critical hit!\n"
						<< enc.getName() << " took " << (atk * steathDmgBonus * critDmg) << " dmg.\n";
					enc.takeDamage(atk * steathDmgBonus * critDmg);
				}
				else
				{
					std::cout << enc.getName() << " took " << (atk * steathDmgBonus) << " dmg.\n";
					enc.takeDamage(atk * steathDmgBonus);
				}
			}
			else
			{
				if (isACritHit)
				{
					std::cout << "You did a critical hit!\n"
						<< enc.getName() << " took " << (atk * critDmg) << " dmg.\n";
					enc.takeDamage(atk * critDmg);
				}
				else
				{
					std::cout << enc.getName() << " took " << (atk) << " dmg.\n";
					enc.takeDamage(atk);
				}
			}

		}

		void Thief::printStats() const
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
				<< "Stealth hit chance: " << stealthHitChance << '\n'
				<< "Stealth damage bonus: " << steathDmgBonus << '\n'
				<< "Stamina: " << stamina << "\n"
				<< "Weight: " << weight << "\n"
				<< "Strenght: " << m_stats.strength << "\n"
				<< "Dexterity: " << m_stats.dexterity << "\n"
				<< "Constitution: " << m_stats.constitution << '\n'
				<< "Intelligence: " << m_stats.intelligence << "\n"
				<< "Wisdom: " << m_stats.wisdom << "\n"
				<< "Charisma: " << m_stats.charisma << "\n";
		}

		void Thief::resetAllStats()
		{
			// reset player character stats
			hp = 9;
			maxHp = 9;
			atk = 2;
			maxAtk = 2;
			def = 0;
			maxDef = 0;
			xp = 0;
			lvlUpXp = 22;
			lvl = 1;
			critRate = 15;
			critDmg = 2;
			stealthHitChance = 40;
			steathDmgBonus = 2.5;
			stamina = 120;
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

	};
};