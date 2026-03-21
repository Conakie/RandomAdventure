
#ifndef KIIYUO_PLAYER_CREATOR_CLASS_H
#define KIIYUO_PLAYER_CREATOR_CLASS_H

#include <string>
#include <string_view>
#include "Playerz.h"

class PlayerCreator
{
public:
    Creatures::Player::Playerz* createPlayer();
    Creatures::Player::Playerz* silentCreatePlayer(std::string_view name = "You");
private:
    Creatures::Player::PlayerRole selectRole();
    Creatures::Player::Playerz* createPlayerOfRole(Creatures::Player::PlayerRole role) const;
    Creatures::Player::Playerz* m_player{ nullptr };
};

#endif // !KIIYUO_PLAYER_CREATOR_CLASS_H