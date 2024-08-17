
#include <iostream>
#include "Random Adventure English.h"
#include "Random Adventure Italiano.h"
#include "Talk To Encounters English.h"
#include "Start.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"



void intro()
{
    bool answerAgain{ false };
    bool playAgain{ false };


    std::cout << "Necoto: \"Welcome back, master~\"\n";
        
    do
    {
        std::cout << "s: Start game.\n"
            << "o: Open settings.\n"
            << "n: Hear news.\n"
            << "All other keys: Hear intro and tutorial.\n";
        switch (Input::character())
        {
        case 's':// skip intro
            answerAgain = false;
            break;

        case 'o':// open settings
            std::cout << "Nanre: \"I'm working on this right now.\n"
                << "Wait for the next version and hopefully this should be ready.\"\n";
            answerAgain = true;
            break;

        case 'n':
            newz();
            answerAgain = true;
            break;

        default:// hear intro
            std::cout << "Necoto: \"Random Adventure is a rogue-like game developed by Nanre.\n"
                << "In your journey you'll find many encounters, with which you can:\n"
                << "talk('t'): most of the encounters have dialogues;\n"
                << "fight('a'): attack everyone and everything;\"\n";
            waitForAnyKey();
            std::cout << "Necoto: \"When you're playing, and you want to check what you can do"
                << " use 'z'.\n"
                << "When an encounter goes away or is defeated he/she/it will drop something.\n"
                << "You'll be able to use these objects with 'i'.\"\n";
            waitForAnyKey();
            std::cout << "Necoto: \"Almost everything in the game is generated randomly.\n"
                << "Except for your main stats and the main stats of encounters.\n"
                << "Now you are ready to play!\"\n";
            answerAgain = true;
            break;
        }

    } while (answerAgain);

}



int selectGameMode()
{
    bool answerAgain{ false };
    int gameMode{ 0 };
    std::cout << "Necoto: \"Select the language you wanna play.\"\n";
    
    do
    {
        std::cout << "1: English.\n"
            << "2: Italiano.\n"
            << "3: Close the game.\n";
        switch (Input::integer())
        {
        case 1:// English.
            std::cout << "Kelmod: \"Hello, I am Kelmod and I'm here to guide you.\n"
                << "Wanna know the actions you can do?\"\n"
                << "y: Yes, I want to see the actions I can do.\n"
                << "n: No, I don't want to.\n";
            Input::character();
            std::cout << "Kelmod: \"I don't care about your opinion.\n"
                << "Here is the list.\"\n";
            actionsList();
            waitForAnyKey();
            std::cout << "Kelmod: \"I would ask the same about your stats "
                << "but I'm not paid enough.\n"
                << "Look at them with 'q'. Now go and destroy everyone!\"\n";
            waitForAnyKey();
            return 1;

        case 2:// italian
            std::cout << "Lenre: \"Mi dispiace dirlo ma l'italiano non e' piu' supportato.\n"
                << "Pero' ci sono ancora alcuni file in italiano che nessuno vuole rimuovere.\n"
                << "Se vuoi, apri la repo e leggili.\"\n";
            waitForAnyKey();
            return 2;

        case 3:// Close the game
            std::cout << "Nanre: \"Elesya, leaving the job to you.\"\n";
            return 3;

        default:// ask again, wrong number.
            answerAgain = true;
            break;
        }
    } while (answerAgain);

    // if this executes somehow, I failed as a programmer
    return 0;
}



bool playAgain(bool isKelmodTheNarrator)
{
    bool answerAgain{ false };


    if (isKelmodTheNarrator)
    {
        std::cout << "Kelmod: \"Wanna play again?\"\n"
            << "y: yes, I want to.\n"
            << "n: No, I don't want tot play again.\n";
    }
    else
    {
        std::cout << "Lenre: \"Vuoi riprovare a non morire?\"\n"
            << "y: Questa volta non moriro'.\n"
            << "n: Non ne ho voglia. Domani.\n";
    }

    do
    {

        switch (Input::character())
        {
        case 'y':// yes: play again
            return true;

        case 'n':// no: don't play again
            return false;

        default:
            printNotPossible();
            answerAgain = true;
            break;
        }

    } while (answerAgain);

    return false;
}



void outro()
{
    bool answerAgain{ false };


    do
    {
        std::cout << "Elesya: \"Write something to close the game.\"\n";
        Input::string();
        //switch (Input::character())
        //{
        //case 'K':// Kelomd
        //    encounter().setUid(EncounterUid::kelmod);
        //    talkToEncounters();
        //    answerAgain = true;
        //    break;

        //case 'L':// Lenre
        //    encounter().setUid(EncounterUid::lenre);
        //    talkToEncounters();
        //    answerAgain = true;
        //    break;

        //case 'E':// Elesya
        //    encounter().setUid(EncounterUid::elesya);
        //    talkToEncounters();
        //    answerAgain = true;
        //    break;

        //case 'N':// Necoto
        //    encounter().setUid(EncounterUid::necoto);
        //    talkToEncounters();
        //    answerAgain = true;
        //    break;

        //case 'C':// Kyo
        //    encounter().setUid(EncounterUid::kyo);
        //    talkToEncounters();
        //    answerAgain = true;
        //    break;

        //default:
        //    std::cout << "Necoto: \"Goodbye~ Come back again, I'll be waiting for you.\"\n";
        //    delay(2);
        //    answerAgain = false;
        //    break;
        //}
        std::cout << "Necoto: \"Goodbye~ Come back again, I'll be waiting for you.\"\n";
        delay(2);
    } while (answerAgain);

}