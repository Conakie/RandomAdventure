
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"



void drunkGuy()
{
	char answer{ 0 };


	bool answerAgain{ false };



	std::cout << "(The guy is singing)\n"
		<< "Drunk guy: \"IIIII aaaaam sooooooooomeooooooneeee aaaaand II doooon't reeeemeeeembeeeeeer\n"
		<< "myyyyyyyy naaaaaameeee\n" << "(He saw you and comes towards you)\n"
		<< " Yooooou loooook familiaaaaaaar. Do IIII knooooow youuuu?\"\n\n"
		<< "y: Yes, you know me.\n"
		<< "n: No, you don't know me.\n"
		<< "s: Stay silent.\n";

	answer = Input::character();
	do
	{

		switch (answer)
		{
		case 'y'://yes

			std::cout << "Drunk guy: \"Theeeeen teeeel meeee whooo III am.\n"
				<< "Wait... YOU ARE MAKING A FOOL OF ME! DIEEEEEEEEEEEEEE!\"\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		case 'n'://no

			std::cout << "Drunk guy: \"Oh sooorry if IIII gaveeeeee youuu proooblemmmmmssssss\n"
				<< "Bye little guy.\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case 's'://Skip

			std::cout << "Drunk guy: \"Ooooh a mute guy, uh.\n"
				<< "Give me all your coins I want more wine.\"\n"
				<< "(A guard is running towards you and the drunk guy)\n";

			waitForAnyKey();

			std::cout << "Guard: \"Whats happenig here?\n"
				<< "Wait you are a little drunk! Come with me to a little cold place\"\n"
				<< "Drunk guy: \"Noooooooooooooooooooooooooooo...\"\n";

			waitForAnyKey();

			std::cout << "Guard: \"Did he took anything from you?\"\n"
				<< "y: Yes, he took something!\n"
				<< "n: No, he didn't take anything.\n"
				<< "s: (Stay silent)\n";

			do
			{

				switch (Input::character())
				{
				case 'y'://yes

					std::cout << "Drunk guy: \"He is lying I was about to take all his coins "
						<< "but you came!\"\n"
						<< "Guard: \"It look like he is telling the truth...\n"
						<< "Well go where you want I don't mind. But you Drunk guy...\"\n"
						<< "(The guard goes with the drunk guy away leaving you alone)\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'n'://no

					std::cout << "Guard: \"Well then my work it to take him to prison.\n"
						<< "You can go where the laws says you can go.\n"
						<< "Bye little one.\"\n"
						<< "(The guard goes away with the drunk guy)\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 's'://Skip

					std::cout << "Guard: \"I'll take that as a no.\n" <<
						"Bye little one. He will come with me.\"\n" <<
						"(The guard and the drunk guy go away leaving you behind)\n";
					answerAgain = false;
					encounter().setIsGone(true);
					break;

				default:

					printNotPossible();
					answerAgain = false;

					break;

				}

			} while (answerAgain == true);

			break;

		default:
			answerAgain = true;
			break;
		}

	} while (answerAgain == true);


	encounter().setCanTalk(false);

}



void tizioUbriaco()
{

	char answer{ 0 };


	bool answerAgain{ false };



	std::cout << "(il tizio sta cantando)\n"
		<< "Tizio Ubriaco: \"Soonooo quaaalcunooo eeee iiooo noooon ricoordoooo\n"
		<< "iiiil miiiooo nooomeee\n" << "(Ti vede e viene verso di te)\n"
		<< "Seeembriiii faaamiiliiaareee. Tiii conooscoooo?\"\n";

	answer = Input::character();
	do
	{

		switch (answer)
		{
		case 'y'://yes

			std::cout << "Tizio Ubriaco: \"Aallooooraaaa diimmiiii chii soonooo...\n"
				<< "Aspetta... MI STAI PRENDENDO IN GIRO! MUORIIIIIIIIII!!!\"\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		case 'n'://no

			std::cout << "Tizio Ubriaco: \"Oh scuuusaa se tii hoo datooo problemiii.\n"
				<< "Ciao piccoletto.\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case 'w'://Skip

			std::cout << "Tizio Ubriaco: \"Ooooh un tizio muto, uh.\n"
				<< "Dammi tutte le tue monete, voglio altro vino.\"\n"
				<< "(Una guardi sta correndo verso te e il tizio ubriaco)\n"
				<< "Guardia: \"Che sta succedendo qui?\n"
				<< "Aspetta, tu sei un po' ubriaco! Vieni con me in un piccolo posto freddo.\"\n"
				<< "Tizio Ubriaco: \"Noooooooooooooooooooooooooooo...\"\n"
				<< "Guardia: \"Ti ha preso qualcosa?\"\n";

			answer = Input::character();
			do
			{

				switch (answer)
				{
				case 'y'://yes

					std::cout << "Tizio Ubriaco: \"Sta mentendo, stavo per prendergli tutte le sue monete "
						<< "ma sei arrivato tu!\"\n"
						<< "Guardia: \"Sembra che stia dicendo la verita'...\n"
						<< "Vabbe', vai dove vuoi, non mi interessa. Ma te tizio ubriaco...\"\n"
						<< "(La guardia se ne va' col tizio ubriaco lasciandoti da solo.)\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'n'://no

					std::cout << "Guardia: \"Bene, quindi il mio lavoro e' portarlo in prigione.\n"
						<< "Puoi andare dove la legge vuole che tu vada.\n"
						<< "Ciao piccoletto.\"\n"
						<< "(La guardia se ne va con il tizio ubriaco)\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'w'://Skip

					std::cout << "Guardia: \"Lo prendero' come un no.\n" <<
						"Ciao piccoletto. Lui verra' con me.\"\n" <<
						"(La guardia e il tizio ubriaco se ne vannno lasciandoti indietro)\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				default:

					std::cout << "(Non possibile)\n";
					answerAgain = false;

					break;

				}

			} while (answerAgain == true);

			break;

		default:
			answerAgain = true;
			break;
		}

	} while (answerAgain == true);
	

	encounter().setCanTalk(false);

}