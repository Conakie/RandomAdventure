
#include <iostream>
#include "Everywhere Used Func.h"
#include "Input.h"
#include "Talk To Encounters English.h"
#include "Stats.h"



void theBeer()
{

	bool answerAgain{ false };


    std::cout << "Beer: \"hey girlie, wanna go out with me?\n"
        << "y: Yes, I want to go out with you!\n"
        << "n: No, and why am I talking to a beer stein?!\n"
		<< "s: (don't say a word)\n";

	do
	{

		switch (Input::character())
		{
		case 'y':// yes

			std::cout << "(You go around the place with the beer and have a lot of fun.\n"
				<< "Before leaving, you choose to hug the beer.\n"
				<< "You close your eyes and tears start coming out of your eyes)\n";

			waitForAnyKey();

			std::cout << "(When you open your eyes you find yourself lying on the floor.\n"
				<< "You get up without seeing the beer stein anywere.\n"
				<< "In that moment you realize it was all a dream.)\n";
			answerAgain = false;

			break;

		case 'n':// no

			std::cout << "Beer: \"...\"\n"
				<< "(You think you are becoming crazy and you go away)\n";
			answerAgain = false;

			break;

		case 's':// skip

			std::cout << "Beer: \"I know I'm so sexy and all but wanna go and have some 'fun' "
				<< "together?\n";
			answerAgain = true;

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