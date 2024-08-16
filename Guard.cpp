
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Guard.h"
#include "Random.h"



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



void Creatures::Encounter::Guard::talk()
{
	if (m_canTalk && !(m_isUnderAttack))
	{
		dialogue();
	}
	else
	{
		if (m_isUnderAttack)
		{
			std::cout << "Kelmod: \"" << name << " refuses to talk after you attacked it.\"\n";
		}
		else
		{
			std::cout << "Kelmod: \"You have already talked to him.\n";
		}
	}
}

void Creatures::Encounter::Guard::thinkAndAct()
{
	if (isAlive())
	{
		if (m_isUnderAttack)
		{
			if (hp < maxHp - (maxHp * 0.3) && (healAmount != 0))
				heal(Random::get(1, 3 * lvl));
			else
				attack(*m_player);
		}
		else
		{
			std::cout << "Kelmod: \"Do something. Look, he's waiting.\"\n";
		}
	}
	else
	{

	}
}

void Creatures::Encounter::Guard::printStats() const
{
	Encounterz::printStats();
	std::cout << name << " can heal himself " << healAmount << " times.\n";
}

void Creatures::Encounter::Guard::resetStats()
{
	Encounterz::resetStats();
	healAmount = 1;
}

void Creatures::Encounter::Guard::setName()
{
	name = "Guard";
}

void Creatures::Encounter::Guard::setStats()
{
	maxHp = 10 + (7 * (lvl - 1));
	maxAtk = 2.5 + (1.5 * lvl);
	maxDef = 5;
	critRate = 0;
	critDmg = 0;
	xp = 1;
	healAmount = 1;

	hp = maxHp;
	atk = maxAtk;
	def = maxDef;
}

void Creatures::Encounter::Guard::dialogue()
{
	bool answerAgain{ false };


	std::cout << name << ": \"Good morning sir, may I check the content of you backpack?\n"
		<< "I'm looking for a thief who stole 10 kilos of dinamyte.\n"
		<< "So, can I check your backpack?\"\n";
	do
	{
		std::cout << "1: Yes, here's my backpack.\n"
			<< "2: No, I won't let you see what's inside.\n"
			<< "3: You'll have to kill me to see its content.\n"
			<< "4: Look! (Try to run away)\n";
		switch (Input::character())
		{
		case '1':// option 1: Yes, here's my backpack.
			std::cout << name << ": \"Sorry for taking your time. You can go.\n"
				<< "Here's your backpack. Have a good day.\"\n";
			m_isGone = true;
			answerAgain = false;
			break;

		case '2':// option 2: No, I won't let you see what's inside.
			dialogueRefuse();
			answerAgain = false;
			break;

		case '3':// option 3: You'll have to kill me to see its content.
			std::cout << name << ": \"Don't go back to your daddy crying when I'll beat you!\"\n";
			m_isUnderAttack = true;
			answerAgain = false;
			break;

		case '4':// option 4: Look! (Try to run away)
			dialogueRunAway();
			answerAgain = false;
			break;

		default:
			printNotPossible();
			answerAgain = true;
			break;
		}
	} while (answerAgain);
	
	waitForAnyKey();
	m_canTalk = false;
}

void Creatures::Encounter::Guard::dialogueRefuse()
{
	bool answerAgain{ false };


	std::cout << name << "\"Look, I'll let you go. But, if you do anything against the law,\n"
		<< "I won't let you go away that easily.\"\n";
	do
	{
		std::cout << "1: Understood. Thanks!\n"
			<< "2: Yeah yeah, whatever.\n"
			<< "3: Yes daddy!\n";
		switch (Input::character())
		{
		case '1':// option 1: Understood. Thanks!
			std::cout << name << ": \"Everyone has something they want to hide.\n"
				<< "And you too. but you don't look like a bad person.\n"
				<< "Now go! Enjoy your life while you still can.\"\n";
			m_isGone = true;
			answerAgain = false;
			break;

		case '2':// option 2: Yeah yeah, whatever.
			std::cout << name << ": \"You know, I should teach you a lesson...\n"
				<< "Come here, let's see if MY lesson will make you reason.\"\n";
			m_isUnderAttack = true;
			answerAgain = false;
			break;

		case '3':// option 3: Yes daddy!
			std::cout << name << ": \"Go before I change my mind.\"\n"
				<< "(The guard goes away with a disappointed face)\n";
			m_isGone = true;
			answerAgain = false;
			break;

		default:
			printNotPossible();
			answerAgain = true;
			break;
		}
	} while (answerAgain);
}

void Creatures::Encounter::Guard::dialogueRunAway()
{
	bool answerAgain{ false };
	bool failedToEscape{ false };


	std::cout << name << ": \"Come here!\"\n";
	if (Random::get(0, 99) < 49)
	{
		std::cout << "(The guard catches up to you)"
			<< name << ": \"Where do you think of going?!\n"
			<< "Let me teach you a lesson, youngster.\"\n";
		m_isUnderAttack = true;
	}
	else
	{
		std::cout << "(You ran so fast the guard lost you)\n"
			<< "You're now free to go everywhere)\n";
		m_isGone = true;
	}
}
