
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Skeletron.h"



void skeletron()
{

	char answer{ 0 };


	bool answerAgain{ false };


	
	std::cout << "Skeleton: \"Did you know my friend Yugei Sansae?\"\n";

	do
	{
		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes

			std::cout << "Skeletron: \"Do you know how to use a weapon and are you strong with it?"
				<< "\nIf yes can I challenge you?\"\n";

			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "Skeleton: \"Good choice. Ready? Prepare to lose.\"\n";
					answerAgain = false;
					encounter().setIsUnderAttack(true);

					break;

				case 'n'://no

					std::cout << "Skeletron: \"Oh well it was a pleasure to meet you. Bye.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'w'://Skip

					std::cout << "Skeleton: \"I'll give you some time to think about it.\n"
						<< "When you're ready say yes.\"\n";
					answerAgain = true;

					break;

				default:

					printNotPossible();
					answerAgain = true;

					break;
				}

			} while (answerAgain == true);


			answerAgain = false;
			
			break;

		case 'n'://no

			std::cout << "Skeleton: \"Go away. I'm not interested in you if you don't know him."
				<< "\nBut maybe you can defeat me. Wanna try?\"\n";

			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "Skeletron: \"Prepare to lose!\"\n";
					answerAgain = false;
					encounter().setIsUnderAttack(true);

					break;

				case 'n'://no

					std::cout << "Skeleton: \"This confirm that you are a useless and worthless "
						<< "creature. Bye\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'w'://Skip

					std::cout << "Skeleton: \"I don't have time to lose so go away. Bye.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				default:

					printNotPossible();
					answerAgain = true;

					break;
				}

			} while (answerAgain == true);


			answerAgain = false;
			
			break;

		case 'w'://Skip

			std::cout << "Skeleton: \"You don't know him ok. Bye.\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain == true);


	encounter().setCanTalk(false);

}



void skeletro()
{

	char answer{ 0 };


	bool answerAgain{ false };



	std::cout << "Skeletro: \"Conosci il mio amico Yugei Sansae?\"\n";

	do
	{
		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes

			std::cout << "Scheletro: \"Sai come usare un'arma e sei forte con essa?"
				<< "\nSe si posso sfidarti?\"\n";

			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "Scheletro: \"Ottima scelta. Preparati a perdere.\"\n";
					answerAgain = false;
					encounter().setIsUnderAttack(true);

					break;

				case 'n'://no

					std::cout << "Scheletron: \"Oh beh, e' stato un piacere conoscerti. Ciao.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'w'://Skip

					std::cout << "Scheletro: \"Ti do' un po' di tempo per pensarci.\n"
						<< "Quando sei pronto dimmi di si.\"\n";
					answerAgain = true;
					encounter().setIsUnderAttack(true);

					break;

				default:

					std::cout << "(Non possibile)\n";
					answerAgain = true;
					encounter().setIsUnderAttack(true);

					break;
				}

			} while (answerAgain == true);


			answerAgain = false;

			break;

		case 'n'://no

			std::cout << "Scheletro: \"Vai via. Non sono interessato a te se non lo conosci."
				<< "\nPero' forse puoi battermi. Vuoi provare?\"\n";

			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "Scheletron: \"Preparati a perdere!\"\n";
					answerAgain = false;
					encounter().setIsUnderAttack(true);

					break;

				case 'n'://no

					std::cout << "Scheletron: \"Questo conferma che sei una creature inutile e "
						<< "senza valore. Ciao.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'w'://Skip

					std::cout << "Scheletro: \"Non ho tempo da perdere quindi vattene. Ciao.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				default:

					std::cout << "(Non possibile)\n";
					answerAgain = true;

					break;
				}

			} while (answerAgain == true);


			answerAgain = false;

			break;

		case 'w'://Skip

			std::cout << "Scheletro: \"Non lo conosci ok. Ciao.\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		default:

			std::cout << "(Non possibile)\n";
			answerAgain = true;

			break;
		}

	} while (answerAgain == true);


	encounter().setCanTalk(false);

}

void Creatures::Encounter::Skeletron::talk()
{
}

void Creatures::Encounter::Skeletron::setName()
{
	name = "Skeletron";
}

void Creatures::Encounter::Skeletron::setStats()
{
	maxHp = 11 + (9 * (lvl - 1));
	maxAtk = 1 + (1.25 * lvl);
	maxDef = 4;
	critRate = 0;
	critDmg = 0;
	xp = 2;

	hp = maxHp;
	atk = maxAtk;
	def = maxDef;
}
