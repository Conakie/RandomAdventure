
#include "Warrior.h"
#include "Random.h"



//void Warrior::attack(Encounters enc)
//{
//    std::cout << "\nYou attack the encounter.";
//    if (Random::get(0, 99) <= critRate)
//    {
//        std::cout << "\nYou did a critical hit!\n";
//        enc.takeDamage(atk * critDmg);
//    }
//    else
//    {
//
//        enc.takeDamage(atk);
//
//    }
//}

void Warrior::attack(Encounters& enc)
{
    bool isACritHit{ false };


    std::cout << "You attack " << enc.getName();
    if (Random::get(0, 99) < critRate)
    {
        std::cout << "You did a critical hit!\n";
    }
    else
    {

    }
}
