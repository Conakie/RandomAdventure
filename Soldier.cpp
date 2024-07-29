
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Soldier.h"
#include "Random.h"



void soldier()
{


	char answer{ 0 };


	bool answerAgain{ false };


	std::cout << "Soldier: \"It's not safe here. You should go somewhere else.\"\n"
		<< "y: Understood, I'll go.\n"
		<< "n: No, I'll stay here.\n"
		<< "s: (Stay silent and look at him)\n";

	do
	{
		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes

			std::cout << "Soldier: \"Good. Now go before something happen to you.\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case 'n'://no

			std::cout << "Soldier: \"Why don't you go? I can't save both of us.\nDon't you know "
				<< "we're in war? These guys know how to control elements better than us.\n"
				<< "We can't accept that. That's why we developed weapons that are "
				<< "better than the one they have.\n";

			waitForAnyKey();

			std::cout << "Wait... Forget what I have just said.\n"
				<< "What are you still doing here? Go away. Go.\"\n(The soldier pushes you away "
				<< "before a giant rock hits you)\n(Do you want to check if he's ok?)\n"
				<< "y: (Go and check if he's fine)\n"
				<< "n: (Go away)\n"
				<< "s: (Don't move)\n";

			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "(You see the soldier is fine. He have some scratches but he's "
						<< "fine)\nSoldier: \"See I told you to go away. So bye.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'n'://no

					std::cout << "(You leave him behind and go away)\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 's'://Skip

					std::cout << "(You don't do nothing and wait there)\n"
						<< "(After some time the soldier comes from behind the rock and sees you)"
						<< "\nSoldier: \"You're fine. See I told you that it wasn't safe here.\n";

					waitForAnyKey();

					std::cout << "I think they are waiting for some more energies. Creating rocks like "
						<< "this one takes a lot of energy.\nFor now bye. I have some work to do."
						<< "\nGo away from this place.\"\n(The soldier goes away)\n";
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

		case 's'://Skip

			std::cout << "Soldier: \"I warned you. Now go. I now have some work to do so bye.\"\n";
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

void soldato()
{


	char answer{ 0 };


	bool answerAgain{ false };


	std::cout << "Soldato: \"Non e' sicuro qua. Dovresti andartene.\"\n";

	do
	{
		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes

			std::cout << "Soldato: \"Bene. Ora vai prima che qualcosa ti accada.\"\n";
			answerAgain = false;
			encounter().setIsGone(true);

			break;

		case 'n'://no

			std::cout << "Soldato: \"Perche' non te ne vai? Non posso salvare entrambi.\nNon sai che "
				<< "siamo in guerra? Sti qua sanno controllare gli elementi meglio di noi.\n"
				<< "Non possiamo accettarlo. Ecco perche' abbiamo sviluppato armi che sono "
				<< "migliori di quelle che hanno.\nAspetta... Dimentica cio' che ti ho appena detto.\n"
				<< "Che stai facendo ancora qua? Vattene. Vai.\"\n(Il soldato ti spinge "
				<< "prima che una roccia gigante ti colpisca.)\n(Vuoi vedere se sta bene?)";

			do
			{
				answer = Input::character();
				switch (answer)
				{
				case 'y'://yes

					std::cout << "(Vedi che il soldato sta bene. Ha solo alcuni graffi ma sta "
						<< "bene)\nSoldato: \"Visto ti avevo detto di andartene. Quindi ciao.\"\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'n'://no

					std::cout << "(Lo lasci indetro e te ne vai via)\n";
					answerAgain = false;
					encounter().setIsGone(true);

					break;

				case 'w'://Skip

					std::cout << "(Non fai niente e aspetti)\n"
						<< "(Dopo un po' il soldato arriva da dietro la roccia e ti vede)"
						<< "\nSoldato: \"Stai bene. Te lo avevo detto che non era sicuro qua.\n"
						<< "Penso che ora stiano aspettando per avere piu energia. Creare roccie come "
						<< "questa richiede un bel po' di energia.\nPer ora ciao. Io ho del lavoro da fare."
						<< "\nVattene da questo posto.\"\n(Il soladto se ne va via)\n";
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

			std::cout << "Soldato: \"Ti avevo avvisato. Ora vai. Ho del lavoro da fare, ciao.\"\n";
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



void Creatures::Encounter::Soldier::talk()
{
}

void Creatures::Encounter::Soldier::thinkAndAct()
{
	
	if (isUnderAttack && isAlive() && !isGone)
	{
		if ((hp < maxHp / 2) && (lastHealHappenedInTurns >= healTurnCooldown))
		{
			heal(Random::get(1, 3 * lvl));
		}
		else
		{
			attack(*m_player);
		}
	}
	else if (isGone)
	{
		dropItems();
	}
	else
	{
		std::cout << "Kelmod: \"Still here? Do something. He's waiting.\"\n";
	}
	++lastHealHappenedInTurns;
}

void Creatures::Encounter::Soldier::printStats() const
{
	Encounterz::printStats();
	std::cout << name << " can also heal with a cooldown of " << healTurnCooldown << '\n'
		<< " turn.\n";
}

void Creatures::Encounter::Soldier::resetStats()
{
	Encounterz::resetStats();
	healTurnCooldown = 1;
	lastHealHappenedInTurns = 0;
}

void Creatures::Encounter::Soldier::setName()
{
	name = "Soldier";
}

void Creatures::Encounter::Soldier::setStats()
{
	maxHp = 12 + (10 * (lvl - 1));
	maxAtk = 2.5 + (2.5 * lvl);
	maxDef = 5;
	critRate = 0;
	critDmg = 0;
	xp = 1;
	healTurnCooldown = 1;
	lastHealHappenedInTurns = 0;

	hp = maxHp;
	atk = maxAtk;
	def = maxDef;
}
