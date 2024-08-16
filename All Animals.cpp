
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Encounterz.h"



void allAnimals()
{

	char answer{ 0 };


	bool answerAgain{ false };


	std::cout << "Nanre: \"Do you have the ability to talk and understand animals?\"\n"
		<< "y: I do have that!\n"
		<< "n: I don't have that amount of knowledge\n"
		<< "1: What ability?\n";

	do
	{
		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes

			std::cout << "Nanre: \"At least you tried. But no, you don't have that ability.\n"
				<< "So good luck surviving.\"\n";
			answerAgain = false;

			break;

		case 'n'://no

			std::cout << "Nanre: \"I'm so proud of you. You're right. You don't have that.\n"
				<< "Now go and die with honour. Good luck.\"\n";
			answerAgain = false;

			break;

		case '1'://next

			std::cout << "Nanre: \"Didn't I told ya you don't have that ability? Oh well. Now you "
				<< "know.\nNow go and die with honour\"\n";
			answerAgain = false;

			break;

		default:

			std::cout << "(Not possible)\n";
			answerAgain = true;

			break;
		}

	} while (answerAgain);


	encounter().setCanTalk(false);
	encounter().setIsUnderAttack(true);

}



void tuttiGliAnimali()
{

	char answer{ 0 };


	bool answerAgain{ false };


	std::cout << "Nanre: \"Hai l'abilita' di parlare e capire gli animali?\"\n";

	do
	{
		answer = Input::character();
		switch (answer)
		{
		case 'y'://yes

			std::cout << "Nanre: \"Almeno ci hai provato. Ma no, non hai quell'abilita'.\n"
				<< "Quindi buona fortuna a sopravvivere.\"\n";
			answerAgain = false;

			break;

		case 'n'://no

			std::cout << "Nanre: \"Sono così fiero di te. Hai ragione. Non la hai.\n"
				<< "Ora vai e muori con onore. Buona fortuna.\"\n";
			answerAgain = false;

			break;

		case 'w'://next

			std::cout << "Nanre: \"Non ti avevo detto che no hai quell'abilita'? Oh beh. Ora lo ."
				<< "sai.\nOra vai e muori con onore.\"\n";
			answerAgain = false;

			break;

		default:

			std::cout << "(Non possibile)\n";
			answerAgain = true;

			break;
		}

	} while (answerAgain);


	encounter().setIsUnderAttack(true);
	encounter().setCanTalk(false);

}


void rats(Creatures::Encounter::Encounterz* rat)
{
	std::cout << "Nanre: \"You do not have the skill: Animal language\"\n"
		<< "Go, fight and die with honour!\"\n";
	rat->takeDamage(0);
	std::cout << "Nanre: \"Look! He's now angry!\"\n";
}