
#include "Mage.h"
#include "Random.h"
#include "Input.h"
#include "Everywhere Used Func.h"



namespace Creatures
{
    namespace Player
    {
        void Mage::attack(Encounters& enc)
        {
            bool isACritHit{ false };
            bool answerAgain{ false };
            double spellDmg{ 0 };

            // check if this hit will be a crit hit or not
            if (Random::get(0, 99) < critRate)
                isACritHit = true;
            else
                isACritHit = false;

            // ask for the spell to use and multiply it if the hit is a critical one
            std::cout << "\nYou chose violence.\n";
            spellDmg = useSpell();
            if (isACritHit)
                spellDmg *= critDmg;

            // attack the encounter or notify the player he does not have enough mana
            if (spellDmg < 0)
            {
                std::cout << "You don't have enough mana. Choose another action or spell.\n";
            }
            else
            {
                std::cout << enc.getName() << " took " << spellDmg << "dmg.\n";
                enc.takeDamage(spellDmg);
            }
        }

        void Mage::printStats() const
        {
            std::cout << "\n\nYour stats are:\n"
                << "Health: " << hp << "\n"
                << "Max Health: " << maxHp << "\n"
                << "Attack: " << atk << "\n"
                << "Max Attack: " << maxAtk << "\n"
                << "Mana: " << mana << '\n'
                << "Max Mana: " << maxMana << '\n'
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

        void Mage::resetAllStats()
        {
            // reset player character stats
            hp = 8;
            maxHp = 8;
            atk = 2;
            maxAtk = 2;
            def = 0;
            maxDef = 0;
            xp = 0;
            lvlUpXp = 22;
            lvl = 1;
            critRate = 5;
            critDmg = 2;
            stamina = 70;
            weight = 0;
            mana = 100;
            maxMana = 100;

            // reset stats
            m_stats.strength = -1;
            m_stats.dexterity = -1;
            m_stats.constitution = -1;
            m_stats.intelligence = -1;
            m_stats.wisdom = -1;
            m_stats.charisma = -1;

            //reset the inventory
            m_inventory.reset();
        }

        int Mage::useSpell()
        {
            int dmg{ -1 };
            int manaUsed{ 0 };
            bool answerAgain{ false };


            std::cout << "Choose the spell you would like to use (Your mana: " << mana << ")\n"
                << "0: Dagger. (0 mana)\n"
                << "1: Lightning bolt. (3 mana)\n"
                << "2: Fire bolt. (3 mana)\n"
                << "3: Water cannon. (5 mana)\n"
                << "4: Fireball. (8 mana)\n"
                << "5: Iceball. (8 mana)\n"
                << "6: Chill touch. (10 mana)\n"
                << "7: Supernova. (80 mana)\n";

            do
            {
                switch (Input::character())
                {
                case '0':// option 0: Dagger.
                    manaUsed = 0;
                    dmg = 2 * lvl;
                    answerAgain = false;
                    break;

                case '1':// option 1: Lightning bolt.
                    manaUsed = 3;
                    dmg = 4 * lvl;
                    answerAgain = false;
                    break;

                case '2':// option 2: Fire bolt.
                    manaUsed = 3;
                    dmg = 4 * lvl;
                    answerAgain = false;
                    break;

                case '3':// option 3: Water cannon.
                    manaUsed = 5;
                    dmg = 5 * lvl;
                    answerAgain = false;
                    break;

                case '4':// option 4: Fireball.
                    manaUsed = 8;
                    dmg = 6 * lvl;
                    answerAgain = false;
                    break;

                case '5':// option 5: Iceball.
                    manaUsed = 8;
                    dmg = 6 * lvl;
                    answerAgain = false;
                    break;

                case '6':// option 6: Chill touch.
                    manaUsed = 10;
                    dmg = 8 * lvl;
                    answerAgain = false;
                    break;

                case '7':// option 7: Supernova.
                    manaUsed = 80;
                    dmg = 261884;
                    answerAgain = false;
                    break;

                default:
                    printNotPossible();
                    answerAgain = true;
                    break;
                }
            } while (answerAgain);

            if (manaUsed > mana)
                return -1;
            else
                mana -= manaUsed;

            return dmg;
        }

    };
};