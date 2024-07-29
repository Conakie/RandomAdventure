
#ifndef KIIYUO_RATABS_GETENCOUNTERPERPLACE_H
#define KIIYUO_RATABS_GETENCOUNTERPERPLACE_H

#include "EncounterType.h"
#include "PlaceNames.h"

Creatures::Encounter::EncounterType getEncounterTypePerPlace(Places place);
Creatures::Encounter::EncounterType getVillageEncountersType();
Creatures::Encounter::EncounterType getDungeonEncountersType();
Creatures::Encounter::EncounterType getCaveEncountersType();
Creatures::Encounter::EncounterType getForestEncountersType();

#endif // !KIIYUO_RATABS_GETENCOUNTERPERPLACE_H