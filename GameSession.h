
#ifndef KIIYUO_RATABS_GAMESESSION_CLASS_H
#define KIIYUO_RATABS_GAMESESSION_CLASS_H

#include <vector>
#include "Playerz.h"
#include "Encounterz.h"
#include "Locale.h"
#include "PlayerActions.h"

class GameSession
{
private:
    using Encounter = Creatures::Encounter::Encounterz;
    using Player = Creatures::Player::Playerz;
    using Actionz = Creatures::Player::PlayerActionz;
    using EncType = Creatures::Encounter::EncounterType;
public:
    void prepareGameSession();
    void silentPrepareGameSession();
    void playGame();
protected:
    int playerTurn();
    void encounterTurn();
    void updateGameState();

    Player* m_player{ nullptr };
    Encounter* m_activeEncounter{ nullptr };
    std::vector<Encounter*> m_encounterList{};
    int m_worldLvl{ 1 };
    int xp{ 0 };
    int xpToNextLvl{ 100 };
    Locale m_locale{};
};

#endif KIIYUO_RATABS_GAMESESSION_CLASS_H