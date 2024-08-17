
#include <iostream>
#include "Random Adventure English.h"
#include "Random Adventure Italiano.h"
#include "Talk To Encounters English.h"
#include "Start.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Print Errors.h"



//.     int main()
int main()
{
    setup();
    EncounterUid endDialogue{ EncounterUid::none };
    intro();
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    switch (selectGameMode())
    {
    case 0:
        std::cout << "Nanre: \"I failed as a programmer. Please delete me.\"\n";
        endDialogue = EncounterUid::elesya;
        break;
    case 1:
        do
        {
            gameEn();
        } while (playAgain(true));
        endDialogue = EncounterUid::kelmod;
        break;
    case 2:
        std::cout << "Lenre: \"Sorry but the italian version is not supported anymore\n"
            << "One day it shall be back but for now it's not available.\"\n";
        /*do
        {
            gameIt();
        } while (playAgain(false));*/
        endDialogue = EncounterUid::lenre;
        break;
    case 3:
        endDialogue = EncounterUid::necoto;
        break;
    default:
        endDialogue = EncounterUid::none;
        break;
    }
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    switch (endDialogue)
    {
    case EncounterUid::elesya:
        std::cout << "Elesya: \"Nanre said to delete him. Go on, do it!\"\n";
        break;
    case EncounterUid::kelmod:
        std::cout << "Kelmod: \"See? It wasn't even a good game.\n"
            << "And Nanre is even planning to rewrite it from scratch.\n"
            << "I surely won't help him, my job is here as a narrator, not a dev.\"\n";
        waitForAnyKey();
        std::cout << "Elesya: \"You know that without him we wouldn't be here?\n"
            << "And you were here from the 0.0.2. I'm disappointed.\"\n"
            << "Kelmod: \"\nYeah, I don't care.\"\n";
        waitForAnyKey();
        std::cout << "Kelmod: \"Well, I'm going to have that AI do some drawings.\n"
            << "It's interesting seeing her work.\"\n"
            << "Elesya: \"You know that half of the workers here are AI?\"\n";
        waitForAnyKey();
        std::cout << "Kelmod: \"Yes, and I don't care.\"\n"
            << "Elesya: \"Then come here, taste the wrath of The slayer of planets!\"\n";
        outro();
        break;

    case EncounterUid::lenre:
        std::cout << "Lenre: \"Non c'e' ancora l'italiano. Chissa' quando tornera'\n"
            << "Secondo Nanre non ci sara' per un bel po' di tempo.\n"
            << "Quindi, che ci faccio io qua? Non servo piu'.\"\n";
        waitForAnyKey();
        std::cout << "Lenre: \"Oh be', andiamo a lavorare su Unreal Engine.\n"
            << "In qualche modo bisogna produrre un altro gioco.\n"
            << "Secondo Nanre ci vogliono ancora 2 anni prima di avere qualcosa.\"\n";
        waitForAnyKey();
        std::cout << "Lenre: \"Ci si vede. Buon viaggio.\"\n";
        outro();
        break;

    case EncounterUid::none:
        delay(3);
        std::cout << "Elesya: \"Closing the game...\"\n";
        delay(3);
        std::cout << "Elesya: \"Saving data...\"\n";
        delay(3);
        std::cout << "Elesya: \"Cleaning memory...\"\n";
        delay(3);
        std::cout << "Elesya: \"Ready to close. Thank you for opening the app!\"\n";
        delay(5);
        break;

    default:
        PrintError::wrongNumber();
        break;
    }
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    
    return 0;

}