
#include "Encounter Stats.h"
#include "Encounter UID.h"
#include "Place.h"
#include "PlaceNames.h"
#include "Prng.h"
#include "Print Errors.h"
#include "Set Encounters.h"
#include "Stats.h"



void setEncountersPerPlace()
{

    // when the player gains a new lvl, he'll find a lvl up boss
    if (player().getLvlUpXp() >= player().getXp())
    {

        switch (printMainPlace(false))
        {
        case Places::village:// village
            setVillageEncounters();
            break;

        case Places::dungeon:// dungeon
            setDungeonEncounters();
            break;

        case Places::cave:// cave
            setCaveEncounters();
            break;

        case Places::forest:
            setForestEncounters();
            break;

        default:
            PrintError::notFound();
            break;
        }

    }
    else
    {

        switch (player().getLvl())
        {
        case 2://EXP. N. 30A
            encounter().setUid(EncounterUid::expN30A);
            break;

        case 3://EXP. N. 30B
            encounter().setUid(EncounterUid::expN30B);
            break;

        case 4://EXP. N. 30C
            encounter().setUid(EncounterUid::expN30C);
            break;

        case 5://Sila
            encounter().setUid(EncounterUid::sila);
            break;

        case 6:// Arm Nuc
            encounter().setUid(EncounterUid::armNuc);
            break;

        case 7://Miiro
            encounter().setUid(EncounterUid::miiro);
            break;

        case 8://Chishao
            encounter().setUid(EncounterUid::chishao);
            break;

        default://None

            break;
        }

    }
    

    // For a specific encounter use the next comment
    //encounter().setUid(EncounterUid::theRock);

}



void setDungeonEncounters()
{

    switch (Random::get(0, 30))
    {
    case 0:

        encounter().setUid(EncounterUid::loli);

        break;

    case 1:

        encounter().setUid(EncounterUid::torturer);

        break;

    case 2:

        encounter().setUid(EncounterUid::giant);

        break;

    case 3:

        encounter().setUid(EncounterUid::cleric);

        break;

    case 4:

        encounter().setUid(EncounterUid::elf);

        break;

    case 5:

        encounter().setUid(EncounterUid::dwarf);

        break;

    case 6:

        encounter().setUid(EncounterUid::prisoner);

        break;

    case 7:

        encounter().setUid(EncounterUid::theRock);

        break;

    case 8:

        encounter().setUid(EncounterUid::loli);

        break;

    case 9:

        encounter().setUid(EncounterUid::shota);

        break;

    case 10:

        encounter().setUid(EncounterUid::zombie);

        break;

    case 11:

        encounter().setUid(EncounterUid::skeleton);

        break;

    case 12:

        encounter().setUid(EncounterUid::witch);

        break;

    case 13:

        encounter().setUid(EncounterUid::ghost);

        break;

    case 14:

        encounter().setUid(EncounterUid::theBeer);

        break;

    case 15:

        encounter().setUid(EncounterUid::yourself);

        break;

    case 16:

        encounter().setUid(EncounterUid::stoneGolem);

        break;

    case 17:

        encounter().setUid(EncounterUid::smallRat);

        break;

    case 18:

        encounter().setUid(EncounterUid::rat);

        break;

    case 19:

        encounter().setUid(EncounterUid::giantRat);

        break;

    case 20:

        encounter().setUid(EncounterUid::enormousRat);

        break;

    case 21:

        encounter().setUid(EncounterUid::colossalRat);

        break;

    case 22:

        encounter().setUid(EncounterUid::colossalSpider);

        break;

    case 23:

        encounter().setUid(EncounterUid::ratman);

        break;

    case 24:

        encounter().setUid(EncounterUid::goblin);

        break;

    case 25:

        encounter().setUid(EncounterUid::hobgoblin);

        break;

    case 26:

        encounter().setUid(EncounterUid::orc);

        break;

    case 27:

        encounter().setUid(EncounterUid::kobold);

        break;

    case 28:

        encounter().setUid(EncounterUid::kockbold);

        break;

    case 29:

        encounter().setUid(EncounterUid::cockblin);

        break;

    case 30:

        encounter().setUid(EncounterUid::the104);

        break;

    default:

        encounter().setUid(EncounterUid::errorGuy);

        break;
    }

}



void setVillageEncounters()
{

    switch (Random::get(0, 17))
    {
    case 0:

        encounter().setUid(EncounterUid::guard);

        break;

    case 1:

        encounter().setUid(EncounterUid::drunkGuy);

        break;

    case 2:

        encounter().setUid(EncounterUid::torturer);

        break;

    case 3:

        encounter().setUid(EncounterUid::giant);

        break;

    case 4:

        encounter().setUid(EncounterUid::cleric);

        break;

    case 5:

        encounter().setUid(EncounterUid::elf);

        break;

    case 6:

        encounter().setUid(EncounterUid::dwarf);

        break;

    case 7:

        encounter().setUid(EncounterUid::prisoner);

        break;

    case 8:

        encounter().setUid(EncounterUid::theRock);

        break;

    case 9:

        encounter().setUid(EncounterUid::trader);

        break;

    case 10:

        encounter().setUid(EncounterUid::bartender);

        break;

    case 11:

        encounter().setUid(EncounterUid::bard);

        break;

    case 12:

        encounter().setUid(EncounterUid::loli);

        break;

    case 13:

        encounter().setUid(EncounterUid::shota);

        break;

    case 14:

        encounter().setUid(EncounterUid::smallRat);

        break;

    case 15:

        encounter().setUid(EncounterUid::rat);

        break;

    case 16:

        encounter().setUid(EncounterUid::ratman);

        break;

    case 17:

        encounter().setUid(EncounterUid::the104);

        break;

    default:

        encounter().setUid(EncounterUid::errorGuy);

        break;
    }

}



void setCaveEncounters()
{

    switch (Random::get(0, 30))
    {
    case 0:

        encounter().setUid(EncounterUid::soldier);

        break;

    case 1:

        encounter().setUid(EncounterUid::torturer);

        break;

    case 2:

        encounter().setUid(EncounterUid::giant);

        break;

    case 3:

        encounter().setUid(EncounterUid::cleric);

        break;

    case 4:

        encounter().setUid(EncounterUid::elf);

        break;

    case 5:

        encounter().setUid(EncounterUid::dwarf);

        break;

    case 6:

        encounter().setUid(EncounterUid::prisoner);

        break;

    case 7:

        encounter().setUid(EncounterUid::theRock);

        break;

    case 8:

        encounter().setUid(EncounterUid::loli);

        break;

    case 9:

        encounter().setUid(EncounterUid::shota);

        break;

    case 10:

        encounter().setUid(EncounterUid::zombie);

        break;

    case 11:

        encounter().setUid(EncounterUid::skeleton);

        break;

    case 12:

        encounter().setUid(EncounterUid::witch);

        break;

    case 13:

        encounter().setUid(EncounterUid::ghost);

        break;

    case 14:

        encounter().setUid(EncounterUid::theBeer);

        break;

    case 15:

        encounter().setUid(EncounterUid::yourself);

        break;

    case 16:

        encounter().setUid(EncounterUid::stoneGolem);

        break;

    case 17:

        encounter().setUid(EncounterUid::smallRat);

        break;

    case 18:

        encounter().setUid(EncounterUid::rat);

        break;

    case 19:

        encounter().setUid(EncounterUid::giantRat);

        break;

    case 20:

        encounter().setUid(EncounterUid::enormousRat);

        break;

    case 21:

        encounter().setUid(EncounterUid::colossalRat);

        break;

    case 22:

        encounter().setUid(EncounterUid::colossalSpider);

        break;

    case 23:

        encounter().setUid(EncounterUid::rat);

        break;

    case 24:

        encounter().setUid(EncounterUid::goblin);

        break;

    case 25:

        encounter().setUid(EncounterUid::hobgoblin);

        break;

    case 26:

        encounter().setUid(EncounterUid::orc);

        break;

    case 27:

        encounter().setUid(EncounterUid::kobold);

        break;

    case 28:

        encounter().setUid(EncounterUid::kockbold);

        break;

    case 29:

        encounter().setUid(EncounterUid::cockblin);

        break;

    case 30:

        encounter().setUid(EncounterUid::the104);

        break;

    default:

        encounter().setUid(EncounterUid::errorGuy);

        break;
    }

}



void setForestEncounters()
{

    switch (Random::get(0, 34))
    {
    case 0:

        encounter().setUid(EncounterUid::guard);

        break;

    case 1:

        encounter().setUid(EncounterUid::drunkGuy);

        break;

    case 2:

        encounter().setUid(EncounterUid::soldier);

        break;

    case 3:

        encounter().setUid(EncounterUid::torturer);

        break;

    case 4:

        encounter().setUid(EncounterUid::giant);

        break;

    case 5:

        encounter().setUid(EncounterUid::cleric);

        break;

    case 6:

        encounter().setUid(EncounterUid::elf);

        break;

    case 7:

        encounter().setUid(EncounterUid::dwarf);

        break;

    case 8:

        encounter().setUid(EncounterUid::prisoner);

        break;

    case 9:

        encounter().setUid(EncounterUid::theRock);

        break;

    case 10:

        encounter().setUid(EncounterUid::trader);

        break;

    case 11:

        encounter().setUid(EncounterUid::bartender);

        break;

    case 12:

        encounter().setUid(EncounterUid::bard);

        break;

    case 13:

        encounter().setUid(EncounterUid::loli);

        break;

    case 14:

        encounter().setUid(EncounterUid::shota);

        break;

    case 15:

        encounter().setUid(EncounterUid::zombie);

        break;

    case 16:

        encounter().setUid(EncounterUid::skeleton);

        break;

    case 17:

        encounter().setUid(EncounterUid::witch);

        break;

    case 18:

        encounter().setUid(EncounterUid::ghost);

        break;

    case 19:

        encounter().setUid(EncounterUid::theBeer);

        break;

    case 20:

        encounter().setUid(EncounterUid::yourself);

        break;

    case 21:

        encounter().setUid(EncounterUid::stoneGolem);

        break;

    case 22:

        encounter().setUid(EncounterUid::smallRat);

        break;

    case 23:

        encounter().setUid(EncounterUid::rat);

        break;

    case 24:

        encounter().setUid(EncounterUid::giant);

        break;

    case 25:

        encounter().setUid(EncounterUid::colossalRat);

        break;

    case 26:

        encounter().setUid(EncounterUid::colossalSpider);

        break;

    case 27:

        encounter().setUid(EncounterUid::ratman);

        break;

    case 28:

        encounter().setUid(EncounterUid::goblin);

        break;

    case 29:

        encounter().setUid(EncounterUid::hobgoblin);

        break;

    case 30:

        encounter().setUid(EncounterUid::orc);

        break;

    case 31:

        encounter().setUid(EncounterUid::kobold);

        break;

    case 32:

        encounter().setUid(EncounterUid::kockbold);

        break;

    case 33:

        encounter().setUid(EncounterUid::cockblin);

        break;

    case 34:

        encounter().setUid(EncounterUid::the104);

        break;

    default:

        encounter().setUid(EncounterUid::errorGuy);

        break;
    }

}