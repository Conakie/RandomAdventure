
#include <iostream>
#include "Playerz.h"
#include "Print Errors.h"
#include "Player Stats.h"
#include "PlayerBase.h"
#include "Inventory.h"
#include "Object UID.h"
#include "Items.h"
#include "Inventory.h"
#include "Costants.h"
#include "Random.h"
#include "GetEncounterTypePerPlace.h"
#include "Place.h"
#include "Encounterz.h"
#include "Talk To Encounters English.h"



void Creatures::Encounter::Encounterz::heal(double healing)
{
    if ((hp + healing) >= maxHp)
    {
        std::cout << name << " is back at full health (" << hp << " hp).\n";
        hp = maxHp;
    }
    else
    {
        std::cout << name << " healed of " << healing << " hp.\n"
            << "Now " << name << " has " << hp << " hp.\n";
        hp += healing;
    }
}

void Creatures::Encounter::Encounterz::takeDamage(double damage)
{
    hp -= damage;
    if (isAlive())
    {
        std::cout << name << " has " << hp << " hp now.\n";
        m_isUnderAttack = true;
    }
    else
    {
        std::cout << name << " is dead.\n";
        dropItems();
    }
}

void Creatures::Encounter::Encounterz::attack(Creatures::Player::Playerz& player)
{
    std::cout << name << " attacks " << player.getName() << " and did " << (atk) << " dmg.\n";
    player.takeDamage(atk);
}

void Creatures::Encounter::Encounterz::talk()
{
    if (m_canTalk && !(m_isUnderAttack))
    {
        talkToEncounters(encounterType);
    }
    else
    {
        if (m_isUnderAttack)
        {
            std::cout << "Kelmod: \"" << name << " refuses to talk after you attacked it.\"\n";
        }
        else
        {
            std::cout << "Kelmod: \"You have already talked.\n";
        }
    }
}

void Creatures::Encounter::Encounterz::dropItems() const
{
    // if no player has been set return early
    if (!m_player)
    {
        std::cout << name << " didn't have any items to drop.\n";
        return;
    }
    ObjectUid item{ ObjectUid::none };
    int percentage{ Random::get(0,99) };
    int quantity{ Random::get(1, 3) };
    Player::Playerz& player{ *m_player };
    // common -> 40%
    // rare -> 30%
    // epic -> 20%
    //legendary -> 10%

    if (percentage < 40)
    {// the drop is a common item
        switch (Random::get(0, 4))
        {
        case 0:// small healing potion
            std::cout << "You got " << quantity << " small healing potions.";
            player.setInventory().addItem(ObjectUid::smallHealingPotion, quantity);
            break;
        case 1:// herbs
            std::cout << "You got " << quantity << " herbs.";
            player.setInventory().addItem(ObjectUid::herbs, quantity);
            break;
        case 2:// bone
            item = ObjectUid::bone;
            std::cout << "You got " << quantity << " bones.";
            player.setInventory().addItem(ObjectUid::bone, quantity);
            break;
        case 3:// meat
            std::cout << "You got " << quantity << " steaks.";
            player.setInventory().addItem(ObjectUid::meat, quantity);
            break;
        case 4:// fish
            std::cout << "You got " << quantity << " fish.";
            player.setInventory().addItem(ObjectUid::fish, quantity);
            break;
        default:
            PrintError::wrongRandomNumber();
            break;
        }
    }
    else if (percentage >= 40 && percentage < 70)
    {// the drop is a rare item
        switch (Random::get(0, 4))
        {
        case 0:// medium healing potion
            std::cout << "You got " << quantity << " medium healing potions.";
            player.setInventory().addItem(ObjectUid::mediumHealingPotion, quantity);
            break;
        case 1:// molotov
            std::cout << "You got " << quantity << " molotov.";
            player.setInventory().addItem(ObjectUid::molotov, quantity);
            break;
        case 2:// arrow
            std::cout << "You got " << quantity << " arrows.";
            player.setInventory().addItem(ObjectUid::arrow, quantity);
            break;
        case 3:// stone
            std::cout << "You got " << quantity << " stone.";
            player.setInventory().addItem(ObjectUid::stone, quantity);
            break;
        case 4:// paper
            std::cout << "You got " << quantity << " sheets of papers.";
            player.setInventory().addItem(ObjectUid::paper, quantity);
            break;
        default:
            PrintError::wrongRandomNumber();
            break;
        }
    }
    else if (percentage >= 70 && percentage < 90)
    {// the drop is a epic item
        switch (Random::get(0, 2))
        {
        case 0:// big healing potion
            std::cout << "You got " << quantity << " big healing potions.";
            player.setInventory().addItem(ObjectUid::bigHealingPotion, quantity);
            break;
        case 1:// wood
            std::cout << "You got " << quantity << " wood logs.";
            player.setInventory().addItem(ObjectUid::wood, quantity);
            break;
        case 2:// leather
            std::cout << "You got " << quantity << " leather.";
            player.setInventory().addItem(ObjectUid::leather, quantity);
            break;
        default:
            PrintError::wrongRandomNumber();
            break;
        }
    }
    else if (percentage <= 90)
    {// the drop is a legendary item
        switch (Random::get(0, 1))
        {
        case 0:// nuke
            std::cout << "You got " << quantity << " nukes.";
            player.setInventory().addItem(ObjectUid::nuke, quantity);
            break;
        case 1:// magic scroll
            std::cout << "You got " << quantity << " magic scroll.";
            player.setInventory().addItem(ObjectUid::magicScroll, quantity);
            break;
        default:
            PrintError::wrongRandomNumber();
            break;
        }
    }
    else
        std::cout << name << " didn't drop any item.";
    std::cout << '\n';
}
/*
void Creatures::Encounter::Encounterz::dropItems(Inventoryz* inventory) const
{
    // if no player has been set return early
    if (!m_player)
    {
        std::cout << name << " didn't have any items to drop.\n";
        return;
    }
    ObjectUid item{ ObjectUid::none };
    int percentage{ Random::get(0,99) };
    int quantity{ Random::get(1, 3) };
    Player::Playerz& player{ *m_player };
    // common -> 40%
    // rare -> 30%
    // epic -> 20%
    //legendary -> 10%

    if (percentage < 40)
    {// the drop is a common item
        switch (Random::get(0, 4))
        {
        case 0:// small healing potion
            std::cout << "You got " << quantity << " small healing potions.";
            player.setInventory().addItem(ObjectUid::smallHealingPotion, quantity);
            break;
        case 1:// herbs
            std::cout << "You got " << quantity << " herbs.";
            player.setInventory().addItem(ObjectUid::herbs, quantity);
            break;
        case 2:// bone
            item = ObjectUid::bone;
            std::cout << "You got " << quantity << " bones.";
            player.setInventory().addItem(ObjectUid::bone, quantity);
            break;
        case 3:// meat
            std::cout << "You got " << quantity << " steaks.";
            player.setInventory().addItem(ObjectUid::meat, quantity);
            break;
        case 4:// fish
            std::cout << "You got " << quantity << " fish.";
            player.setInventory().addItem(ObjectUid::fish, quantity);
            break;
        default:
            PrintError::wrongRandomNumber();
            break;
        }
    }
    else if (percentage >= 40 && percentage < 70)
    {// the drop is a rare item
        switch (Random::get(0, 4))
        {
        case 0:// medium healing potion
            std::cout << "You got " << quantity << " medium healing potions.";
            player.setInventory().addItem(ObjectUid::mediumHealingPotion, quantity);
            break;
        case 1:// molotov
            std::cout << "You got " << quantity << " molotov.";
            player.setInventory().addItem(ObjectUid::molotov, quantity);
            break;
        case 2:// arrow
            std::cout << "You got " << quantity << " arrows.";
            player.setInventory().addItem(ObjectUid::arrow, quantity);
            break;
        case 3:// stone
            std::cout << "You got " << quantity << " stone.";
            player.setInventory().addItem(ObjectUid::stone, quantity);
            break;
        case 4:// paper
            std::cout << "You got " << quantity << " sheets of papers.";
            player.setInventory().addItem(ObjectUid::paper, quantity);
            break;
        default:
            PrintError::wrongRandomNumber();
            break;
        }
    }
    else if (percentage >= 70 && percentage < 90)
    {// the drop is a epic item
        switch (Random::get(0, 2))
        {
        case 0:// big healing potion
            std::cout << "You got " << quantity << " big healing potions.";
            player.setInventory().addItem(ObjectUid::bigHealingPotion, quantity);
            break;
        case 1:// wood
            std::cout << "You got " << quantity << " wood logs.";
            player.setInventory().addItem(ObjectUid::wood, quantity);
            break;
        case 2:// leather
            std::cout << "You got " << quantity << " leather.";
            player.setInventory().addItem(ObjectUid::leather, quantity);
            break;
        default:
            PrintError::wrongRandomNumber();
            break;
        }
    }
    else if (percentage <= 90)
    {// the drop is a legendary item
        switch (Random::get(0, 1))
        {
        case 0:// nuke
            std::cout << "You got " << quantity << " nukes.";
            player.setInventory().addItem(ObjectUid::nuke, quantity);
            break;
        case 1:// magic scroll
            std::cout << "You got " << quantity << " magic scroll.";
            player.setInventory().addItem(ObjectUid::magicScroll, quantity);
            break;
        default:
            PrintError::wrongRandomNumber();
            break;
        }
    }
    else
        std::cout << name << " didn't drop any item.";
    std::cout << '\n';
}
*/
void Creatures::Encounter::Encounterz::thinkAndAct()
{
    if (m_isUnderAttack && isAlive() && !m_isGone)
    {
        if (m_player)
            attack(*m_player);
        else
            heal(1);
    }
    else if (m_isGone)
    {
        dropItems();
    }
    else
    {
        std::cout << "Kelmod: \"" << name << " is waiting...\"\n";
    }
}

void Creatures::Encounter::Encounterz::printStats() const
{
    std::cout << name << " stats:\n"
        << "Hp: "               << hp       << '\n'
        << "Max Hp: "           << maxHp    << '\n'
        << "Atk: "              << atk      << '\n'
        << "Max Atk: "          << maxAtk   << '\n'
        << "Def: "              << def      << '\n'
        << "Max Def: "          << maxDef   << '\n'
        << "Crit Rate: "        << critRate << '\n'
        << "Crit Dmg: "         << critDmg  << '\n'
        << "Xp: "               << xp       << '\n'
        << "Xp for lvl up: "    << xpPerLvl << '\n'
        << "Lvl: "              << lvl      << '\n';
}

void Creatures::Encounter::Encounterz::resetStats()
{
    name = "Ermenegildo";
    hp = 0;
    maxHp = 0;
    atk = 0;
    maxAtk = 0;
    critDmg = 0;
    critRate = 0;
    def = 0;
    maxDef = 0;
    xp = 0;
    xpPerLvl = 0;
    lvl = 1;
    m_isGone = false;
    m_isUnderAttack = false;
    m_canTalk = true;
    encounterType = EncounterType::none;
}

void Creatures::Encounter::Encounterz::setPlayer(Creatures::Player::Playerz* player)
{
    m_player = player;
}

void Creatures::Encounter::Encounterz::setEncounter()
{
    setStats();
    setState();
    setName();
    announceEncounter();
}

void Creatures::Encounter::Encounterz::announceEncounter() const
{
    std::cout << "\n\n\n";
    switch (encounterType)
    {
    case EncounterType::guard:// Guard
        std::cout << "You found a guard!";
        break;

    case EncounterType::drunkGuy:// Drunk Guy
        std::cout << "There is a drunk guy near you!";
        break;

    case EncounterType::soldier:// Soldier
        std::cout << "There is a Flasail Soldier in front of you.";
        break;

    case EncounterType::torturer:// Torturer
        std::cout << "A torturer goes in your direction.";
        break;

    case EncounterType::giant:// Giant
        std::cout << "There is a giant and he doesn't look friendly.";
        break;

    case EncounterType::cleric:// Cleric
        std::cout << "You found a Cleric of Miiro!";
        break;

    case EncounterType::elf:// Elf

        std::cout << "There is lonely elf.";

        break;

    case EncounterType::dwarf:// Dwarf

        std::cout << "You found a Dwarf of Osloba";

        break;

    case EncounterType::prisoner:// Prisoner

        std::cout << "There is a prisoner walking with some chains.";

        break;

    case EncounterType::theRock:// The Rock

        std::cout << "The Cock... No, The Rock is walking.";

        break;

    case EncounterType::trader:// Trader

        std::cout << "You have found a trader. Not the wandering trader of minecraft.";

        break;

    case EncounterType::bartender:// Bartender

        std::cout << "Why is there a bartender here in the middle of the forest?";

        break;

    case EncounterType::bard:// Bard

        std::cout << "There is a bard writing something.";

        break;

    case EncounterType::loli:// Loli

        std::cout << "THERE IS A LOLI! PUT HER IN THE NUCLEAR REACTOR!";

        break;

    case EncounterType::shota:// Shota

        std::cout << "A shota? Who cares? Not me.";

        break;

    case EncounterType::zombie:// Zombie

        std::cout << "There is a Zombie!(Not the ones of Gakkou Gurashi!)";

        break;

    case EncounterType::skeleton:// Skeleton

        std::cout << "There is a bone man(skeleton) in front of you.";

        break;

    case EncounterType::witch:// Witch

        std::cout << "There is a witch. You may try to burn her.";

        break;

    case EncounterType::ghost:// Ghost

        std::cout << "There is a ghost of a human.";

        break;

    case EncounterType::theBeer:// The Beer

        std::cout << "You have found a beer stein full of beer!";

        break;

    case EncounterType::yourself:// Yourself

        std::cout << "You have found yourself!";

        break;

    case EncounterType::stoneGolem:// Stone Golem

        std::cout << "Is that a stone man? Nope, it's a stone golem.";

        break;

    case EncounterType::blurp:

        std::cout << "Ohh! A slime called Blurp is in front of you!";

        break;

    case EncounterType::smallRat:// Small rat

        std::cout << "Oh no there is a small rat!";

        break;

    case EncounterType::rat://Rat

        std::cout << "Oh no, a rat!";

        break;

    case EncounterType::giantRat:// Giant rat

        std::cout << "Run, a giant rat!";

        break;

    case EncounterType::enormousRat:// Enormous rat

        std::cout << "Good luck with this Enormous Rat.";

        break;

    case EncounterType::colossalRat:// Colossal rat

        std::cout << "You found the colossal rat! He is the boss of rats!";

        break;

    case EncounterType::colossalSpider:// Colossal spider

        std::cout << "Colossal spider! Kill it pleaseee.";

        break;

    case EncounterType::ratman:// Ratman

        std::cout << "You have just witnessed the rise of Ratman.";

        break;

    case EncounterType::goblin:// Goblin

        std::cout << "A goblin for ya!";

        break;

    case EncounterType::hobgoblin:// Hobgoblin

        std::cout << "Ohh, an hobgoblin! How interesting.";

        break;

    case EncounterType::orc:// Orc

        std::cout << "You found an orc. Not an or gate.";

        break;

    case EncounterType::kobold:// Kobold

        std::cout << "Do you hate this kobold? Because I do.";

        break;

    case EncounterType::kockbold:// Kockbold

        std::cout << "KOCKBOLD! RUN AWAY OR YOU'LL BE GAY!";

        break;

    case EncounterType::cockblin:// Cockblin

        std::cout << "Why a cockblin? You'll have to kill it, sorry.";

        break;

    case EncounterType::the104:// 104

        std::cout << "You now have the 104 after you!";

        break;

    case EncounterType::errorGuy:// error guy

        std::cout << "You found the OP Error Guy. Send a screen shot to Nanre!";

        break;

    case EncounterType::elesya://Elesya

        std::cout << "Elesya: \"Why are you attacking me?!\"";

        break;

    case EncounterType::kelmod:// Kelmod

        std::cout << "Kelmod:\" I'm not an enemy. I'm here for maintenance.\"";

        break;

    case EncounterType::lenre:// Lenre

        std::cout << "Lenre:\" Adios.\"";

        break;

    case EncounterType::necoto:// Necoto



        break;

    case EncounterType::kyo:// Kyo

        std::cout << "Kyo:\" Hello and bye.\"";

        break;

    case EncounterType::expN30A:// Exp. N. 30A

        std::cout << "You found an elf sitting on the ground reading a book.";

        break;

    case EncounterType::expN30B:// Exp. N. 30B

        std::cout << "You found an elf. She is loocking at a piece of wood.";

        break;

    case EncounterType::expN30C:// Exp. N. 30C

        std::cout << "You found an elf looking around for something or someone.";

        break;

    case EncounterType::sila:// Sila

        std::cout << "You found Sila walking on a pathway.";

        break;

    case EncounterType::armNuc:// Arm Nuc

        std::cout << "Uhh, a human? No, wait, it's a robot!";

        break;

    case EncounterType::miiro:// Miiro

        std::cout << "There is a girl with cat ears lying on the ground.";

        break;

    case EncounterType::chishao:// Chishao

        std::cout << "There is a girl with rabbit ears looking at you.";

        break;

    default://Not found

        PrintError::notFound();

        break;
    }
    std::cout << "\n\n\n";
}

void Creatures::Encounter::Encounterz::setName()
{
    switch (encounterType)
    {
    case EncounterType::guard:
        name = "Guard";
        break;
    case EncounterType::drunkGuy:
        name = "Drunk Guy";
        break;
    case EncounterType::soldier:
        name = "Soldier";
        break;
    case EncounterType::torturer:
        name = "Torturer";
        break;
    case EncounterType::giant:
        name = "Giant";
        break;
    case EncounterType::cleric:
        name = "Cleric";
        break;
    case EncounterType::elf:
        name = "Elf";
        break;
    case EncounterType::dwarf:
        name = "Dwarf";
        break;
    case EncounterType::prisoner:
        name = "Prisoner";
        break;
    case EncounterType::theRock:
        name = "The Rock";
        break;
    case EncounterType::trader:
        name = "Trader";
        break;
    case EncounterType::bartender:
        name = "Bartender";
        break;
    case EncounterType::bard:
        name = "Bard";
        break;
    case EncounterType::loli:
        name = "Loli";
        break;
    case EncounterType::shota:
        name = "Shota";
        break;
    case EncounterType::zombie:
        name = "Zombie";
        break;
    case EncounterType::skeleton:
        name = "Skeletron";
        break;
    case EncounterType::witch:
        name = "Witch";
        break;
    case EncounterType::ghost:
        name = "Ghost";
        break;
    case EncounterType::theBeer:
        name = "The Beer";
        break;
    case EncounterType::yourself:
        name = "Yourself";
        break;
    case EncounterType::stoneGolem:
        name = "Stone Golem";
        break;
    case EncounterType::blurp:
        name = "Blurp";
        break;
    case EncounterType::smallRat:
        name = "SmallRat";
        break;
    case EncounterType::rat:
        name = "Rat";
        break;
    case EncounterType::giantRat:
        name = "Giant Rat";
        break;
    case EncounterType::enormousRat:
        name = "Enormous Rat";
        break;
    case EncounterType::colossalRat:
        name = "Colossal Rat";
        break;
    case EncounterType::colossalSpider:
        name = "Colossal Spider";
        break;
    case EncounterType::ratman:
        name = "Ratman";
        break;
    case EncounterType::goblin:
        name = "Goblino";
        break;
    case EncounterType::hobgoblin:
        name = "Hobgoblin";
        break;
    case EncounterType::orc:
        name = "Orc";
        break;
    case EncounterType::kobold:
        name = "Kobold";
        break;
    case EncounterType::kockbold:
        name = "Kockbold";
        break;
    case EncounterType::cockblin:
        name = "Cockblin";
        break;
    case EncounterType::the104:
        name = "The 104";
        break;
    case EncounterType::errorGuy:
        name = "Error guy";
        break;
    case EncounterType::elesya:
        name = "Elesya";
        break;
    case EncounterType::kelmod:
        name = "Kelmod";
        break;
    case EncounterType::lenre:
        name = "Lenre";
        break;
    case EncounterType::necoto:
        name = "Necoto";
        break;
    case EncounterType::kyo:
        name = "Kyo";
        break;
    case EncounterType::expN30A:
        name = "Experiment number 30A";
        break;
    case EncounterType::expN30B:
        name = "Experiment number 30B";
        break;
    case EncounterType::expN30C:
        name = "Experiment number 30C";
        break;
    case EncounterType::sila:
        name = "Sila";
        break;
    case EncounterType::armNuc:
        name = "Arm Nuc";
        break;
    case EncounterType::miiro:
        name = "Miiro";
        break;
    case EncounterType::chishao:
        name = "Chishao";
        break;
    case EncounterType::none:
        name = "Asdrubale";
        break;
    default:
        name = "Ermenegildo";
        break;
    }
}

void Creatures::Encounter::Encounterz::setStats()
{
    switch (encounterType)
    {
    case EncounterType::guard:
        maxHp = 10;
        maxAtk = 2.5 + (1.5 * lvl);
        maxDef = 5;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::drunkGuy:
        maxHp = 8;
        maxAtk = 1 + (1 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::soldier:
        maxHp = 12 * lvl;
        maxAtk = 1.5 + (3.5 * lvl);
        maxDef = 10;
        critRate = 0;
        critDmg = 0;
        xp = 4;
        break;
    case EncounterType::torturer:
        maxHp = 10 * lvl;
        maxAtk = 2 + (2 * lvl);
        maxDef = 5;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::giant:
        maxHp = 16.67 * lvl;
        maxAtk = 3 + (1.5 * lvl);
        maxDef = 10;
        critRate = 0;
        critDmg = 0;
        xp = 3;
        break;
    case EncounterType::cleric:
        maxHp = 11 * lvl;
        maxAtk = 1 + (0.5 * lvl);
        maxDef = 1;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::elf:
        maxHp = 9 * lvl;
        maxAtk = 2 + (2 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 2;
        break;
    case EncounterType::dwarf:
        maxHp = 13 * lvl;
        maxAtk = 1.5 + (2.5 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 2;
        break;
    case EncounterType::prisoner:
        maxHp = 9 * lvl;
        maxAtk = 2 + (1 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::theRock:
        maxHp = 5;
        maxAtk = 1.5 + (2.5 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 3;
        break;
    case EncounterType::trader:
        maxHp = 10;
        maxAtk = 0 + (0 * lvl);
        maxDef = -60;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::bartender:
        maxHp = 10;
        maxAtk = 1 + (2 * lvl);
        maxDef = -60;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::bard:
        maxHp = 10;
        maxAtk = 1 + (1 * lvl);
        maxDef = -60;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::loli:
        maxHp = 6 * lvl;
        maxAtk = 1 + (3.75 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 2;
        break;
    case EncounterType::shota:
        maxHp = 20 * lvl;
        maxAtk = 1 + (1.75 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 2;
        break;
    case EncounterType::zombie:
        maxHp = 12 * lvl;
        maxAtk = 2 + (1.5 * lvl);
        maxDef = 5;
        critRate = 0;
        critDmg = 0;
        xp = 2;
        break;
    case EncounterType::skeleton:
        maxHp = 11 * lvl;
        maxAtk = 1 + (1.25 * lvl);
        maxDef = 4;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::witch:
        maxHp = 8 * lvl;
        maxAtk = 1 + (3 * lvl);
        maxDef = -1;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::ghost:
        maxHp = 7 * lvl;
        maxAtk = 1 + (1 * lvl);
        maxDef = 10;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::theBeer:
        maxHp = 0.69 * lvl;
        maxAtk = 0.01 + (0 * lvl);
        maxDef = -1000;
        critRate = 0;
        critDmg = 0;
        xp = 5;
        break;
    case EncounterType::yourself:
        maxHp = 10 * lvl;
        maxAtk = 3 + (1.5 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 4;
        break;
    case EncounterType::stoneGolem:
        maxHp = 25 * lvl;
        maxAtk = 0.5 + (0.5 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 3;
        break;
    case EncounterType::blurp:
        maxHp = 3 * lvl;
        maxAtk = 2 + (3 * lvl);
        maxDef = 1;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::smallRat:
        maxHp = 2 * lvl;
        maxAtk = 0.2 + (0.1 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::rat:
        maxHp = 3 * lvl;
        maxAtk = 0.5 + (0.4 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::giantRat:
        maxHp = 5.5 * lvl;
        maxAtk = 1 + (0.9 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::enormousRat:
        maxHp = 7 * lvl;
        maxAtk = 2 + (1.9 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 2;
        break;
    case EncounterType::colossalRat:
        maxHp = 7.5 * lvl;
        maxAtk = 3 + (1.5 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 3;
        break;
    case EncounterType::colossalSpider:
        maxHp = 8 * lvl;
        maxAtk = 2 + (1.05 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 3;
        break;
    case EncounterType::ratman:
        maxHp = 60.06 * lvl;
        maxAtk = 1 + (0.5 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 2;
        break;
    case EncounterType::goblin:
        maxHp = 6.5 * lvl;
        maxAtk = 1 + (1 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::hobgoblin:
        maxHp = 8.5 * lvl;
        maxAtk = 1.5 + (1.5 * lvl);
        maxDef = 5;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::orc:
        maxHp = 9 * lvl;
        maxAtk = 2.25 + (2.25 * lvl);
        maxDef = 5;
        critRate = 0;
        critDmg = 0;
        xp = 2;
        break;
    case EncounterType::kobold:
        maxHp = 6 * lvl;
        maxAtk = 0.5 + (1 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::kockbold:
        maxHp = 5.65 * lvl;
        maxAtk = 0.5 + (1 * lvl);
        maxDef = -69;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::cockblin:
        maxHp = 5.65 * lvl;
        maxAtk = 0.5 + (1 * lvl);
        maxDef = -69;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::the104:
        maxHp = 26 * lvl;
        maxAtk = 0 + (0.7 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 4;
        break;
    case EncounterType::errorGuy:
        maxHp = 0.01 * lvl;
        maxAtk = 0.1 + (0.1 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 1;
        break;
    case EncounterType::elesya:
        maxHp = 0 * lvl;
        maxAtk = 0 + (0 * lvl);
        maxDef = 50;
        critRate = 0;
        critDmg = 0;
        xp = -1;
        break;
    case EncounterType::kelmod:
        maxHp = 0 * lvl;
        maxAtk = 0 + (0 * lvl);
        maxDef = 35;
        critRate = 0;
        critDmg = 0;
        xp = -1;
        break;
    case EncounterType::lenre:
        maxHp = 0 * lvl;
        maxAtk = 0 + (0 * lvl);
        maxDef = 35;
        critRate = 0;
        critDmg = 0;
        xp = -1;
        break;
    case EncounterType::necoto:
        maxHp = 0 * lvl;
        maxAtk = 0 + (0 * lvl);
        maxDef = 80;
        critRate = 0;
        critDmg = 0;
        xp = -1;
        break;
    case EncounterType::kyo:
        maxHp = 0 * lvl;
        maxAtk = 0 + (0 * lvl);
        maxDef = 90;
        critRate = 0;
        critDmg = 0;
        xp = -1;
        break;
    case EncounterType::expN30A:
        maxHp = 0 * lvl;
        maxAtk = 0 + (0 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 0;
        break;
    case EncounterType::expN30B:
        maxHp = 0 * lvl;
        maxAtk = 0 + (0 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 0;
        break;
    case EncounterType::expN30C:
        maxHp = 0 * lvl;
        maxAtk = 0 + (0 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 0;
        break;
    case EncounterType::sila:
        maxHp = 0 * lvl;
        maxAtk = 0 + (0 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 0;
        break;
    case EncounterType::armNuc:
        maxHp = 0 * lvl;
        maxAtk = 0 + (0 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 0;
        break;
    case EncounterType::miiro:
        maxHp = 0 * lvl;
        maxAtk = 0 + (0 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 0;
        break;
    case EncounterType::chishao:
        maxHp = 0 * lvl;
        maxAtk = 0 + (0 * lvl);
        maxDef = 0;
        critRate = 0;
        critDmg = 0;
        xp = 0;
        break;
    case EncounterType::none:
        maxHp = 0 * lvl;
        maxAtk = 0 + (0 * lvl);
        maxDef = 999;
        critRate = 999;
        critDmg = 999;
        xp = 0;
        break;
    default:
        PrintError::notFound();
        break;
    }
    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}

void Creatures::Encounter::Encounterz::setState()
{
    m_isGone = false;
    m_isUnderAttack = false;
    m_canTalk = true;
}
