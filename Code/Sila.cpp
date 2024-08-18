
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Sila.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"



void sila()
{
	bool answerAgain{ false };

	

	std::cout << "Sila: \"Morning! Are you a courier?\n"
		<< "I'm waiting for a letter from Kelmod.\n"
		<< "We wanted to meet somewhere but here to send messages we hire couriers.\"\n"
		<< "1: No, I was just passing by.\n"
		<< "2: Hey, do you remember me?\n"
		<< "3: sdbhfhius.\n";

	do
	{

		switch (Input::character())
		{
		case '1':// option 1: 

			std::cout << "Sila: \"Oh, sorry. You probably have work to do so bye.\"\n";

			encounter().setIsGone(true);
			answerAgain = false;

			break;

		case '2':// option 2: 

			rememberSila();
			answerAgain = false;

			break;

		case '3':// option 3: 

			std::cout << "Sila: \"I should remove bugged npc. So lets see who wins!\"\n";

			encounter().setIsUnderAttack(true);
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



void rememberSila()
{

	std::cout << "Sila \"Oh yes, I didn't recognise you.\n"
		<< "You changed a lot. And that's because Nanre rewrote the code from zero.\n"
		<< "He even fired me as a Narrator. Not that I don't like being a boss.\"\n";

	waitForAnyKey();

	std::cout << "Sila: \"I... I have to work overtime because of the production of Flasail "
		<< "Slavendo.\nAnd I'm almost everywhere in the first chapter.\n"
		<< "Maybe Nanre has to work even more than me since he has to create everything.\"\n";

	waitForAnyKey();

	std::cout << "Sila: \"Oh well. I should now go and help him.\n"
		<< "I fell sorry for all the work he has to do.\"\n"
		<< "Nanre: \"It's no problem working more than usual for me.\"\n";

	waitForAnyKey();

	std::cout << "Nanre: \"After hundreds of hours working here I don't even know who I am.\n"
		<< "So what could be one or two hours of overtime for me?\n"
		<< "I'm already part of the game. These two games are me.\"\n";

	waitForAnyKey();

	std::cout << "Nanre: \"This is all to say for don't worry about me. See ya.\"\n"
		<< "Sila: \"I always wondered how he can appear everywhere when you say 'Nanre'\n"
		<< "Anyway, It's time for me to go. Kelmod is waiting for me somewhere.\"\n";

	encounter().setIsGone(true);

}
