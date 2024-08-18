
#include <iostream>
#include "Random Adventure English.h"
#include "Parla Con Gli Incontri.h"
#include "Azioni.h"
#include "Everywhere Used Func.h"
#include "Player Stats.h"
#include "Encounter Stats.h"
#include "Stats.h"



void parla()
{

    //Check if player can talk to the encounter
    if (encounter().getCanTalk())
    {
        // talk to the encounter and changes some stats like isGone or isUnderAttack
        parlaConGliIncontri();

        //setConsoleColor(0);

    }
    else//The player won't be able to talk to encounters if he has already done that
    {

    }

}



void cura(double healing)
{

}



void attaccaIncontro()
{
    
}



void stampAzioniRimanenti(int actionsLeft)
{

    

}
