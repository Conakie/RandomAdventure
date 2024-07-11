
#include "Mage.h"
#include "Random.h"
#include "Input.h"
#include "Everywhere Used Func.h"



void Mage::attack(Encounters enc) const
{
    bool isACritHit { false };
    bool answerAgain{ false };


    if (Random::get(0, 99) <= critRate)
        isACritHit = true;
    else
        isACritHit = false;

    std::cout << "\nYou attack the encounter.\n"
        << "Select the spell you want to use:\n"
        << "1: Lightning bolt (2 mana)\n"
        << "2: Fireball (10 mana)\n"
        << "3: Chill touch (5 mana)\n";
    do
    {
        switch (Input::character())
        {
        case '1':// option 1: Lightning bolt
            std::cout << "The encounter took 5 hp\n";
            answerAgain = false;
            break;

        case '2':// option 2: Fireball
            answerAgain = false;
            break;

        case '3':// option 3: Chill touch
            answerAgain = false;
            break;

        default:
            printNotPossible();
            answerAgain = true;
            break;
        }
    } while (answerAgain);

}

void Mage::printStats() const
{
    Playerz::printStats();
    std::cout << "Mana: " << mana << "\n\n";
}

void Mage::resetAllStats()
{
    Playerz::resetAllStats();
    mana = 100;
    maxMana = 100;
}

int Mage::useSpell() const
{
    int dmg{ 0 };
    int manaUsed{ 0 };
    bool answerAgain{ false };


    std::cout << "Choose the spell you would like to use (Your mana: " << mana << ")\n"
        << "1: Lightning bolt. (3 mana)\n"
        << "2: Fire bolt. (3 mana)\n"
        << "3: Water cannon. (5 mana)\n"
        << "4: Fireball. (8 mana)\n"
        << "5: Iceball. (8 mana)\n"
        << "6: Chill touch. (10 mana)\n"
        << "7: Supernova. (30 mana)\n";

    do
    {
        switch (Input::character())
        {
        case '1':// option 1: Lightning bolt.
            manaUsed = 0;
            dmg = 0;
            answerAgain = false;
            break;

        case '2':// option 2: Fire bolt.
            manaUsed = 0;
            dmg = 0;
            answerAgain = false;
            break;

        case '3':// option 3: Water cannon.
            manaUsed = 0;
            dmg = 0;
            answerAgain = false;
            break;

        case '4':// option 4: Fireball.
            manaUsed = 0;
            dmg = 0;
            answerAgain = false;
            break;

        case '5':// option 5: Iceball.
            manaUsed = 0;
            dmg = 0;
            answerAgain = false;
            break;

        case '6':// option 6: Chill touch.
            manaUsed = 0;
            dmg = 0;
            answerAgain = false;
            break;

        case '7':// option 7: Supernova.
            manaUsed = 0;
            dmg = 0;
            answerAgain = false;
            break;

        default:
            printNotPossible();
            answerAgain = true;
            break;
        }
    } while (answerAgain);

    if (manaUsed < mana)
        return -1;
    else
        return dmg;
}
