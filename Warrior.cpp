
#include "Warrior.h"
#include "Random.h"



namespace Creatures
{
    namespace Player
    {
        void Warrior::attack(Encounters& enc)
        {
            std::cout << "You attack " << enc.getName() << '\n';
            if (Random::get(0, 99) < critRate)
            {
                std::cout << "You did a critical hit!\n"
                    << enc.getName() << " took " << (atk * critDmg) << "dmg.\n";
                enc.takeDamage(atk * critDmg);
            }
            else
            {
                std::cout << enc.getName() << " took " << (atk) << "dmg.\n";
                enc.takeDamage(atk);
            }
        }

        void Warrior::resetAllStats()
        {
            // reset player character stats
            hp = 12;
            maxHp = 12;
            atk = 4;
            maxAtk = 4;
            def = 10;
            maxDef = 10;
            xp = 0;
            lvlUpXp = 22;
            lvl = 1;
            critRate = 10;
            critDmg = 1.5;
            stamina = 110;
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