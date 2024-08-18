
#include <optional>
#include "PlayerActions.h"
#include "Input.h"



static PlayerActions getPlayerActionFromChar(char c)
{
    PlayerActions action{ PlayerActions::attack };

    switch (c)
    {
    case 'a':
        return PlayerActions::attack;
    case 'h':
        return PlayerActions::heal_;
    case 'H':
        return PlayerActions::healToMax;
    case 't':
        return PlayerActions::talk_;
    case 'w':
        return PlayerActions::continue_;
    case 's':
        return PlayerActions::skip;
    case 'q':
        return PlayerActions::seePlayerStats;
    case 'r':
        return PlayerActions::seeAlliesStats;
    case 'e':
        return PlayerActions::seeEncountersStats;
    case 'x':
        return PlayerActions::seeInventory;
    case 'z':
        return PlayerActions::seeActions;
    case 'i':
        return PlayerActions::useItem;
    case '/':
        return PlayerActions::useCommands;
    default:
        return PlayerActions::none;
    }
}

std::ostream& operator<<(std::ostream out, PlayerActions action)
{
    switch (action)
    {
    case PlayerActions::attack:
        break;
    case PlayerActions::heal_:
        break;
    case PlayerActions::healToMax:
        break;
    case PlayerActions::talk_:
        break;
    case PlayerActions::continue_:
        break;
    case PlayerActions::skip:
        break;
    case PlayerActions::seePlayerStats:
        break;
    case PlayerActions::seeAlliesStats:
        break;
    case PlayerActions::seeEncountersStats:
        break;
    case PlayerActions::seeInventory:
        break;
    case PlayerActions::seeActions:
        break;
    case PlayerActions::useItem:
        break;
    case PlayerActions::useCommands:
        break;
    case PlayerActions::none:
        break;
    default:
        break;
    }
    return out;
}

std::istream& operator>>(std::istream& in, PlayerActions& action)
{
    // create a character variable
    char c{ };
    // get a character from the player and store it in the variable
    in >> c;
    // get the action using the variable
    action = getPlayerActionFromChar(c);
    // repeat
    return in;
}
