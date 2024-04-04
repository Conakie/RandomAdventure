
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"



//dialogues for the guard (or Erelio if you rember his name)
void guard()
{

	char answer{ 0 };


	bool answerAgain{ false };



	std::cout << "Guard: \"Let me check your inventory. There are many thiefs these days.\"\n"
		<< "(Do you want to try to escape?)\n"
		<< "y: (Run away)\n"
		<< "n: (Stay there)\n"
		<< "i: Check inventory)\n"
		<< "s: (Stay silent)\n"
		<< "a: You won't get out of here alive. Dieee!\n";

	answer = Input::character();
	do
	{

		switch (answer)
		{
		case 'y':

			std::cout << "Guard: \"Don't try to escape. Try not to die.\"\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		case 'n'://no
			std::cout << "Guard: \"Good It looks like you don't have anything stolen on you.\n"
				<< "If you need anything find me. I'll help you if I can.\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case '4'://check inventory
			std::cout << "Guard: \"What are you doing?\nThinkin' of removing stolen objects so i don't see 'em?"
				<< "Prepare to die!\"\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		case 's'://next
			std::cout << "Guard: \"Why so silent? Anyway go where you want. There are no stolen\n"
				<< "objects on you. If you need help find me and if I can I'll help you.\n"
				<< "My name is Erelio. Remember it, and when you call me I'll be there.\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case 'a'://attack
			std::cout << "Guard: \"Wanna die? Ok, then... DIE!\"\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		default://again, why user whyyyyyyyyyy?
			
			printNotPossible();
			answerAgain = true;

			break;

		}

	} while (answerAgain == true);


	encounter().setCanTalk(false);

}



void guardia()
{

	char answer{ 0 };


	bool answerAgain{ false };



	std::cout << "Guardia: \"Fammi controllare il tuo inventario. Ci sono molti ladri in questi giorni.\"\n"
		<< "(Vuoi provare a fuggire?)\n";

	answer = Input::character();
	do
	{

		switch (answer)
		{
		case 'y':

			std::cout << "Guardia: \"Non provare a fuggire. Prova a non morire.\"\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		case 'n'://no
			std::cout << "Guardia: \"Bene. Sembra che non hai nulla di rubato con te.\n"
				<< "Se ti serve qualcosa cercami. Ti aiutero' se posso.\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case '4'://check inventory
			std::cout << "Guardia: \"Cosa pensi di fare?\nPensi di rimuovere gli oggetti rubati cosi' non li vedo?"
				<< "Preparati a morire!\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case 'w'://next
			std::cout << "Guardia: \"Perche' cosi' silenzioso? Comunque vai dove vuoi. Non ci sono\n"
				<< "oggetti rubati con te. Se ti serve aiuto, trovami e se posso ti aiutero'.\n"
				<< "Il mio nome e' Erelio. Ricordalo, e quando mi chiami ci saro'.\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case 'a'://attack
			std::cout << "Guardia: \"Vuoi morire? Ok, quindi...  MUORI!\"\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		default:// hi
			std::cout << "(Non possibile)\n";
			answerAgain = true;

			break;

		}

	} while (answerAgain == true);

	
	encounter().setCanTalk(false);

}