
#include <iostream>
#include "Witch.h"
#include "Random.h"
#include "Print Errors.h"
#include "Playerz.h"
#include "Everywhere Used Func.h"



void Creatures::Encounter::Witch::talk()
{
    if (m_canTalk && !(m_isUnderAttack))
    {
        dialogue();
    }
    else
    {
        if (m_isUnderAttack)
        {
            std::cout << "Kelmod: \"" << name << " refuses to talk after you attacked it.\"\n";
        }
        else
        {
            std::cout << "Kelmod: \"You have already talked to him.\n";
        }
    }
}

void Creatures::Encounter::Witch::setName()
{
    name = "Witch";
}

void Creatures::Encounter::Witch::setStats()
{
    maxHp = 8.8 + (6.6 * (lvl - 1));
    maxAtk = 1 + (3 * lvl);
    maxDef = -1;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}

void Creatures::Encounter::Witch::dialogue()
{
    switch (Random::get(0, 10))
    {
    case 0:
        std::cout << name << ": \"Abra Calabria, dritto!\"\n";
        m_isUnderAttack = true;
        break;
    case 1:
        std::cout << name << ": \"Apriti, sedano!\"\n";
        m_isUnderAttack = true;
        break;
    case 2:
        std::cout << name << ": \"Le rose sono rosse,\n"
            << "Le viole sono blu,\n"
            << "Guarda il tuo polso,\n"
            << "L'orologio non c'e' piu'.\"\n";
        m_isGone = true;
        break;
    case 3:
        std::cout << name << ": \"Roses are red,\n"
            << "Violets are blue,\n"
            << "I am Oppainaimer,\n"
            << "And this is a nuke.\"\n";
        if (m_player)
        {
            m_player->setInventory().addItem(ObjectUid::nuke);
            m_player->setInventory().useItem(ObjectUid::nuke);
        }
        m_isGone = true;
        break;
    case 4:
        std::cout << name << ": \"Abra Calabria, curva!\"\n";
        m_isGone = true;
        break;
    case 5:
        std::cout << name << ": \"Abura cadabura, sushi!\"\n";
        heal(32767);
        break;
    case 6:
        std::cout << name << ": \"I am the witch of the nuke!\n"
            << "Boom! Boom! Boom!\"\n";
        if (m_player)
        {
            m_player->setInventory().addItem(ObjectUid::nuke);
            m_player->setInventory().useItem(ObjectUid::nuke);
        }
        m_isGone = true;
        break;
    case 7:// UwU, onii-chan.
        std::cout << name << ": \"01010101 01110111 01010101 00101100\n"
            << "00100000 01101111 01101110 01101001\n"
            << "01101001 00101101 01100011 01101000\n"
            << "01100001 01101110 00101110\"\n";
        m_isGone = true;
        break;
    case 8:
        std::cout << name << ": \".._ .__ .._, ___ _. .. .. _._. .... ._ _.\"\n";
        m_isGone = true;
        break;
    case 9:
        std::cout << name << ": \"" << static_cast<char>(178) << static_cast<char>(176) << "\"\n";
        m_isUnderAttack = true;
        break;
    case 10:
        std::cout << name << ": \"Sonderkraftfahrzeug 234 4 mit 7,5 cm panzerabwehrkanonen wagen."
            << "\"\n";
        m_isUnderAttack = true;
        break;
    default:
        PrintError::wrongRandomNumber();
        m_isGone = true;
        break;
    }


    m_canTalk = false;
    waitForAnyKey();
}
