
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Elf.h"
#include "Print Errors.h"



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

void Creatures::Encounter::Elf::talk()
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

void Creatures::Encounter::Elf::thinkAndAct()
{
	if (isAlive() && m_isUnderAttack)
	{
		attack(*m_player);
	}
	else if (isAlive() && !m_isUnderAttack && m_canTalk)
	{
		talk();
	}
	else
	{
		std::cout << "Kelmod: \"Do something man. I'm bored.\"\n";
	}
}

void Creatures::Encounter::Elf::setName()
{
	name = "Elf";
}

void Creatures::Encounter::Elf::setStats()
{
	maxHp = 9 + (8 * (lvl - 1));
	maxAtk = 2 + (2 * lvl);
	maxDef = 0;
	critRate = 0;
	critDmg = 0;
	xp = 2;

	hp = maxHp;
	atk = maxAtk;
	def = maxDef;
}

void Creatures::Encounter::Elf::dialogue()
{
	bool answerAgain{ false };


	std::cout << name << ": \"You're here to kill me, aren't you?\"\n";
	do
	{
		std::cout << "1: Why would I?!\n"
			<< "2: Yes, I'm here for your head.\n"
			<< "3: No, but should I?\n";
		switch (Input::character())
		{
		case '1':// option 1: Why would I?!
			dialogueWhyWouldI();
			answerAgain = false;
			break;

		case '2':// option 2: Yes, I'm here for your head.
			dialogueKillHim();
			answerAgain = false;
			break;

		case '3':// option 3: No, but should I?
			dialogueWhyWouldI();
			answerAgain = false;
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

void Creatures::Encounter::Elf::dialogueWhyWouldI()
{
	bool answerAgain{ false };


	std::cout << name << ": \"Huh?! You aren't here for the bounty on me?\n"
				<< "I thought you were here because they didn't want me to live...\n"
				<< "So you'll let me live, right?\"\n";
	do
	{
		std::cout << "1: I don't have any reason to kill you.\n"
			<< "2: A bounty you said? Let's see how much it is.\n"
			<< "3: Do what you want. I'm just an adventurer.\n";
		switch (Input::character())
		{
		case '1':// option 1: I don't have any reason to kill you.
			std::cout << name << ": \"Really? Thank you!\n"
				<< "I'm sorry but could you hide where I am?\n"
				<< "The other elves don't want me to be free.\"\n";
			waitForAnyKey();
			std::cout << name << ": \"You see, not long ago I had to run away.\n"
				<< "They were scared of me for summoning a demon at my age.\n"
				<< "So they chose to put a bounty on my head and had me killed.\"\n";
			waitForAnyKey();
			std::cout << name << ": \"That's why I would like you to not reveal my new home to them"
				<< ".\nIf you don't want to, you're not obliged to do it.\n"
				<< "Even for letting me live, I would like to give you something.\"\n";
			waitForAnyKey();
			std::cout << name << ": \"Oh! I know, take these herbs.\n"
				<< "It may not be much but it's all I have. Please, take them.\"\n"
				<< "(The elf gives you 10 herbs)\n";
			if (m_player)
			{
				m_player->setInventory().addItem(ObjectUid::herbs, 10);
			}
			else
			{
				PrintError::playerNotFound();
			}
			answerAgain = false;
			m_isGone = false;
			break;

		case '2':// option 2: A bounty you said? Let's see how much it is.
			std::cout << name << ": \"So you want to fight, so be it.\n"
				<< "Be ready to die!\"\n";
			m_isUnderAttack = true;
			answerAgain = false;
			break;

		case '3':// option 3: Do what you want. I'm just an adventurer.
			dialogueDoWhatYouWant();
			answerAgain = false;
			break;

		default:
			printNotPossible();
			answerAgain = true;
			break;
		}
	} while (answerAgain);
}

void Creatures::Encounter::Elf::dialogueKillHim()
{
	std::cout << name << ": \"So you were here for me, huh?\n"
		<< "Then be ready to fall under my sword!\"\n";
	m_isUnderAttack = true;
}

void Creatures::Encounter::Elf::dialogueDoWhatYouWant()
{
	bool answerAgain{ false };


	std::cout << name << ": \"You're an adventurer? Really?\n"
		<< "So can I ask something of you? It's nothing important so, if you don't want\n"
		<< "I understand. But just in case, could hide where I live?\"\n";
	waitForAnyKey();
	std::cout << name << ": \"'Cause, you know, if any of the other elves finds out...\n"
		<< "Well, let's just say I will have to change country if that happened.\n"
		<< "And if possible I would like to avoid it.\"\n";
	waitForAnyKey();
	std::cout << name << ": \"Sorry if it looked selfish but I don't wanna die now.\n"
		<< "Not until I find Shaktea again. I want to see her once again before the end "
		<< "of me.\"\n";

	do
	{
		std::cout << "1: If you want, I can look for her.\n"
			<< "2: I wish you good luck, I also am looking for someone.\n"
			<< "3: My mouth is sealed.\n";
		switch (Input::character())
		{
		case '1':// option 1: If you want, I can look for her.
			std::cout << name << ": \"Wait, you will do that for me?\n"
				<< "I-I don't know how to repay you... Oh I know, take this.\n"
				<< "It may not be much but it's all I have.\"\n";
			waitForAnyKey();
			std::cout << "(+2 magic scrolls)\n"
				<< name << ": \"When you see her, tell her my name, I'm Catyer.\n"
				<< "She'll understand everything after she hears my name.\"\n";
			name = "Catyer";
			if (m_player)
			{
				m_player->setInventory().addItem(ObjectUid::magicScroll, 10);
			}
			else
			{
				PrintError::playerNotFound();
			}
			waitForAnyKey();
			std::cout << name << ": \"Anyway, you should go. Someone's coming\"\n"
				<< "(You both say goodbye to the each other and go on separate ways)\n"
				<< "(One day you shall find Shaktea)\n";
			m_isGone = true;
			answerAgain = false;
			break;

		case '2':// option 2: I wish you good luck, I also am looking for someone.
			std::cout << name << ": \"Then let's be on our way. Your friend is probably more "
				<< "important.\nI wish you good luck too. I hope you find him or her soon.\"\n"
				<< "(You say thank you and go away. He does the same)\n";
			m_isGone = true;
			answerAgain = false;
			break;

		case '3':// option 3: My mouth is sealed.
			std::cout << name << ": \"You have my gratitude. If you did't say that I don't know "
				<< "what could have happened.\n"
				<< "Well then, I'll be on my way, goodbye.\"\n"
				<< "(The elf goes away. You're now alone)\n";
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
