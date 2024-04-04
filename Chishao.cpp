
#include <iostream>
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Talk To Encounters English.h"
#include "Chishao.h"
#include "Input.h"
#include "Stats.h"



void chishao()
{

	std::cout << "Chishao: \"Hello. Please, stay away from me, I don't wanna die now.\n"
		<< "I'm too young to die!\"\n"
		<< "(After saying that she disappeared)\n";

	waitForAnyKey();

	std::cout << "(You now go somewhere else since you don't have anything to do now)\n";

	encounter().setIsGone(true);
	encounter().setCanTalk(false);

}