
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"



void noTalking()
{

	std::cout << "Nanre: \"Sorry to say this but there aren't any dialogues available for this "
		<< "encounter.\nAnyway since I'm a good person I'll send this encounter away for you.\n"
		<< "Or maybe not.\nNow go and die.\"\n";


	encounter().setCanTalk(false);

}



void noParlamento()
{

	std::cout << "Nanre: \"Mi dispiace di dirti questo ma non ci sono dialoghi disponibili per questo "
		<< "incontro.\nComunque visto che sono una brava persona cacciero' questo incontro per te.\n"
		<< "Oppure no.\nOra vai e muori.\"\n";


	encounter().setCanTalk(false);

}
