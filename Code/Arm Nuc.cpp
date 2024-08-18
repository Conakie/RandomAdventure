
#include <iostream>
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Talk To Encounters English.h"
#include "Arm Nuc.h"
#include "Random.h"
#include "Input.h"
#include "Stats.h"



void armNuc()
{

	bool answerAgain{ false };

	print10RandomNumbersArmNuc();

	do
	{

		std::cout << "1: What? Could you repeat what you said?\n"
			<< "2: Kill me.\n"
			<< "3: Bye.\n";

		switch (Input::character())
		{
		case '1':// option 1: What? Could you repeat what you said?

			print10RandomNumbersArmNuc();
			answerAgain = true;

			break;

		case '2':// option 2: Kill me.

			std::cout << "Arm Nuc: \"Order received. Proceding to kill 'Player'\"\n";

			encounter().setIsUnderAttack(true);
			answerAgain = false;

			break;

		case '3':// option 3: Bye.

			std::cout << "Arm Nuc: \"Ordere received. Autodestruction in ";

			for (int i = 10; i > 0; --i)
			{

				std::cout << i << "\n ";

			}

			std::cout << "\bArm Nuc: \"Boom!\"\n"
				<< "(Arm Nuc exploded after saying that)\n";

			encounter().takeDamage(encounter().getHealth());
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);

	
	encounter().setCanTalk(false);

}



void print10RandomNumbersArmNuc()
{

	for (int i = 0; i < 10; ++i)
	{

		std::cout << "Arm Nuc: \"" << Random::get(-9223372036854775807, 9223372036854775807) << "\"\n";

	}

}
