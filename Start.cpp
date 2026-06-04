
#include <iostream>
#include <Windows.h>
#include "Inventory.h"
#include "Playerz.h"
#include "Encounterz.h"
#include "Input.h"
#include "KiiyuoMath.h"
#include "ConsoleStyle.h"
#include "PlacesID.h"
#include "Locale.h"
#include "GameSession.h"
#include "Locale.h"
#include "Timer.h"



int main()
{
    ConsoleStyle::setColorPerPlace(PlacesID::village);
    
    GameSession gameSessions{};
    gameSessions.silentPrepareGameSession();
    gameSessions.playGame();
    //gameSessions.prepareGameSession();
    //gameSessions.playGame();
    return 0;
    /*
    Kokomi (genshin)
    Lynx (Star Rail)
    Nephie (Archdemon Dilemma)
    Priestess (Goblin Slayer)
    Faputa (Made in Abyss)
    Eumiella (Villainess lvl 99)
    Mahiro (Onimai)
    Shiro (Senko-san)
    Mare (Overlord)
    Cocoa (Gochiusa)
    Yuki (School live!)
    Shiro (No Game No Life)
    Neru Akita 
    Mayano Top Gun (Umamusume)
    Neneko (battle cats)
    Sila (Random Adventure)
    Sayori (DDLC)
    Pei (Oxygen Not Included)
    Annie (Oyxgen Not Included)
    */
}


/*
Encounterz

attack,
heal,
takeDamage,
talk,
drop items,
thinkAndAct

getXp
isAlive
getIsGone
reset

setPlayer
setEncounter
setType
setLvl
*/