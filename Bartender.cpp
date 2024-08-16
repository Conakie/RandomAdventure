
#include <iostream>
#include "Bartender.h"
#include "Talk To Encounters English.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"



void bartender()
{

	bool answerAgain{ false };


    std::cout << "Bartender: \"Need something? If not, go away.\"\n"
        << "1: I would like a room please.\n"
        << "2: I would like something to eat.\n"
        << "3: I have some questions.\n";
	do
	{

		switch (Input::character())
		{
		case '1':// option 1: I would like a room please.

			roomPlease();
			answerAgain = false;

			break;

		case '2':// option 2: I would like something to eat.

			foodPlease();
			answerAgain = false;

			break;

		case '3':// option 3: I have some questions.

			questions();
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);


	encounter().setIsGone(true);
	encounter().setCanTalk(false);

}



void roomPlease()
{

	bool answerAgain{ false };


	std::cout << "Bartender: \"We do have some at different prices. Choose one from the list.\"\n"
		<< "(You look at the list. The prices are for 1 night)\n"
		<< "1: Stable: 20 cota. (+0 stamina)\n"
		<< "2: Single small room: 40 cota. (+0 stamina)\n"
		<< "3: Multiple small rooms: 60 cota. (+0 stamina)\n"
		<< "4: Single big room: 80 cota. (+0 stamina)\n"
		<< "5: Multiple big rooms: 100 cota. (+0 stamina)\n"
		<< "6: go back to the bartender.\n\n"
		<< "Additional services:\n"
		<< "Bathroom: 5 cota per use.\n"
		<< "Room service: 15 cota per call.\n\n";

	do
	{

		switch (Input::character())
		{
		case '1':// option 1: 

			player().setInventory().useItem(ObjectUid::cota, 0);
			//player().rest(10);
			answerAgain = false;

			break;

		case '2':// option 2: 

			player().setInventory().useItem(ObjectUid::cota, 0);
			//player().rest(10);
			answerAgain = false;

			break;

		case '3':// option 3: 

			player().setInventory().useItem(ObjectUid::cota, 0);
			//player().rest(10);
			answerAgain = false;

			break;

		case '4':// option 4: 

			player().setInventory().useItem(ObjectUid::cota, 0);
			//player().rest(10);
			answerAgain = false;

			break;

		case '5':// option 5: 

			player().setInventory().useItem(ObjectUid::cota, 0);
			//player().rest(10);
			answerAgain = false;

			break;

		case '6':// option 6: 

			std::cout << "(You don't find anything interesting so you go away)\n";

			boolValueKeeper(true, true);
			encounter().setIsGone(true);

			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);

	// if the player doesn't choose a room (6 -> true) the bartender will hate the player
	if (boolValueKeeper())
	{

		std::cout << "Bartender: \"Next time I see you here, I won't let you in!\n"
			<< "Understood?!\"\n";

	}
	else
	{

		std::cout << "Bartender: \"Have a nice stay. Here's the key.\n"
			<< "(The Bartender tells you where your room is)\"\n"
			<< "(You say thanks and go to your room. The next day you go away)\n";

	}

}



void foodPlease()
{

	bool answerAgain{ false };


	std::cout << "Bartender: \"Do you want to eat it now or not?\"\n"
		<< "y: Yes, I'll eat it now.\n"
		<< "n: No, I want to take it away.\n";

	do
	{

		switch (Input::character())
		{
		case 'y':// yes

			eatAtTable();
			answerAgain = false;

			break;

		case 'n':// no

			takeAway();
			answerAgain = false;

			break;

		default:

			printNotPossible();
			answerAgain = true;

			break;
		}

	} while (answerAgain);


}



void takeAway()
{

	bool answerAgain{ false };


	std::cout << "Bartender: \"this is all the food you can take with you.\"\n"
		<< "(The bartender gives you the list)"
		<< "1: Meat: 7 cota.\n"
		<< "2: Fish: 10 cota.\n"
		<< "3: Mushyroom: 5 cota.\n"
		<< "4: Bone: free.\n"
		<< "5: The good stuff: 40 cota.\n"
		<< "UwU: Nothing.\n";

	do
	{

		switch (Input::character())
		{
		case '1':// option 1: meat

			// if the player has enough money use the money and get food
			if (!player().setInventory().useItem(ObjectUid::cota, 0))
			{
				player().setInventory().addItem(ObjectUid::meat);
			}
			else
			{
				// else then print a custom message
				std::cout << "Bartender: \"You can't even afford a steak! Ahahaha!\"\n";
			}
			answerAgain = false;

			break;

		case '2':// option 2: fish

			// if the player has enough money use the money and get food
			if (!player().setInventory().useItem(ObjectUid::cota, 0))
			{
				player().setInventory().addItem(ObjectUid::fish);
			}
			else
			{
				// else then print a custom message
				std::cout << "Bartender: \"You're too poor.\"\n";
			}
			answerAgain = false;

			break;

		case '3':// option 3: mushyroom

			// if the player has enough money use the money and get food
			if (!player().setInventory().useItem(ObjectUid::cota, 0))
			{
				player().setInventory().addItem(ObjectUid::mushroom);
			}
			else
			{
				// else then print a custom message
				std::cout << "Bartender: \"Go away Mario\"\n";
			}
			answerAgain = false;

			break;

		case '4':// option 4: bone

			// if the player has enough money use the money and get food
			if (!player().setInventory().useItem(ObjectUid::cota, 0))
			{
				player().setInventory().addItem(ObjectUid::bone);
			}
			else
			{
				// else then print a custom message
				std::cout << "Bartender: \"Your dog will have to starve for today. Sorry.\"\n";
			}
			answerAgain = false;

			break;

		case '5':// option 5: good stuff

			// if the player has enough money use the money and get food
			if (!player().setInventory().useItem(ObjectUid::cota, 0))
			{
				player().setInventory().addItem(ObjectUid::herbs);
			}
			else
			{
				// else then print a custom message
				std::cout << "Bartender: \"Don't go say I sell this stuff to the guards!\"\n";
			}
			answerAgain = false;

			break;

		default:// nothing

			std::cout << "Bartender: \"Don't show your face here again if you don't plan to "
				<< "order anything!\"\n";

			break;
		}

	} while (answerAgain);

}



void eatAtTable()
{

	bool answerAgain{ false };

	
	std::cout << "Menu."
		<< "1: Soup: 10 cota.\n"
		<< "2: Kartoffelpuffer: 8 cota.\n"
		<< "3: Hacke Peter: 20 cota.\n"
		<< "4: Apfelschorle: 3 cota.\n"
		<< "5: Spaghetti Eis: 7 cota.\n"
		<< "6: Senfkreppel: 6 cota.\n"
		<< "UwU: Nothing.\n";

	do
	{

		switch (Input::character())
		{
		case '1':// option 1: Soup

			// if the player has enough money use the money and eat the food
			if (!player().setInventory().useItem(ObjectUid::cota, 0))
			{
				std::cout << "Bartender: \"Here, enjoy your Soup.\"\n";
				player().heal(3 * player().getLvl());
			}
			else
			{
				// else then print a custom message
				std::cout << "Bartender: \"I souppose you are poor. GO AWAY!\"\n";
			}
			answerAgain = false;

			break;

		case '2':// option 2: Kartoffelpuffer

			// if the player has enough money use the money and eat the food
			if (!player().setInventory().useItem(ObjectUid::cota, 0))
			{
				std::cout << "Bartender: \"Here, enjoy your Kartoffelpuffer.\"\n";
				player().heal(69 * player().getLvl());
			}
			else
			{
				// else then print a custom message
				std::cout << "Bartender: \"Bow down and pray that I don't take your soul.\"\n";
			}
			answerAgain = false;

			break;

		case '3':// option 3: Hacke Peter

			// if the player has enough money use the money and eat the food
			if (!player().setInventory().useItem(ObjectUid::cota, 0))
			{
				std::cout << "Bartender: \"Here, enjoy your Hacke Peter.\"\n";
				player().heal(4 * player().getLvl());
			}
			else
			{
				// else then print a custom message
				std::cout << "Bartender: \"Useless. Worthless.\"\n";
			}
			answerAgain = false;

			break;

		case '4':// option 4: Apfelschorle

			// if the player has enough money use the money and eat the food
			if (!player().setInventory().useItem(ObjectUid::cota, 0))
			{
				std::cout << "Bartender: \"Here, enjoy your Apfelschorle.\"\n";
				player().heal(1 * player().getLvl());
			}
			else
			{
				// else then print a custom message
				std::cout << "Bartender: \"Ahahaha! You don't have the money to drink!\"\n";
			}
			answerAgain = false;

			break;

		case '5':// option 5: Spaghetti Eis

			// if the player has enough money use the money and eat the food
			if (!player().setInventory().useItem(ObjectUid::cota, 0))
			{
				std::cout << "Bartender: \"Here, enjoy your Spaghetti Eis.\"\n";
				player().heal(104 * player().getLvl());
			}
			else
			{
				// else then print a custom message
				std::cout << "Bartender: \"Are you joking? Can't even afford a meal?\"\n";
			}
			answerAgain = false;

			break;

		case '6':// option 6: Senfkreppel

			// if the player has enough money use the money and eat the food
			if (!player().setInventory().useItem(ObjectUid::cota, 0))
			{
				std::cout << "Bartender: \"Here, enjoy your Senfkreppel.\"\n";
				player().heal(289 * player().getLvl());
			}
			else
			{
				// else then print a custom message
				std::cout << "Bartender: \"Go way you worthless human.\"\n";
			}
			answerAgain = false;

			break;

		default:

			std::cout << "Bartender: \"Don't come here again!\"\n";
			answerAgain = false;

			break;
		}

	} while (answerAgain);


}



void questions()
{

	bool answerAgain{ false };


	std::cout << "Bartender: \"Tell me waht you wanna know.\"\n";

	do
	{
		std::cout << "(Questions)\n"
			<< "1: Have you seen Eyil?\n"
			<< "2: Is there a way to kill Nanre?\n"
			<< "3: Know any good 'hotel'? If you know what I mean.\n"
			<< "4: Where can I buy an enchanted sword?\n"
			<< "5: Do you have a free room?\n"
			<< "6: Can I order something to eat?\n"
			<< "7: Do you wanna see it?\n"
			<< "UwU: Nothing else, my darling~\n";

		switch (Input::character())
		{
		case '1':// option 1: Have you seen Eyil?

			std::cout << "Bartender: \"That girl is everywhere, who knows where she is right "
				<< "now.\nTry going to heaven. Sometimes she's there.\n"
				<< "Bartender: \"Want to know something else?\"\n";
			answerAgain = true;

			break;

		case '2':// option 2: Is there a way to kill Nanre?

			std::cout << "Bartender: \"Who?\"\n";
			answerAgain = true;

			break;

		case '3':// option 3: Know any good 'hotel'? If you know what I mean.

			std::cout << "Bartender: \"Why y'all want THAT kind of hotel?\n"
				<< "Anyway, you can find as many as you want if you go 6 feet under.\n"
				<< "Anything else?\"\n";
			answerAgain = true;

			break;

		case '4':// option 4: Where can I buy an enchanted sword?

			std::cout << "Bartender: \"Lemme think a sec...\"\n";
			
			waitForAnyKey();

			std::cout << "Bartender: \"In your dreams\"\n";
			answerAgain = false;

			break;

		case '5':// option 5: Do you have a free room?

			roomPlease();
			answerAgain = false;

			break;

		case '6':// option 6: Can I order something to eat?

			foodPlease();
			answerAgain = false;

			break;

		case '7':// option 7: Do you wanna see it?

			std::cout << "Bartender: \"See what?\"\n"
				<< player().getName() << ": \"My cock\"\n"
				<< "Bartender: \"Not interested. It's too small to be seen.\"\n";
			answerAgain = false;

			break;

		default:// end: Nothing else, my darling~

			std::cout << "Bartender: \"Kill yourself.\"\n";
			answerAgain = false;

			break;
		}

	} while (answerAgain);


}

void Creatures::Encounter::Bartender::talk()
{
	if (m_canTalk && !(m_isUnderAttack))
	{
		talkToEncounters(encounterType);
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

void Creatures::Encounter::Bartender::thinkAndAct()
{
	if (m_player)
	{
		if (isAlive() && !m_isUnderAttack && m_canTalk)
		{
			talk();
		}
		else if (m_isUnderAttack)
		{
			m_isGone = true;
		}
		else
		{
			std::cout << "Kelmod: \"Do something man. I'm bored.\"\n";
		}
	}
	else
	{
		std::cout << "The bartender ignores you.\n";
		m_isGone = true;
	}
}

void Creatures::Encounter::Bartender::setName()
{
	name = "Bartenderererer";
}

void Creatures::Encounter::Bartender::setStats()
{
	maxHp = 10 + (10 * (lvl - 1));
	maxAtk = 1 + (1 * lvl);
	maxDef = -60;
	critRate = 0;
	critDmg = 0;
	xp = 1;

	hp = maxHp;
	atk = maxAtk;
	def = maxDef;
}
