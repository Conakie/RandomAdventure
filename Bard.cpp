
#include <iostream>
#include "Bartender.h"
#include "Talk To Encounters English.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Bard.h"



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

void Creatures::Encounter::Bard::talk()
{
}

void Creatures::Encounter::Bard::thinkAndAct()
{
	if (m_player)
	{
		if (isAlive() && !isUnderAttack && canTalk)
		{
			talk();
		}
		else if (isUnderAttack)
		{
			isGone = true;
		}
		else
		{
			std::cout << "Kelmod: \"Do something man. I'm bored.\"\n";
		}
	}
	else
	{
		std::cout << "The priest ignores you and keeps going his way.\n";
		isGone = true;
	}
}

void Creatures::Encounter::Bard::setName()
{
	name = "Barbonium";
}

void Creatures::Encounter::Bard::setStats()
{
	maxHp = 10 + (10 * (lvl - 1));
	maxAtk = 1 + (2 * lvl);
	maxDef = -60;
	critRate = 0;
	critDmg = 0;
	xp = 1;

	hp = maxHp;
	atk = maxAtk;
	def = maxDef;
}
