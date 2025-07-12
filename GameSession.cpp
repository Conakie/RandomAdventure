
#include <iostream>
#include "GameSession.h"
#include "Input.h"
#include "Random.h"
#include "PrintErrors.h"

bool GameSession::startSession()
{
    createPlayer();
    return true;
}

void GameSession::play()
{
}

void GameSession::createPlayer()
{
    bool answerAgain{ false };
    int num{ 0 };


    std::cout << "Kelmod: \"Before we start, choose the class of your character.\n"
        << "You can choose between the following or let fate decide for you.\n"
        << "You won't be able to change class again in this game.\"\n";
    do
    {
        std::cout
            << "1: Warrior.\n"
            << "2: Mage.\n"
            << "3: Berserker.\n"
            << "4: Archer.\n"
            << "5: Barbarian.\n"
            << "6: Thief.\n"
            << "7: Spearman.\n"
            << "8: Shielder.\n"
            << "9: Cleric.\n"
            << "10: Let fate decide.\n";
        num = Input::integer();
        if (num == 10)
            num = Random::get(1, 9);

    } while (answerAgain);
}

bool GameSession::setPlayer(int playerClasss)
{
    for (int i = 0; i < 3; ++i)
    {
        try
        {
            switch (playerClasss)
            {
            case 1:
                player = new Creatures::Player::Playerz;
                break;
            case 2:
                player = new Creatures::Player::Playerz;
                break;
            case 3:
                player = new Creatures::Player::Playerz;
                break;
            case 4:
                player = new Creatures::Player::Playerz;
                break;
            case 5:
                player = new Creatures::Player::Playerz;
                break;
            case 6:
                player = new Creatures::Player::Playerz;
                break;
            case 7:
                player = new Creatures::Player::Playerz;
                break;
            case 8:
                player = new Creatures::Player::Playerz;
                break;
            case 9:
                player = new Creatures::Player::Playerz;
                break;
            default:
                Print::Errors::notFound();
                break;
            }
            i = 69;
        }
        catch (const std::exception&)
        {
            Print::Errors::cannotCreateObject();
            exit(0);
        }
    }

    return false;
}
