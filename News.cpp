
#include <iostream>
#include "Random Adventure English.h"
#include "Random Adventure Italiano.h"
#include "Start.h"
#include "Everywhere Used Func.h"
#include "Random.h"
#include "Input.h"



void newz()
{
    bool answerAgain{ false };


    std::cout << "Necoto: \"The current version is 0.0.5: the Stats Update.\n"
        << "And this is also the first public version of Random Adventure.\n"
        << "Unfortunately there are many bugs right now, we're sorry about that.\"\n";
    waitForAnyKey();
    std::cout << "Necoto: \"The inventory doesn't work as expected.\n"
        << "When Nanre tried to make it work he received 1952 errors so we had to cancel the idea."
        << "\nNext update should fix everything, or so Nanre says.\"\n";
    waitForAnyKey();
    std::cout << "Necoto: \"Nanre has something to say. I'll leave the word to him.\"\n"
        << "Nanre: \"Thanks. I hope you liked the game so far. If you want to add something,\n"
        << "let me know. I am trying to add everything as fast as possible.\"\n";
    waitForAnyKey();
    std::cout << "Nanre: \"Not that it worked well this time. But I am still trying to meet\n"
        << "my goals every update.\n"
        << "Unfortunately this time didn't work as expected.\n";
    waitForAnyKey();
    std::cout << "Nanre: \"Anyway, I'll be rewriting the entire game in another project.\n"
        << "This will save me many future problems.\"\n"
        << "Necoto: \"Thanks for being here. Now, anything else you wanna do or know?\"\n";
}