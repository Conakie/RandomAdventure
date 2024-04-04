
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Yugei Sansae.h"
#include "Input.h"
#include "Stats.h"



void zombie()
{

	char answer{ 0 };


	bool answerAgain{ false };



	std::cout << "Zombie: \"You are someone I know... Oh now I may know why. You killed me.\n";

	do
	{
		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes

			std::cout << "Zombie: \"Time for my revenge. Die.\"\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);
			
			break;

		case 'n'://no

			std::cout << "Zombie: \"Then are you the one who killed my friend Skeletron?\"\n";

			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "Zombie: \"What have you done? He was a good skeleton.\n You'll "
						<< "pay with your own life for what you've done.\"\n";
					answerAgain = false;
					encounter().setIsUnderAttack(true);

					break;

				case 'n'://no

					std::cout << "Zombie: \"Strange. You seem so familiar but I still don't "
						<< "remember you.\nDo you know who killed my friend skeletron?\"\n";
					do
					{
						answer = Input::character();
						switch (answer)
						{
						case 'y'://yes

							std::cout << "Zombie: \"Give me his name. Maybe write that on a piece "
								<< "of paper.\nAnd maybe add a description of him or her.\n"
								<< "So will you give me the name and description?\"\n";
							zombieRevenge();
							answerAgain = false;

							break;

						case 'n'://no

							std::cout << "Zombie: \"Oh. Sorry to make these kind of questions but "
								<< "I would like to take revenge.\nSomone killed him and I couldn'"
								<< "t help him.\nI'll leave you there. Bye\"\n";
							answerAgain = false;
							encounter().setIsGone(true);

							break;

						case 'w'://Skip

							std::cout << "Zombie: \"Are you not sure about that? I'll leave you "
								<< "some time to think and then answer me again.\nSo have you "
								<< "remembered who did that?\"\n";
							answerAgain = true;

							break;

						default:

							printNotPossible();
							answerAgain = true;

							break;
						}

					} while (answerAgain);

					answerAgain = false;

					break;

				case 'w'://Skip

					std::cout << "Zombie: \"How is it possible that you don't know if you killed "
						<< "him or not?\nAnyway after you remembered answer me again.\"\n";
					answerAgain = true;

					break;

				default:

					printNotPossible();
					answerAgain = true;

					break;
				}

			} while (answerAgain);

			answerAgain = false;

			break;

		case 'w'://Skip

			std::cout << "Zombie: \"You don't remember me? I'm Yugei Sansae.\n"
				<< "Does that says something to you?\"\n";

			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes
					
					std::cout << "Zombie: \"Oh finally it's been a long time. Now time for my "
						<< "revenge.\nDiee!\"\n";
					answerAgain = false;
					encounter().setIsUnderAttack(true);

					break;

				case 'n'://no

					std::cout << "Zombie: \"Then you aren't my enemy. For now. Don't see you agian.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'w'://Skip

					std::cout << "Zombie: \"You're still thinking? You never changed. So I can "
						<< "beat you now. DIEE!\"\n";
					answerAgain = false;
					encounter().setIsUnderAttack(true);

					break;

				default:

					printNotPossible();
					answerAgain = true;

					break;
				}

			} while (answerAgain);

			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain == true);


	encounter().setCanTalk(false);

}



void zombieRevenge()
{

	char answer{ 0 };


	bool answerAgain{ false };
	//For when the player isn't sure to give the name to the zombie
	bool alreadyAsked{ false };



	do
	{
		answer = Input::character();
		if (alreadyAsked)
		{

			switch (answer)
			{
			case 'y'://yes

				std::cout << "Zombie: \"Good. Now I'll go. Bye.\"\n(The zombie goes away)\n";
				answerAgain = false;
				encounter().setIsGone(true);

				break;

			case 'n'://no

				std::cout << "Zombie: \"Are you really sure you don't want to give that to me?\n"
					<< "Well then prepare to die.\"\n";
				answerAgain = false;
				encounter().setIsUnderAttack(true);

				break;

			case 'w'://Skip
				std::cout << "Zombie: \"How much time do you need to decide to say yes? An hour?\n"
					<< "You know what? You stressed me. Die.\"\n";
				answerAgain = false;
				encounter().setIsUnderAttack(true);

				break;

			default:

				printNotPossible();
				answerAgain = true;

				break;
			}

		}
		else
		{
			switch (answer)
			{
			case 'y'://yes

				std::cout << "Zombie: \"Thank you. You're a really gentle guy.\"\n";
				answerAgain = false;
				encounter().setIsGone(true);

				break;

			case 'n'://no

				std::cout << "Zombie: \"You shouldn't say that. You may not survive this.\nSo will you"
					<< " give me the name and description?\"\n";
				answerAgain = true;
				alreadyAsked = true;

				break;

			case 'w'://Skip

				std::cout << "Zombie: \"Don't leave me take that with violence. I hate doing "
					<< "things this way.\nSo you will now give it to me. Right?\"\n";
				answerAgain = true;
				alreadyAsked = true;

				break;

			default:

				printNotPossible();
				answerAgain = true;

				break;
			}
			

		}
		

	} while (answerAgain == true);

}



void zombi()
{

	char answer{ 0 };


	bool answerAgain{ false };


	std::cout << "Zombie: \"Tu sei qualcuno che conosco... Oh ora so perche'. Tu mi hai ucciso.\n";

	do
	{
		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes

			std::cout << "Zombie: \"Tempo per la mia vendetta. Muori.\"\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		case 'n'://no

			std::cout << "Zombie: \"Allora sei quello che ha ucciso il mio amico Scheletron?\"\n";

			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "Zombie: \"Cosa hai fatto? Era un bravo scheletro.\n"
						<< "Pagherai con la tua stessa vita per cio' che hai fatto.\"\n";
					answerAgain = false;
					encounter().setIsUnderAttack(true);

					break;

				case 'n'://no

					std::cout << "Zombie: \"Strano. Mi sembri familiare ma continuo a non "
						<< "ricordare chi sei.\nSai chi ha ucciso il mio amico Scheletron?\"\n";
					do
					{
						answer = Input::character();
						switch (answer)
						{
						case 'y'://yes

							std::cout << "Zombie: \"Dammi il suo nome. Magari scrivilo su un pezzo "
								<< "di carta.\nE magari aggiungi una sua descrizione.\n"
								<< "Quindi, mi darai il suo nome e descrizione?\"\n";
							zombiRevenge();
							answerAgain = false;

							break;

						case 'n'://no

							std::cout << "Zombie: \"Oh. Scusa se ti ho fatto queste domande ma "
								<< "vorrei vendicarlo.\nQualcuno lo ha ucciso e io non ho potuto "
								<< "aiutarlo.\nTi lascio qua. Ciao.\"\n";
							answerAgain = false;
							encounter().setIsGone(true);

							break;

						case 'w'://Skip

							std::cout << "Zombie: \"Non ne sei sicuro? Ti lascio un po' "
								<< "di tempo per pensare e poi rispondimi di nuovo.\nQuindi ti "
								<< "sei ricordato chi lo ha fatto?\"\n";
							answerAgain = true;

							break;

						default:

							std::cout << "(NaN possibyte)\n";
							answerAgain = true;

							break;
						}

					} while (answerAgain == true);

					answerAgain = false;

					break;

				case 'w'://Skip

					std::cout << "Zombie: \"Come e' possibile che non ricordi se lo hai ucciso "
						<< "o no?\nComunque appena lo ricordi rispondimi di nuovo.\"\n";
					answerAgain = true;

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

			std::cout << "Zombie: \"Non ti ricordi di me? Sono Yugei Sansae.\n"
				<< "Ti dice qualcosa?\"\n";

			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "Zombie: \"Oh finalmente e' passatocosi' tanto tempo. E' ora "
						<< "per la mia vendetta.\nMuorii!\"\n";
					answerAgain = false;
					encounter().setIsUnderAttack(true);

					break;

				case 'n'://no

					std::cout << "Zombie: \"Quindi tu non sei mio nemico. Per ora. A mai piu'.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'w'://Skip

					std::cout << "Zombie: \"Stai ancoa pensando? Non cambi mai. Quindi ora posso "
						<< "batterti. MUORII!\"\n";
					answerAgain = false;
					encounter().setIsUnderAttack(true);

					break;

				default:

					std::cout << "(Non possibible)\n";
					answerAgain = true;

					break;
				}

			} while (answerAgain == true);

			answerAgain = false;

			break;

		default:

			std::cout << "(Non possibile)\n";
			answerAgain = true;

			break;
		}

	} while (answerAgain == true);


	encounter().setCanTalk(false);

}



void zombiRevenge()
{

	char answer{ 0 };


	bool answerAgain{ false };
	bool alreadyAsked{ false };//For when the player isn't sure to give the name to the zombie


	do
	{
		answer = Input::character();
		if (alreadyAsked == false)
		{

			switch (answer)
			{
			case 'y'://yes

				std::cout << "Zombie: \"Grazie. Sei una persona molta gentilo.\"\n";
				answerAgain = false;
				encounter().setIsGone(true);

				break;

			case 'n'://no

				std::cout << "Zombie: \"Non dovresti dirlo. Potresti non sopravvivere a questo.\n"
					<< "Quindi mi darai il nome e descrizione?\"\n";
				answerAgain = true;
				alreadyAsked = true;

				break;

			case 'w'://Skip

				std::cout << "Zombie: \"Non farmelo prendere con la violenza. Odio farlo cosi'"
					<< ".\nQuindi me lo darai. Giusto?\"\n";
				answerAgain = true;
				alreadyAsked = true;

				break;

			default:

				std::cout << "(Non possibillie)\n";
				answerAgain = true;

				break;
			}

		}
		else
		{

			switch (answer)
			{
			case 'y'://yes

				std::cout << "Zombie: \"Bene. Ora vado. Ciao.\"\n(Lo zombie se ne va via)\n";
				answerAgain = false;
				encounter().setIsGone(true);

				break;

			case 'n'://no

				std::cout << "Zombie: \"sei davvero sicuro che non me lo vuoi dare?\n"
					<< "Bene, preparati a morire.\"\n";
				answerAgain = false;
				encounter().setIsUnderAttack(true);

				break;

			case 'w'://Skip
				std::cout << "Zombie: \"Quanto tempo ti serve per deciderti di dire si? Un ora?\n"
					<< "Sai cosa? Tu mi hai stressato. Muori.\"\n";
				answerAgain = false;
				encounter().setIsUnderAttack(true);

				break;

			default:

				std::cout << "(Non possibile)\n";
				answerAgain = true;

				break;
			}

		}


	} while (answerAgain == true);

}