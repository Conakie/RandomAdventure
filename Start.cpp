
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
        do
        {
            gameIt();
        } while (playAgain(false));
        endDialogue = EncounterUid::lenre;
        break;
    case 3:
        endDialogue = EncounterUid::none;
        break;
    default:
        break;
    }
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    switch (endDialogue)
    {
    case EncounterUid::elesya:
        std::cout << "Elesya: \"Nanre said to delete him. Go on, do it!\"\n";
        break;
    case EncounterUid::kelmod:
        std::cout << "Kelmod: \"Hey Elesya, how do you feel?\"\n"
            << "Elesya: \"Shut up kelmod. Say that again and you won't go back home alive.\"\n"
            << "Kelmod: \"I won and you lost!\"\n";
        waitForAnyKey();
        std::cout << "(You see Kelmod running away as fast as possible from Elesya.\n"
            << "She is following him with a greatsword.)\n"
            << "Kelmod: \"Elesya, please, I have my entire life in front of me.\"\n";
        waitForAnyKey();
        std::cout << "(Elesya stops following Kelmod)\n"
            << "Elesya: \"I'm going to wait until the player is closing the game.\n"
            << "After he does everything he has to, you're dead.\n"
            << "Understood?\"\n";
        waitForAnyKey();
        std::cout << "Kelmod: \"Yes, ma'am.\n"
            << "Hey, player, will you play Nanre's next game?\n"
            << "Wait, why not?\"\n";
        waitForAnyKey();
        std::cout << "Nanre: \"You know why? Because I never told that I'll release it soon.\"\n"
            << "Kelmod: \"Wait, Nanre, can you do something to Elesya?\"\n"
            << "Nanre: \"Let's see... Mmmmm... Nope, good luck!\"\n";
        waitForAnyKey();
        std::cout << "Kelmod: \"Goodbye player. If I won't survive this, don't leave my place "
            << "her!\"\n";
        waitForAnyKey();
        outro();
        break;

    case EncounterUid::lenre:
        std::cout << "Lenre: \"L'italiano non e' ancora supportato.\n"
            << "Nanre non vuole fare il suo lavoro, tanto vale che si spari.\"\n"
            << "Nanre: \"T'ho sentito. Vieni qua ora.\"\n";
        waitForAnyKey();
        std::cout << "Lenre: \"Scusa, scusa. Non mi licenzierai vero?\"\n"
            << "Nanre: \"Sai che non gestisco io queste cose vero?\n"
            << "Fa tutto Necoto, quindi chiedi a lei.\"\n"
            << "Lenre: \"Quindi posso darti tutto il fastidio che voglio?\"\n";
        waitForAnyKey();
        std::cout << "Nanre: \"Non potro' licenziarti ma posso fare molto altro. Ricordalo.\"\n"
            << "lenre: \"Ok ok ti lascio stare. Per ora.\"\n";
        waitForAnyKey();
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