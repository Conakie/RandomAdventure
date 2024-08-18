
#include <string>
#include <string_view>
#include "Stats.h"
#include "Input.h"
#include "GameSession.h"
#include "Everywhere Used Func.h"
#include "ConsoleStyle.h"
#include "Place.h"
#include "Random.h"
#include "Everywhere Used Func.h"
#include "Object UID.h"
#include "Shielder.h"
#include "Warrior.h"
#include "Mage.h"
#include "Berserker.h"
#include "Thief.h"
#include "Archer.h"
#include "Cleric.h"
#include "Barbarian.h"
#include "Encounterz.h"
#include "GetEncounterTypePerPlace.h"
#include "Print Errors.h"
#include "Create Encounters.h"




void GameSession::startSession()
{
    createPlayer();
    m_encounters.resize(1);

    m_encounters[0] = nullptr;
    m_worldLevel = 1;
    m_worldXp = 0;
    m_worldXpNecessaryForLvlUp = 22;
    m_actionsCost = 0;
}

void GameSession::play()
{
    if (!m_player)
        throw ("No player created");

    while (m_player->getHealth() > 0.00)
    {
        encountersTurn();
        redrawConsole();
        playerTurn();
    }
    std::cout << "UwU\n";
}

void GameSession::createPlayer()
{
    bool answerAgain{ false };
    bool retry{ false };


    std::cout << "Kelmod: \"Before we start, let's choose your class.\n"
        << "There is no confirm button so be careful~\"\n";
    do
    {
        int failedAmount{ 0 };
        try
        {
            m_player = setAndGetPlayer();
        }
        catch (std::bad_alloc)
        {
            if (failedAmount > 4)
            {
                std::cout << "Nanre: \"The OS did not give us any ram for too many times.\n"
                    << "We'll kill the app. Please, open it again and be sure to have enough ram.\n"
                    << "Random Adventure is being killed...\"\n";
                delay(2);
                exit(1);
            }
            else
            {
                std::cout << "Nanre: \"An error occurred. Please, choose you class again.\"\n";
                ++failedAmount;
                retry = true;
            }
        }
    } while (retry);
    

    std::cout << "Kelmod: \"Now we're ready for the next step.\n"
        << "How do you wanna call yourself?\"\n";
    m_player->setName(Input::string());
    m_player->resetAllStats();
    m_player->setStats();
}

bool GameSession::isPlayerAlive()
{
    return m_player->isAlive();
}

void GameSession::redrawConsole()
{
    Console::setColorPerPlace(printMainPlace(false));
}

void GameSession::playerTurn()
{
    // if the player has not been created, kill this game
    if (!m_player)
        throw ("No player found");

    bool answerAgain{ false };
    m_actionsCost = 2;


    std::cout << "It's your turn now. Choose your next action.\n";
    
    do
    {
        switch (Input::playerAction())
        {
        case PlayerActions::attack:
            if (m_encounters[0])
            {
                m_player->attack(*m_encounters[0]);
                m_actionsCost = -1;
            }
            else
            {
                std::cout << "No encounter available...\n";
            }
            break;

        case PlayerActions::heal_:
            m_player->heal(Random::get(1, 6 * m_player->getLvl()));
            --m_actionsCost;
            break;

        case PlayerActions::healToMax:
            m_player->heal(m_player->getMaxHealth() - m_player->getHealth());
            m_actionsCost = -1;
            break;

        case PlayerActions::talk_:
            if (m_encounters[0])
            {
                m_encounters[0]->talk();
                m_actionsCost = -1;
            }
            else
            {
                std::cout << "No encounter in sight...\n";
            }
            break;

        case PlayerActions::continue_:
            
            break;

        case PlayerActions::skip:
            std::cout << "Turn skipped.\n";
            m_actionsCost = -1;
            break;

        case PlayerActions::seePlayerStats:
            m_player->printStats();
            break;

        case PlayerActions::seeAlliesStats:
            std::cout << "You have no party members.\n"
                << "Invite an encounter to join your party before using this.\n";
            break;

        case PlayerActions::seeEncountersStats:
            if (m_encounters[0])
            {
                m_encounters[0]->printStats();
            }
            else
            {
                std::cout << "There seem to be no encounter here...\n";
            }
            break;

        case PlayerActions::seeInventory:
            m_player->setInventory().print();
            break;

        case PlayerActions::useItem:
        {
            ObjectUid item{ 0 };
            int quantity{ 0 };

            // select the item to be used
            std::cout << "Select the item you want to use.\n";
            m_player->setInventory().print();
            item = static_cast<ObjectUid>(Input::integer() - 1);

            // select the quantity of items to use
            // since the player uses @print as reference, decrease the input of 1
            std::cout << "Write the amount you want to use:";
            quantity = Input::integer();

            // set the targets of possible effects
            //m_player->setInventory().setUtilities(m_player, m_encounters[0]);
            // use the item
            // if @useItem fails, notify the player otherwise let
            if ((m_player->setInventory().useItem(item, quantity)))
                std::cout << "Not enough items. Use another one or change item.\n";
            else
                --m_actionsCost;
            break;
        }
        case PlayerActions::useCommands:
            
            break;

        case PlayerActions::none:
            
            break;

        default:
            std::cout << "Necoto: \"How can you be here? This is the default case...\n"
                << "Please, report this to Nanre. He is the one taking care of bugs.\n"
                << "If you can, please, add a screenshot. It helps a lot.\"\n";
            break;
        }
    } while (m_actionsCost > 0);
}

void GameSession::alliesTurn()
{
    std::cout << "UwU\n";
}

void GameSession::encountersTurn()
{
    if (m_encounters[0])
    {
        // if the encounter is alive and not gone
        if (m_encounters[0]->isAlive() && !m_encounters[0]->isGone())
        {
            m_encounters[0]->thinkAndAct();
        }
        else // the encounter is gone or dead
        {
            addXp(m_encounters[0]->getXp());
            m_player->increaseXpAndCheckForLvlUp(m_encounters[0]->getXp());
            delete m_encounters[0];
            m_encounters[0] = createEncounter(getEncounterTypePerPlace(printMainPlace(false)), m_worldLevel);
            m_encounters[0]->setPlayer(m_player);
            printMainPlace(true);
        }
    }
    else
    {
        delete m_encounters[0];
        m_encounters[0] = createEncounter(getEncounterTypePerPlace(printMainPlace(false)), m_worldLevel);
        m_encounters[0]->setPlayer(m_player);
        
    }
}

Creatures::Player::Playerz* GameSession::setAndGetPlayer()
{
    bool answerAgain{ false };


    do
    {
        std::cout << "1: Warrior.\n"
            << "2: Mage.\n"
            << "3: Archer.\n"
            << "4: Shielder.\n"
            << "5: Berserker.\n"
            << "6: Barbarian.\n"
            << "7: Thief.\n"
            << "8: Cleric.\n";
        switch (Input::character())
        {
        case '1':// option 1: Warrior.
            return new Creatures::Player::Warrior;

        case '2':// option 2: Mage.
            return new Creatures::Player::Mage;

        case '3':// option 3: Archer.
            return new Creatures::Player::Archer;

        case '4':// option 4: Shielder.
            return new Creatures::Player::Shielder;

        case '5':// option 5: Berserker.
            return new Creatures::Player::Berserker;

        case '6':// option 6: Barbarian.
            return new Creatures::Player::Barbarian;

        case '7':// option 7: Thief.
            return new Creatures::Player::Thief;

        case '8':// option 8: Cleric.
            return new Creatures::Player::Cleric;

        default:
            printNotPossible();
            answerAgain = true;
            break;
        }
    } while (answerAgain);

    return nullptr;
}

void GameSession::addXp(int value)
{
    m_worldXp += value;
    lvlUpWorldLvl();
}

void GameSession::lvlUpWorldLvl()
{
    if (m_worldXp >= m_worldXpNecessaryForLvlUp)
    {
        ++m_worldLevel;
        m_worldXp -= m_worldXpNecessaryForLvlUp;
        m_worldXpNecessaryForLvlUp = m_worldXpNecessaryForLvlUp + ((m_worldXpNecessaryForLvlUp * 50) / 100);
        std::cout << "Kelmod: \"World level increased!\n"
            << "From now on, all new encounters are going to be stronger.\"\n";
    }
    else
    {

    }
}
