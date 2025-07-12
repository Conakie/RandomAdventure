
#ifndef KIIYUO_RATABS_GAMESESSION_CLASS_H
#define KIIYUO_RATABS_GAMESESSION_CLASS_H

#include "Playerz.h"
#include "Encounterz.h"

class GameSession
{
public:
    bool startSession();
    void play();
protected:
    void createPlayer();
    bool setPlayer(int playerClasss);

    Creatures::Player::Playerz* player{ nullptr };
    Creatures::Encounter::Encounterz* encounter{ nullptr };
};

#endif KIIYUO_RATABS_GAMESESSION_CLASS_H