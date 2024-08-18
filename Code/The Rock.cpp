
#include <iostream>
#include "Talk To Encounters English.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"



void theRock()
{

    std::cout << "Nanre: \"Why do you want to talk to a rock?\n"
        << "It's not even the person with the same name.\n"
        << "Oh, maybe you imagined it was him. Sorry, my bad. It's not him.\"\n";

    waitForAnyKey();

    std::cout << "One day, one day you'll be able to find that person.\n"
        << "That day will be when I'll go to hell, so pretty soon.\n"
        << "Be careful, that rock is angry! See ya.\"\n";

    encounter().setCanTalk(false);
    encounter().setIsUnderAttack(true);

}
