
#include <iostream>
#include "Bartender.h"
#include "Talk To Encounters English.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"



void bard()
{
	
	bool answerAgain{ false };


    std::cout << "Bard: \"Hey, wanna hear something good?\"\n";

	do
	{

		switch (Input::character())
		{
		case 'y':// yes

			std::cout << "(The bards starts singing a song\n"
				<< "The lyrics may be good, but what you are hearing is only noise.\n"
				<< "Hopefullly he'll stop soon)\n";

			waitForAnyKey();

			std::cout << "(The bard stops singing and asks you how good it was.\n"
				<< "You tried to say something good, but the only thing you could say was:\n"
				<< "\"It's the worst song I've ever heard.\")\n";

			waitForAnyKey();

			std::cout << "(You expected him to be sad. However he wasn't)\n"
				<< "Bard: \"Thanks for the honest answer, everyone said it was beautiful.\n"
				<< "It would be a better world if there were more people like you.\"\n";

			waitForAnyKey();

			std::cout << "Bard: \"Anyway, I wanted to ask if I could come with ya, but your "
				<< "party is full, so bye.\n"
				<< "Next time we'll meet you'll be amazed.\"\n";
			answerAgain = false;

			break;

		case 'n':// no

			std::cout << "Bard: \"Fine. Bye, worthless human.\"\n";
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);


	encounter().setIsGone(true);
	encounter().setCanTalk(false);
	
}