
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Random Adventure English.h"
#include "Random Adventure Italiano.h"
#include "ConsoleStyle.h"
#include "Stats.h"



void setup()
{
    // set light mode for console color
    Console::isAuto = true;
    Console::setColor(Console::Color::light);

    // reset the player and the encounter stats to default
}
