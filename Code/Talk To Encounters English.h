
#ifndef KIIYUO_RATABS_TALKTOENCOUNTERS_H
#define KIIYUO_RATABS_TALKTOENCOUNTERS_H

#include "EncounterType.h"
#include "Encounterz.h"

// This choose the encounter to talk to.
void talkToEncounters();
void talkToEncounters(Creatures::Encounter::EncounterType encType);


// Encounters
void guard();

void drunkGuy();

void cleric();

void goblin();

void soldier();

void elf();

void dwarf();

void prisoner();

void allAnimals();

void torturer();

void kobold();

void kockEncounters();

void theBeer();

void yourself();

void theRock();

void bartender();

void bard();

void blurp();

void stoneGolem();

void trader();

void ghost();

void giant();

void loli();

void shota();

void ratman();

void rats(Creatures::Encounter::Encounterz* rat);

// also known as Yugei sansae
void zombie();

// also known as Seina Olpi
void skeletron();


// lvl bosses
void expN30A();

void expN30B();

void expN30C();

void sila();

void armNuc();

void miiro();

void chishao();

//	Narrators
bool elesya();

bool kelmod(bool sendByElesya);

bool lenre(bool sendByElesya);

void necoto();

//void necoto();

void kyo();


// If dialogues aren't available
void noTalking();

#endif // !KIIYUO_RATABS_TALKTOENCOUNTERS_H
