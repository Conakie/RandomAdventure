
#include <iostream>
#include "Talk To Encounters English.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Random.h"
#include "Blurp.h"



void blurp()
{

	bool answerAgain{ false };


    if (Random::get(0, 99) > 69)
    {

        std::cout << "Blurp: \"Squish squash\nYour opinion is trash\"\n";

        encounter().setIsUnderAttack(true);

    }
    else
    {

        std::cout << "Blurp: \"Blurp blurp, squish, blurp squash?\"\n"
			<< "y: Yes, I'll do it.\n"
			<< "n: No, I won't do it.\n";
        
		do
		{

			switch (Input::character())
			{
			case 'y':// yes: Yes, I'll do it.

				std::cout << "Blurp: \"Squish squash. Blurp!\"\n";
				answerAgain = false;

				encounter().setIsUnderAttack(true);

				break;

			case 'n':// no: No, I won't do it.

				std::cout << "Blurp: \"Blurp blurp. Squish blurp squash.\"\n";
				answerAgain = false;

				encounter().setIsGone(true);

				break;

			default:

				printNotPossible();
				answerAgain = true;

				break;
			}

		} while (answerAgain);


    }


	encounter().setCanTalk(false);

}

void Creatures::Encounter::Blurp::talk()
{
}

void Creatures::Encounter::Blurp::setName()
{
	name = "Blurp";
}

void Creatures::Encounter::Blurp::setStats()
{
	maxHp = 3 + (3 * (lvl - 1));
	maxAtk = 2.5 + (2.5 * lvl);
	maxDef = 0;
	critRate = 0;
	critDmg = 0;
	xp = 1;

	hp = maxHp;
	atk = maxAtk;
	def = maxDef;
}

void Creatures::Encounter::Blurp::dialogue()
{
	bool answerAgain{ false };


	if (Random::get(0, 99) > 69)
    {

        std::cout << "Blurp: \"Squish squash\nYour opinion is trash.\"\n";
		m_isUnderAttack = true;

    }
    else
    {

		std::cout << "Blurp: \"Blurp blurp, squish, blurp squash?\"\n";
		do
		{
			std::cout << "y: Yes, I'll do it.\n"
				<< "n: No, I won't do it.\n";
			switch (Input::character())
			{
			case 'y':// yes: Yes, I'll do it.

				std::cout << "Blurp: \"Squish squash. Blurp!\"\n";
				answerAgain = false;
				m_isUnderAttack = true;

				break;

			case 'n':// no: No, I won't do it.

				std::cout << "Blurp: \"Blurp blurp. Squish blurp squash.\"\n";
				answerAgain = false;
				m_isGone = true;

				break;

			default:

				printNotPossible();
				answerAgain = true;

				break;
			}

		} while (answerAgain);
    }


	m_canTalk = false;
	waitForAnyKey();
}
