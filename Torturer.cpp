
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"



void torturer()
{

	char answer{ 0 };


	bool answerAgain{ false };


	std::cout << "Torturer: \"Have ya found my prisoner? She's gone.\"\n"
		<< "y: Yes, I did find her.\n"
		<< "n: No, I didn't. Sorry.\n"
		<< "s: Sorry...\n"
		<< "a: Wanna die?\n";

	do
	{
		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes

			std::cout << "Torturer: \"Really?! Thank you. I'm so happy that you found her.\n"
				<< "Is she ok?\"\n"
				<< "y: SHe was doin' fine.\n"
				<< "n: I don't remember. Sorry.\n"
				<< "s: ...\n"
				<< "a: Ready to do her asme end?\n";

			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "Torturer: \"Is she okay? Where did she go? I have to find her.\""
						<< "\n(You tell him where the prisoner went)\nTorturer: \"Thank you. I..."
						<< "I don't know how to repay you. Better that I go after her. Bye and "
						<< "thank you.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'n'://no

					std::cout << "Torturer: \"Oh... I'm sorry to have disturbed you. But you'll"
						<< "probably do the same thing if she was your only friend.\n"
						<< "See you.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 's'://Skip

					std::cout << "Torturer: \"Where did she go? We were happy. So why did she go"
						<< " away?\nI wan't to find her now. She's there. Found her. Bye.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'a'://Attack

					std::cout << "Torturer: \"WHAT HAVE YOU DONE?! YOU KILLED MY PRISONER?"
						<< "\nPREPARE TO DO THE SAME END OF HER. NO, EVEN WORST.\nSHE DIDN'T "
						<< "DO ANYTHING BAT TO ANYONE. MAYBE TO ONLY ONE GUY BUT STILL.\n"
						<< "NOW DIEEE!!!\"\n";
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

		case 'n'://no
			
			std::cout << "Torturer: \"So she's really gone. Why she's gone. she was my first prisoner"
				<< ".\"\n(The torturer starts crying)\n(A girl is coming from behind the torturer)"
				<< "\nPrisoner: \"Did ya miss me? I'm sorry I needed to buy some chains.\nThe one "
				<< "ya have like 300 years. If someone finds on me tetanus I'll probably die "
				<< "soon after that.\"\n";

			waitForAnyKey();

			std::cout << "Torturer: \"You came back? For me? Really? Tonight pizza for everyone!\"\n"
				<< "Prisoner: \"I left ya a piece of paper to say I went shopping. Haven't ya "
				<< "seen that?\"\n"
				<< "Torturer: \"There was a piece of paper?\"\n";

			waitForAnyKey();

			std::cout << "Prisoner: \"Yes. Why don't we go back together?\"\n"
				<< "Torturer: \"I'll gladly accept youre invite.\"\n"
				<< "(The torturer and the prisoner go away while talking)\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case 's'://Skip

			std::cout << "Torturer: \"Oh. Sorry if I disturbed. I'll go now.\"\n"
				<< "(The torturer goes away shouting: \"Prisoner? Where are you?\"\nHe also "
				<< "started to cry because he isn't finding the prisoner)\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case 'a'://Skip

			std::cout << "Torturer: \"So you chose death? I'll survive to this only to find "
				<< "you my prisoner.\nYou're the only reason I exist.\"\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);
			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain == true);


	encounter().setCanTalk(false);
	
}



void torturatore()
{

	char answer{ 0 };


	bool answerAgain{ false };


	std::cout << "Torturatore: \"Hai trovato il mio prigioniero? E' sparito.\"\n";

	do
	{
		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes

			std::cout << "Torturatore: \"Davvero?! Grazie. Sono cosi' felice che lo hai trovato.\n"
				<< "E' ancora vivo?\"\n";
			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "Torturatore: \"Sta bene? Dove e' andato? Devo trovarlo.\""
						<< "\n(Gli dici dove e' andato)\nTorturatore: \"Grazie. Non..."
						<< "Non so come ripagarti. Meglio che lo vado a prendere. Ciao e "
						<< "grazie.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'n'://no

					std::cout << "Torturatore: \"Oh... Scusami se ti ho disturbato ma faresti "
						<< "probabilmente la stessa cosa se lui fosse il tuo unico amico.\n"
						<< "Ci si vede.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'w'://Skip

					std::cout << "Torturatore: \"Dove e' andato? Eravamo felici. Quindi perche' se ne e' andato"
						<< "?\nVoglio trovarlo ora. Eccolo li'. Trovato. Ciao.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'a'://Attack

					std::cout << "Torturatore: \"COSA HAI FATTO?! HAI USCCISO IL MIO PRIGIONIERO?"
						<< "\nPREPARATI A FARE LA STESSA FINE CHE HA FATTO. MA ANCHE PEGGIORE.\nLUI NON HA "
						<< "FATTO NULLA DI MALE A NESSUNO. MAGARI A SOLO UNO MA COMUNQUE.\n"
						<< "ORA MUORI!!!\"\n";
					answerAgain = false;
					encounter().setIsUnderAttack(true);

					break;

				default:

					std::cout << "(Non possibile)\n";
					answerAgain = true;

					break;
				}

			} while (answerAgain == true);
			answerAgain = false;

			break;

		case 'n'://no

			std::cout << "Torturatore: \"Quindi se ne e' veramente andato. Perche'? Egli era il mio primo prigioniero"
				<< ".\"\n(Il torturatore inizia a piangere)\n(Un tizio sta arrivando da dietro il torturatore)"
				<< "\nPrigioniero: \"Ti mancavo? Scusami ma avevo bisogno di comprare alcune catene.\nQuelle "
				<< "che hai hanno come 300 anni. Se qualcuno mi trova il tetano probabilmente "
				<< "moriro' poco dopo quello.\"\n"
				<< "Torturatore: \"Sei tornato indietro? Per me? Davvero? Stasera pizza per tutti.\"\n"
				<< "Prigioniero: \"Ti ho lasciato un pezzo di carta per dirti che andavo a fare sh"
				<< "opping. Non lo hai visto?\"\n"
				<< "Torturatore: \"C'era un pezzo di carta?\"\n"
				<< "Prigioniero: \"Si. Perche' non torniamo indietro insieme?\"\n"
				<< "Torturatore: \"Accetto molto volentieri il tuo invito.\"\n"
				<< "(Il torturatore e il prigioniero vanno via mentre stanno parlando)\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case 'w'://Skip

			std::cout << "Torturatore: \"Oh. Scusami se ti ho disturbato. Ora vado.\"\n"
				<< "(Il torturatore se ne va urlando: \"Prigioniero? Dove sei?\".\nHa anche "
				<< "iniziato a piangere perche' non riesce a trovare il suo prigioniero)\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case 'a'://Skip

			std::cout << "Torturatore: \"Quindi hai scelto la morte? Sopravvivero' a questo solo per trovare "
				<< "il mio prigioniero.\nLui e' la mia unica ragione per cui esisto.\"\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		default:

			std::cout << "(Non possible)\n";
			answerAgain = true;

			break;
		}

	} while (answerAgain == true);


	encounter().setCanTalk(false);
	
}