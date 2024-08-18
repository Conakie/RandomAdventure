
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Goblin.h"



void goblin()
{
	bool answerAgain{ false };

	
	std::cout << "(The goblin looks at you)\n"
		<< "y: Yes.\n"
		<< "n: No, please no.\n"
		<< "s: (Intense stare)\n"
		<< "a: Die, goblin!\n"
		<< "t: Let's talk!\n";

	do
	{
		
		switch (Input::character())
		{
		case 'y'://yes

			std::cout << "\nGoblin: \"What yes? Is it for your death? I think so. DIE!\"\n";
			encounter().setIsUnderAttack(true);
			answerAgain = false;

			break;

		case 'n'://no

			std::cout << "Goblin: \"Too scared of me? That's new. You're scared of me.\"\n"
				<< "(The goblin start laughing at you)\n(What do you do?)\n"
				<< "y: Yes, and what is the problem with that?\n"
				<< "n: Who is scared of you?\n"
				<< "s: (Stay silent)\n"
				<< "a: Do you want me to show you I'm not scared? Die.\n";

			do
			{

				if (answerAgain)
				{

					std::cout << "\n(The goblin keeps laughing)\n";

				}
				else
				{

				}

				switch (Input::character())
				{
				case 'y'://yes

					std::cout << "\nGoblin: \"You made me laugh so much that I'll let you go.\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'n'://no

					std::cout << "\nGoblin: \"Yeah yeah, I trust you. With all my leg.\n"
						<< "If you're so sure fight me.\"\n";
					answerAgain = true;

					break;

				case 's'://Skip

					std::cout << "\nGoblin: \"You're so scared that you can't even talk.\"\n";
					answerAgain = true;

					break;

				case 'a'://Attack

					std::cout << "\nGoblin: \"You do really want lo lose. Then prepare to die!\"\n";
					answerAgain = false;
					encounter().setIsUnderAttack(true);

					break;

				default:

					printNotPossible();
					answerAgain = true;

					break;
				
				
				}
				
			} while (answerAgain);
			
			
			break;

		case 's'://Skip

			std::cout << "Goblin: \"YOU ARE IGNORING ME? HOW DARE YOU IGNORE ME. DIE!\"\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		case 'a'://attack

			std::cout << "Goblin: \"Do you want to challenge me? Prepare to die here and now.\"\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		case 't'://talk

			std::cout << "Goblin: \"You want to talk to me? Why?\"\n"
				<< "(The goblin runs away and leave you there)\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}


	} while (answerAgain);


	encounter().setCanTalk(false);

}



void goblino()
{

	char answer{ 0 };


	bool answerAgain{ false };


	std::cout << "(Il goblin ti guarda)\n";

	do
	{

		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes

			std::cout << "\nGoblin: \"Cosa si?? E' per la tua morte? Penso di si. MUORI!\"\n";
			encounter().setIsUnderAttack(true);

			break;

		case 'n'://no

			std::cout << "Goblin: \"Troppo sapventato da me? Questa e' nuova. Sei spaventato di me.\"\n"
				<< "(Il goblin inizia a ridere di te)\n(Cosa fai?)\n";

			do
			{
				if (answerAgain)
				{

					std::cout << "\n(Il goblin continua a ridere di te)\n";

				}
				else
				{

				}

				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "Goblin: \"Mi hai fatto ridere cosi' tanto che ti lascio andare.\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'n'://no

					std::cout << "\nGoblin: \"Si si, mi fido di te. Con tutta la mia gamba.\n"
						<< "Se ne sei cosi' sicuro battimi.\"\n";
					answerAgain = true;

					break;

				case 'w'://Skip

					std::cout << "\nGoblin: \"Sei cosi' spaventato che non riesci neanche a parlare.\"\n";
					answerAgain = true;

					break;

				case 'a'://Attack

					std::cout << "\nGoblin: \"Vuoi veramente perdere. Preparati a morire.\"\n";
					answerAgain = false;
					encounter().setIsUnderAttack(true);

					break;

				default:

					std::cout << "(Non possibile)\n";
					answerAgain = true;

					break;


				}

			} while (answerAgain == true);


			break;

		case 'w'://Skip

			std::cout << "Goblin: \"MI STAI IGNORANDO? COME OSI IGNORARMI. MUORI!\"\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		case 'a'://attack

			std::cout << "Goblin: \"Mi vuoi sfidare? Preparati a morire qui e ora.\"\n";
			answerAgain = false;
			encounter().setIsUnderAttack(true);

			break;

		case 't'://talk

			std::cout << "Goblin: \"Mi vuoi parlare? Perche'?\"\n"
				<< "(Il goblin fugge e ti lascia li')\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		default:

			std::cout << "(Not possibile)\n";
			answerAgain = true;

			break;
		}


	} while (answerAgain == true);


	encounter().setCanTalk(false);

}



void Creatures::Encounter::Goblin::talk()
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

void Creatures::Encounter::Goblin::setName()
{
	name = "Goblin";
}

void Creatures::Encounter::Goblin::setStats()
{
	maxHp = 6.5 + (4 * (lvl - 1));
	maxAtk = 1 + (1 * lvl);
	maxDef = 0;
	critRate = 0;
	critDmg = 0;
	xp = 1;

	hp = maxHp;
	atk = maxAtk;
	def = maxDef;
}

void Creatures::Encounter::Goblin::dialogue()
{
	bool answerAgain{ false };


	
	std::cout << "(The goblin looks at you)\n";
		
	do
	{
		std::cout << "1: Yes.\n"
			<< "2: No, please no.\n"
			<< "3: (Intense stare)\n"
			<< "4: Die, goblin!\n"
			<< "5: Let's talk!\n";
		switch (Input::character())
		{
		case '1':// option y: Yes.
			std::cout << "\nGoblin: \"What yes? Is it for your death? I think so. DIE!\"\n";
			m_isUnderAttack = true;
			answerAgain = false;
			break;

		case '2':// option n: No, please no.
			dialogueScared();
			answerAgain = false;
			break;

		case '3':// option s: (Intense stare)
			std::cout << "Goblin: \"YOU ARE IGNORING ME? HOW DARE YOU IGNORE ME. DIE!\"\n";
			m_isUnderAttack = true;
			answerAgain = false;
			break;

		case '4':// option a: Die, goblin!
			std::cout << "Goblin: \"Do you want to challenge me? Prepare to die here and now.\"\n";
			m_isUnderAttack = true;
			answerAgain = false;
			break;

		case '5':// option t: Let's talk!
			std::cout << "Goblin: \"You want to talk to me? Why?\"\n"
				<< "(The goblin runs away and leave you there)\n";
			m_isGone = true;
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

void Creatures::Encounter::Goblin::dialogueScared()
{
	bool answerAgain{ false };


	std::cout << "Goblin: \"Too scared of me? That's new. You're scared of me.\"\n"
		<< "(The goblin start laughing at you)\n(What do you do?)\n";
				
	do
	{
		if (answerAgain)
			std::cout << "(The goblin keeps laughing)\n";

		std::cout << "y: Yes, and what is the problem with that?\n"
			<< "n: Who is scared of you?\n"
			<< "s: (Stay silent)\n"
			<< "a: Do you want me to show you I'm not scared? Die.\n";
		switch (Input::character())
		{
		case 'y':// option 1: Yes, and what is the problem with that?
			std::cout << "\nGoblin: \"This was so fun! Come on, go! Or I'm gonna do something.\n"
				<< "(You go away)\n";
			m_isGone = true;
			answerAgain = false;
			break;

		case 'n':// option 2: Who is scared of you?
			std::cout << "\nGoblin: \"Yeah yeah, I trust you. With all my leg.\n"
				<< "If you're so sure fight me.\"\n";
			answerAgain = true;
			break;

		case 's':// option 3: (Stay silent)
			std::cout << "\nGoblin: \"You're so scared that you can't even talk.\"\n";
			answerAgain = true;
			break;

		case 'a':// option 4: Do you want me to show you I'm not scared? Die.
			std::cout << "\nGoblin: \"You do really want lo lose. Then prepare to die!\"\n";
			m_isUnderAttack = true;
			answerAgain = false;
			break;

		default:
			printNotPossible();
			answerAgain = true;
			break;
		}
	} while (answerAgain);
}
