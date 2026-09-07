
#include <iostream>
#include "Playerz.h"
#include "Encounterz.h"
#include "Random.h"
#include "AbilityScores.h"
#include "Inventory.h"
#include "KiiyuoMath.h"



void Creatures::Player::Playerz::attack(Encounter::Encounterz& encounter)
{
    std::cout << "You attack " << encounter.getName() << ".\n";
    // if it's a crit hit, multiply the atk with critDmg
    // otherwise do normal damaga
    if (Random::get(0, 99) < m_critRate)
    {
        std::cout << "You did a critical hit!\n";
        encounter.takeDamage(m_atk * m_critDmg);
    }
    else
    {
        encounter.takeDamage(m_atk);
    }
}

void Creatures::Player::Playerz::heal(double healing)
{
    healing = roundToTwoDecimals(healing);
    std::cout << "You healed of " << healing << " hp.\n";
    // if the hp plus the healing is less than the max hp
    // add healing to hp
    // otherwise hp is set to maxHp
    if (m_hp + healing < m_maxHp)
        m_hp += healing;
    else
        m_hp = m_maxHp;

    std::cout << "Now you have " << m_hp << " hp.\n";
}

void Creatures::Player::Playerz::takeDamage(double damage)
{
    damage = roundToTwoDecimals(damage);
    m_hp -= roundToTwoDecimals((damage - (damage * m_def / 100)));

    if (isAlive())
        std::cout << "You took " << damage << " hp of damage.\n"
        << "Now you have " << m_hp << " hp.\n";
    else
        std::cout << "You died!\n";
}

// useless: delete it
void Creatures::Player::Playerz::talk()
{
}

void Creatures::Player::Playerz::resetPlayer()
{
    m_name = "UwU";
    m_hp = 10;
    m_maxHp = 10;
    m_atk = 4;
    m_maxAtk = 4;
    m_critDmg = 2;
    m_critRate = 10;
    m_def = 10;
    m_maxDef = 10;
    m_xp = 0;
    m_xpForLvlUp = 22;
    m_lvl = 1;
    m_role = PlayerRole::none;
    m_abilityScores.reset();
    m_inventory.reset();
    m_inventory.setTarget(this);
}

void Creatures::Player::Playerz::printPlayerStats() const
{
    std::cout << "Name: " << m_name << "\n"
        << "Level: " << m_lvl << "\n"
        << "Health: " << m_hp << "/" << m_maxHp << "\n"
        << "Attack: " << m_atk << "/" << m_maxAtk << "\n"
        << "Crit Rate: " << m_critRate << "%\n"
        << "Crit Damage: " << m_critDmg << "\n"
        << "Defense: " << m_def << "/" << m_maxDef << "\n"
        << "Xp: " << m_xp << "/" << m_xpForLvlUp << "\n"
        << "Ability Scores:\n";
    m_abilityScores.printStats();
}

void Creatures::Player::Playerz::setRole(PlayerRole role)
{
    m_role = role;
}

void Creatures::Player::Playerz::setAbilityScores()
{
    m_abilityScores.setStats();
}

void Creatures::Player::Playerz::setPlayer(PlayerRole role, std::string_view name)
{
    m_hp = 100;
    m_maxHp = 100;
    m_atk = 10;
    m_maxAtk = 10;
    m_critDmg = 2;
    m_critRate = 10;
    m_def = 10;
    m_maxDef = 10;
    m_xp = 0;
    m_xpForLvlUp = 22;
    m_lvl = 1;
    m_role = role;
    m_name = name;
    m_abilityScores.setStats();
    m_inventory.reset();
    m_inventory.setTarget(this);
}

void Creatures::Player::Playerz::silentSetPlayer(PlayerRole role, std::string_view name)
{
    m_hp = 100;
    m_maxHp = 100;
    m_atk = 10;
    m_maxAtk = 10;
    m_critDmg = 2;
    m_critRate = 10;
    m_def = 10;
    m_maxDef = 10;
    m_xp = 0;
    m_xpForLvlUp = 22;
    m_lvl = 1;
    m_role = role;
    m_name = name;
    m_abilityScores.silentSetStats();
    m_inventory.reset();
    m_inventory.setTarget(this);
}
