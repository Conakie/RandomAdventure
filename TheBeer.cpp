
#include <iostream>
#include "TheBeer.h"
#include "Input.h"
#include "Everywhere Used Func.h"



void Creatures::Encounter::TheBeer::talk()
{
	dialogue();
}

void Creatures::Encounter::TheBeer::setName()
{
    name = "The Beer";
}

void Creatures::Encounter::TheBeer::setStats()
{
    maxHp = 0.69 + (0.69 * (lvl - 1));
    maxAtk = 1 + (0.1 * lvl);
    maxDef = -100;
    critRate = 0;
    critDmg = 0;
    xp = 5;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}

void Creatures::Encounter::TheBeer::dialogue()
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
				<< "In that moment you realize it was all a dream)\n";
			m_isGone = true;
			answerAgain = false;

			break;

		case 'n':// no

			std::cout << "Beer: \"...\"\n"
				<< "(You think you are becoming crazy and you go away)\n";
			m_isGone = true;
			answerAgain = false;

			break;

		case 's':// skip

			std::cout << "Beer: \"I know I'm so sexy and all but wanna go and have some 'fun' "
				<< "together?\"\n";
			answerAgain = true;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);


	m_canTalk = false;
	waitForAnyKey();
}
