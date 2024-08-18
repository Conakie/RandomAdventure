
#ifndef KIIYUO_RANDOMADVENTURE_GAMESESSION_H
#define KIIYUO_RANDOMADVENTURE_GAMESESSION_H

#include <vector>
#include "Playerz.h"
#include "Encounterz.h"
#include "ConsoleStyle.h"


class GameSession
{
public:
    void startSession();
    void play();
    

    Creatures::Player::Playerz& player() { return *m_player; }
private:
    void createPlayer();
    bool isPlayerAlive();
    void redrawConsole();

    void playerTurn();
    void alliesTurn();
    void encountersTurn();

    Creatures::Player::Playerz* setAndGetPlayer();

    void addXp(int value);
    void lvlUpWorldLvl();

    Creatures::Player::Playerz* m_player{ nullptr };
    std::vector<Creatures::Encounter::Encounterz*> m_encounters{ };
    

    int m_worldLevel{ 1 };
    int m_worldXp{ 0 };
    int m_worldXpNecessaryForLvlUp{ 22 };
    short m_actionsCost{ 0 };
};

#endif //KIIYUO_RANDOMADVENTURE_GAMESESSION_H
