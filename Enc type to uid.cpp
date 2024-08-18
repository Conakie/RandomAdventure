
#include "Encounter UID.h"
#include "EncounterType.h"


EncounterUid toEncUid(Creatures::Encounter::EncounterType type)
{
    using EncType = Creatures::Encounter::EncounterType;

    switch (type)
    {
    case EncType::guard:
        return EncounterUid::guard;
    case EncType::drunkGuy:
        return EncounterUid::drunkGuy;
    case EncType::soldier:
        return EncounterUid::soldier;
    case EncType::torturer:
        return EncounterUid::torturer;
    case EncType::giant:
        return EncounterUid::giant;
    case EncType::cleric:
        return EncounterUid::cleric;
    case EncType::elf:
        return EncounterUid::elf;
    case EncType::dwarf:
        return EncounterUid::dwarf;
    case EncType::prisoner:
        return EncounterUid::prisoner;
    case EncType::theRock:
        return EncounterUid::theRock;
    case EncType::trader:
        return EncounterUid::trader;
    case EncType::bartender:
        return EncounterUid::bartender;
    case EncType::bard:
        return EncounterUid::bard;
    case EncType::loli:
        return EncounterUid::loli;
    case EncType::shota:
        return EncounterUid::shota;
    case EncType::zombie:
        return EncounterUid::zombie;
    case EncType::skeleton:
        return EncounterUid::skeleton;
    case EncType::witch:
        return EncounterUid::witch;
    case EncType::ghost:
        return EncounterUid::ghost;
    case EncType::theBeer:
        return EncounterUid::theBeer;
    case EncType::yourself:
        return EncounterUid::yourself;
    case EncType::stoneGolem:
        return EncounterUid::stoneGolem;
    case EncType::blurp:
        return EncounterUid::blurp;
    case EncType::smallRat:
        return EncounterUid::smallRat;
    case EncType::rat:
        return EncounterUid::rat;
    case EncType::giantRat:
        return EncounterUid::giantRat;
    case EncType::enormousRat:
        return EncounterUid::enormousRat;
    case EncType::colossalRat:
        return EncounterUid::colossalRat;
    case EncType::colossalSpider:
        return EncounterUid::colossalSpider;
    case EncType::ratman:
        return EncounterUid::ratman;
    case EncType::goblin:
        return EncounterUid::goblin;
    case EncType::hobgoblin:
        return EncounterUid::hobgoblin;
    case EncType::orc:
        return EncounterUid::orc;
    case EncType::kobold:
        return EncounterUid::kobold;
    case EncType::kockbold:
        return EncounterUid::kockbold;
    case EncType::cockblin:
        return EncounterUid::cockblin;
    case EncType::the104:
        return EncounterUid::the104;
    case EncType::errorGuy:
        return EncounterUid::errorGuy;
    case EncType::elesya:
        return EncounterUid::elesya;
    case EncType::kelmod:
        return EncounterUid::kelmod;
    case EncType::lenre:
        return EncounterUid::lenre;
    case EncType::necoto:
        return EncounterUid::necoto;
    case EncType::kyo:
        return EncounterUid::kyo;
    case EncType::expN30A:
        return EncounterUid::expN30A;
    case EncType::expN30B:
        return EncounterUid::expN30B;
    case EncType::expN30C:
        return EncounterUid::expN30C;
    case EncType::sila:
        return EncounterUid::sila;
    case EncType::armNuc:
        return EncounterUid::armNuc;
    case EncType::miiro:
        return EncounterUid::miiro;
    case EncType::chishao:
        return EncounterUid::chishao;
    case EncType::none:
        return EncounterUid::none;
    default:
        return EncounterUid::none;
    }
    return EncounterUid::errorGuy;
}