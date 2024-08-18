
#include <iostream>
#include "Everywhere Used Func.h"
#include "Random.h"
#include "Print Errors.h"
#include "Place.h"
#include "PlaceNames.h"
#include "ConsoleStyle.h"



Places printMainPlace(bool canBeDecremented)
{

    // place stores the main place the player is in
    static Places place{ 10 };
    // changePlaceIn stores how many times the player stays in the same place
    static int changePlaceIn{ 0 };



    if (changePlaceIn <= 0)
    {

        // choose a random place
        switch (Random::get(0, 3))
        {
        case 0:
            place = Places::village;
            break;
        case 1:
            place = Places::dungeon;
            break;
        case 2:
            place = Places::cave;
            break;
        case 3:
            place = Places::forest;
            break;
        default:
            PrintError::wrongRandomNumber();
            place = Places::forest;
            break;
        }
        // choose in how many rooms the player will go through before changing the main place
        changePlaceIn = Random::get(2, 10);


        // print where the player is
        std::cout << "\n\nYou arrived in a ";
        switch (place)
        {
        case Places::village:// village

            std::cout << "village.";

            break;

        case Places::dungeon:// dungeon

            std::cout << "dungeon.";

            break;

        case Places::cave:// cave

            std::cout << "cave.";

            break;

        case Places::forest:

            std::cout << "forest.";

            break;

        default:

            PrintError::wrongRandomNumber();

            break;
        }

        std::cout << "\n";
        printRoom(place);

    }
    else if (canBeDecremented)
    {

        // print the room the player is
        --changePlaceIn;
        printRoom(place);

    }
    else
    {

    }

    return place;

}



void printRoom(Places mainPlace)
{

    switch (mainPlace)
    {
    case Places::village:// village

        village();

        break;

    case Places::dungeon:// dungeon

        dungeon();

        break;

    case Places::cave:// cave

        cave();

        break;

    case Places::forest:

        forest();

        break;

    default:

        PrintError::notFound();

        break;
    }

}



void dungeon()
{

    switch (Random::get(0, 7))
    {

    case 0:// greenhouse

        std::cout << "The room you're in now is a greenhouse.";

        break;

    case 1:// hallway

        std::cout << "You're in an hallway.";

        break;

    case 2:// graveyard

        std::cout << "The room you're in now is a graveyard.";

        break;

    case 3:// church

        std::cout << "The room you're in now is a church of Asbestosis.";

        break;

    case 4:// rectangular room

        std::cout << "The room you're in now is a rectangular room.";

        break;

    case 5:// circular room

        std::cout << "The room you're in now is a circular room.";

        break;

    case 6:// cubic room

        std::cout << "The room you're in now is a cubic room.";

        break;

    case 7:// alchemy lab

        std::cout << "The room you're in now is an alchemy lab.";

        break;

    default:

        PrintError::wrongRandomNumber();

        break;

    }

    std::cout << "\n";

}



void village()
{
    int a{ Random::get(0, 4) };
    switch (a)
    {
    case 0:

        std::cout << "You're walking on a road.";

        break;

    case 1:

        std::cout << "You've found a small road leading to an unknown place.";

        break;

    case 2:

        std::cout << "The road you're walking on now is one of the main ones.";

        break;

    case 3:

        std::cout << "You are now in a small square.";

        break;

    case 4:

        std::cout << "This square here is a big one.";

        break;

    default:

        PrintError::wrongRandomNumber();

        break;
    }

    std::cout << "\n";

}



void cave()
{

    switch (Random::get(0, 5))
    {
    case 0:

        std::cout << "This looks like a never ending tunnel.";

        break;

    case 1:

        std::cout << "Guess what? A tunnel.";

        break;

    case 3:

        std::cout << "The tunnel you're in is full of stalactites and stalagmites.";

        break;

    case 4:

        std::cout << "This part of the cave is a large circular room.";

        break;

    case 5:

        std::cout << "This tunnel there are many water droplets falling from the ceiling.";

        break;

    default:

        PrintError::wrongRandomNumber();

        break;
    }

    std::cout << "\n";

}



void forest()
{

    switch (Random::get(0, 5))
    {
    case 0:

        std::cout << "You're going on a random direction because you don't know dee way.";

        break;

    case 1:

        std::cout << "Guess what? You're lost in a forest.";

        break;

    case 2:

        std::cout << "You have found a pond of water!";

        break;

    case 3:

        std::cout << "The only thing you can see in front of you are some trees.";

        break;

    case 4:

        std::cout << "There is a small open place in front of you.";

        break;

    case 5:

        std::cout << "There is a rock in front of you.";
        if (Random::get(0, 100) <= 50)
        {

            std::cout << "\nOn the rock there is a small drawing of a divine chicken.";

        }
        else
        {

        }

        break;

    default:

        PrintError::wrongRandomNumber();

        break;
    }

    std::cout << "\n";

}
