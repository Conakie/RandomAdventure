
#include <iostream>
#include <Windows.h>
#include "Inventory.h"
#include "Playerz.h"
#include "Encounterz.h"
#include "Input.h"
#include "KiiyuoMath.h"



int main()
{
    Creatures::Player::Playerz player{};
    player.resetPlayer();
    system("Color 69");
    std::cout << "UwU";
    player.openInventory().addItem(Items::ItemName::cota, 10);
    player.openInventory().useItem(Items::ItemName::cota);
    player.heal(10);
    player.takeDamage(0);
    std::cout << roundToTwoDecimals(5.562);
    return 0;
}


/*
Encounterz

attack,
heal,
takeDamage,
talk,
drop items,
thinkAndAct

getXp
isAlive
getIsGone
reset

setPlayer
setEncounter
setType
setLvl
*/