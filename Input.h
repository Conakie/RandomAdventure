
#ifndef KIIYUO_INPUT_H
#define KIIYUO_INPUT_H

#include <string_view>
#include "PlayerActions.h"

namespace Input
{
    // return an integer value from 
    int integer();

    double real();

    char character();

    // the string input isn't working properly, send help
    std::string_view string();

    PlayerActions playerAction();
}

#endif // !KIIYUO_INPUT_H