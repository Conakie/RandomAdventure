
#include <iostream>
#include "Random Adventure English.h"
#include "Talk To Encounters English.h"
#include "Actions.h"
#include "Everywhere Used Func.h"
#include "Prng.h"
#include "Stats.h"
#include "ConsoleStyle.h"
#include "Place.h"



void talk()
{

    //Check if player can talk to the encounter
    if (encounter().getCanTalk() && !(encounter().getIsUnderAttack()))
    {
        // set the color to talk
        Console::setColor(Console::Color::talk);

        // talk to the encounter and changes some stats like isGone or isUnderAttack
        talkToEncounters();

        // reset the color to dungeon mode
        Console::setColorPerPlace(printMainPlace(false));
        
    }
    else//The player won't be able to talk to encounters if he has already done that
    {

    }

}



void attackEncounter(Encounters& encounter)
{

    std::cout << "\nYou attack the encounter.";
    if (Random::get(0, 99) <= player().getCritRate())
    {

        std::cout << "\nYou did a critical hit!\n";
        encounter.takeDamage(player().getAttack() * player().getCritDmg());

    }
    else
    {

        encounter.takeDamage(player().getAttack());

    }

}



void printActionsLeft(int actionsLeft)
{

    if (actionsLeft >= 1)
    {

        std::cout << "You have " << actionsLeft << " action(s) left until your turn is over.\n";

    }
    else
    {

        std::cout << "\nYour turn is over. Now it is the encounter turn.\n";

    }

}