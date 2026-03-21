
#ifndef KIIYUO_INPUT_H
#define KIIYUO_INPUT_H

#include <string_view>
#include <string>

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
    //PlayerActions playerAction();
}

// waits for the user to press any key
void waitForKeypress();

// asks the player a questions and returns true if the answer is yes
bool isPlayerSure(std::string_view text = "Are you sure? (y/n)\n");

#endif // !KIIYUO_INPUT_H