
#include <iostream>
#include "Random Adventure English.h"
#include "Random Adventure Italiano.h"
#include "Start.h"
#include "Everywhere Used Func.h"
#include "Prng.h"
#include "Input.h"



void newz()
{
    bool answerAgain{ false };


    std::cout << "Necoto: \"The current version is 0.0.4: the Random Update.\n"
        << "To read all the changes use this link:\n"
        << "https://docs.google.com/document/d/1HGnkRQi1B1nbXYYJLaOiHeqwSvJIo_RteeR7n2gAaWE/edit?usp=sharing"
        << '\n';
    waitForAnyKey();
    std::cout << "Necoto: \"Do you want to know why blurp oneshotted you?\n"
        << "Check the wiki at this link:\n"
        << "https://docs.google.com/spreadsheets/d/16ghCx4eWSLNN9NrB-XN0d859A6BURuI9YRh21GXaoko/edit?usp=sharing"
        << '\n';
    waitForAnyKey();
    std::cout << "Necoto: \"Nanre has something to say. I'll leave the word to him.\"\n"
        << "Nanre: \"Thanks. Do you like this game? Do you want to suggest anything?\n"
        << "Send me a message! I'll answer after as soon as possible!\"\n";
    waitForAnyKey();
    std::cout << "Nanre: \"I am looking for help. Want to join me on this project?\n"
        << "I don't need only developers, but also artists, writers and everything you can "
        << "think of.\"\n";
    waitForAnyKey();
    std::cout << "Nanre: \"Maybe someone will talk to me now.\n"
        << "Well, seeing you want to play so much, good luck on your adventure!\"\n"
        << "Necoto: \"We don't have anything else to say about news and announcements,\n"
        << "So anything else you wanna know?";
    waitForAnyKey();
}