
#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Talk To Encounters English.h"
#include "Actions.h"
#include "Exp. N. 30C.h"
#include "Print Errors.h"
#include "Prng.h"
#include "Input.h"
#include "Stats.h"



void expN30C()
{

	bool answerAgain{ false };



	std::cout << "???: \"Ohh someone!\n"
		<< "Hello! Can we talk please?\"\n"
		<< "y: Yes, we can talk since I'm free.\n"
		<< "n: No, I can't because I have more important things to do right now.\n"
		<< "3: Are you searching for something?\n";

	do
	{

		switch (Input::character())
		{
		case 'y':// yes

			solveFirstMathProblem30C();
			answerAgain = false;

			break;

		case 'n':// no

			std::cout << "???: \"If you don't wanna talk, why are you still here?\n"
				<< "Go and do your things!\"\n"
				<< "(The girl goes away)\n"
				<< "Nanre: \"You could've talked to her. 30C doesn't bite.\n";

			waitForAnyKey();

			std::cout << "Luckily she didn't asked you about math.\n"
				<< "Last time six or seven npc disappeared misteriously after she asked something"
				<< " about math.\n"
				<< "You can say you're lucky. See ya.\"\n";

			encounter().setIsGone(true);
			answerAgain = false;

			break;

		case '3':// option 3

			// she says this only one time
			if (answerAgain)
			{

			}
			else
			{

				std::cout << "???: \"I'm looking for someone to talk with.\n"
					<< "Can we talk? Pleaseee.\"\n"
					<< "y: Ok.\n"
					<< "n: No, I don't want to talk to you.\n";

			}

			answerAgain = true;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);


	encounter().setCanTalk(false);

}



void solveFirstMathProblem30C()
{

	bool answerAgain{ false };

	int firstNumber{ Random::get(0, 10269) };
	int secondNumber{ Random::get(0, 15350) };
	int solution{ firstNumber + secondNumber };
	int correctAnswer{ 0 };


	std::cout << "30C: \"Yay! I'm Exp. N. 30C. To have it shorter, 30C.\n"
		<< "What is " << firstNumber << " + " << secondNumber << "?\"\n";
	changeSolution(solution);


	// get the answer to the question
	do
	{

		// if the input is the same as intValuekeeper the player answered correctly
		// the int number needs to be converted into a char
		if (Input::character() == convertToChar(correctAnswer))
		{
			
			solveSecondMathProblem30C();

		}
		else
		{

			std::cout << "30C: \"Wrong answer. You're of no use to me so I'm gonna kill you.\"\n";
			encounter().setIsUnderAttack(true);

		}

	} while (answerAgain);

}



int changeSolution(int solution)
{

	int correctAnswer{ 0 };
	int i{ 1 };

	// set all possible answers
	long int answer[3] = { (solution + Random::get(270, 1040)), (solution - Random::get(696, 969), solution)};
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


void solveSecondMathProblem30C()
{

	bool answerAgain{ false };



	// 4.294.967.294
	std::cout << "30C: \"you can do math. Then what is 2147483647 + 2147483647?\"\n"
		<< "1: 4294967294\n"
		<< "2: 4294967294\n"
		<< "3: 4294967294\n";

	do
	{

		switch (Input::character())
		{
		case '1':// option 1

			mathTester30C();
			answerAgain = false;

			break;

		case '2':// option 2

			mathTester30C();
			answerAgain = false;

			break;

		case '3':// option 3

			mathTester30C();
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);


}



void mathTester30C()
{

	std::cout << "30C: \"Npc nowadays are of higher level. Interesting"
		<< "Let's test now your fighting knowledge.\n"
		<< "Come on, try to beat me!\"\n"
		<< "(She comes to attack you)\n";

	encounter().setIsUnderAttack(true);

}