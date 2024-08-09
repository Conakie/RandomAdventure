
#include <iostream>
#include "Everywhere Used Func.h"
#include "Input.h"
#include "Talk To Encounters English.h"
#include "Stats.h"
#include "Kobold.h"



void kobold()
{

	bool answerAgain{ false };

    std::cout << "Kobold: \"Some text here\n"
        << "Some more text.\n"
        << "Question.\"\n"
        << "1: Answer 1\n"
        << "2: Answer 2\n"
        << "3: What am I doing with my life?\n";

	do
	{

		switch (Input::character())
		{
		case '1':// option 1: Answer 1

			std::cout << "Angry kobold. Declaration of war.\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		case '2':// option 2: Answer 2

			std::cout << "Calm kobold. He goes away.\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case '3':// option 3: What am I doing with my life?

			std::cout << "To see this answer you need to have premium account.\n"
				<< "You can buy it in the store with 500 cota.\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);


	encounter().setCanTalk(false);

}



void Creatures::Encounter::Kobold::talk()
{
}

void Creatures::Encounter::Kobold::setName()
{
	name = "Kobold";
}

void Creatures::Encounter::Kobold::setStats()
{
	maxHp = 6 + (4 * (lvl - 1));
	maxAtk = 1 + (1 * lvl);
	maxDef = 0;
	critRate = 0;
	critDmg = 0;
	xp = 1;

	hp = maxHp;
	atk = maxAtk;
	def = maxDef;
}
