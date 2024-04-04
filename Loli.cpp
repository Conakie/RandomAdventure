
#include <iostream>
#include "Talk To Encounters English.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"



void loli()
{
	// increase every time the player talks to the loli
    static short annoyLevel{ 0 };


	switch (annoyLevel)
	{
	case 0:
		std::cout << "Loli: \"Don't talk to me.\"\n";
		break;
	case 1:
		std::cout << "Loli: \"Why do you keep talking to me.\"\n";
		break;
	case 2:
		std::cout << "Loli: \"Stop! I said STOP talking to me!\"\n";
		break;
	case 3:
		std::cout << "Loli: \"Go away. I don't like you!\"\n";
		break;
	case 4:
		std::cout << "Loli: \"Fine here take this and go away!\"\n"
			<< "(The loli gives you 8 nukes)\n";
		player().setInventory().addItem(ObjectUid::nuke, 8);
		break;
	case 5:
		std::cout << "Loli: \"Talk to me again and I'll kill myself!\"\n";
		break;
	default:
		std::cout << "Loli: \"Fine. Don't come here again.\"\n"
			<< "(The loli goes away)\n";
		annoyLevel = -1;
		encounter().setIsGone(true);
		break;
	}


	++annoyLevel;

}