
#include "Barbarian.h"
#include "Random.h"

namespace Creatures
{
    namespace Player
    {
        void Barbarian::attack(Encounters& enc)
        {
            bool isOneShotted{ false };


            if ((Random::get(0, 99) < oneShotChance))
            {
                std::cout << "You oneshotted " << enc.getName() << "!\n";
                enc.takeDamage(enc.getHealth());
            }
            else
            {
                if (Random::get(0, 99) < critRate)
                {
                    std::cout << "You did a crtitcal hit!\n"
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

        void Barbarian::printStats() const
        {
            std::cout << "\n\nYour stats are:\n"
                << "Health: " << hp << "\n"
                << "Max Health: " << maxHp << "\n"
                << "Attack: " << atk << "\n"
                << "Max Attack: " << maxAtk << "\n"
                << "Chance to one shot the enemy: " << oneShotChance << '\n'
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

        void Barbarian::resetAllStats()
        {
            // reset player character stats
            hp = 10;
            maxHp = 10;
            atk = 5;
            maxAtk = 5;
            def = -10;
            maxDef = -10;
            xp = 0;
            lvlUpXp = 22;
            lvl = 1;
            critRate = 1;
            critDmg = 1.5;
            oneShotChance = 10;
            stamina = 70;
            weight = 0;

            // reset stats
            m_stats.strength = -1;
            m_stats.dexterity = -1;
            m_stats.intelligence = -1;
            m_stats.wisdom = -1;
            m_stats.charisma = -1;

            //reset the inventory
            m_inventory.reset();
        }

    };
};