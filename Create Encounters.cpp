
#include<iostream>
#include "Create Encounters.h"
#include "Print Errors.h"
#include "Guard.h"
#include "DrunkGuy.h"
#include "Soldier.h"
#include "Torturer.h"
#include "Giant.h"
#include "Priest.h"
#include "Elf.h"
#include "Dwarf.h"
#include "Prisoner.h"
#include "TheRock.h"
#include "Trader.h"
#include "Bartender.h"
#include "Bard.h"
#include "Loli.h"
#include "Shota.h"
#include "Zombie.h"
#include "Skeletron.h"
#include "Witch.h"
#include "Ghost.h"
#include "TheBeer.h"
#include "Yourself.h"
#include "StoneGolem.h"
#include "Blurp.h"
#include "SmallRat.h"
#include "Rat.h"
#include "GiantRat.h"
#include "EnormousRat.h"
#include "ColossalRat.h"
#include "ColossalSpider.h"
#include "Ratman.h"
#include "Goblin.h"
#include "HobGoblin.h"
#include "Orc.h"
#include "Kobold.h"
#include "Cockblin.h"
#include "Kockbold.h"
#include "The104.h"



Creatures::Encounter::Encounterz* createEncounter(Creatures::Encounter::EncounterType encType, int level)
{
    Creatures::Encounter::Encounterz* enc{ nullptr };
    int i{ 0 };
    bool retry{ false };
    

    do
    {
        try
        {
            // next line is for specific tests. Comment it after finishing
            //encType = Creatures::Encounter::EncounterType::goblin;
            enc = setAndGetEncounter(encType);
            retry = false;
        }
        catch (std::bad_alloc&)
        {
            if (i > 4)
            {
                std::cout << "Nanre: \"A fatal error came upon us! Your os is not giving us any ram.\n"
                    << "Please, free some ram for us or close the game. We cannot do much.\"\n";
                retry = false;
            }
            else
            {
                std::cout << "Nanre: \"An error occured... We're trying to solve the problem.\"\n";
                ++i;
                retry = true;
            }
        }
    } while (retry);
    
    enc->resetStats();
    enc->setLevel(level);
    enc->setType(encType);
    enc->setEncounter();

    return enc;
}

Creatures::Encounter::Encounterz* setAndGetEncounter(Creatures::Encounter::EncounterType encType)
{
    using Encounter_Type = Creatures::Encounter::EncounterType;


    Creatures::Encounter::Encounterz* enc{ nullptr };


    switch (encType)
    {
    case Encounter_Type::guard:
        enc = new Creatures::Encounter::Guard;
        enc->setType(encType);
        break;
    case Encounter_Type::drunkGuy:
        enc = new Creatures::Encounter::DrunkGuy;
        enc->setType(encType);
        break;
    case Encounter_Type::soldier:
        enc = new Creatures::Encounter::Soldier;
        enc->setType(encType);
        break;
    case Encounter_Type::torturer:
        enc = new Creatures::Encounter::Torturer;
        enc->setType(encType);
        break;
    case Encounter_Type::giant:
        enc = new Creatures::Encounter::Giant;
        enc->setType(encType);
        break;
    case Encounter_Type::cleric:
        enc = new Creatures::Encounter::Priest;
        enc->setType(encType);
        break;
    case Encounter_Type::elf:
        enc = new Creatures::Encounter::Elf;
        enc->setType(encType);
        break;
    case Encounter_Type::dwarf:
        enc = new Creatures::Encounter::Dwarf;
        enc->setType(encType);
        break;
    case Encounter_Type::prisoner:
        enc = new Creatures::Encounter::Prisoner;
        enc->setType(encType);
        break;
    case Encounter_Type::theRock:
        enc = new Creatures::Encounter::TheRock;
        enc->setType(encType);
        break;
    case Encounter_Type::trader:
        enc = new Creatures::Encounter::Trader;
        enc->setType(encType);
        break;
    case Encounter_Type::bartender:
        enc = new Creatures::Encounter::Bartender;
        enc->setType(encType);
        break;
    case Encounter_Type::bard:
        enc = new Creatures::Encounter::Bard;
        enc->setType(encType);
        break;
    case Encounter_Type::loli:
        enc = new Creatures::Encounter::Loli;
        enc->setType(encType);
        break;
    case Encounter_Type::shota:
        enc = new Creatures::Encounter::Shota;
        enc->setType(encType);
        break;
    case Encounter_Type::zombie:
        enc = new Creatures::Encounter::Zombie;
        enc->setType(encType);
        break;
    case Encounter_Type::skeleton:
        enc = new Creatures::Encounter::Skeletron;
        enc->setType(encType);
        break;
    case Encounter_Type::witch:
        enc = new Creatures::Encounter::Witch;
        enc->setType(encType);
        break;
    case Encounter_Type::ghost:
        enc = new Creatures::Encounter::Ghost;
        enc->setType(encType);
        break;
    case Encounter_Type::theBeer:
        enc = new Creatures::Encounter::TheBeer;
        enc->setType(encType);
        break;
    case Encounter_Type::yourself:
        enc = new Creatures::Encounter::Yourself;
        enc->setType(encType);
        break;
    case Encounter_Type::stoneGolem:
        enc = new Creatures::Encounter::StoneGolem;
        enc->setType(encType);
        break;
    case Encounter_Type::blurp:
        enc = new Creatures::Encounter::Blurp;
        enc->setType(encType);
        break;
    case Encounter_Type::smallRat:
        enc = new Creatures::Encounter::SmallRat;
        enc->setType(encType);
        break;
    case Encounter_Type::rat:
        enc = new Creatures::Encounter::Rat;
        enc->setType(encType);
        break;
    case Encounter_Type::giantRat:
        enc = new Creatures::Encounter::GiantRat;
        enc->setType(encType);
        break;
    case Encounter_Type::enormousRat:
        enc = new Creatures::Encounter::EnormousRat;
        enc->setType(encType);
        break;
    case Encounter_Type::colossalRat:
        enc = new Creatures::Encounter::ColossalRat;
        enc->setType(encType);
        break;
    case Encounter_Type::colossalSpider:
        enc = new Creatures::Encounter::ColossalSpider;
        enc->setType(encType);
        break;
    case Encounter_Type::ratman:
        enc = new Creatures::Encounter::Ratman;
        enc->setType(encType);
        break;
    case Encounter_Type::goblin:
        enc = new Creatures::Encounter::Goblin;
        enc->setType(encType);
        break;
    case Encounter_Type::hobgoblin:
        enc = new Creatures::Encounter::HobGoblin;
        enc->setType(encType);
        break;
    case Encounter_Type::orc:
        enc = new Creatures::Encounter::Orc;
        enc->setType(encType);
        break;
    case Encounter_Type::kobold:
        enc = new Creatures::Encounter::Kobold;
        enc->setType(encType);
        break;
    case Encounter_Type::kockbold:
        enc = new Creatures::Encounter::Kockbold;
        enc->setType(encType);
        break;
    case Encounter_Type::cockblin:
        enc = new Creatures::Encounter::Cockblin;
        enc->setType(encType);
        break;
    case Encounter_Type::the104:
        enc = new Creatures::Encounter::The104;
        enc->setType(encType);
        break;
    case Encounter_Type::errorGuy:
        enc = new Creatures::Encounter::Encounterz;
        enc->setType(encType);
        break;
    case Encounter_Type::elesya:
        enc = new Creatures::Encounter::Encounterz;
        enc->setType(encType);
        break;
    case Encounter_Type::kelmod:
        enc = new Creatures::Encounter::Encounterz;
        enc->setType(encType);
        break;
    case Encounter_Type::lenre:
        enc = new Creatures::Encounter::Encounterz;
        enc->setType(encType);
        break;
    case Encounter_Type::necoto:
        enc = new Creatures::Encounter::Encounterz;
        enc->setType(encType);
        break;
    case Encounter_Type::kyo:
        enc = new Creatures::Encounter::Encounterz;
        enc->setType(encType);
        break;
    case Encounter_Type::expN30A:
        enc = new Creatures::Encounter::Encounterz;
        enc->setType(encType);
        break;
    case Encounter_Type::expN30B:
        enc = new Creatures::Encounter::Encounterz;
        enc->setType(encType);
        break;
    case Encounter_Type::expN30C:
        enc = new Creatures::Encounter::Encounterz;
        enc->setType(encType);
        break;
    case Encounter_Type::sila:
        enc = new Creatures::Encounter::Encounterz;
        enc->setType(encType);
        break;
    case Encounter_Type::armNuc:
        enc = new Creatures::Encounter::Encounterz;
        enc->setType(encType);
        break;
    case Encounter_Type::miiro:
        enc = new Creatures::Encounter::Encounterz;
        enc->setType(encType);
        break;
    case Encounter_Type::chishao:
        enc = new Creatures::Encounter::Encounterz;
        enc->setType(encType);
        break;
    case Encounter_Type::none:
        enc = new Creatures::Encounter::Encounterz;
        enc->setType(Encounter_Type::errorGuy);
        break;
    default:
        enc = new Creatures::Encounter::Encounterz;
        enc->setType(Encounter_Type::errorGuy);
        break;
    }

    return enc;
}
