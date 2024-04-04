
#include <iostream>
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Player Stats.h"
#include "Talk To Encounters English.h"
#include "Actions.h"
#include "Miiro.h"
#include "Input.h"
#include "Stats.h"



void miiro()
{

	bool answerAgain{ false };
	constexpr unsigned short healPercentage{ 35 };



	std::cout << "Miiro: \"Hello, little one. If you need something, please, let me rest.\n"
		<< "I worked too much and there are many hours before the end of the day.\n"
		<< "It's not a living being dying right?\"\n"
		<< "1: Nope, I was only wondering what you were doing.\n"
		<< "2: I'm dying.\n";

	do
	{

		switch (Input::character())
		{
		case '1':// option 1: Nope, I was only wondering what you were doing.

			answerAgain = false;

			break;

		case '2':// option 2: I'm dying.

			if (player().getHealth() <= (player().getMaxHealth() * 25 / 100))
			{

				std::cout << "Miiro: \"Here, do you feel better?\"\n"
					<< "(You feel way better, you also tell her you feel better)\n"
					<< "(She sit down on the ground)\n";

				waitForAnyKey();

				std::cout << "Miiro: \"Excuse me if I sit down, but I'm non in my best shape.\n"
					<< "Sometime I wish to be an Ersilia not many know so I can relax.\n"
					<< "But everyone know me so I can't rest more than five minutes.\"\n";

				waitForAnyKey();

				std::cout << "Miiro: \"I should buy some energy bottles to get better and fast.\n"
					<< "(You say bye and leave so she can rest.)\n"
					<< "(After you go away a girl with rabbit ears appear from nowhere)\n";

				waitForAnyKey();

				std::cout << "(The two of them start talking)\n"
					<< "(You can see the girl healing Miiro)\n"
					<< "(Knowing she'll be safe you choose to go away)\n";

				waitForAnyKey();

				std::cout << "(Miiro healed you of " << healPercentage << "% of your total hp)\n";
				player().heal((player().getMaxHealth() * healPercentage / 100));

			}
			else
			{

				tiredMiiro();


			}
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



void tiredMiiro()
{
	bool answerAgain{ false };



	std::cout << "Miiro: \"You're fine. So please, let me rest for a while.\"\n";
		

	do
	{

		std::cout << "y: Ok, bye.\n"
			<< "n: No, die.\n"
			<< "s: (Stay there withou talking)\n";


		switch (Input::character())
		{
		case 'y':// yes

			std::cout << "Miiro: \"Bye.\"\n"
				<< "(After you went away she laid down to rest)\n";

			encounter().setIsGone(true);
			answerAgain = false;

			break;

		case 'n':// no

			std::cout << "Miiro: \"I don't want to waste my time like this,\n"
				<< "but if I can rest, I'll fight. So you'll die.\"\n";

			encounter().setIsUnderAttack(true);
			answerAgain = false;

			break;

		case 's':// skip

			std::cout << "Miiro: \"Please, go away\"\n";

			answerAgain = true;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);

}