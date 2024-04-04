
#include <iostream>
#include "Talk To Encounters English.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Ratman.h"



void ratman()
{
	bool answerAgain{ false };
	int stayedSilentFor{ 0 };


    std::cout << "Ratman: \"Hello, adventurer. Are you here to seek my help?\"\n"
		<< "y: Yes, I need help.\n"
		<< "n: No, I don't need anything.\n"
		<< "s: (Stay silent)\n";
	do
	{

		switch (Input::character())
		{
		case 'y':// yes: Yes, I need your help.

			requestHelp();
			answerAgain = false;

			break;

		case 'n':// no: No, I don't need anything.

			std::cout << "Ratman: \"Then I presume you have reached inner peace, correct?\n"
				<< "y: Yes I did, and you?\n"
				<< "n: Nope, but I guess you did?\n";
			Input::character();
			std::cout << "Ratman: \"Uh? Have you said something?\n"
				<< "Oh yeah, yes, I did. Look: \n";
			encounter().heal(encounter().getHealth());
			std::cout << "Ratman: \"I don't think I'm feeling so...\"";
			encounter().takeDamage(encounter().getHealth());
			answerAgain = false;

			break;

		case 's':// skip: (Stay silent)

			// if the player stays silent for 10 or 20 times
			// add 10 wood/ 20 smallHealingPotion
			if (stayedSilentFor == 10)
			{
				std::cout << "Ratman: \"Fine, fine. Take this thing here adventurer.\"\n"
					<< "(Ratman gives you 10 wood logs)\n";
				player().setInventory().addItem(ObjectUid::wood, 10);
			}
			else if (stayedSilentFor == 20)
			{
				std::cout << "Ratman: \"Fine, fine. Take this thing here adventurer.\"\n"
					<< "(Ratman gives you 20 big healing potions)\n";
				player().setInventory().addItem(ObjectUid::smallHealingPotion, 20);
			}
			else if (stayedSilentFor >= 100)
			{
				std::cout << "Nanre: \"Please, get a life.\"\n";
			}
			else
			{
				std::cout << "Ratman: \"...\"\n";
			}
			++stayedSilentFor;
			answerAgain = true;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);


}



void requestHelp()
{
	bool answerAgain{ false };


	std::cout << "Ratman: \"And if I may know, what is that you are seeking so much?\"\n"
		<< "1: I am looking for immorality.\n"
		<< "2: I am seeking only one thing, your head.\n"
		<< "3: My objective is one: I am going to kill all of 'them'.\n"
		<< "4: My, oh my! Good sir, please, mind your business.\n"
		<< "5: What am I looking for cannot be described by simple words.\n";
	do
	{

		switch (Input::character())
		{
		case '1':// option 1: I am looking for immorality.

			std::cout << "Ratman: \"Your wish is my command.\n"
				<< "The place you are looking for is 2500 km north-east from here.\n"
				<< "It has been know as the most immoral country.\"\n";
			waitForAnyKey();
			std::cout << "Ratman: \"Since I have had issues with this matter, I can't say more.\n"
				<< "You may be able to find a way to go there and accomplish what I failed.\n"
				<< "I hope you succeed in your mission. I will stay here, rooting for you.\"\n";
			waitForAnyKey();
			std::cout << "May our path cross again seeker.\n"
				<< "Until we meet again.\"\n";
			encounter().setIsGone(true);
			answerAgain = false;

			break;

		case '2':// option 2: I am seeking only one thing, your head.

			takeHead();
			answerAgain = false;

			break;

		case '3':// option 3: My objective is one: I am going to kill all of 'them'.

			std::cout << "Ratman: \"Is your name perphaps, Eren Yeager?\n"
				<< "I presume, all these giants are going to last long, right?\n"
				<< "Behind you! A giant!\"\n";
			std::cout << "Ratman: \"Did you fall for this?.\n"
				<< "Fine, fine, take this item. It will help in your adventure.\"\n"
				<< "(Ratman gives you 6 big healing potion and goes away)\n";
			player().setInventory().addItem(ObjectUid::bigHealingPotion, 6);
			encounter().setIsGone(true);
			answerAgain = false;

			break;
			
		case '4':// option 4: My, oh my! Good sir, please, mind your business.

			std::cout << "Ratman: \"Excuse me sir, please, go kill yourself\"\n"
				<< "(Ratman goes away)\n";
			encounter().setIsGone(true);
			answerAgain = false;
			
			break;
			
		case '5':// option 5: What am I looking for cannot be described by simple words.

			std::cout << "Ratman: \"Then look for this number: 6992.\n"
				<< "I think that is what you are searching for.\"\n"
				<< "(Ratman disappears in a black alley)\n";
			encounter().setIsGone(true);
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);

}



void takeHead()
{
	bool answerAgain{ false };


	std::cout << "Ratman: \"The only one who can get my head is my creator.\n"
		<< "If you wish to meet with her, I could plan you a meeting.\"\n"
		<< "y: Yes, please. I want to talk to your creator.\n"
		<< "n: No, but thank you for your availability.\n";
	do
	{

		switch (Input::character())
		{
		case 'y':// yes: Yes, please. I want to talk to your creator.

			argue();
			answerAgain = false;

			break;

		case 'n':// no: No, but thank you for your availability.

			std::cout << "Ratman: \"Understood, then I wish good luck on your mission.\n"
				<< "Until we meet again.\"\n";
			encounter().setIsGone(true);
			answerAgain = false;

			break;

		case 'a':// attack: (hidden action)

			fight();
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);

}



void argue()
{
	bool answerAgain{ false };


	std::cout << "Ratman: \"Your wish is my command.\"\n"
		<< "(Ratman starts to shout Necoto while looking above)\n"
		<< "Ratman: \"Here she is, my creator.\"\n";
	waitForAnyKey();
	std::cout << "Necoto: \"What is it again?\"\n"
		<< "Ratman: \"This adventurer wants to talk to you, my creator.\"\n"
		<< "Necoto: \"I'm no creator, just a manager.\"\n";
	waitForAnyKey();
	std::cout << "Necoto: \"So you want to kill him, he refuses to attack you\n"
		<< "because he says I'm the only one that can kill him? Really?!\n"
		<< "May I know why you always have to call me?!\"\n";
	waitForAnyKey();
	std::cout << "Necoto: \"Sorry that I lost my cool.\n"
		<< "It's just that I have too much work on my shoulders recently.\n"
		<< "Anyway, why don't the both of you go on your own road?\"\n";
	waitForAnyKey();
	std::cout << "Ratman: \"As you wish, my creator.\"\n"
		<< "Necoto: \"It's not an order, you can do whatever you want.\n"
		<< "I won't stop you unless you break the rules, ok?\"\n";
	waitForAnyKey();
	std::cout << "Necoto: \"Now if you'll excuse me I'm going to meet with Nala.\n"
		<< "Before I go, Ratman, choose for yourself what you wanna do.\n"
		<< "I hate interviews...\"\n";
	waitForAnyKey();
	std::cout << "(Necoto disappears)\n"
		<< "Ratman: \"Do you still want to fight me?\"\n"
		<< "y: Yes, let's fight!\n"
		<< "n: No, I am going away.\n";

	do
	{

		switch (Input::character())
		{
		case 'y':// yes: Yes, let's fight!

			fight();
			answerAgain = false;

			break;

		case 'n':// no: No, I am going away.

			std::cout << "Ratman: \"Understood, until we meet again, adventurer.\"\n"
				<< "(The both of you go away)\n";
			encounter().setIsGone(true);
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);

}



void fight()
{
	std::cout << "Ratman: \"Understood. You chose death.\n"
		<< "Increasing attack by 666%... Attack increased.\n"
		<< "Increasing health by 999%... Health increased.\"\n";
	waitForAnyKey();
	std::cout << "Ratman: \"Ready to fight!\n\"";

	encounter().setIsUnderAttack(true);
}