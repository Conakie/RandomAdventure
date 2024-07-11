
#include <iostream>
#include "Yourself.h"
#include "Everywhere Used Func.h"
#include "Input.h"
#include "Talk To Encounters English.h"
#include "Stats.h"
#include "Random.h"



void yourself()
{

	bool answerAgain{ false };


    std::cout << "Yourself: \"Hello, myself. How's your day going?\"\n"
        << "1: Pretty well. And yours?\n"
        << "2: It would be better a paper cut than today.\n"
        << "3: Who are you?!\n";

	do
	{

		switch (Input::character())
		{
		case '1':// option 1: Pretty well. And yours?

			std::cout << "Yourself: \"Mine was good, it could have been better if I had found "
				<< "10k cota but,\n hey it could have been worse.\n"
				<< "Need help with something?\"\n"
				<< "1: Do you know any healing spell?\n"
				<< "2: Do you know where Eyil is?\n"
				<< "3: I'm fine. I don't need anything.\n";

			dialogue1Part1();

			answerAgain = false;

			break;

		case '2':// option 2: It would be better a paper cut than today.

			std::cout << "Yourself: \"I'm sorry to hear this.\n"
				<< "If there is something I can do to help, just tell me.\n"
				<< "1: Do you know any healing spell?\n"
				<< "2: Do you know where Eyil is?\n"
				<< "3: I'm fine. And anyway what could go worse?\n";

			dialogue1Part1();

			answerAgain = false;

			break;

		case '3':// option 3: Who are you?!

			std::cout << "Yourself: \"Who am I? I am you. We are the same person.\n"
				<< "What's my name? It's " << player().getName() << ".\n"
				<< "I don't wanna fight so, how was your day until now?\n"
				<< "1: Pretty good. Yours?\n"
				<< "2: It would be better eating a granade than today.\n";
			answerAgain = true;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);


	encounter().setCanTalk(false);
	encounter().setIsGone(true);

}



void dialogue1Part1()
{

	bool answerAgain{ false };


	do
	{

		switch (Input::character())
		{
		case '1':// option 1: Do you know any healing spell?

			std::cout << "Yourself: \"I can't teach you one but i can you you.\n"
				<< "Here, How do you feel now? Better?.\n";

			player().heal(Random::get(1, (6 * player().getLvl()) ));

			answerAgain = false;

			break;

		case '2':// option 2: Do you know where Eyil is?

			std::cout << "Yourself: \"Eyil... She isn't here. Sorry.\"\n";

			answerAgain = false;

			break;

		case '3':// option 3: I'm fine. I don't need anything.

			std::cout << "Yourself: \"Good. Then I can go away.\"\n";
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);

	std::cout << "(You see the yourself disappearing in front of you)\n";


}