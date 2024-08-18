
#ifndef KIIYUO_RATABS_PLAYER_ACTIONS_ENUM_H
#define KIIYUO_RATABS_PLAYER_ACTIONS_ENUM_H

#include <iostream>

enum class PlayerActions
{
    attack,
    heal_,
    healToMax,
    talk_,
    continue_,
    skip,
    seePlayerStats,
    seeAlliesStats,
    seeEncountersStats,
    seeInventory,
    seeActions,
    useItem,
    useCommands,
    none,
};

std::ostream& operator<<(std::ostream out, PlayerActions action);
std::istream& operator>>(std::istream& in, PlayerActions& action);

#endif // !KIIYUO_RATABS_PLAYER_ACTIONS_ENUM_H
