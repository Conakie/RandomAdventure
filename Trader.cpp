
#include <iostream>
#include "Talk To Encounters English.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"



void trader()
{

    std::cout << "Trader: \"Hello, hello!\n"
        << "If you wanted something I'm sorry to announce I don't have anything to sell at the "
        << "moment.\"\n";

    waitForAnyKey();

    std::cout << "Trader: \"I'm resupplying my stock right now.\n"
        << "Be sure to come back later~\"\n"
        << "(The trader goes away)\n";

    encounter().setIsGone(true);
    encounter().setCanTalk(false);

}