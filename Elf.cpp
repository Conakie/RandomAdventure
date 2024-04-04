
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"



void elf()
{

	char answer{ 0 };


	bool answerAgain{ false };


	std::cout << "(The elf is taking some erbs)\n(Do you want to say hi?)"
		<< "y: (Go ans say hi)\n"
		<< "n: (Go away)\n"
		<< "s: (Slowly and quietly go away)\n";

	do
	{
		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes

			std::cout << "Elf: \"Finally you're here. I really wanted someone to talk to.\n"
				<< "Want to stay here for some time? I haven't seen anyone in months.";
			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "Elf: \"Thank you. I'm really happy that you want to stay.\n"
						<< "If you need something to eat I have some erbs and some rat meat.\n"
						<< "It may not be much but it's what I have.\n";

					waitForAnyKey();

					std::cout << "You may want to know why "
						<< "I'm here alone, in a dungeon and in the dark.\nWell it's a long "
						<< "story but in not many words I was living my own life when for some "
						<< "unknown\nreasons my people exiled me.\n";

					waitForAnyKey();

					std::cout << "If I rememmber correctly it "
						<< "because my skills with the sword was too powerful and they exiled me\n"
						<< "was thinking I could kill 'em all.\nAfter that I came here so they"
						<< " won't find me and who knows what will happen if they find me.\n";

					waitForAnyKey();

					std::cout << "Sorry I haven't talked to someone for a lot of time.\nOne last thing "
						<< "and I'll let you go. If you find a Drow named Shakti say hi to her.\n"
						<< "Tell her that I would like to meet her again.\n";

					waitForAnyKey();

					std::cout << "She may ask for my name.\n"
						<< "Answer with Catyer.\nNow if you want to stay here you can "
						<< "stay I won't stop you.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'n'://no

					std::cout << "Elf: \"Oh well it's been an happy moment talking to you even if "
						<< "it was for not long.\nGood luck in your adventure, maybe I'll see you"
						<< " again in the future.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'w'://Skip

					std::cout << "Elf: \"I have a bad look I know but I've been here for...\nI "
						<< "don't even remember when I came here for the first time.\n"
						<< "Since you don't want to stay here with me I won't stop you.\nBye.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'a':

					std::cout << "Elf: \"Do you really want to kill the ex sword master of the "
						<< "elves? Well, good luck surviving to this.\"\n";
					answerAgain = false;
					encounter().setIsUnderAttack(true);

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

			std::cout << "Elf: \"I heard you 10 minutes ago finally you came here.\"\n"
				<< "Go away. I know you don't like elves like me but please at least say hi.\n"
				<< "Anyway since you want to go away from me bye.\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case 's'://Skip

			std::cout << "Elf: \"I heard you. How are you doing? It's been ages since I "
				<< "last talked to somone.\nNeed some healing? I know a cleric that lives nearby."
				<< "\nOh you're fine? Good I'm happy to hear that.\n";

			waitForAnyKey();

			std::cout << "Sorry I'm talking too much I "
				<< "know, but I was here alone and the last one I talked was Shakti.\n"
				<< "I miss her so much. She was the only one that understood my objective.\n";

			waitForAnyKey();

			std::cout << "If you find her please tell her to find me here. Please?\n"
				<< "Sorry I talk too much. I'll let you go. Bye.\"\n";
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



void elfo()
{

	char answer{ 0 };


	bool answerAgain{ false };


	std::cout << "(L'elfo sta prendendo alcune erbe)\n(Vuoi andare a dire ciao?)";

	do
	{
		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes

			std::cout << "Elfo: \"Finalmente sei qui. Volevo qualcuno con cui parlare.\n"
				<< "Vuoi stare qui per un po' di tempo? Non vedo qualcuno da mesi.";

			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "Elfo: \"grazie. Sono veramente felice che tu vuoi stare.\n"
						<< "Se ti serve qualcosa da mangiare ho alcune erbe e carne di ratto.\n"
						<< "Non sara' molto ma e' quel che ho.\nPotresti voler sapere perche' "
						<< "Sono qui da solo, in un dungeon e al buio.\nBeh e' una lunga storia "
						<< "ma in non molte parole stavo vivendo la mia vita quando per qualche "
						<< "sconosciuta\nragione mi hanno esiliato.\nSe non sbaglio "
						<< "perche' le mie abilita' con la spada erano cosi' potenti che mi hanno cacciato\n"
						<< " pensando che li avrei fatti fuori.\nDopo quello sono andato qua cosi' "
						<< "non mi troveranno e chi sa cosa accadrebbe se mi trovssero.\n"
						<< "Sorry I haven't talked to someone for a lot of time.\nOne last thing " //	<--
						<< "and I'll let you go. If you find a Drow named Shakti say hi to her.\n"
						<< "Tell her that I would like to meet her again.\nShe may ask for my "
						<< "name.\n Answer with Catyer.\nNow if you want to stay here you can "
						<< "stay I won't stop you.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'n'://no

					std::cout << "Elfo: \"Oh well it's been an happy moment talking to you even if "
						<< "it was for not long.\nGood luck in your adventure, maybe I'll see you"
						<< " again in the future.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'w'://Skip

					std::cout << "Elfo: \"I have a bad look I know but I've been here for...\nI "
						<< "don't even remember when I came here for the first time.\n"
						<< "Since you don't want to stay here with me I won't stop you.\nBye.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'a':

					std::cout << "Elfo: \"Do you really want to kill the ex sword master of the "
						<< "elves? Well, good luck surviving to this.\"\n";
					answerAgain = false;
					encounter().setIsUnderAttack(true);

					break;

				default:

					std::cout << "(Not possible)\n";
					answerAgain = true;

					break;
				}

			} while (answerAgain == true);

			answerAgain = false;

			break;

		case 'n'://no

			std::cout << "Elfo: \"I heard you 10 minutes ago finally you came here.\"\n"
				<< "Go away. I know you don't like elves like me but please at least say hi.\n"
				<< "Anyway since you want to go away from me bye.\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case 'w'://Skip

			std::cout << "Elfo: \"I heard you. How are you doing? It's been ages since I "
				<< "last talked to somone.\nNeed some healing? I know a cleric that lives nearby."
				<< "\nOh you're fine? Good I'm happy to hear that.\nSorry I'm talking too much I "
				<< "know, but I was here alone and the last one I talked was Shakti.\n"
				<< "I miss her so much. She was the only one that understood my objective.\n"
				<< "If you find her please tell her to find me here. Please?\n"
				<< "Sorry I talk too much. I'll let you go. Bye.\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		default:

			std::cout << "(Not possible)\n";
			answerAgain = true;

			break;
		}

	} while (answerAgain == true);


	encounter().setCanTalk(false);

}