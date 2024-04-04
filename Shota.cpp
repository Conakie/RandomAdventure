
#include <iostream>
#include "Talk To Encounters English.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"



void shota()
{
    // increased every time the player talks to the shota
    static short annoyLevel{ 0 };


    switch (annoyLevel)
    {
    case 0:
        std::cout << "Shota: \"Hii. I'm a shota!\"\n";
        break;
    case 1:
        std::cout << "Shota: \"What? I'm small? Yeah, I know.\"\n";
        break;
    case 2:
        std::cout << "Shota: \"Have you seen a loli? I love her.\"\n";
        break;
    case 3:
        std::cout << "Shota: \"You too?! What the hell?!\"\n";
        break;
    case 4:
        std::cout << "Shota: \"Here take this and go away.\"\n"
            << "(The shota gives you 8 magic scrolls)\n";
        player().setInventory().addItem(ObjectUid::magicScroll, 8);
        break;
    case 5:
        std::cout << "Shota: \"Now leave me alone!\"\n";
        break;
    default:
        std::cout << "Shota: \"Still here? Fine I'm going to the psychologist because of you!\"\n";
        annoyLevel = -1;
        encounter().setIsGone(true);
        break;
    }
    

    ++annoyLevel;

}