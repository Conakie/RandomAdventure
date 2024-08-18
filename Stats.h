
#ifndef KIIYUO_STATS_H
#define KIIYUO_STATS_H

#include "Playerz.h"
#include "Encounters.h"
#include "Encounterz.h"

Creatures::Player::Playerz& player();
Creatures::Encounter::Encounterz& encounter();
//Encounters& encounter();

extern Creatures::Player::Playerz* g_player;
extern Creatures::Encounter::Encounterz* g_encounter;
//Playerz player;
//Encounters encounter;

#endif // !KIIYUO_STATS_H
