
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Talk To Encounters English.h"
#include "Actions.h"
#include "Exp. N. 30B.h"
#include "Print Errors.h"
#include "Player Stats.h"
#include "Input.h"
#include "Stats.h"



void expN30B()
{

	bool answerAgain{ false };



	std::cout << "???: \"I have to move my ship but this log is perfect.\n"
		<< "Finally, found a problem with the model and texture!\n"
		<< "Uh? Hello. Are you also interested in trees?\"\n"
		<< "1: Not much, but may I know what are you doing?\n"
		<< "2: No, I'm not. Now die, you useless elf!\n"
		<< "3: Yes, I know everything about trees.\n";

	do
	{

		switch (Input::character())
		{
		case '1':// option 1: Not much, but may I know what are you doing?

			ask30B();
			answerAgain = false;

			break;

		case '2':// option 2: No, I'm not. Now die, you useless elf!

			std::cout << "30B: \"I, 30B, will survive this because\n"
				<< "I'm the strongest among the strongest mages of the Ratabs Village.\n"
				<< "You're gonna get cancelled from this game!\"\n";

			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		case '3':// option 3: Yes, I know everything about trees.

			treeQuestion30B();
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



void ask30B()
{

	std::cout << "30B: \"I'm studying trees for my research.\n"
		<< "Anyway I'm Experiment Number 30B, Since no one likes a name that long,\n"
		<< "you can call me 30B.\"\n";

	waitForAnyKey();

	std::cout << "30B: \"If you look at this log, you'll say that this is a loblolly pine.\n"
		<< "And the that tree with yellow leaves is a witch hazel.\n"
		<< "Usually not many knows that the trees in this game are inspired by the "
		<< "ones we have in our world.\"\n";

	waitForAnyKey();

	std::cout << "30B: \"In the forests near Telub there are trees that sometimes scream.\n"
		<< "They are called Pinus Strobus or as the people that live call them: Screaming Pine.\n"
		<< "Another tree I wanna see is the Codariocalyx Motorius.\"\n";

	waitForAnyKey();

	std::cout << "30B: \"It's said that she can talk with other plants of it's kind.\n"
		<< "That's why she's also called the telegraph plant or dancing tree.\n"
		<< "I suppose I told you too much. You're probablye not inerested in trees.\"\n";

	waitForAnyKey();

	std::cout << "30B: \"So since you probably want to run away and remove your brain,\n"
		<< "I'll let you go. If you want a tree try to find me, I know everything about them.\"\n";

	waitForAnyKey();

	std::cout << "(The girl disappeared in the void)\n"
		<< "Nanre: \"Fun fact: all the plants and trees she said exist in Our world.\n"
		<< "See ya.\"\n";


	encounter().setIsGone(true);

}// 11:59. now guess what that time means



void treeQuestion30B()
{

	bool answerAgain{ false };

	int correctAnswer{ 0 };



	std::cout << "Then, tell me what is the tree that is known as Telegraph Plant?\"\n";

	correctAnswer = changeSolution();

	do
	{

		// if the input is the same as correctAnswer the player answered correctly
		// the int number needs to be converted into a char
		if (Input::character() == convertToChar(correctAnswer))
		{

			surviveTo30B();

		}
		else
		{

			liedTo30B();

		}

	} while (answerAgain);

}



void liedTo30B()
{

	std::cout << "£=B: \"YOU LIED TO ME!\n"
		<< "I don't care. So I'll leave you in the hands of Nanre.\"\n";

	waitForAnyKey();

	std::cout << "Nanre: \"You dared to lie to a girl?\n"
		<< "At least you didn't asked for her stats.\n"
		<< "For the punishment, I'll remove you 1 hp.\"\n";

	player().takeDamage(1);

	waitForAnyKey();

	std::cout << "Nanre: \"Did you learn the lesson?\n"
		<< "30B, could I ask you to come with me?\n"
		<< "I need you for the new dialogues of Flasail Slavendo.\"\n"
		<< "30B: \"Ok\"\n"
		<< "30B: \"Bye monster.\"\n"
		<< "Nanre: \"See ya.\"\n";


	encounter().setIsGone(true);

}



void surviveTo30B()
{

	std::cout << "30B: \"Good. Now I'll leave you alone because Nanre should be coming for me.\n"
		<< "Speak of the devil.\"\n"
		<< "Nanre: \"Morning. You already know why I'm here.\"\n";

	waitForAnyKey();

	std::cout << "Nanre: \"Should I come later?\"\n"
		<< "30B: \"No, I'll come with you.\"\n"
		<< "Then see ya Player. We have recording to do now!\"\n";

	waitForAnyKey();

	std::cout << "(They left you alone.)\n"
		<< "(Soon Nanre will start working again on Unreal Engine)\n"
		<< "(That's why he needs 30B and the others)\n";


	encounter().setIsGone(true);

}



int changeSolution()
{

	int i{ 1 };
	int correctAnswer{ 0 };

	// set all possible answers
	std::string answer[4] = { "Pinus Strobus", "Codariocalyx Motorius", "Omocestus Viridulus", "Error"};
	std::array<int, 3> foo{ 0, 1, 2 };

	// obtain a time-based seed:
	unsigned seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());

	// shuffle answers
	shuffle(foo.begin(), foo.end(), std::default_random_engine(seed));

	// print all answers
	for (int& x : foo)
	{
		std::cout << i << ": " << answer[x] << ".\n";
		++i;

		// when x = 2, the array contains the correct solution
		if (x == 2)
		{

			correctAnswer = i;

		}
		else
		{

		}

	}


	return correctAnswer;

}
