
#include <iostream>
#include <cmath>
#include "GameSession.h"
#include "PlayerCreator.h"
#include "Input.h"
#include "PrintErrors.h"
#include "PlayerActions.h"
#include "Delays.h"
#include "Random.h"
#include "EncounterType.h"
#include "Items.h"
#include <print>



void GameSession::prepareGameSession()
{
    PlayerCreator playerCreator{};
    m_player = playerCreator.createPlayer();
}

void GameSession::silentPrepareGameSession()
{
    PlayerCreator playerCreator{};
    m_player = playerCreator.silentCreatePlayer();
}

void GameSession::playGame()
{
    //std::cout << "UwU";
    if (!m_player)
        return;
    //std::cout << "OwO";
    while(m_player->isAlive())
    {
        updateGameState();
        playerTurn();
        waitForKeypress();
        encounterTurn();
        waitForKeypress();
    }
}

int GameSession::playerTurn()
{
    bool answerAgain{ false };

    std::cout << "\nKelmod: \"It is your turn. Choose what to do.\"\n";
    do
    {
        std::cout << "a: Attack.\n"
            << "t: Talk.\n"
            << "h: Heal.\n"
            << "H: Heal to full.\n"
            << "E: Escape.\n"
            << "s: See your stats.\n"
            << "r: See inventory.\n"
            << "q: See encounter stats.\n"
            << "f: Use item.\n"
            << "/: Use command.\n"
            << "1: Go to next room.\n"
            << "2: go to previous room.\n";

        switch (Input::character())
        {
        case Actionz::attack:
            if (!m_activeEncounter)
            {
                if (m_locale.getCurrentRoomEncounterType() == EncType::none)
                {
                    std::cout << "kelmod: \"Do you want to attack the ground?\n"
                        << "there is nobody here other than you.\"\n";
                }
                else
                {
                    Print::Errors::noEncounterPresent();
                }
            }
            else
            {
                m_player->attack(*m_activeEncounter);
                return 2;
            }
            break;

        case Actionz::talk:
            if (m_activeEncounter)
            {
                m_activeEncounter->talk();
            }
            else
            {
                std::cout << "kelmod: \"You wanna talk to me? Too bad, you can't.\n"
                    << "Go and exolore the place or something.\"\n";
            }
            return 2;

        case Actionz::heal:
            m_player->heal(Random::get(1, (6 * m_worldLvl)));
            return 1;

        case Actionz::healToFull:
            m_player->heal((m_player->getMaxHealth() - m_player->getHealth()));
            return 1;

        case Actionz::escape:
            std::cout << "It's empty, but I'm wasting your turn anyway.\n";
            return 2;

        case Actionz::seePlayerStats:
            m_player->printPlayerStats();
            break;

        case Actionz::seeInventory:
            m_player->openInventory().printInventory();
            break;

        case Actionz::seeEncounterStats:
            if (!m_activeEncounter)
            {
                if (m_locale.getCurrentRoomEncounterType() == EncType::none)
                {
                    std::cout << "Kelmod: \"You wanna check the stats of air?\"\n";
                }
                else
                {
                    Print::Errors::noEncounterPresent();
                }
            }
            else
            {
                m_activeEncounter->printStats();
            }
            break;

        case Actionz::useItem:
        {
            Items::ItemName itemToUse{ Items::ItemName::none };
            int quantityToUse{ 0 };

            std::cout << "Kelmod: \"Choose the item you want to use:\"\n"
                << "1: small healing potion.\n"
                << "2: medium healing potion.\n"
                << "3: large healing potion.\n"
                << "4: molotov.\n"
                << "5: nuke.\n"
                << "6: herbs.\n"
                << "7: wood.\n"
                << "8: arrow.\n"
                << "9: leather.\n"
                << "10: stone.\n"
                << "11: bone.\n"
                << "12: paper.\n"
                << "13: meat.\n"
                << "14: fish.\n"
                << "15: mushroom.\n"
                << "16: magic scroll.\n"
                /* << "17: Fridgenade.\n"*/;
            itemToUse = static_cast<Items::ItemName>(Input::integer());
            std::cout << "Kelmod: \"Now choose the quantity to use:\n"
                << "Also, do not dare to use negative numbers.\"\n";
            quantityToUse = Input::integer();
            if (m_player->openInventory().useItem(itemToUse, abs(quantityToUse)))
                return 2;
            else
                answerAgain = true;
            break;
        }
        case Actionz::useCommand:
            std::cout << "Nanre: \"Bold of you to think I made commands.\"\n";
            break;

        case Actionz::yes:
            std::cout << "(You shout \"Yes\" for some unknown reason)\n";
            if (m_activeEncounter)
                std::cout << '(' << m_activeEncounter->getName() 
                << " wonders why you shouted \"Yes\".\n"
                << "You also wasted a turn)\n";
            return 2;

        case Actionz::no:
            std::cout << "(You shout \"No\" for some unknown reason)\n";
            if (m_activeEncounter)
                std::cout << '(' << m_activeEncounter->getName()
                << " wonders why you shouted \"No\".\n"
                << "You also wasted a turn)\n";
            return 2;

        case Actionz::continues:
            std::cout << "(You continue to do nothing for some unknown reason.\n"
                << "And you skip a turn)\n";
            return 2;

        case Actionz::skip:
            std::cout << "(You skip your turn. Good luck)\n";
            return 2;

        case Actionz::none:
            std::cout << "Kelmod: \"I admire your ability in doing nothing.\"\n";
            return 2;

        case Actionz::goToNextRoom:
            if (m_activeEncounter)
            {
                if (m_activeEncounter->isAlive())
                {
                    std::print("Kelmod: \"You can't escape this way. Fight to the death!\"\n");
                }
                else
                {
                    std::print("(You continue your adventure forward.)\n");
                    if (m_locale.goToNextRoom())
                        m_hasToRegenerateLocale = true;
                    setActiveEncounter();
                    return 2;
                }
            }
            break;
            
        case Actionz::goToPreviousRoom:
            std::print("Empty for now");
            m_hasToRegenerateLocale = true;
            break;

        default:
            answerAgain = true;
            break;
        }
    } while (answerAgain);

    return 0;
}

void GameSession::encounterTurn()
{
    if (m_activeEncounter)
    {
        m_activeEncounter->thinkAndAct();
    }
    else if (!m_activeEncounter && m_locale.getCurrentRoomEncounterType() != EncType::none)
    {
        m_activeEncounter = m_encounterList[m_locale.getCurrentRoomIndex()];
    }
    else
    {
        std::cout << "The area around you is quiet. Maybe even too quiet for your taste.\n";
    }
}

void GameSession::updateGameState()
{
    if (m_hasToRegenerateLocale)
    {
        m_hasToRegenerateLocale = false;
        m_locale.generateLocale();
        m_encounterList.clear();
        for (size_t index = 0; index < m_locale.size(); index++)
        {
            if (m_locale.getCurrentRoomEncounterType() != EncType::none)
            {
                Encounter* encounter = new Encounter{};
                encounter->setPlayer(m_player);
                encounter->setType(m_locale.getCurrentRoomEncounterType());
                encounter->setEncounter(m_worldLvl);
                m_encounterList.push_back(encounter);
                //std::print("enemy at: {}/{}\n", index, (m_locale.size() - 1));
            }
            else
            {
                m_encounterList.push_back(nullptr);
            }
        }
        m_locale.printCurrentRoom();
        m_locale.setCurrentRoomIndex(0);
        setActiveEncounter();
    }
    else
    {
        if (m_activeEncounter)
        {
            if (!m_activeEncounter->isAlive() || m_activeEncounter->isGone())
            {
                delete m_activeEncounter;
                m_activeEncounter = nullptr;
                m_locale.removeCurrentRoomEncounter();
                m_locale.getLootFromCurrentRoom();
            }
        }
    }
}

void GameSession::setActiveEncounter()
{
    m_activeEncounter = m_encounterList[m_locale.getCurrentRoomIndex()];
    if (m_activeEncounter)
        std::print("{}", m_activeEncounter->getIntro());
}
