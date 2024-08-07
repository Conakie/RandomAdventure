
#include <iostream>
#include "Prisoner.h"
#include "Talk To Encounters English.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"



void prisoner()
{

    bool answerAgain{ false };


    std::cout << "Prisoner: \"Where did he go? He was there a moment ago...\n"
        << "Hey you, traveler! Have you seen someone that's probably crying?\n"
        << "Or searching for someone?\"\n"
		<< "y: I think so. He went that way.\n"
		<< "n: Sorry, I haven't seen him.\n"
		<< "a: Want to do his same end?\n"
		<< "h: Are those scars? Let me help you.\n"
		<< "1: How does he look like?\n"
		<< "2: Want me to help?\n";

	do
	{

		switch (Input::character())
		{
		case 'y':// yes: I think so. He went that way.

			std::cout << "Prisoner: \"Really?! Thank you!\"\n"
				<< "(She hugs you and runs in the direction you pointed at)\n";

			encounter().setIsGone(true);
			answerAgain = false;

			break;

		case 'n':// no: Sorry, I haven't seen him.

			std::cout << "Prisoner: \"Oh, sorry to have disturbed ya. Bye\"\n"
				<< "(The girl goes away leaving you alone. She looked a bit sad)\n";

			encounter().setIsGone(true);
			answerAgain = false;

			break;

		case 'a':// attack: Want to do his same end?

			killOrNot();
			answerAgain = false;

			break;

		case 'h':// heal: Are those scars? Let me help.

			std::cout << "Prisoner: \"There's no need, but thanks anyway.\n"
				<< "I'm going to find him. Bye.\"\n";

			encounter().setIsGone(true);
			answerAgain = false;

			break;

		case '1':// How does he look like?
			
			std::cout << "(The prisoner takes out a picture of a man from her pocket.\n"
				<< "He looks like the common torturer)\n"
				<< "Prisoner: \"So have you seen him?\"\n"
				<< "y: Yes, I saw him going in thet direction.\n"
				<< "n: no, I haven't seen him.\n";

			answerAgain = true;
			
			break;

		case '2':// Want me to help?
			
			std::cout << "Prisoner: \"Would you do that for me?! Really?!\"\n"
				<< "(While she was saying that you could swear her eyes strated glowing "
				<< "for how happy she was to hear that)\n";

			waitForAnyKey();

			std::cout << "(After hours of going around looking for him, she points to a man)\n"
				<< "Prisoner: \"It's him!\"\n"
				<< "(After that she goes to the man)\n";

			waitForAnyKey();

			std::cout << "(You go after her. The girl jums when she's close enough to the man.\n"
				<< "She then hugs him in mid air. You could see they were so happy that tears "
				<< "started flowing from their eyes)\n";

			waitForAnyKey();

			std::cout << "Torturer: \"I thought you left me forever...\"\n"
				<< "Prisoner: \"I would never do such a thing... To you.\n"
				<< "I went to buy new chains. The ones you have are about to break!\"\n";

			waitForAnyKey();

			std::cout << "Prisoner: \"HOw can you do your job without them?\"\n"
				<< "Torturer: \"I planned to buy them as soon as I got my payment.\"\n"
				<< "Prisoner: \"Well, thank you for helping me.\"\n";

			waitForAnyKey();

			std::cout << "Prisoner: \"Take this as a token of my appreciation. Byee!\"\n"
				<< "Torturer: \"Thank you. Goodbye.\"\n";

			player().setInventory().addItem(ObjectUid::magicScroll);
			encounter().setIsGone(true);
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



void killOrNot()
{

	bool answerAgain{ false };


	std::cout << "Prisoner: \"What have ya done to my love?!\"\n"
		<< "(She starts crying. After that she falls on her knees)\n"
		<< "Prisoner: \"I-I don't have anything left in my life anymore...\"\n";

	waitForAnyKey();

	std::cout << "Prisoner: \"You can kill me, I won't do anything against you.\"\n"
		<< "(She is still crying)\n"
		<< "1: (Kill her)\n"
		<< "2: (Spare her life)\n"
		<< "3: Become my slave and join my party!\n";
	do
	{

		switch (Input::character())
		{
		case '1':// option 1: (Kill her)

			std::cout << "(You take your weapon attack her.\n"
				<< "Like she said, she didn't oppose to you.\n"
				<< "You kill her with a single blow)\n";
			answerAgain = false;

			break;

		case '2':// option 2: (Spare her life)

			std::cout << "(The prisoner keeps crying so you leave her behind.\n"
				<< "Not long after a rock falls from somewhere and hits the girl on her head)\n";
			answerAgain = false;

			break;

		case '3':// option 3: Become my slave and join my party!

			std::cout << "(While shse was crying you heard a yes, but Necoto said she didn't "
				<< "like that.\nSo she saved her by erasing her from the game)\n";
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);


	encounter().setIsUnderAttack(true);
	encounter().takeDamage(encounter().getHealth());

}

void Creatures::Encounter::Prisoner::talk()
{
}

void Creatures::Encounter::Prisoner::thinkAndAct()
{
}

void Creatures::Encounter::Prisoner::setName()
{
	name = "Prisoner";
}

void Creatures::Encounter::Prisoner::setStats()
{
	maxHp = 9 + (6 * (lvl - 1));
	maxAtk = 1 + (1 * lvl);
	maxDef = -5;
	critRate = 0;
	critDmg = 0;
	xp = 1;

	hp = maxHp;
	atk = maxAtk;
	def = maxDef;
}