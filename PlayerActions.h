
#ifndef KIIYUO_PLAYERACTIONO_ENUM_CLASS_H
#define KIIYUO_PLAYERACTIONO_ENUM_CLASS_H

namespace Creatures::Player
{
    enum PlayerActionz
    {
        attack = 'a',
        talk = 't',
        heal = 'h',
        healToFull = 'H',
        escape = 'E',
        seePlayerStats = 's',
        seeInventory = 'r',
        seeEncounterStats = 'q',
        useItem = 'f',
        useCommand = '/',
        yes = 'y',
        no = 'n',
        continues = ',',
        skip = '.',
        none = ' ',
    };
};

#endif // !KIIYUO_PLAYERACTIONO_ENUM_CLASS_H
