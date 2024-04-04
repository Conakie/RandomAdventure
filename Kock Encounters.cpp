
#include <iostream>
#include "Everywhere Used Func.h"
#include "Input.h"
#include "Talk To Encounters English.h"
#include "Stats.h"



void kockEncounters()
{

    std::cout << "Nanre: \"I'm not here to disturb you while you play,\n"
        << "but are you sure you're not gay?\n"
        << "Have you read the name of this creature? It says COCK!\"\n";

    waitForAnyKey();

    std::cout << "Nanre: \"Uhm, I have created those two to be reduced to smithereens\n"
        << "not for you to have a nice chat with. That's the job of Sila or Necoto.\n"
        << "Now go, and kill it before he comes to you.\"\n";

    waitForAnyKey();

    std::cout << "Nanre: \"Look, he's coming for you!\"\n";


    encounter().setIsUnderAttack(true);
    encounter().setCanTalk(false);

}