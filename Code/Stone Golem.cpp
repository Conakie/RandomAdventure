
#include <iostream>
#include "Talk To Encounters English.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Random.h"



void stoneGolem()
{

    if (Random::get(0, 99) > 69)
    {

        std::cout << "Stone Golem: \"Crack crock\nYour neck is goin' to crock!\"\n";

        encounter().setIsUnderAttack(true);

    }
    else
    {

        std::cout << "Stone Golem: \"Crick crack\nI'm sniffin' crack!\n";

        encounter().setIsGone(true);

    }

    encounter().setCanTalk(false);
}
