
#include <iostream>
#include "Playerz.h"
#include "Stats.h"



void attackPlayer(Creatures::Player::Playerz& player)
{

    std::cout << "You have been attacked!";
    player.takeDamage(encounter().getAttack());

}