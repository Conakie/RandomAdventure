
#include "GetEncounterTypePerPlace.h"
#include "Random.h"



Creatures::Encounter::EncounterType getEncounterTypePerPlace(Places place)
{
	switch (place)
	{
	case Places::village:
		return getVillageEncountersType();
	case Places::dungeon:
		return getDungeonEncountersType();
	case Places::cave:
		return getCaveEncountersType();
	case Places::forest:
		return getForestEncountersType();
	default:
		return Creatures::Encounter::EncounterType::errorGuy;
		break;
	}
    return Creatures::Encounter::EncounterType::errorGuy;
}

Creatures::Encounter::EncounterType getVillageEncountersType()
{
    switch (Random::get(0, 17))
    {
    case 0:
        return Creatures::Encounter::EncounterType::guard;
    case 1:
        return Creatures::Encounter::EncounterType::drunkGuy;
    case 2:
        return Creatures::Encounter::EncounterType::torturer;
    case 3:
        return Creatures::Encounter::EncounterType::giant;
    case 4:
        return Creatures::Encounter::EncounterType::cleric;
    case 5:
        return Creatures::Encounter::EncounterType::elf;
    case 6:
        return Creatures::Encounter::EncounterType::dwarf;
    case 7:
        return Creatures::Encounter::EncounterType::prisoner;
    case 8:
        return Creatures::Encounter::EncounterType::theRock;
    case 9:
        return Creatures::Encounter::EncounterType::trader;
    case 10:
        return Creatures::Encounter::EncounterType::bartender;
    case 11:
        return Creatures::Encounter::EncounterType::bard;
    case 12:
        return Creatures::Encounter::EncounterType::loli;
    case 13:
        return Creatures::Encounter::EncounterType::shota;
    case 14:
        return Creatures::Encounter::EncounterType::smallRat;
    case 15:
        return Creatures::Encounter::EncounterType::rat;
    case 16:
        return Creatures::Encounter::EncounterType::ratman;
    case 17:
        return Creatures::Encounter::EncounterType::the104;
    default:
        break;
    }
	return Creatures::Encounter::EncounterType::errorGuy;
}

Creatures::Encounter::EncounterType getDungeonEncountersType()
{
    switch (Random::get(0, 29))
    {
    case 0:
        return Creatures::Encounter::EncounterType::shota;
    case 1:
        return Creatures::Encounter::EncounterType::loli;
    case 2:
        return Creatures::Encounter::EncounterType::torturer;
    case 3:
        return Creatures::Encounter::EncounterType::giant;
    case 4:
        return Creatures::Encounter::EncounterType::cleric;
    case 5:
        return Creatures::Encounter::EncounterType::elf;
    case 6:
        return Creatures::Encounter::EncounterType::dwarf;
    case 7:
        return Creatures::Encounter::EncounterType::prisoner;
    case 8:
        return Creatures::Encounter::EncounterType::theRock;
    case 9:
        return Creatures::Encounter::EncounterType::zombie;
    case 10:
        return Creatures::Encounter::EncounterType::skeleton;
    case 11:
        return Creatures::Encounter::EncounterType::witch;
    case 12:
        return Creatures::Encounter::EncounterType::ghost;
    case 13:
        return Creatures::Encounter::EncounterType::theBeer;
    case 14:
        return Creatures::Encounter::EncounterType::yourself;
    case 15:
        return Creatures::Encounter::EncounterType::stoneGolem;
    case 16:
        return Creatures::Encounter::EncounterType::smallRat;
    case 17:
        return Creatures::Encounter::EncounterType::rat;
    case 18:
        return Creatures::Encounter::EncounterType::giantRat;
    case 19:
        return Creatures::Encounter::EncounterType::enormousRat;
    case 20:
        return Creatures::Encounter::EncounterType::colossalRat;
    case 21:
        return Creatures::Encounter::EncounterType::colossalSpider;
    case 22:
        return Creatures::Encounter::EncounterType::ratman;
    case 23:
        return Creatures::Encounter::EncounterType::goblin;
    case 24:
        return Creatures::Encounter::EncounterType::hobgoblin;
    case 25:
        return Creatures::Encounter::EncounterType::kobold;
    case 26:
        return Creatures::Encounter::EncounterType::kockbold;
    case 27:
        return Creatures::Encounter::EncounterType::cockblin;
    case 28:
        return Creatures::Encounter::EncounterType::the104;
    case 29:
        return Creatures::Encounter::EncounterType::orc;
    default:
        return Creatures::Encounter::EncounterType::errorGuy;
        break;
    }
	return Creatures::Encounter::EncounterType::errorGuy;
}

Creatures::Encounter::EncounterType getCaveEncountersType()
{
    switch (Random::get(0, 28))
    {
    case 0:
        return Creatures::Encounter::EncounterType::soldier;
    case 1:
        return Creatures::Encounter::EncounterType::torturer;
    case 2:
        return Creatures::Encounter::EncounterType::giant;
    case 3:
        return Creatures::Encounter::EncounterType::cleric;
    case 4:
        return Creatures::Encounter::EncounterType::elf;
    case 5:
        return Creatures::Encounter::EncounterType::dwarf;
    case 6:
        return Creatures::Encounter::EncounterType::prisoner;
    case 7:
        return Creatures::Encounter::EncounterType::theRock;
    case 8:
        return Creatures::Encounter::EncounterType::loli;
    case 9:
        return Creatures::Encounter::EncounterType::shota;
    case 10:
        return Creatures::Encounter::EncounterType::zombie;
    case 11:
        return Creatures::Encounter::EncounterType::skeleton;
    case 12:
        return Creatures::Encounter::EncounterType::witch;
    case 13:
        return Creatures::Encounter::EncounterType::ghost;
    case 14:
        return Creatures::Encounter::EncounterType::theBeer;
    case 15:
        return Creatures::Encounter::EncounterType::yourself;
    case 16:
        return Creatures::Encounter::EncounterType::stoneGolem;
    case 17:
        return Creatures::Encounter::EncounterType::smallRat;
    case 18:
        return Creatures::Encounter::EncounterType::rat;
    case 19:
        return Creatures::Encounter::EncounterType::giantRat;
    case 20:
        return Creatures::Encounter::EncounterType::enormousRat;
    case 21:
        return Creatures::Encounter::EncounterType::colossalRat;
    case 22:
        return Creatures::Encounter::EncounterType::colossalSpider;
    case 23:
        return Creatures::Encounter::EncounterType::goblin;
    case 24:
        return Creatures::Encounter::EncounterType::hobgoblin;
    case 25:
        return Creatures::Encounter::EncounterType::cockblin;
    case 26:
        return Creatures::Encounter::EncounterType::kockbold;
    case 27:
        return Creatures::Encounter::EncounterType::orc;
    case 28:
        return Creatures::Encounter::EncounterType::the104;
    default:
        return Creatures::Encounter::EncounterType::errorGuy;
        break;
    }
	return Creatures::Encounter::EncounterType::errorGuy;
}

Creatures::Encounter::EncounterType getForestEncountersType()
{
    switch (Random::get(0, 36))
    {
    case 0:
        return Creatures::Encounter::EncounterType::guard;
    case 1:
        return Creatures::Encounter::EncounterType::drunkGuy;
    case 2:
        return Creatures::Encounter::EncounterType::soldier;
    case 3:
        return Creatures::Encounter::EncounterType::torturer;
    case 4:
        return Creatures::Encounter::EncounterType::giant;
    case 5:
        return Creatures::Encounter::EncounterType::cleric;
    case 6:
        return Creatures::Encounter::EncounterType::elf;
    case 7:
        return Creatures::Encounter::EncounterType::dwarf;
    case 8:
        return Creatures::Encounter::EncounterType::prisoner;
    case 9:
        return Creatures::Encounter::EncounterType::theRock;
    case 10:
        return Creatures::Encounter::EncounterType::trader;
    case 11:
        return Creatures::Encounter::EncounterType::bard;
    case 12:
        return Creatures::Encounter::EncounterType::loli;
    case 13:
        return Creatures::Encounter::EncounterType::shota;
    case 14:
        return Creatures::Encounter::EncounterType::zombie;
    case 15:
        return Creatures::Encounter::EncounterType::skeleton;
    case 16:
        return Creatures::Encounter::EncounterType::witch;
    case 17:
        return Creatures::Encounter::EncounterType::ghost;
    case 18:
        return Creatures::Encounter::EncounterType::theBeer;
    case 19:
        return Creatures::Encounter::EncounterType::yourself;
    case 20:
        return Creatures::Encounter::EncounterType::stoneGolem;
    case 21:
        return Creatures::Encounter::EncounterType::blurp;
    case 22:
        return Creatures::Encounter::EncounterType::smallRat;
    case 23:
        return Creatures::Encounter::EncounterType::rat;
    case 24:
        return Creatures::Encounter::EncounterType::giantRat;
    case 25:
        return Creatures::Encounter::EncounterType::giantRat;
    case 26:
        return Creatures::Encounter::EncounterType::enormousRat;
    case 27:
        return Creatures::Encounter::EncounterType::colossalRat;
    case 28:
        return Creatures::Encounter::EncounterType::colossalSpider;
    case 29:
        return Creatures::Encounter::EncounterType::ratman;
    case 30:
        return Creatures::Encounter::EncounterType::goblin;
    case 31:
        return Creatures::Encounter::EncounterType::hobgoblin;
    case 32:
        return Creatures::Encounter::EncounterType::orc;
    case 33:
        return Creatures::Encounter::EncounterType::kobold;
    case 34:
        return Creatures::Encounter::EncounterType::kockbold;
    case 35:
        return Creatures::Encounter::EncounterType::cockblin;
    case 36:
        return Creatures::Encounter::EncounterType::the104;
    default:
        return Creatures::Encounter::EncounterType::errorGuy;
        break;
    }
	return Creatures::Encounter::EncounterType::errorGuy;
}
