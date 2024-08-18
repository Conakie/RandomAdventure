
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

void Creatures::Encounter::Yourself::talk()
{
	diarogue();
}

void Creatures::Encounter::Yourself::setName()
{
	if (m_player)
		name = m_player->getName();
	else
		name = "Yourself";
}

void Creatures::Encounter::Yourself::setStats()
{
	if (m_player)
	{
		maxHp = m_player->getMaxHealth();
		maxAtk = m_player->getAttack();
		maxDef = 10;
		critRate = 0;
		critDmg = 0;
		xp = 5;
	}
	else
	{
		maxHp = 10;
		for (int i = 0; i < lvl; ++i)
			maxHp += Random::get(1, 10);
		maxAtk = 3 + (1.5 * lvl);
		maxDef = 10;
		critRate = 0;
		critDmg = 0;
		xp = 4;
	}
}

void Creatures::Encounter::Yourself::diarogue()
{
	bool answerAgain{ false };


	std::cout << name << ": \"Hello, myself. How's your day going?\"\n";
        
	do
	{
		std::cout << "1: Pretty well. And yours?\n"
			<< "2: It would be better a paper cut than today.\n"
			<< "3: Who are you?!\n";
		switch (Input::character())
		{
		case '1':// option 1: Pretty well. And yours?

			std::cout << name << ": \"Mine was good, it could have been better if I had found "
				<< "10k cota but,\n hey it could have been worse.\n"
				<< "Need help with something?\"\n"
				<< "1: Do you know any healing spell?\n"
				<< "2: Do you know where Eyil is?\n"
				<< "3: I'm fine. I don't need anything.\n";
			dialogueOne();

			answerAgain = false;

			break;

		case '2':// option 2: It would be better a paper cut than today.

			std::cout << name << ": \"I'm sorry to hear this.\n"
				<< "If there is something I can do to help, just tell me.\n"
				<< "1: Do you know any healing spell?\n"
				<< "2: Do you know where Eyil is?\n"
				<< "3: I'm fine. And anyway what could go worse?\n";

			dialogueOne();

			answerAgain = false;

			break;

		case '3':// option 3: Who are you?!

			std::cout << "Yourself: \"Who am I? I am you. We are the same person.\n"
				<< "What's my name? It's ";
			if (m_player)
				std::cout << m_player->getName();
			else
				std::cout << "Yourself";

				std::cout << ".\n"
				<< "I don't wanna fight so, how was your day until now?\n"
				<< "1: Pretty good. Yours?\n"
				<< "2: It would be better eating a granade what happened today.\n";
			answerAgain = true;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);

	m_canTalk = false;
	waitForAnyKey();
}

void Creatures::Encounter::Yourself::dialogueOne()
{
	bool answerAgain{ false };
	do
	{
		switch (Input::character())
		{
		case '1':// option 1: Do you know any healing spell?

			std::cout << "Yourself: \"I can't teach you one but i can you you.\n"
				<< "Here, How do you feel now? Better?.\n";
			if (m_player)
				m_player->heal(Random::get(1, (6 * player().getLvl())));

			answerAgain = false;

			break;

		case '2':// option 2: Do you know where Eyil is?

			std::cout << "Yourself: \"Eyil... She isn't here. Sorry.\"\n"
				<< "Nanre: \"Ayo! She is not from Random Adventure.\n"
				<< "She didn't even try it. See ya.\"\n";

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
