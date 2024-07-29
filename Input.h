
#ifndef KIIYUO_INPUT_H
#define KIIYUO_INPUT_H

#include <string_view>
#include "PlayerActions.h"

namespace Input
{
    // return an integer value
    int integer();

    // return a floating point number
    double real();

    // return a character
    char character();

    // don't know why but the user has to press enter two times
    std::string string();

    // return the action of the player
    PlayerActions playerAction();
}

#endif // !KIIYUO_INPUT_H