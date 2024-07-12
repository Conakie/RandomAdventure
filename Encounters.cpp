
#include <iostream>
#include <string_view>
#include "Print Errors.h"
#include "Encounter Stats.h"
#include "Encounter UID.h"
#include "Set Encounters.h"
#include "Encounters.h"
#include "Playerz.h"
#include "Random.h"
#include "Items.h"
#include "Inventory.h"
#include "Stats.h"



void Encounters::heal(double healing)
{

    std::cout << "The encounter healed of " << healing << "hp.\n";
    if (m_encounter.hp + healing >= m_encounter.maxHp)
    {

        m_encounter.hp = m_encounter.maxHp;

    }
    else
    {

        m_encounter.hp += healing;

    }
    std::cout << "The encounter now has " << m_encounter.hp << "hp.\n";

}

void Encounters::takeDamage(double damage)
{
    m_encounter.hp -= damage;
    m_encounter.isUnderAttack = true;
    m_encounter.canTalk = false;

    if (m_encounter.hp <= 0.00)
    {
        std::cout << "\nThe encounter is dead.\n";
    }
    else
    {
        std::cout << "\nNow the encounter has " << m_encounter.hp << "Hp\n";
    }
}

void Encounters::attack(Playerz& ally) const
{
}

void Encounters::increaseXp(short value)
{

    m_encounter.xp += value;
    lvlUp();

}

void Encounters::setEncounter()
{

    if (m_encounter.hp <= 0.00 || m_encounter.isGone)
    {

        // choose the uid
        setEncountersPerPlace();
        // then set the health and attack
        setStats();
        // to complete everything, set the state of the encounter
        setState();
        // since we want the player to know there is a new encounter we
        introduceEncounter();

    }
    else
    {

    }

}

void Encounters::dropItems()
{

    // amount of items to add
    int quantity{ Random::get(1, 3) };
    int percentage{ Random::get(0, 99) };
    ObjectUid item{ ObjectUid::none };
    // common -> 40%
    // rare -> 30%
    // epic -> 20%
    //legendary -> 10%

    std::cout << "\n";
    if (percentage <= 40)
    {
        // common
        switch (Random::get(0, 1))
        {
        case 0:// small healing potion
            std::cout << "You got " << quantity << " small healing potions.";
            item = ObjectUid::smallHealingPotion;
            break;
        case 1:// herbs
            std::cout << "You got " << quantity << " herbs.";
            item = ObjectUid::herbs;
            break;
        case 2:// bone
            item = ObjectUid::bone;
            std::cout << "You got " << quantity << " bones.";
            break;
        case 3:// meat
            item = ObjectUid::meat;
            std::cout << "You got " << quantity << " steaks.";
            break;
        case 4:// fish
            item = ObjectUid::fish;
            std::cout << "You got " << quantity << " fish.";
            break;
        default:
            PrintError::wrongRandomNumber();
            break;
        }
    }
    else if (percentage > 40 && percentage <= 70)
    {
        // rare
        switch (Random::get(0, 1))
        {
        case 0:// medium healing potion
            std::cout << "You got " << quantity << " medium healing potions.";
            item = ObjectUid::mediumHealingPotion;
            break;
        case 1:// molotov
            std::cout << "You got " << quantity << " molotov.";
            item = ObjectUid::molotov;
            break;
        case 2:// arrow
            std::cout << "You got " << quantity << " arrows.";
            item = ObjectUid::arrow;
            break;
        case 3:// stone
            std::cout << "You got " << quantity << " stone.";
            item = ObjectUid::stone;
            break;
        case 4:// paper
            std::cout << "You got " << quantity << " sheets of papers.";
            item = ObjectUid::paper;
            break;
        default:
            PrintError::wrongRandomNumber();
            break;
        }
    }
    else if (percentage > 70 && percentage <= 90)
    {
        // epic
        switch (Random::get(0, 1))
        {
        case 0:// big healing potion
            std::cout << "You got " << quantity << " big healing potions.";
            item = ObjectUid::bigHealingPotion;
            break;
        case 1:// wood
            std::cout << "You got " << quantity << " wood logs.";
            item = ObjectUid::wood;
            break;
        case 2:// leather
            std::cout << "You got " << quantity << " leather.";
            item = ObjectUid::leather;
            break;
        default:
            PrintError::wrongRandomNumber();
            break;
        }
    }
    else if (percentage > 90)
    {
        // legendary
        switch (Random::get(0, 1))
        {
        case 0:// nuke
            std::cout << "You got " << quantity << " nukes.";
            item = ObjectUid::nuke;
            break;
        case 1:// magic scroll
            std::cout << "You got " << quantity << " magic scroll.";
            item = ObjectUid::magicScroll;
            break;
        default:
            PrintError::wrongRandomNumber();
            break;
        }
    }
    else
    {
        PrintError::wrongRandomNumber();
    }
    
    
    std::cout << "\n";
    player().setInventory().addItem(item, quantity);

}

std::string_view Encounters::getName()
{
    switch (m_encounter.uid)
    {
    case EncounterUid::guard:
        return "Guard";
    case EncounterUid::drunkGuy:
        return "Drunk Guy";
    case EncounterUid::soldier:
        return "Soldier";
    case EncounterUid::torturer:
        return "Torturer";
    case EncounterUid::giant:
        return "Giant";
    case EncounterUid::cleric:
        return "Cleric";
    case EncounterUid::elf:
        return "Elf";
    case EncounterUid::dwarf:
        return "Dwarf";
    case EncounterUid::prisoner:
        return "Prisoner";
    case EncounterUid::theRock:
        return "The Rock";
    case EncounterUid::trader:
        return "Trader";
    case EncounterUid::bartender:
        return "Bartender";
    case EncounterUid::bard:
        return "Bard";
    case EncounterUid::loli:
        return "Loli";
    case EncounterUid::shota:
        return "Shota";
    case EncounterUid::zombie:
        return "Zombie";
    case EncounterUid::skeleton:
        return "Skeletron";
    case EncounterUid::witch:
        return "Witch";
    case EncounterUid::ghost:
        return "Ghost";
    case EncounterUid::theBeer:
        return "The Beer";
    case EncounterUid::yourself:
        return "Yourself";
    case EncounterUid::stoneGolem:
        return "Stone Golem";
    case EncounterUid::blurp:
        return "Blurp";
    case EncounterUid::smallRat:
        return "SmallRat";
    case EncounterUid::rat:
        return "Rat";
    case EncounterUid::giantRat:
        return "Giant Rat";
    case EncounterUid::enormousRat:
        return "Enormous Rat";
    case EncounterUid::colossalRat:
        return "Colossal Rat";
    case EncounterUid::colossalSpider:
        return "Colossal Spider";
    case EncounterUid::ratman:
        return "Ratman";
    case EncounterUid::goblin:
        return "Goblino";
    case EncounterUid::hobgoblin:
        return "Hobgoblin";
    case EncounterUid::orc:
        return "Orc";
    case EncounterUid::kobold:
        return "Kobold";
    case EncounterUid::kockbold:
        return "Kockbold";
    case EncounterUid::cockblin:
        return "Cockblin";
    case EncounterUid::the104:
        return "The 104";
    case EncounterUid::errorGuy:
        return "Error guy";
    case EncounterUid::elesya:
        return "Elesya";
    case EncounterUid::kelmod:
        return "Kelmod";
    case EncounterUid::lenre:
        return "Lenre";
    case EncounterUid::necoto:
        return "Necoto";
    case EncounterUid::kyo:
        return "Kyo";
    case EncounterUid::expN30A:
        return "Experiment number 30A";
    case EncounterUid::expN30B:
        return "Experiment number 30B";
    case EncounterUid::expN30C:
        return "Experiment number 30C";
    case EncounterUid::sila:
        return "Sila";
    case EncounterUid::armNuc:
        return "Arm Nuc";
    case EncounterUid::miiro:
        return "Miiro";
    case EncounterUid::chishao:
        return "Chishao";
    case EncounterUid::none:
        return "Asdrubale";
    default:
        PrintError::notFound();
        break;
    }
    return "Ermenegildo";
}

void Encounters::thinkAndAct()
{
    bool canHealItself{ false };
    bool isPeacefull{ false };

    // check if the encounter can heal itself or is peacefull
    switch (m_encounter.uid)
    {
    case EncounterUid::cleric:
        canHealItself = true;
        isPeacefull = true;
        break;

    case EncounterUid::bard:
        isPeacefull = true;
        break;

    case EncounterUid::bartender:
        isPeacefull = true;
        break;

    case EncounterUid::trader:
        isPeacefull = true;
        break;

    case EncounterUid::yourself:
        canHealItself = true;
        isPeacefull = true;
        break;

    default:
        canHealItself = false;
        isPeacefull = false;
        break;
    }

    // if the encounter is peacefull make it go away next turn
    if (isPeacefull)
    {
        m_encounter.isGone = true;
    }
    else
    {
        
    }
}

void Encounters::resetAllStats()
{
    m_encounter.uid = EncounterUid::none;
    m_encounter.hp = 0;
    m_encounter.maxHp = 0;
    m_encounter.atk = 0;
    m_encounter.maxAtk = 0;
    m_encounter.xp = 0;
    m_encounter.lvlUpXp = 22;
    m_encounter.isGone = false;
    m_encounter.isUnderAttack = false;
    m_encounter.canTalk = true;

}

// under this line there are all the private member functions

void Encounters::lvlUp()
{

    if (m_encounter.lvlUpXp <= m_encounter.xp)
    {

        ++m_encounter.lvl;
        m_encounter.xp = 0;
        m_encounter.lvlUpXp = m_encounter.lvlUpXp * 25 / 100;

        std::cout << "The stats of the next encounters are going to be higher.\n";

    }
    else// nothing happens
    {
        // are you the s in https? Because without you I'm not feeling so secure.
    }

}

void Encounters::setState()
{

    m_encounter.canTalk = true;
    m_encounter.isGone = false;
    m_encounter.isUnderAttack = false;

}

void Encounters::setStats()
{

    switch (m_encounter.uid)
    {
    case EncounterUid::guard:// Guard

        m_encounter.maxHp = 10 * m_encounter.lvl;
        m_encounter.maxAtk = 2.5 + (1.5 * m_encounter.lvl);

        break;

    case EncounterUid::drunkGuy:// Drunk Guy

        m_encounter.maxHp = 8 * m_encounter.lvl;
        m_encounter.maxAtk = 1 + (1 * m_encounter.lvl);

        break;

    case EncounterUid::soldier:// Soldier

        m_encounter.maxHp = 12 * m_encounter.lvl;
        m_encounter.maxAtk = 1.5 + (3.5 * m_encounter.lvl);

        break;

    case EncounterUid::torturer:// Torturer

        m_encounter.maxHp = 10 * m_encounter.lvl;
        m_encounter.maxAtk = 2 + (2 * m_encounter.lvl);

        break;

    case EncounterUid::giant:// Giant

        m_encounter.maxHp = 16.67 * m_encounter.lvl;
        m_encounter.maxAtk = 3 + (1.5 * m_encounter.lvl);

        break;

    case EncounterUid::cleric:// Cleric

        m_encounter.maxHp = 11 * m_encounter.lvl;
        m_encounter.maxAtk = 1 + (0.5 * m_encounter.lvl);

        break;

    case EncounterUid::elf:// Elf

        m_encounter.maxHp = 9 * m_encounter.lvl;
        m_encounter.maxAtk = 1.5 + (2 * m_encounter.lvl);

        break;

    case EncounterUid::dwarf:// Dwarf

        m_encounter.maxHp = 13 * m_encounter.lvl;
        m_encounter.maxAtk = 2 + (2.5 * m_encounter.lvl);

        break;

    case EncounterUid::prisoner:// Prisoner

        m_encounter.maxHp = 9 * m_encounter.lvl;
        m_encounter.maxAtk = 1.5 + (1 * m_encounter.lvl);

        break;

    case EncounterUid::theRock:// The Rock

        m_encounter.maxHp = 10 * m_encounter.lvl;
        m_encounter.maxAtk = 1.5 + (2.5 * m_encounter.lvl);

        break;

    case EncounterUid::trader:// Trader

        m_encounter.maxHp = 10 * m_encounter.lvl;
        m_encounter.maxAtk = 0 + (0.5 * m_encounter.lvl);

        break;

    case EncounterUid::bartender:// Bartender

        m_encounter.maxHp = 10 * m_encounter.lvl;
        m_encounter.maxAtk = 1 + (2 * m_encounter.lvl);

        break;

    case EncounterUid::bard:// Bard

        m_encounter.maxHp = 10 * m_encounter.lvl;
        m_encounter.maxAtk = 1 + (1 * m_encounter.lvl);

        break;

    case EncounterUid::loli:// Loli

        m_encounter.maxHp = 6 * m_encounter.lvl;
        m_encounter.maxAtk = 1 + (3.75 * m_encounter.lvl);

        break;

    case EncounterUid::shota:// Shota

        m_encounter.maxHp = 20 * m_encounter.lvl;
        m_encounter.maxAtk = 1 + (1.75 * m_encounter.lvl);

        break;

    case EncounterUid::zombie:// Zombie

        m_encounter.maxHp = 12 * m_encounter.lvl;
        m_encounter.maxAtk = 2 + (1.5 * m_encounter.lvl);

        break;

    case EncounterUid::skeleton:// Skeleton

        m_encounter.maxHp = 11 * m_encounter.lvl;
        m_encounter.maxAtk = 1 + (1.25 * m_encounter.lvl);

        break;

    case EncounterUid::witch:// Witch

        m_encounter.maxHp = 8 * m_encounter.lvl;
        m_encounter.maxAtk = 1 + (3 * m_encounter.lvl);

        break;

    case EncounterUid::ghost:// Ghost

        m_encounter.maxHp = 7 * m_encounter.lvl;
        m_encounter.maxAtk = 1 + (1 * m_encounter.lvl);

        break;

    case EncounterUid::theBeer:// The Beer

        m_encounter.maxHp = 0.69 * m_encounter.lvl;
        m_encounter.maxAtk = 0.01 + (0 * m_encounter.lvl);

        break;

    case EncounterUid::yourself:// Yourself

        m_encounter.maxHp = 10 * m_encounter.lvl;
        m_encounter.maxAtk = 3 + (1.5 * m_encounter.lvl);

        break;

    case EncounterUid::stoneGolem:// Stone Golem

        m_encounter.maxHp = 25 * m_encounter.lvl;
        m_encounter.maxAtk = 0.5 + (0.5 * m_encounter.lvl);

        break;

    case EncounterUid::blurp:// Stone Golem

        m_encounter.maxHp = 3 * m_encounter.lvl;
        m_encounter.maxAtk = 2 + (3 * m_encounter.lvl);

        break;

    case EncounterUid::smallRat:// Small rat

        m_encounter.maxHp = 2 * m_encounter.lvl;
        m_encounter.maxAtk = 0.2 + (0.1 * m_encounter.lvl);

        break;

    case EncounterUid::rat://Rat

        m_encounter.maxHp = 3 * m_encounter.lvl;
        m_encounter.maxAtk = 0.5 + (0.5 * m_encounter.lvl);

        break;

    case EncounterUid::giantRat:// Giant rat

        m_encounter.maxHp = 5.5 * m_encounter.lvl;
        m_encounter.maxAtk = 1 + (0.9 * m_encounter.lvl);

        break;

    case EncounterUid::enormousRat:// Enormous rat

        m_encounter.maxHp = 7 * m_encounter.lvl;
        m_encounter.maxAtk = 2 + (1.9 * m_encounter.lvl);

        break;

    case EncounterUid::colossalRat:// Colossal rat

        m_encounter.maxHp = 7.5 * m_encounter.lvl;
        m_encounter.maxAtk = 3 + (1.5 * m_encounter.lvl);

        break;

    case EncounterUid::colossalSpider:// Colossal spider

        m_encounter.maxHp = 8 * m_encounter.lvl;
        m_encounter.maxAtk = 2 + (1.05 * m_encounter.lvl);

        break;

    case EncounterUid::ratman:// Ratman

        m_encounter.maxHp = 11 * m_encounter.lvl;
        m_encounter.maxAtk = 1 + (0.5 * m_encounter.lvl);

        break;

    case EncounterUid::goblin:// Goblin

        m_encounter.maxHp = 6.5 * m_encounter.lvl;
        m_encounter.maxAtk = 1 + (1 * m_encounter.lvl);

        break;

    case EncounterUid::hobgoblin:// Hobgoblin

        m_encounter.maxHp = 8.5 * m_encounter.lvl;
        m_encounter.maxAtk = 1.5 + (1.5 * m_encounter.lvl);

        break;

    case EncounterUid::orc:// Orc

        m_encounter.maxHp = 11 * m_encounter.lvl;
        m_encounter.maxAtk = 2.25 + (2.25 * m_encounter.lvl);

        break;

    case EncounterUid::kobold:// Kobold

        m_encounter.maxHp = 6 * m_encounter.lvl;
        m_encounter.maxAtk = 1 + (1 * m_encounter.lvl);

        break;

    case EncounterUid::kockbold:// Kockbold

        m_encounter.maxHp = 5.65 * m_encounter.lvl;
        m_encounter.maxAtk = 0.5 + (1 * m_encounter.lvl);

        break;

    case EncounterUid::cockblin:// Cockblin

        m_encounter.maxHp = 5.65 * m_encounter.lvl;
        m_encounter.maxAtk = 0.5 + (1 * m_encounter.lvl);

        break;

    case EncounterUid::the104:// 104

        m_encounter.maxHp = 26 * m_encounter.lvl;
        m_encounter.maxAtk = 0 + (0.7 * m_encounter.lvl);

        break;

    case EncounterUid::errorGuy:// error guy

        m_encounter.maxHp = 0.01 * m_encounter.lvl;
        m_encounter.maxAtk = 0.1 + (0.1 * m_encounter.lvl);

        break;

    case EncounterUid::elesya://Elesya

        m_encounter.maxHp = 0 * m_encounter.lvl;
        m_encounter.maxAtk = 0 + (0 * m_encounter.lvl);

        break;

    case EncounterUid::kelmod:// Kelmod

        m_encounter.maxHp = 0 * m_encounter.lvl;
        m_encounter.maxAtk = 0 + (0 * m_encounter.lvl);

        break;

    case EncounterUid::lenre:// Lenre

        m_encounter.maxHp = 0 * m_encounter.lvl;
        m_encounter.maxAtk = 0 + (0 * m_encounter.lvl);

        break;

    case EncounterUid::necoto:// Necoto

        m_encounter.maxHp = 0 * m_encounter.lvl;
        m_encounter.maxAtk = 0 + (0 * m_encounter.lvl);

        break;

    case EncounterUid::kyo:// Kyo

        m_encounter.maxHp = 0 * m_encounter.lvl;
        m_encounter.maxAtk = 0 + (0 * m_encounter.lvl);

        break;

    case EncounterUid::expN30A:// Exp. N. 30A

        m_encounter.maxHp = 45;
        m_encounter.maxAtk = 6;

        break;

    case EncounterUid::expN30B:// Exp. N. 30B

        m_encounter.maxHp = 60;
        m_encounter.maxAtk = 8;

        break;

    case EncounterUid::expN30C:// Exp. N. 30C

        m_encounter.maxHp = 30;
        m_encounter.maxAtk = 4;

        break;

    case EncounterUid::sila:// Sila

        m_encounter.maxHp = 70;
        m_encounter.maxAtk = 10;

        break;

    case EncounterUid::armNuc:// Arm Nuc

        m_encounter.maxHp = 80;
        m_encounter.maxAtk = 11;

        break;

    case EncounterUid::miiro:// Miiro

        m_encounter.maxHp = 101;
        m_encounter.maxAtk = 14;

        break;

    case EncounterUid::chishao:// Chishao

        m_encounter.maxHp = 101;
        m_encounter.maxAtk = 14;

        break;

    default://Not found

        PrintError::notFound();

        break;
    }

    m_encounter.hp = m_encounter.maxHp;
    m_encounter.atk = m_encounter.maxAtk;

}

void Encounters::introduceEncounter()
{

    std::cout << "\n\n\n";

    switch (m_encounter.uid)
    {
    case EncounterUid::guard:// Guard

        std::cout << "You found a guard!";

        break;

    case EncounterUid::drunkGuy:// Drunk Guy

        std::cout << "There is a drunk guy near you!";

        break;

    case EncounterUid::soldier:// Soldier

        std::cout << "There is a Flasail Soldier in front of you.";

        break;

    case EncounterUid::torturer:// Torturer

        std::cout << "A torturer goes in your direction.";

        break;

    case EncounterUid::giant:// Giant

        std::cout << "There is a giant and he doesn't look friendly.";

        break;

    case EncounterUid::cleric:// Cleric

        std::cout << "You found a Cleric of Miiro!";

        break;

    case EncounterUid::elf:// Elf

        std::cout << "There is lonely elf.";

        break;

    case EncounterUid::dwarf:// Dwarf

        std::cout << "You found a Dwarf of Osloba";

        break;

    case EncounterUid::prisoner:// Prisoner

        std::cout << "There is a prisoner walking with some chains.";

        break;

    case EncounterUid::theRock:// The Rock

        std::cout << "The Cock... No, The Rock is walking.";

        break;

    case EncounterUid::trader:// Trader

        std::cout << "You have found a trader. Not the wandering trader of minecraft.";

        break;

    case EncounterUid::bartender:// Bartender

        std::cout << "Why is there a bartender here in the middle of the forest?";

        break;

    case EncounterUid::bard:// Bard

        std::cout << "There is a bard writing something.";

        break;

    case EncounterUid::loli:// Loli

        std::cout << "THERE IS A LOLI! PUT HER IN THE NUCLEAR REACTOR!";

        break;

    case EncounterUid::shota:// Shota

        std::cout << "A shota? Who cares? Not me.";

        break;

    case EncounterUid::zombie:// Zombie

        std::cout << "There is a Zombie!(Not the ones of Gakkou Gurashi!)";

        break;

    case EncounterUid::skeleton:// Skeleton

        std::cout << "There is a bone man(skeleton) in front of you.";

        break;

    case EncounterUid::witch:// Witch

        std::cout << "There is a witch. You may try to burn her.";

        break;

    case EncounterUid::ghost:// Ghost

        std::cout << "There is a ghost of a human.";

        break;

    case EncounterUid::theBeer:// The Beer

        std::cout << "You have found a beer stein full of beer!";

        break;

    case EncounterUid::yourself:// Yourself

        std::cout << "You have found yourself!";

        break;

    case EncounterUid::stoneGolem:// Stone Golem

        std::cout << "Is that a stone man? Nope, it's a stone golem.";

        break;

    case EncounterUid::blurp:

        std::cout << "Ohh! A slime called Blurp is in front of you!";

        break;

    case EncounterUid::smallRat:// Small rat

        std::cout << "Oh no there is a small rat!";

        break;

    case EncounterUid::rat://Rat

        std::cout << "Oh no, a rat!";

        break;

    case EncounterUid::giantRat:// Giant rat

        std::cout << "Run, a giant rat!";

        break;

    case EncounterUid::enormousRat:// Enormous rat

        std::cout << "Good luck with this Enormous Rat.";

        break;

    case EncounterUid::colossalRat:// Colossal rat

        std::cout << "You found the colossal rat! He is the boss of rats!";

        break;

    case EncounterUid::colossalSpider:// Colossal spider

        std::cout << "Colossal spider! Kill it pleaseee.";

        break;

    case EncounterUid::ratman:// Ratman

        std::cout << "You have just witnessed the rise of Ratman.";

        break;

    case EncounterUid::goblin:// Goblin

        std::cout << "A goblin for ya!";

        break;

    case EncounterUid::hobgoblin:// Hobgoblin

        std::cout << "Ohh, an hobgoblin! How interesting.";

        break;

    case EncounterUid::orc:// Orc

        std::cout << "You found an orc. Not an or gate.";

        break;

    case EncounterUid::kobold:// Kobold

        std::cout << "Do you hate this kobold? Because I do.";

        break;

    case EncounterUid::kockbold:// Kockbold

        std::cout << "KOCKBOLD! RUN AWAY OR YOU'LL BE GAY!";

        break;

    case EncounterUid::cockblin:// Cockblin

        std::cout << "Why a cockblin? You'll have to kill it, sorry.";

        break;

    case EncounterUid::the104:// 104

        std::cout << "You now have the 104 after you!";

        break;

    case EncounterUid::errorGuy:// error guy

        std::cout << "You found the OP Error Guy. Send a screen shot to Nanre!";

        break;

    case EncounterUid::elesya://Elesya

        std::cout << "Elesya: \"Why are you attacking me?!\"";

        break;

    case EncounterUid::kelmod:// Kelmod

        std::cout << "Kelmod:\" I'm not an enemy. I'm here for maintenance.\"";

        break;

    case EncounterUid::lenre:// Lenre

        std::cout << "Lenre:\" Adios.\"";

        break;

    case EncounterUid::necoto:// Necoto



        break;

    case EncounterUid::kyo:// Kyo

        std::cout << "Kyo:\" Hello and bye.\"";

        break;

    case EncounterUid::expN30A:// Exp. N. 30A

        std::cout << "You found an elf sitting on the ground reading a book.";

        break;

    case EncounterUid::expN30B:// Exp. N. 30B

        std::cout << "You found an elf. She is loocking at a piece of wood.";

        break;

    case EncounterUid::expN30C:// Exp. N. 30C

        std::cout << "You found an elf looking around for something or someone.";

        break;

    case EncounterUid::sila:// Sila

        std::cout << "You found Sila walking on a pathway.";

        break;

    case EncounterUid::armNuc:// Arm Nuc

        std::cout << "Uhh, a human? No, wait, it's a robot!";

        break;

    case EncounterUid::miiro:// Miiro

        std::cout << "There is a girl with cat ears lying on the ground.";

        break;

    case EncounterUid::chishao:// Chishao

        std::cout << "There is a girl with rabbit ears looking at you.";

        break;

    default://Not found

        PrintError::notFound();

        break;
    }

    std::cout << "\n\n";

}