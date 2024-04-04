
#include <iostream>
#include "Everywhere Used Func.h"
#include "Parla Con Gli Incontri.h"
#include "Talk To Encounters English.h"
#include "Encounter Stats.h"
#include "Print Errors.h"
#include "Encounter UID.h"
#include "Stats.h"



void talkToEncounters()
{
    switch (encounter().getUid())
    {
    case EncounterUid::guard:
        guard();
        break;

    case EncounterUid::drunkGuy:
        drunkGuy();
        break;

    case EncounterUid::soldier:
        soldier();
        break;

    case EncounterUid::torturer:
        torturer();
        break;

    case EncounterUid::giant:
        giant();
        break;

    case EncounterUid::cleric:
        cleric();
        break;

    case EncounterUid::elf:
        elf();
        break;

    case EncounterUid::dwarf:
        dwarf();
        break;

    case EncounterUid::prisoner:
        prisoner();
        break;

    case EncounterUid::theRock:
        theRock();
        break;

    case EncounterUid::trader:
        trader();
        break;

    case EncounterUid::bartender:
        bartender();
        break;

    case EncounterUid::bard:
        bard();
        break;

    case EncounterUid::loli:
        loli();
        break;

    case EncounterUid::shota:
        shota();
        break;

    case EncounterUid::zombie:
        zombie();
        break;

    case EncounterUid::skeleton:
        skeletron();
        break;

    case EncounterUid::witch:
        noTalking();
        break;

    case EncounterUid::ghost:
        ghost();
        break;

    case EncounterUid::theBeer:
        theBeer();
        break;

    case EncounterUid::yourself:
        yourself();
        break;

    case EncounterUid::stoneGolem:
        stoneGolem();
        break;

    case EncounterUid::blurp:
        blurp();
        break;

    case EncounterUid::smallRat:
        allAnimals();
        break;

    case EncounterUid::rat:
        allAnimals();
        break;

    case EncounterUid::giantRat:
        allAnimals();
        break;

    case EncounterUid::enormousRat:
        allAnimals();
        break;

    case EncounterUid::colossalRat:
        allAnimals();
        break;

    case EncounterUid::colossalSpider:
        allAnimals();
        break;

    case EncounterUid::ratman:
        ratman();
        break;

    case EncounterUid::goblin:
        goblin();
        break;

    case EncounterUid::hobgoblin:
        noTalking();
        break;

    case EncounterUid::orc:
        noTalking();
        break;

    case EncounterUid::kobold:
        kobold();
        break;

    case EncounterUid::kockbold:
        kockEncounters();
        break;

    case EncounterUid::cockblin:
        kockEncounters();
        break;

    case EncounterUid::the104:
        noTalking();
        break;

    case EncounterUid::errorGuy:
        noTalking();
        break;

    case EncounterUid::elesya:
        elesya();
        break;

    case EncounterUid::kelmod:
        kelmod(false);
        break;

    case EncounterUid::lenre:
        lenre(false);
        break;

    case EncounterUid::necoto:
        necoto();
        break;

    case EncounterUid::kyo:
        kyo();
        break;

    case EncounterUid::expN30A:
        expN30A();
        break;

    case EncounterUid::expN30B:
        expN30B();
        break;

    case EncounterUid::expN30C:
        expN30C();
        break;

    case EncounterUid::sila:
        sila();
        break;

    case EncounterUid::armNuc:
        armNuc();
        break;
    case EncounterUid::miiro:
        miiro();
        break;

    case EncounterUid::chishao:
        chishao();
        break;

    case EncounterUid::none:
        PrintError::notFound();
        break;

    default:
        PrintError::notFound();
        break;
    }
    waitForAnyKey();
}



void parlaConGliIncontri()
{

    bool attack{ true };


    switch (1)
    {
    case 1://guard

        guardia();

        break;

    case 2://drunk guy

        tizioUbriaco();

        break;

    case 3://Soldier

        soldato();

        break;

    case 4://Torturer

        torturatore();

        break;

    case 5://Giant

        noParlamento();

        break;

    case 6://Cleric

        clerico();

        break;

    case 7://Elf

        elfo();

        break;

    case 8://Dwarf

        nano();

        break;

    case 20://Zombie

        zombi();

        break;

    case 21://Skeleton

        skeletro();

        break;

    case 22://Witch

        noParlamento();

        break;

    case 40://Small rat

        tuttiGliAnimali();

        break;

    case 41://Rat

        tuttiGliAnimali();

        break;

    case 42://Giant rat

        tuttiGliAnimali();

        break;

    case 43://Enormous rat

        tuttiGliAnimali();

        break;

    case 44://Colossal rat

        tuttiGliAnimali();

        break;

    case 45://Colossal spider

        tuttiGliAnimali();

        break;

    case 60://Goblin

        goblino();

        break;

    case 61://Hobgoblin

        noParlamento();

        break;

    case 62://Orc

        noParlamento();

        break;

    case 104://104

        noParlamento();

        break;

    case 69://error guy

        noParlamento();

        break;

    case 200://Elesya

        elesya();

        break;

    case 201://Kelmod

        kelmod(false);

        break;

    case 202://Lenre

        lenre(false);

        break;

    case 203://Necoto

        necoto();

        break;

    case 204://Kyo

        kyo();

        break;

    case 300://Exp. N. 30C

        expN30C();

        break;

    case 301://Exp. N. 30A

        expN30A();

        break;

    case 302://Exp. N. 30B

        expN30B();

        break;

    case 303://Sila

        sila();

        break;

    case 304://Miiro

        miiro();

        break;

    case 305://Chishao

        chishao();

        break;

    default://Not found

        std::cout << "Error: not found\n";

        break;
    }

}