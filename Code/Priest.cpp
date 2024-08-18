
#include <iostream>
#include "Priest.h"
#include "Input.h"
#include "Everywhere Used Func.h"
#include "Playerz.h"
#include "Random.h"



void Creatures::Encounter::Priest::talk()
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

void Creatures::Encounter::Priest::thinkAndAct()
{
    if (m_player)
    {
        if (isAlive() && !m_isUnderAttack && m_canTalk)
        {
            talk();
        }
        else
        {
            std::cout << "Kelmod: \"Do something man. I'm bored.\"\n";
        }
    }
    else
    {
        std::cout << "The priest ignores you and keeps going his way.\n";
        m_isGone = true;
    }
}

void Creatures::Encounter::Priest::setName()
{
    name = "Priest";
}

void Creatures::Encounter::Priest::setStats()
{
    maxHp = 11 + (11 * (lvl - 1));
    maxAtk = 1 + (1 * lvl);
    maxDef = 1;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}

void Creatures::Encounter::Priest::dialogue()
{
    if (!m_player)
        return;
    bool answerAgain{ false };


    std::cout << name << ": \"Hello human. I am a priest of the church of Miiro.\n"
        << "Do you want me to heal your injuries?\"\n";
    do
    {
        std::cout << "1: Yes please. It would be of great help if you did.\n"
            << "2: No need, I'm fine.\n"
            << "3: If it's no problem, yes please.\n";
        switch (Input::character())
        {
        case '1':// option 1: Yes please. It would be of great help if you did.
            std::cout << name << ": \"Wait a bit and you'll be fine.\"\n"
                << "(He wispered some words and now you feel a bit better)\n";
            m_player->heal(Random::get(2, 8 * lvl));
            waitForAnyKey();
            std::cout << name << ": \"Now you should feel better.\n"
                << "If you'll excuse me, I'll be back on my journey.\"\n"
                << "(You thank him and you both go on your separate ways)\n";
            answerAgain = false;
            break;

        case '2':// option 2: No need, I'm fine.
            if (m_player->getHealth() < 5)
            {
                std::cout << name << ": \"You're not fine at all!\n"
                    << "Here, let me heal you.\"\n";
                m_player->heal(Random::get(2, 8 * lvl));
                waitForAnyKey();
                std::cout << name << ": \"Now, rest a bit and you'll be able to go around again.\n"
                    << "And next time, please, rely on us priests a bit more.\"\n"
                    << "(After he said that he leaves you alone)\n";
                waitForAnyKey();
                std::cout << "(After he went away you notice two small healing potions)\n"
                    << "(A letter near the bottle says: \"Take this, it may help you\")";
                m_player->setInventory().addItem(ObjectUid::smallHealingPotion, 2);
            }
            else
            {
                std::cout << name << ": \"I'm happy to hear it. Have a nice journey.\n"
                    << "And remember to stay healty.\"\n"
                    << "(With that said the priest goes away)\n";
            }
            answerAgain = false;
            break;

        case '3':// option 3: If it's no problem, yes please.
            std::cout << name << ": \"It's no problem at all. I'm happy to help.\n"
                << "(He wispers some words and you start feeling better)\n";
            m_player->heal(Random::get(2, 8 * lvl));
            waitForAnyKey();
            std::cout << name << ": \"Feel better? Yes? Perfect, I'm happy to hear that.\n"
                << "Well then, I'll go and continue my journey now. Stay healty~\"\n";
            answerAgain = false;
            break;

        default:
            printNotPossible();
            answerAgain = true;
            break;
        }
    } while (answerAgain);


    m_isGone = true;
    m_canTalk = false;
    waitForAnyKey();
}
