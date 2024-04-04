
#include <iostream>
#include "Playerz.h"
#include "Stats.h"



void attackPlayer(Playerz& player)
{

    std::cout << "You have been attacked!";
    player.takeDamage(encounter().getAttack());

}