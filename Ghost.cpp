
#include <iostream>
#include "Talk To Encounters English.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Random.h"
#include "Print Errors.h"



void ghost()
{

	switch (Random::get(0, 6))
	{
	case 0:
		std::cout << "Ghost: \"Boo!\"\n";
		break;
	case 1:
		std::cout << "Ghost: \"I see you~\"\n";
		break;
	case 2:
		std::cout << "Ghost: \"I can hear you~\"\n";
		break;
	case 3:
		std::cout << "Ghost: \"Where are you~?\"\n";
		break;
	case 4:
		std::cout << "Ghost: \"What are you doing, step-bro~\"\n";
		break;
	case 5:
		std::cout << "Ghost: \"Help me, I'm stuck onii-chan~\"\n";
		break;
	case 6:
		std::cout << "Ghost: \"8===>\"\n";
		break;

	default:
		PrintError::wrongRandomNumber();
		break;
	}

}