
#include <iostream>
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Player Stats.h"
#include "Talk To Encounters English.h"
#include "Actions.h"
#include "Exp. N. 30A.h"
#include "Random.h"
#include "Input.h"
#include "Stats.h"



void expN30A()
{

	bool answerAgain{ false };
	short number{ 0 };
	bool isStressed{ false };



	std::cout << "???: \"Uh? How did you found this place?\n"
		<< "Kelmod said ther weren't any NPC here.\n"
		<< "Fine. What do you want?\"\n";

	do
	{
		
		switch (Input::character())
		{
		case 'a':// attack

			std::cout << "???: \"Fine. And I came here to rest.\n"
				<< "Let's finish this quickly. I want to read.\"\n";
			answerAgain = false;

			break;

		case 't':// talk

			talkTo30A();

			break;

		case 'h':// heal

			player().heal(0.05);
			std::cout << "\n???: \"You really needed to drink that potion here?\n"
				<< "Not that I care about what you do.\n"
				<< "So? Do you have an answer to my question?\"\n";
			answerAgain = true;

			break;

		case 'e':// heal to max

			player().heal(player().getMaxHealth());
			std::cout << "???: \"Everyone can do that. You just have to learn everything.\n"
				<< "What? I can't do it. I am not interested in adventuring so I skipped that part."
				<< "\nNow, if you want to disappear from the RAM, I'll put away my book.\n"
				<< "So choose carefully your next words.\"\n";
			answerAgain = true;

			break;

		case '5':// check player stats

			printPlayerStats();

			// she also talk to the player after he/she check his/her stats
			playerTalk30A();
			answerAgain = false;

			break;

		case 's':// skip

			if (isStressed)// 30A is stressed by the player
			{

				std::cout << "???: \"Let's see. You're taking too much of my time.\n"
					<< "Let's use a prng. If the number that comes out is higher than 50,\n"
					<< "I'll delete you. If it's lower I'll let you live.\n";

				waitForAnyKey();

				number = Random::get(0, 100);
				std::cout << "???: \"The Prng chose: " << number << "\"\n";

				if (number >= 50)// attack
				{

					std::cout << "Prepare to die. I, Experiment number 30 A, Won't leave you "
						<< "alive.\neven if it's going to be the last thing I'll do in my "
						<< "life.\"\n";
					encounter().setIsUnderAttack(true);
					answerAgain = false;

				}
				else// leave the player alive
				{

					std::cout << "???: \"You're lucky. You won't be deleted from the ram.\"\n";
					answerAgain = true;

				}


			}
			else// 30 is not stressed by the player
			{

				std::cout << "???: \"I don't have time to lose so go away or say something.\"\n";
				answerAgain = true;
				isStressed = true;

			}

			break;

		case 'y':// yes

			std::cout << "???: \"What do you mean by 'Yes'?\"\n";

			break;

		case 'n':// no

			std::cout << "???: \"What do you mean by 'No'?\"\n";

			break;

		default:// action not possible or not available

			printNotPossible();

			break;
		}


	} while (answerAgain);
	

	encounter().setCanTalk(false);

}



void talkTo30A()
{

	bool answerAgain{ false };



	std::cout << "30A: \"I'm Experiment Number 30A, for short 30A.\n"
		<< "Tell me, npc, what do you want?\"\n"
		<< "1: I'm not an npc!\n"
		<< "2: Wanna buy or sell something?\n"
		<< "3: How many hp do you have?\n";

	do
	{

		switch (Input::character())
		{
		case '1':// option 1

			std::cout << "30A: \"What?! You could've said that earlier!\n"
				<< "I'm sorry for the way I talked to you. I thinked you were an npc!\"\n"
				<< "(You say that it's no problem at all)\n";

			waitForAnyKey();
			
			std::cout << "30A: \"Then, how about I give you something?\n"
				<< "You have to close your eyes though.\"\n"
				<< "(You closed your eyes)\n";

			waitForAnyKey();

			std::cout << "(It's been two minutes. Nothing happened)\n"
				<< "(You chose to open your eyes)\n"
				<< "(You look around you)\n"
				<< "(30A was nowhere to be found)\n";

			waitForAnyKey();

			std::cout << "(She probably ran away because she was embarassed)\n"
				<< "Nanre: \"You are a monster. You made a girl run away form you!\n"
				<< "She only had 500 years! Ok, ok. I'll go away. See ya soon.\"\n";

			encounter().setIsGone(true);
			answerAgain = false;

			break;

		case '2':// option 2

			stress30A();
			answerAgain = false;

			break;

		case '3':// option 3
			
			angry30A();
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);

}



void angry30A()
{

	bool answerAgain{ false };



	std::cout << "30A: \"It's rude to ask a girl about her stats!\nDon't you know that?\"\n"
		<< "Since you didn't know, I'll let that pass without punishment\""
		<< "Now that I think about it, did you found someone that looks like me?\"\n"
		<< "y: Yes, I there was a girl that looked like you.\n"
		<< "n: No, I didn't find anyone that looked like you.\n";

	do
	{

		switch (Input::character())
		{
		case 'y':// yes

			std::cout << "30A: \"So she's still playing! And it was her turn to "
				<< "take control of the ship!\"\n"
				<< "(You told her that she went away and she stopped playing)\n";

			waitForAnyKey();

			std::cout << "30A: \"Then I'll leave her alone. If you haven't realized, "
				<< "she was 30B, my sister.\nAnd she's usually everywhere.\n"
				<< "Actually she's a bit shy so she works usually in the background.\"\n";

			waitForAnyKey();

			std::cout << "30A: \"If you talked to her, you probably noticed that.\n"
				<< "Or maybe you can't even understand her emotions?\n"
				<< "My free time is ending so I have to go.\"\n";

			waitForAnyKey();

			std::cout << "30A: \"The ship won't take care of herself.\nByee.\"\n"
				<< "(She goes away)\n";
			encounter().setIsGone(true);
			answerAgain = false;

			break;

		case 'n':// no

			std::cout << "£=A: \"Perfect. Hopefully she's working.\n"
				<< "Mmm, I should probably go and clean my ship.\n"
				<< "It's been a week since last cleaning and last use.\n"
				<< "Well then, I'm going to clean the ship. Byee\"\n";
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);


}



void stress30A()
{

	bool answerAgain{ false };



	std::cout << "30A: \"I don't wanna buy anything. Same goes for selling.\n"
		<< "So go away.\"\n"
		<< "1: (Try to convince her to buy something)\n"
		<< "2: (Go Away)\n"
		<< "3: (Stay there)\n";

	do
	{

		switch (Input::character())
		{
		case '1':// option 1

			stressed30A();
			answerAgain = false;

			break;

		case '2':// option 2

			std::cout << "(You went away)\n";
			answerAgain = false;

			break;

		case '3':// option 3

			stressed30A();
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);


}



void stressed30A()
{

	bool answerAgain{ false };



	std::cout << "30A: \"Do you like this sword?\"\n"
		<< "(A sword appears in her hand)\n"
		<< "30A: \"If you want to keep living, go away.\"\n"
		<< "1: (Don't move)\n"
		<< "2: (Run away)\n"
		<< "3: No one can be scared by this.\n";

	do
	{

		switch (Input::character())
		{
		case '1':// option 1

			std::cout << "30A: \"So you choose death. Then die!\"\n";
			encounter().setIsUnderAttack(true);
			answerAgain = false;

			break;

		case '2':// option 2

			std::cout << "(You chose to run away from her)\n"
				<< "(You ran as fast as you could.)\n"
				<< "(You looked behind you)\n"
				<< "(There isn't anyone behind you)\n";

			waitForAnyKey();

			std::cout << "(You can now continue your adventure)\n"
				<< "Nanre: \"Be careful, she may come back for you. See ya.\"\n";
			encounter().setIsGone(true);
			answerAgain = false;

			break;

		case '3':// option 3

			std::cout << "30A: \"So you want to die. Fine then. Not my problem.\"\n";
			encounter().setIsUnderAttack(true);
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);


}



void playerTalk30A()
{

	bool answerAgain{ false };



	std::cout << "???: \"Wait, you're a player like me?\n"
		<< "What edition you're on?\"\n"
		<< "1: Random Adventure: The Aphaca\n"
		<< "2: Random Adventure.exe\n"
		<< "3: Random Adventure: The Simulation\n";


	do
	{

		switch (Input::character())
		{
		case '1':

			std::cout << "???: \"I thinked Necoto close the servers a long time ago.\n"
				<< "I'll ask her later. Now that I think about it, you can't see me.\n"
				<< "Right?\"\n"
				<< "y: Yep.\n"
				<< "n: Nope.\n";

			do
			{

				switch (Input::character())
				{
				case 'y':// yes

					meet30A();
					answerAgain = false;

					break;

				case 'n':// no

					interrogation30A();
					answerAgain = false;

					break;

				default:

					printNotPossible();
					answerAgain = true;

					break;
				}

			} while (answerAgain);

			break;

		case '2':

			std::cout << "30A: \"Wait, You know one of the devs?!\n"
				<< "Please, take me to him or her. Pleaseee.\"\n"
				<< "y: Ok. Let me go and call him.\n"
				<< "n: No, I won't.\n";

			do
			{

				switch (Input::character())
				{
				case 'y':// yes

					std::cout << "(You decided to disconnect from the game)\n"
						<< "(Legends says that she is still there waiting for an answer)\n"
						<< "(Also you changed server without losing your progress)\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'n':// no

					std::cout << "30A: \"Not that I cared much of meeting one of the devs."
						<< "\nI'm one of the most active beta testers of Keeyuo.\n"
						<< "Oh... Now that I think about it I have to test version 0.0.1 of "
						<< "Random Adventure.\nThis time they said that none of current version "
						<< "can match with it.\"\n";

					waitForAnyKey();

					std::cout << "30A: \"If I'm not worng it should be made with Unreal Engine 5.3"
						<< ".\nFrom what I know all textures are made by Nanre. Same for 3D models"
						<< ".\nYou know what, if you don't wanna do anything I'm gonna go try it."
						<< "\"\n"
						<< "1: Ok. See ya.\n"
						<< "2: Let's fight before you go.";
					fightOrGoAway30A(true);

					answerAgain = false;

					break;

				default:

					printNotPossible();
					answerAgain = true;

					break;
				}

			} while (answerAgain);

			answerAgain = false;

			break;

		case '3':

			std::cout << "30A: \"No one can play that!\"\n"
				<< "Nanre: \"But I can.\"\n"
				<< "30A: \"Where did you come from?\"\n";

			waitForAnyKey();

			std::cout << "Nanre: \"Daryan Village. Why do you ask?\nI'm everywhere.\"\n"
				<< "30A: \"Next time I won't ask.\n\""
				<< "Nanre: \"No one can play Random Adventure: The Simulation without my "
				<< "approval.\"\n";

			waitForAnyKey();

			std::cout << "Nanre: \"Since you lied I'm gonna remove you 1 hp.\"\n"
				<< "*Evil Laugh*\nSee ya.\"\n"
				<< "30A: \"I don't trust liars. Bye.\"\n";

			player().takeDamage(1);

			waitForAnyKey();

			std::cout << "(You are now alone)\n";


			encounter().setIsGone(true);
			answerAgain = false;

			break;

		default:

			std::cout << "???: \"What have you said? Sorry I didn't hear.\"\n";
			answerAgain = true;

			break;
		}

	} while (answerAgain == true);

}



void meet30A()
{

	bool answerAgain{ false };



	std::cout << "???: \"Then you shouldn't have the colors in the game.\n"
		<< "Could we meet? I wanna see it in person.\n"
		<< "I usually play the Simulation edition of the game.\n";

	waitForAnyKey();

	std::cout << "So wanna meet? I can pay for everything.\n"
		<< "It doesn't look like but I work... Sometimes.\n";


	do
	{

		switch (Input::character())
		{
		case 'y':// yes

			std::cout << "Exp. N. 30A: \"Well, I'm Exp. N. 30A. For short 30A.\"\n"
				<< "1: Ok, let's meet somewhere!\n"
				<< "2: You're a worthless elf! Die!\n"
				<< "3: Nope.";

			meetOrFight30A();
			answerAgain = false;

			break;

		case 'n':// no

			std::cout << "30A: \"Oh well, I always wanted to play that edition of the game.\n"
				<< "So... what do we do now? If you don't have anything to do, I have to go.\n"
				<< "Can I go? I have to take control of this ship. Work is calling me.\"\n"
				<< "1: See ya.\n"
				<< "2: You can go if you defeat me!\n";

			fightOrGoAway30A(false);
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);

}



void fightOrGoAway30A(bool hasFreeTime)
{

	bool answerAgain{ false };



	do
	{

		switch (Input::character())
		{
		case '1':// option 1

			std::cout << "30A: \"Byeee!\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case '2':// option 2

			if (hasFreeTime)
			{

				std::cout << "30A: \"I won't go easy on you.\n"
					<< "Now prepare to lose!\"\n";

			}
			else
			{

				std::cout << "30A: \"Fine. I'll finish this quickly and then I'll go do "
					<< "my job.\"\n";

			}
			
			encounter().setIsUnderAttack(true);
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);

}



void interrogation30A()
{

	bool answerAgain{ false };



	std::cout << "30A: \"From my knowledge Random Adventure: The Aphaca doesn't have a world.\n"
		<< "Don't tell me that you haven't downloaded the game from Keeyuo?\"\n"
		<< "1: Yeah, I haven't.\n"
		<< "2: Yes, a friend of mine sent me a copy.\n";

	do
	{

		switch (Input::character())
		{
		case '1':// option 1

			std::cout << "30A: \"You are a monster. Why haven't you chose the original?\n"
				<< "You don't even need to pay for it! It's free!\n"
				<< "Anyway, I would check if your device is fine. You never know.\n"
				<< "Now, I'll go away because my holofole is almost dead. So bye.\"\n";

			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case '2':// option 2

			std::cout << "30A: \"Please go and download the original.\n"
				<< "Not that I don't trust your friend but the original is way better.\n"
				<< "Well, I'll leave you. My holofole is at 5%.\nSee ya around the dungeons!\"\n";

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



void meetOrFight30A()
{

	bool answerAgain{ false };



	do
	{

		switch (Input::character())
		{
		case '1':// option 1

			std::cout << "30A: \"Should we meet at the Random Adventure ship?\n"
				<< "My sisters probably don't wanna move too much with ours "
				<< "so I probably can't come soon.\n";

			waitForAnyKey();

			std::cout << "Anyway since I have my Holofole that is about to die for overheating,"
				<< " when you wanna meet,\nfind me on Biskord as Conakie.\n"
				<< "I gotta go. It's at 6% so byee. See ya on Biskord.\"\n";

			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case '2':// option 2

			std::cout << "30A: \"Fine. You wanted to die. So die.\"\n";

			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		case '3':// option 3

			std::cout << "30A: \"Oh well, I've tried. So... what do we do now?\n"
				<< "We can go on our way, fight. I don't have much time left.\n"
				<< "My Holofole is about to burn. So What do you wanna do?\"\n"
				<< "1: Let's go on our own, separated ways.\n"
				<< "2: Let's battle!\n";

			fightOrGoAway30A(true);
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);

}
