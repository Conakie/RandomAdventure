
#include <iostream>
#include <string>
#include <string_view>
#include "PlayerCreator.h"
#include "Input.h"
#include "PrintErrors.h"

Creatures::Player::Playerz* PlayerCreator::createPlayer()
{
    Creatures::Player::PlayerRole role{ Creatures::Player::PlayerRole::none };
    std::string name{ "You" };
    std::cout << "Nekoto: \"Hello~ I shall let Elesya and Kelmod help you in creating\n"
        << "your character. I'll be waiting here. Once you finish, I'll show you the way.\"\n";
    // get the name
    std::cout << "Elesya: \"I wanna do this quickly, so get a move and choose a name for yourself."
        << "\"\n";
    do
    {
        name = Input::string();
    } while (!isPlayerSure());
    std::cout << "Elesya: \"Now choose the class of your character among the following ones:\"\n";
    // get the role
    role = selectRole();
    std::cout << "Elesya: \"Now that you have chosen the class, let us move forward\n"
        << "Ability scores! Kelmod will take care of it.\"\n";
    m_player = createPlayerOfRole(role);
    if (m_player)
    {
        m_player->setPlayer(role, name);
        return m_player;
    }
    return nullptr;
}

Creatures::Player::Playerz* PlayerCreator::silentCreatePlayer(std::string_view name)
{
    using Player = Creatures::Player::Playerz;
    Player* m_player = createPlayerOfRole(Creatures::Player::PlayerRole::none);
    //std::string nane{ "Balls" };

    if (m_player)
    {
        m_player->setPlayer(Creatures::Player::PlayerRole::none, name);
        return m_player;
    }
    return nullptr;
}

Creatures::Player::PlayerRole PlayerCreator::selectRole()
{
    bool retryAnswer{ false };

    std::cout << "Choose the class of your character:\n";
    do
    {
        std::cout << "0: Pre-Class update player.\n";
        switch (Input::integer())
        {
        case 0:
            std::cout << "You have chosen the default class.\n";
            return Creatures::Player::PlayerRole::none;
            retryAnswer = false;
            break;
        default:
            std::cout << "Nuh uh, choose one of these:\n";
            retryAnswer = true;
            break;
        }
    } while (retryAnswer);
    return Creatures::Player::PlayerRole::none;
}

Creatures::Player::Playerz* PlayerCreator::createPlayerOfRole(Creatures::Player::PlayerRole role) const
{
    int repeatCounter{ 0 };
    Creatures::Player::Playerz* tmp{ nullptr };
    while (repeatCounter < 3)
    {
        try
        {
            switch (role)
            {
            case Creatures::Player::PlayerRole::warrior:
                break;
            case Creatures::Player::PlayerRole::mage:
                break;
            case Creatures::Player::PlayerRole::archer:
                break;
            case Creatures::Player::PlayerRole::cleric:
                break;
            case Creatures::Player::PlayerRole::thief:
                break;
            case Creatures::Player::PlayerRole::shielder:
                break;
            case Creatures::Player::PlayerRole::lancer:
                break;
            case Creatures::Player::PlayerRole::berserker:
                break;
            case Creatures::Player::PlayerRole::barbarian:
                break;
            case Creatures::Player::PlayerRole::narrator:
                break;
            case Creatures::Player::PlayerRole::none:
                tmp = new Creatures::Player::Playerz;
                break;
            default:
                tmp = new Creatures::Player::Playerz;
                break;
            }
            if (tmp)
            {
                tmp->setRole(role);
                return tmp;
            }
        }
        catch (const std::bad_alloc&)
        {
            Print::Errors::cannotCreateObject();
            ++repeatCounter;
            return nullptr;
        }
    }
    return tmp;
}

